package org.fattili.luckymusic.ui.view.main.song

import android.app.Activity
import android.view.View
import android.widget.ImageView
import android.widget.LinearLayout
import org.fattili.easypopup.view.EasyPop
import org.fattili.luckymusic.R
import org.fattili.luckymusic.ui.view.common.CommonDialog

/**
 * 歌曲操作
 */
class SongListMorePopup : EasyPop {

    constructor(activity: Activity) : super(activity) {}

    var back: ImageView? = null
    var deleteLayout: LinearLayout? = null
    var editLayout: LinearLayout? = null
    var prePlayLayout: LinearLayout? = null
    var addToSongsLayout: LinearLayout? = null

    interface PopCallBack {
        fun delete()
        fun prePlay()
        fun edit()
        fun addToSongs()
    }

    var callback: PopCallBack? = null

    override fun getLayoutId(): Int {
        return R.layout.lm_song_popup_song_list_more
    }

    override fun initData() {
    }

    override fun initView(view: View?) {
        back = view?.findViewById(R.id.lm_song_song_list_more_back_iv)
        deleteLayout = view?.findViewById(R.id.lm_song_song_list_more_delete_ll)
        editLayout = view?.findViewById(R.id.lm_song_song_list_more_edit_ll)
        prePlayLayout = view?.findViewById(R.id.lm_song_song_list_more_pre_play_ll)
        addToSongsLayout = view?.findViewById(R.id.lm_song_song_list_more_add_to_songs_ll)

        back?.setOnClickListener { finish() }
        deleteLayout?.setOnClickListener { delete() }
        editLayout?.setOnClickListener { edit() }
        prePlayLayout?.setOnClickListener { prePlay() }
        addToSongsLayout?.setOnClickListener { addToSongs() }
    }

    override fun outClickable(): Boolean {
        return false
    }



    private fun delete() {
        finish()
        CommonDialog.Builder(context)
            .setMessage(context?.getString(R.string.lm_song_songs_operate_delete_measure_message))
            .setNegativeButton(null, null)
            .setPositiveButton(null, View.OnClickListener {
                callback?.delete()
            })
            .show()
    }

    private fun edit() {
        finish()
        callback?.edit()
    }

    private fun prePlay() {
        finish()
        callback?.prePlay()
    }
    private fun addToSongs() {
        finish()
        callback?.addToSongs()
    }

}