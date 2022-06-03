package org.fattili.luckymusic.ui.view.main.song.edit

import android.content.Context
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import androidx.databinding.DataBindingUtil
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.ViewModelStore
import kotlinx.android.synthetic.main.lm_common_title.*
import kotlinx.android.synthetic.main.lm_song_activity_song_edit.*
import kotlinx.android.synthetic.main.lm_song_activity_song_list.*
import org.fattili.file_select.ChooseFileMultiple
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.base.BaseBean
import org.fattili.luckymusic.data.constant.MessageType
import org.fattili.luckymusic.data.model.play.Song
import org.fattili.luckymusic.databinding.LmSongActivitySongEditBinding
import org.fattili.luckymusic.databinding.LmSongActivitySongListBinding
import org.fattili.luckymusic.ui.adapter.SongListAdapter
import org.fattili.luckymusic.ui.base.BaseActivity
import org.fattili.luckymusic.ui.view.main.song.SongListViewModel
import org.fattili.luckymusic.util.InjectorUtil
import org.fattili.luckymusic.util.RxBus

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌曲编辑
 */
class SongEditActivity : BaseActivity() {
    override val layoutId: Int = R.layout.lm_song_activity_song_edit
    override val openBind = true

    private val binding by lazy {
        DataBindingUtil.setContentView<LmSongActivitySongEditBinding>(
            this,
            layoutId
        )
    }

    private val viewModel by lazy {
        ViewModelProvider(
            ViewModelStore(),
            InjectorUtil.getSongEditModelFactory()
        ).get(SongEditViewModel::class.java)
    }

    override fun initView() {
        supportActionBar?.hide()
        binding?.viewModel = viewModel
    }

    override fun initData() {
        viewModel.songId = intent.getLongExtra("songId",0)
        viewModel.init()
        setTitleName(viewModel.getTitle())
    }


    override fun onDestroy() {
        super.onDestroy()
        viewModel.save()
        RxBus.send(BaseBean(MessageType.UPDATE_SONG))
    }

    companion object{
        fun actionStart(context: Context, songId:Long){
            val intent = Intent(context,SongEditActivity::class.java)
            intent.putExtra("songId",songId)
            context.startActivity(intent)
        }
    }

}