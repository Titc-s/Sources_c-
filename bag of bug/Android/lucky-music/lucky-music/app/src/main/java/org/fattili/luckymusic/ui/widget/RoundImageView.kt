package org.fattili.luckymusic.ui.widget

import android.content.Context
import android.graphics.Canvas
import android.graphics.Path
import android.os.Build
import android.util.AttributeSet
import android.view.View
import androidx.appcompat.widget.AppCompatImageView

/**
 * 2020/11/10
 * 椭圆ImageView
 * @author dengzhenli
 */
class RoundImageView(context: Context, attrs: AttributeSet?, defStyleAttr: Int) : AppCompatImageView(context, attrs, defStyleAttr) {
    var width = 0f
    var height = 0f

    constructor(context: Context) : this(context, null) {
        init(context, null)
    }

    constructor(
        context: Context,
        attrs: AttributeSet?
    ) : this(context, attrs, 0) {
        init(context, attrs)
    }

    private fun init(
        context: Context,
        attrs: AttributeSet?
    ) {
        if (Build.VERSION.SDK_INT < 18) {
            setLayerType(View.LAYER_TYPE_SOFTWARE, null)
        }
    }

    override fun onLayout(
        changed: Boolean,
        left: Int,
        top: Int,
        right: Int,
        bottom: Int
    ) {
        super.onLayout(changed, left, top, right, bottom)
        width = getWidth().toFloat()
        height = getHeight().toFloat()
    }

    override fun onDraw(canvas: Canvas) {
        if (width >= 12 && height > 12) {
            val path = Path()
            //四个圆角
            path.moveTo(12f, 0f)
            path.lineTo(width - 12, 0f)
            path.quadTo(width, 0f, width, 12f)
            path.lineTo(width, height - 12)
            path.quadTo(width, height, width - 12, height)
            path.lineTo(12f, height)
            path.quadTo(0f, height, 0f, height - 12)
            path.lineTo(0f, 12f)
            path.quadTo(0f, 0f, 12f, 0f)
            canvas.clipPath(path)
        }
        super.onDraw(canvas)
    }

    init {
        init(context, attrs)
    }
}