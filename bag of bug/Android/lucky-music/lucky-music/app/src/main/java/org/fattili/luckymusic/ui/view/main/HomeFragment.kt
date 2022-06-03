package org.fattili.luckymusic.ui.view.main

import kotlinx.android.synthetic.main.lm_main_fragment_home.*
import org.fattili.luckymusic.R
import org.fattili.luckymusic.ui.adapter.SectionsPagerAdapter
import org.fattili.luckymusic.ui.base.BaseFragment
import org.fattili.luckymusic.ui.view.main.play.LyricFragment
import org.fattili.luckymusic.ui.view.main.play.PlayFragment

/**
 * 2020/10/28
 * @author dengzhenli
 * 首页
 */
class HomeFragment : BaseFragment() {

    override val layoutId: Int
        get() = R.layout.lm_main_fragment_home

    override fun initView() {

        lm_main_home_view_pager?.adapter = SectionsPagerAdapter(
            context, childFragmentManager,
            arrayOf(
                PlayFragment.newInstance(), //播放页
                LyricFragment.newInstance(0) //歌词
            )
        )
    }

    override fun initData() {
    }

    companion object {
        fun newInstance(): HomeFragment {
            return HomeFragment()
        }
    }
}