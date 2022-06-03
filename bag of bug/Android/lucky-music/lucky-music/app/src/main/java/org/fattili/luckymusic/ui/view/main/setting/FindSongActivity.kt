package org.fattili.luckymusic.ui.view.main.setting

import androidx.databinding.DataBindingUtil
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.ViewModelStore
import org.fattili.luckymusic.R
import org.fattili.luckymusic.databinding.LmSettingActivityFindSongBinding
import org.fattili.luckymusic.ui.base.BaseActivity
import org.fattili.luckymusic.util.InjectorUtil

/**
 * 2020/10/28
 * @author dengzhenli
 * 扫描歌曲
 */
class FindSongActivity : BaseActivity() {

    override val layoutId: Int = R.layout.lm_setting_activity_find_song
    override val openBind = true

    private val binding by lazy { DataBindingUtil.setContentView<LmSettingActivityFindSongBinding>(this, layoutId) }
    private val viewModel by lazy {
        ViewModelProvider(ViewModelStore(), InjectorUtil.getFindSongModelFactory()).get(FindSongViewModel::class.java)
    }

    override fun initView() {
        supportActionBar?.hide()
        binding.viewModel = viewModel
        setTitleName(getString(R.string.lm_setting_find_song))
    }

    override fun initData() {
        viewModel.findFile()
    }
}