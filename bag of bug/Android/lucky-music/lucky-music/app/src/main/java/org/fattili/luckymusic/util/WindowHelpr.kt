package org.fattili.luckymusic.util

import android.app.Activity
import android.content.Context
import android.content.res.Configuration
import android.view.View

/**
 * 2020/10/28
 * @author dengzhenli
 */
object WindowHelpr {
    /**
     * 获取状态栏高度
     */
    fun getStatusBarHeight(context: Context): Int {
        val resourceId = context.resources.getIdentifier("status_bar_height", "dimen", "android")
        return if (resourceId > 0) { context.resources.getDimensionPixelSize(resourceId) } else -1
    }

    /**
     * 判断屏幕是否改变
     *
     * @param act
     * @return
     */
    fun isScreenChange(act: Activity): Boolean {
        val mConfiguration = act.resources.configuration //获取设置的配置信息
        val ori = mConfiguration.orientation //获取屏幕方向
        return ori == Configuration.ORIENTATION_LANDSCAPE
    }

    /**
     * 获取view的宽高
     *
     * @param view
     * @return
     */
    fun unDisplayViewSize(view: View): IntArray {
        val size = IntArray(2)
        val width = View.MeasureSpec.makeMeasureSpec(0, View.MeasureSpec.UNSPECIFIED)
        val height = View.MeasureSpec.makeMeasureSpec(0, View.MeasureSpec.UNSPECIFIED)
        view.measure(width, height)
        size[0] = view.measuredWidth
        size[1] = view.measuredHeight
        return size
    }
}