package org.fattili.luckymusic.ui.view.main.song.add

import android.app.Activity
import android.view.View
import android.widget.ImageView
import android.widget.ListView
import org.fattili.easypopup.view.EasyPop
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.model.play.Songs
import org.fattili.luckymusic.ui.adapter.AddToSongsListAdapter

/**
 * 添加到歌单
 */
class AddToSongsPopup(var list: MutableList<Songs>, activity: Activity) : EasyPop(activity) {

    var back: ImageView? = null
    private var listview: ListView? = null
    var adapter: AddToSongsListAdapter? = null

    interface PopCallBack {
        fun choice(pos: Int, songs: Songs)
    }

    var callback: PopCallBack? = null

    override fun getLayoutId(): Int {
        return R.layout.lm_song_popup_song_add_to_songs
    }

    override fun initData() {
    }

    override fun initView(view: View?) {
        back = view?.findViewById(R.id.lm_song_song_add_to_songs_back_iv)
        listview = view?.findViewById(R.id.lm_song_song_add_to_songs_lv)
        back?.setOnClickListener { finish() }

        adapter = context?.let { AddToSongsListAdapter(it, list) }
        listview?.adapter = adapter

        listview?.setOnItemClickListener { _, _, position, _ ->
            finish()
            callback?.choice(position, list[position])
        }
    }

    override fun outClickable(): Boolean {
        return false
    }

}