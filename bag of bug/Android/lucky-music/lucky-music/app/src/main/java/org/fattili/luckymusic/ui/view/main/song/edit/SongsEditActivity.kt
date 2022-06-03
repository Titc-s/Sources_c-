package org.fattili.luckymusic.ui.view.main.song.edit

import android.content.Context
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.databinding.DataBindingUtil
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.ViewModelStore
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.base.BaseBean
import org.fattili.luckymusic.data.constant.MessageType
import org.fattili.luckymusic.databinding.LmSongActivitySongListBinding
import org.fattili.luckymusic.databinding.LmSongActivitySongsEditBinding
import org.fattili.luckymusic.ui.base.BaseActivity
import org.fattili.luckymusic.ui.view.main.song.SongListViewModel
import org.fattili.luckymusic.util.InjectorUtil
import org.fattili.luckymusic.util.RxBus

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌单编辑
 */
class SongsEditActivity : BaseActivity() {
    override val layoutId: Int = R.layout.lm_song_activity_songs_edit
    override val openBind = true

    var songsId = 0L

    private val binding by lazy {
        DataBindingUtil.setContentView<LmSongActivitySongsEditBinding>(
            this,
            layoutId
        )
    }

    private val viewModel by lazy {
        ViewModelProvider(
            ViewModelStore(),
            InjectorUtil.getSongsEditModelFactory()
        ).get(SongsEditViewModel::class.java)
    }

    override fun initView() {
        supportActionBar?.hide()
        binding?.viewModel = viewModel

    }

    override fun initData() {
        viewModel.songsId = intent.getLongExtra("songsId",0)
        viewModel.init()
        setTitleName(viewModel.getTitle())
    }

    override fun onDestroy() {
        super.onDestroy()
        viewModel.save()
        RxBus.send(BaseBean(MessageType.UPDATE_SONGS))
    }
    companion object{
        fun actionStart(context:Context, songsId:Long){
            val intent = Intent(context,SongsEditActivity::class.java)
            intent.putExtra("songsId",songsId)
            context.startActivity(intent)
        }
    }

}