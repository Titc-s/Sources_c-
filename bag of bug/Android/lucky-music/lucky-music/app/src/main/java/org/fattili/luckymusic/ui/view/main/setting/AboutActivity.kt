package org.fattili.luckymusic.ui.view.main.setting

import org.fattili.luckymusic.R
import org.fattili.luckymusic.ui.base.BaseActivity

/**
 * 2020/10/28
 * @author dengzhenli
 * 关于
 */
class AboutActivity : BaseActivity() {

    override val layoutId: Int = R.layout.lm_setting_activity_about

    override fun initView() {
        supportActionBar?.hide()
        setTitleName(getString(R.string.lm_setting_about))
    }

    override fun initData() {
    }
}