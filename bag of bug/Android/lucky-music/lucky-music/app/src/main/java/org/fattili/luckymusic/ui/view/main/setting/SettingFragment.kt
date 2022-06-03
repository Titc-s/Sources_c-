package org.fattili.luckymusic.ui.view.main.setting

import android.content.Intent
import androidx.recyclerview.widget.LinearLayoutManager
import kotlinx.android.synthetic.main.lm_main_fragment_setting.*
import org.fattili.luckymusic.R
import org.fattili.luckymusic.ui.adapter.SettingListAdapter
import org.fattili.luckymusic.ui.base.BaseFragment

/**
 * 2020/10/28
 * @author dengzhenli
 * 设置
 */
class SettingFragment : BaseFragment() {
    override val layoutId: Int
        get() = R.layout.lm_main_fragment_setting


    override fun initView() {
        val moreList = arrayOf(getString(R.string.lm_setting_find_song), getString(R.string.lm_setting_about))
        val itemAdapter = SettingListAdapter(moreList.toList())
        lm_main_setting_list.layoutManager = LinearLayoutManager(context)
        lm_main_setting_list.adapter = itemAdapter

        itemAdapter.clickListener = {
            when (it) {
                0 -> startActivity(Intent(context, FindSongActivity::class.java))
                1 -> startActivity(Intent(context, AboutActivity::class.java))
            }
        }
    }

    override fun initData() {
    }


    companion object {
        fun newInstance(): SettingFragment {
            return SettingFragment()
        }
    }
}