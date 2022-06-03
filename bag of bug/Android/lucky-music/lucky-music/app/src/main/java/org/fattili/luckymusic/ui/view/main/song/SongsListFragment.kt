package org.fattili.luckymusic.ui.view.main.song

import android.content.Intent
import androidx.lifecycle.ViewModelProvider
import androidx.recyclerview.widget.LinearLayoutManager
import kotlinx.android.synthetic.main.lm_song_fragment_songs_list.*
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.base.BaseBean
import org.fattili.luckymusic.data.constant.MessageType
import org.fattili.luckymusic.data.constant.ShowMsg
import org.fattili.luckymusic.ui.adapter.SongsListAdapter
import org.fattili.luckymusic.ui.base.BaseFragment
import org.fattili.luckymusic.ui.view.main.song.add.AddSongsDialog
import org.fattili.luckymusic.ui.view.main.song.edit.SongsEditActivity
import org.fattili.luckymusic.util.InjectorUtil
import org.fattili.luckymusic.util.RxBus
import org.fattili.luckymusic.util.registerInBus

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌单列表
 */
class SongsListFragment : BaseFragment() {

    private lateinit var itemAdapter: SongsListAdapter

    override val layoutId: Int
        get() = R.layout.lm_song_fragment_songs_list

    private val viewModel by lazy {
        ViewModelProvider(
            this,
            InjectorUtil.getSongsModelFactory()
        ).get(SongsListViewModel::class.java)
    }

    override fun initView() {
        initList()
        lm_song_songs_list_add_bt.setOnClickListener { showAddDialog() }
        register()
    }

    override fun initData() {
        viewModel.getSongsList()
        viewModel.dataChanged.observe(this, androidx.lifecycle.Observer {
            itemAdapter.update()
        })
    }

    private fun initList() {
        itemAdapter = SongsListAdapter(viewModel.list)

        itemAdapter.clickListener = {
            var intent = Intent(context, SongListActivity::class.java)
            intent.putExtra("songsId", itemAdapter.getItem(it)?.id)
            startActivity(intent)
        }
        itemAdapter.setMoreClickListener { pos ->
            val id = itemAdapter.getItem(pos)?.id ?: 0
            val pop = activity?.let { view?.let { it1 -> SongsListMorePopup(id, it, it1) } }
            pop?.callback = object : SongsListMorePopup.PopCallBack {
                override fun play() { play(id) }
                override fun delete() { delete(id) }
                override fun prePlay() { prePlay(id) }
                override fun edit() { context?.let { SongsEditActivity.actionStart(it,id ) } }
            }
            pop?.show()
        }
        lm_song_songs_list.layoutManager = LinearLayoutManager(context)
        lm_song_songs_list.adapter = itemAdapter

    }

    private fun play(songsId:Long){
        viewModel.play(songsId)
    }


    private fun delete(songsId:Long){
        if (viewModel.delete(songsId) > 0) {
            showMsg(ShowMsg.msg_delete_ok)
        } else {
            showMsg(ShowMsg.msg_delete_fail)
        }
    }


    private fun prePlay(songsId:Long){
        viewModel.prePlay(songsId)
        showMsg(ShowMsg.msg_add_playlist_ok)
    }

    private fun showAddDialog() {
        context?.let {
            var dialog = AddSongsDialog(it)
            dialog.dialogResult = object : AddSongsDialog.DialogResult {
                override fun addResult(name: String) {
                    val ret = viewModel.add(name)
                    if (ret) {
                        showMsg("添加成功")
                        dialog.dismiss()
                    } else {
                        showMsg("添加失败")
                    }
                }
            }
            dialog.show()
        }

    }


    companion object {
        fun newInstance(): SongsListFragment {
            return SongsListFragment()
        }
    }


    /**
     * 注册获取到数据
     */
    private fun register() {

        RxBus.observe<BaseBean>()
            .subscribe { t ->
                    when (t.messageType) {
                        MessageType.UPDATE_SONGS -> {
                            viewModel.getSongsList()
                        }
                    }
            }.registerInBus(this)
    }

    override fun onDestroy() {
        super.onDestroy()
        RxBus.unRegister(this)
    }
}