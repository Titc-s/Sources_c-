package org.fattili.luckymusic.ui.widget

import android.content.Context
import android.util.AttributeSet
import android.util.Log
import android.view.View
import android.view.ViewGroup
import org.fattili.luckymusic.util.ArrayUtil.toString
import kotlin.math.cos
import kotlin.math.sin

/**
 * 2020/10/28
 * @author dengzhenli
 * 椭圆布局
 */
class OvalLayout : ViewGroup {
    constructor(context: Context?) : super(context) {}
    constructor(context: Context?, attrs: AttributeSet?) : super(context, attrs) {}

    constructor(context: Context?, attrs: AttributeSet?, defStyleAttr: Int)
            : super(context, attrs, defStyleAttr) {}

    override fun onMeasure(widthMeasureSpec: Int, heightMeasureSpec: Int) {
        super.onMeasure(widthMeasureSpec, heightMeasureSpec)
        measureChildren(widthMeasureSpec, heightMeasureSpec)
        val widthMode = MeasureSpec.getMode(widthMeasureSpec)
        val width = MeasureSpec.getSize(widthMeasureSpec)
        val heightMode = MeasureSpec.getMode(heightMeasureSpec)
        val height = MeasureSpec.getSize(heightMeasureSpec)
        if (widthMode == MeasureSpec.AT_MOST && heightMode == MeasureSpec.AT_MOST) {
            val groupWidth = maxWidth
            val groupHeight = totalHeight
            setMeasuredDimension(groupWidth, groupHeight)
        } else if (widthMode == MeasureSpec.AT_MOST) {
            setMeasuredDimension(maxWidth, height)
        } else if (heightMode == MeasureSpec.AT_MOST) {
            setMeasuredDimension(width, totalHeight)
        }
    }

    override fun onLayout(changed: Boolean, left: Int, top: Int, right: Int, bottom: Int) {
        val childCount = childCount
        Log.d(TAG, "onLayout: $childCount")
        for (i in 0 until childCount) {
            val childView = getChildAt(i)
            val l = getLocation(i, childCount, childView, left, top, right, bottom)
            Log.d(TAG, "onLayout: " + toString(l))
            childView.layout(l[0], l[1], l[2], l[3])
        }
    }

    var pointX = 0
    var pointY = 0
    private var pWidth = 100
    private var pHeight = 100
    private var startC = 270
    private var endC = 360
    private fun getLocation(index: Int, n: Int, view: View,
                            left: Int, top: Int, right: Int, bottom: Int): IntArray {
        val w = view.width
        val h = view.height
        val angle = getAngle(index, n)
        Log.d(TAG, "getAngle: $angle")
        val xy = getOval(pWidth, pHeight, angle)
        Log.d(TAG, "getOval: " + toString(xy))

        val x = left + xy[0]
        val y = bottom - xy[1]
        val l = x - w / 2
        val r = x + w / 2
        val t = y - h / 2
        val b = y + h / 2
        return intArrayOf(l, t, r, b)
    }

    private fun getAngle(index: Int, n: Int): Int {
        val cT = (endC - startC) / n
        return startC + index * cT + cT / 2
    }

    /**
     * https://www.mathopenref.com/coordparamellipse.html
     *
     * @param a
     * @param b
     * @param t
     * @return
     */
    private fun getOval(a: Int, b: Int, t: Int): IntArray {
        val x: Int = (a * cos(t.toDouble())).toInt()
        val y: Int = (b * sin(t.toDouble())).toInt()
        return intArrayOf(x, y)
    }

    private val maxWidth: Int
        private get() {
            val count = childCount
            var maxWidth = 0
            for (i in 0 until count) {
                val currentWidth = getChildAt(i).measuredWidth
                if (maxWidth < currentWidth) {
                    maxWidth = currentWidth
                }
            }
            return maxWidth
        }

    private val totalHeight: Int
        private get() {
            val count = childCount
            var totalHeight = 0
            for (i in 0 until count) {
                totalHeight += getChildAt(i).measuredHeight
            }
            return totalHeight
        }

    companion object {
        private const val TAG = "Vgtest"
    }
}