package org.fattili.luckymusic.ui.base

import androidx.lifecycle.ViewModel

/**
 * 2020/10/28
 * @author dengzhenli
 */
abstract class BaseViewModel : ViewModel() {
    /**
     * 初始化
     */
    abstract fun init()
}