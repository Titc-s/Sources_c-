package org.fattili.luckymusic.ui.view.main


import android.view.View
import android.widget.CompoundButton
import android.widget.RadioButton
import androidx.viewpager.widget.ViewPager
import kotlinx.android.synthetic.main.lm_main_activity_main.*
import kotlinx.android.synthetic.main.lm_main_layout_toolbar.*
import org.fattili.luckymusic.MainApp
import org.fattili.luckymusic.R
import org.fattili.luckymusic.ui.adapter.SectionsPagerAdapter
import org.fattili.luckymusic.ui.base.BaseActivity
import org.fattili.luckymusic.ui.view.common.CommonDialog
import org.fattili.luckymusic.ui.view.main.setting.SettingFragment
import org.fattili.luckymusic.ui.view.main.song.SongsListFragment

/**
 * 2020/10/28
 * @author dengzhenli
 * 主页面
 */
class MainActivity : BaseActivity(), CompoundButton.OnCheckedChangeListener {

    /**
     * 默认加载页面
     */
    private val defaultPageIndex = 0

    private lateinit var mTitles: Array<String>
    private var radioButtons: MutableList<RadioButton> = arrayListOf()

    override val layoutId: Int
        get() = R.layout.lm_main_activity_main

    override fun initView() {
        initToolBar()
        initViewPager()
    }

    override fun initData() {
    }

    // 工具栏
    private fun initToolBar() {
        setSupportActionBar(lm_main_toolbar)

        mTitles = resources.getStringArray(R.array.lm_main_titles)
        lm_main_tb_play_list_rg.setOnCheckedChangeListener(this)
        lm_main_tb_music_rg.setOnCheckedChangeListener(this)
        lm_main_tb_settings_rg.setOnCheckedChangeListener(this)
        radioButtons.add(lm_main_tb_music_rg)
        radioButtons.add(lm_main_tb_play_list_rg)
        radioButtons.add(lm_main_tb_settings_rg)

        radioButtons[defaultPageIndex].isChecked = (true)

    }

    private fun initViewPager(){
        val adapter = SectionsPagerAdapter(this, supportFragmentManager,
            arrayOf(
                HomeFragment.newInstance(),
                SongsListFragment.newInstance(),
                SettingFragment.newInstance()
            )
        )

        lm_main_view_pager.adapter = (adapter)

        lm_main_view_pager.addOnPageChangeListener(object : ViewPager.OnPageChangeListener {
            override fun onPageScrollStateChanged(state: Int) {}
            override fun onPageScrolled(position: Int, positionOffset: Float, positionOffsetPixels: Int) {}
            override fun onPageSelected(position: Int) { radioButtons[position].isChecked = (true) }
        })

    }

    override fun onCheckedChanged(button: CompoundButton?, isChecked: Boolean) {
        if (isChecked) {
            onItemChecked(radioButtons.indexOf(button))
        }
    }

    private fun onItemChecked(position: Int) {
        lm_main_view_pager.currentItem = (position)
        lm_main_toolbar.title = (mTitles[position])
    }

    override fun onBackPressed() {
        CommonDialog
            .Builder(this)
            .setMessage(getString(R.string.lm_main_exit_app_remind))
            .setPositiveButton(null, View.OnClickListener {
                finish()
                MainApp.instance.onExit()
            })
            .setNegativeButton(null,null)
            .show()
    }
}