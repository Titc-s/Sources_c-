package org.fattili.luckymusic.ui.view.main.song.add

import android.content.Context
import kotlinx.android.synthetic.main.lm_song_dialog_add_songs.*
import org.fattili.luckymusic.R
import org.fattili.luckymusic.ui.base.BaseDialog

/**
 * 2020/10/28
 * @author dengzhenli
 * 添加歌单
 */
class AddSongsDialog(context: Context) : BaseDialog(context, R.style.lm_dialog_base) {

    override val layoutId = R.layout.lm_song_dialog_add_songs

    interface DialogResult {
        fun addResult(name: String);
    }

    lateinit var dialogResult: DialogResult


    override fun initView() {

        lm_common_dialog_candle_bt?.setOnClickListener { dismiss() }
        lm_common_dialog_measure_bt?.setOnClickListener {
            val name = lm_song_songs_add_name_et?.text.toString()
            if (name.isNotEmpty())
                dialogResult.addResult(name)
            else
                showMsg("输入为空")
        }
    }


}