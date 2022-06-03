package org.fattili.luckymusic.ui.view.main.play

import android.app.Activity
import android.view.View
import android.widget.Button
import android.widget.ImageView
import android.widget.LinearLayout
import android.widget.ListView
import org.fattili.easypopup.view.EasyPop
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.base.BaseBean
import org.fattili.luckymusic.data.constant.MessageType
import org.fattili.luckymusic.data.model.play.PlaySong
import org.fattili.luckymusic.player.PlayManager
import org.fattili.luckymusic.ui.adapter.PlayListAdapter
import org.fattili.luckymusic.util.RxBus
import org.fattili.luckymusic.util.registerInBus

/**
 * 播放列表
 */
class PlayListPopup : EasyPop {

    constructor(activity: Activity) : super(activity) {}

    var back: ImageView? = null
    var listView: ListView? = null
    var exit: Button? = null
    var noItem: LinearLayout? = null

    var adapter: PlayListAdapter? = null
    var list: List<PlaySong>? = null


    override fun getLayoutId(): Int {
        return R.layout.lm_play_popup_list
    }

    override fun initView(view: View?) {
        back = view?.findViewById(R.id.lm_play_list_back_iv)
        listView = view?.findViewById(R.id.lm_play_list_lv)
        exit = view?.findViewById(R.id.lm_play_list_exit_bt)
        noItem = view?.findViewById(R.id.lm_play_list_empty_ll)
        back?.setOnClickListener { finish() }
        exit?.setOnClickListener { finish() }
        list = PlayManager.getInstance().playList
        adapter = context?.let {
            list?.let { playlist ->
                if (playlist.isNotEmpty()) {
                    noItem?.visibility = View.GONE
                }
                PlayListAdapter(it, playlist)
            } ?: PlayListAdapter(it, arrayListOf())
        }

        listView?.adapter = adapter
        listView?.setOnItemClickListener { _, _, position, _ ->
            PlayManager.getInstance().goto(position)
            finish()
        }
        adapter?.setDeleteListener { pos ->
            PlayManager.getInstance().remove(pos)
            adapter?.upData()
        }
        register()
    }

    override fun initData() {

    }

    override fun onPopDismiss() {
        super.onPopDismiss()
        RxBus.unRegister(this)
    }

    override fun outClickable(): Boolean {
        return false
    }

    private fun register() {
        RxBus.observe<BaseBean>()
            .subscribe { t ->
                when (t.messageType) {
                    MessageType.CHANGE_PLAY_SONGS -> {
                        adapter?.upData()
                    }
                }
            }.registerInBus(this)
    }

}