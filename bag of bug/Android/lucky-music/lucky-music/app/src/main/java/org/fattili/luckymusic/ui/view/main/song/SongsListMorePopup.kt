package org.fattili.luckymusic.ui.view.main.song

import android.app.Activity
import android.view.View
import android.widget.ImageView
import android.widget.LinearLayout
import org.fattili.easypopup.view.EasyPop
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.constant.ConstantParam
import org.fattili.luckymusic.ui.view.common.CommonDialog

/**
 * 歌单操作
 */
class SongsListMorePopup(private val songsId: Long, activity: Activity, view: View) :
    EasyPop(activity, view) {

    var back: ImageView? = null
    var playLayout: LinearLayout? = null
    var deleteLayout: LinearLayout? = null
    var editLayout: LinearLayout? = null
    var prePlayLayout: LinearLayout? = null

    interface PopCallBack {
        fun play();
        fun delete();
        fun prePlay();
        fun edit();
    }

    var callback: PopCallBack? = null

    override fun getLayoutId(): Int {
        return R.layout.lm_song_popup_songs_list_more
    }

    override fun initData() {
    }

    override fun initView(view: View?) {
        back = view?.findViewById(R.id.lm_song_songs_list_more_back_iv)
        playLayout = view?.findViewById(R.id.lm_song_songs_list_more_play_ll)
        deleteLayout = view?.findViewById(R.id.lm_song_songs_list_more_delete_ll)
        editLayout = view?.findViewById(R.id.lm_song_songs_list_more_edit_ll)
        prePlayLayout = view?.findViewById(R.id.lm_song_songs_list_more_pre_play_ll)

        if (songsId in arrayListOf(ConstantParam.SONGS_ID_LOCAL, ConstantParam.SONGS_ID_MARK)) {
            deleteLayout?.visibility = View.GONE
            editLayout?.visibility = View.GONE
        }

        back?.setOnClickListener { finish() }
        playLayout?.setOnClickListener { play() }
        deleteLayout?.setOnClickListener { delete() }
        editLayout?.setOnClickListener { edit() }
        prePlayLayout?.setOnClickListener { prePlay() }
    }

    override fun outClickable(): Boolean {
        return false
    }


    private fun play() {
        finish()
        CommonDialog.Builder(context)
            .setMessage(context?.getString(R.string.lm_song_songs_operate_play_measure_message))
            .setNegativeButton(null, null)
            .setPositiveButton(null, View.OnClickListener {
                callback?.play()
            })
            .show()
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

}