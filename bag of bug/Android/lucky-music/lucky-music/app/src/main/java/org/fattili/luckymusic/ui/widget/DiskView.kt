package org.fattili.luckymusic.ui.widget

import android.content.Context
import android.graphics.*
import android.graphics.drawable.BitmapDrawable
import android.util.AttributeSet
import android.view.View
import org.fattili.luckymusic.R

/**
 * 仿网易云音乐留声机（唱片机）View
 */
class DiskView(context: Context, attrs: AttributeSet? = null) : View(context, attrs) {
    /**
     * 尺寸计算设计说明：
     * 1、唱片有两个主要尺寸：中间图片的半径、黑色圆环的宽度。
     * 黑色圆环的宽度 = 图片半径的一半。
     * 2、唱针分为“手臂”和“头”，手臂分两段，一段长的一段短的，头也是一段长的一段短的。
     * 唱针四个部分的尺寸求和 = 唱片中间图片的半径+黑色圆环的宽度
     * 唱针各部分长度 比例——长的手臂：短的手臂：长的头：短的头 = 8:4:2:1
     * 3、唱片黑色圆环顶部到唱针顶端的距离 = 唱针长的手臂的长度。
     */
    private var halfMeasureWidth = 0
    /**
     * 获取图片半径
     * @return 图片半径
     */
    /**
     * 设置图片半径
     * @param pictureRadius 图片半径
     */
    private var pictureRadius: Int// 中间图片的半径
    private val ringWidth: Int // 黑色圆环宽度
    /**
     * 获取唱片旋转速度
     * @return 唱片旋转速度
     */
    /**
     * 设置唱片旋转速度
     * @param diskRotateSpeed 旋转速度
     */
    var diskRotateSpeed: Float// 唱片旋转速度
    private val discPaint: Paint// 唱片画笔
    private val clipPath: Path// 裁剪图片的路径
    private var bitmap: Bitmap? = null// 图片
    private val srcRect: Rect// 图片被裁减范围
    private val dstRect: Rect// 图片被绘制范围
    private val smallCircleRadius = 20 // 唱针顶部小圆半径
    private val bigCircleRadius: Int// 唱针顶部大圆半径
    private val longArmLength: Int// 唱针手臂，较长那段的长度
    private val shortArmLength: Int// 唱针手臂，较短那段的长度
    private val longHeadLength: Int// 唱针的头，较长那段的长度
    private val shortHeadLength: Int// 唱针的头，较短那段的长度
    private val needlePaint: Paint // 唱针画笔

    // 状态控制相关变量
    var playing: Boolean = false
        set(value) {
            field = value
            invalidate()
        }
    private var needleDegreeCounter: Int// 唱针旋转角度计数器
    private var diskDegreeCounter: Float// 唱片旋转角度计数器

    /**
     * 根据加载的图片资源尺寸和设置的唱片中间图片直径，
     * 为canvas.drawBitmap()方法设置源Rect和目标Rect，
     * 以宽度为例，假设图片资源宽度为width，唱片中间图片直径为diameter
     * 如果width <= diameter，则截取宽度为整张图片宽度。
     * 如果width > diameter，则截取宽度为图片资源横向中间长度为diameter的区域。
     * 高度的截取方法与宽度相同。
     * @param src 源矩形
     * @param dst 目标矩形
     */
    private fun setBitmapRect(src: Rect, dst: Rect) {
        src[0, 0, bitmap?.width ?: 0] = bitmap?.height ?: 0
        dst[-pictureRadius, -pictureRadius, pictureRadius] = pictureRadius
    }

    override fun onMeasure(widthMeasureSpec: Int, heightMeasureSpec: Int) {
        super.onMeasure(widthMeasureSpec, heightMeasureSpec)
        /**
         * wrap_content属性下View的宽高设计：
         * 宽度：等于唱片直径，即图片半径+圆环宽度求和再乘以2。
         * 高度：等于唱片直径+唱针较长的手臂
         */
        val width = (pictureRadius + ringWidth) * 2
        val height = (pictureRadius + ringWidth) * 2 + longArmLength
        val measuredWidth = resolveSize(width, widthMeasureSpec)
        val measuredHeight = resolveSize(height, heightMeasureSpec)
        setMeasuredDimension(measuredWidth, measuredHeight)
    }

    override fun onDraw(canvas: Canvas) {
        super.onDraw(canvas)
        halfMeasureWidth = measuredWidth shr 1
        drawDisk(canvas)
        drawNeedle(canvas)
        if (needleDegreeCounter > PAUSE_DEGREE) {
            invalidate()
        }
    }

    // 绘制唱片（胶片）
    private fun drawDisk(canvas: Canvas) {
        diskDegreeCounter = diskDegreeCounter% 360//diskDegreeCounter % 360 + diskRotateSpeed
        drawDisk(canvas, diskDegreeCounter)
    }

    // 绘制旋转了制定角度的唱片
    private fun drawDisk(canvas: Canvas, degree: Float) {
        // 绘制圆环，注意理解平移的圆心距离和圆环半径是怎么计算的
        canvas.save()
        canvas.translate(halfMeasureWidth.toFloat(),
            pictureRadius + ringWidth + longArmLength.toFloat()
        )
        canvas.rotate(degree)
        canvas.drawCircle(0f, 0f, pictureRadius + ringWidth / 2.toFloat(), discPaint)
        // 绘制图片
        canvas.clipPath(clipPath)
        bitmap?.let { canvas.drawBitmap(it, srcRect, dstRect, discPaint) }
        canvas.restore()
    }

    // 绘制唱针
    private fun drawNeedle(canvas: Canvas) {
        // 由于PLAY_DEGREE和PAUSE_DEGREE之间的差值是30，所以每次增/减值应当是30的约数即可
        if (playing) {
            if (needleDegreeCounter < PLAY_DEGREE) {
                needleDegreeCounter += 3
            }
        } else {
            if (needleDegreeCounter > PAUSE_DEGREE) {
                needleDegreeCounter -= 3
            }
        }
        drawNeedle(canvas, needleDegreeCounter)
    }

    // 绘制旋转了指定角度的唱针
    private fun drawNeedle(canvas: Canvas, degree: Int) {
        // 移动坐标到水平中点
        canvas.save()
        canvas.translate(halfMeasureWidth.toFloat(), 0f)
        // 绘制唱针手臂
        needlePaint.strokeWidth = 20f
        needlePaint.color = Color.parseColor("#C0C0C0")
        // 绘制第一段臂
        canvas.rotate(degree.toFloat())
        canvas.drawLine(0f, 0f, 0f, longArmLength.toFloat(), needlePaint)
        // 绘制第二段臂
        canvas.translate(0f, longArmLength.toFloat())
        canvas.rotate(-30f)
        canvas.drawLine(0f, 0f, 0f, shortArmLength.toFloat(), needlePaint)
        // 绘制唱针头
        // 绘制第一段唱针头
        canvas.translate(0f, shortArmLength.toFloat())
        needlePaint.strokeWidth = 40f
        canvas.drawLine(0f, 0f, 0f, longHeadLength.toFloat(), needlePaint)
        // 绘制第二段唱针头
        canvas.translate(0f, longHeadLength.toFloat())
        needlePaint.strokeWidth = 60f
        canvas.drawLine(0f, 0f, 0f, shortHeadLength.toFloat(), needlePaint)
        canvas.restore()

        // 两个重叠的圆形
        canvas.save()
        canvas.translate(halfMeasureWidth.toFloat(), 0f)
        needlePaint.style = Paint.Style.FILL
        needlePaint.color = Color.parseColor("#C0C0C0")
        canvas.drawCircle(0f, 0f, bigCircleRadius.toFloat(), needlePaint)
        needlePaint.color = Color.parseColor("#8A8A8A")
        canvas.drawCircle(0f, 0f, smallCircleRadius.toFloat(), needlePaint)
        canvas.restore()
    }



    /**
     * 设置图片资源id
     * @param resId 图片资源id
     */
    fun setPictureRes(resId: Int) {
        bitmap = BitmapFactory.decodeResource(context.resources, resId)
        setBitmapRect(srcRect, dstRect)
        invalidate()
    }

    fun setBitmapByte(bytes: ByteArray) {
        bitmap = BitmapFactory.decodeByteArray(bytes, 0, bytes.size)
        setBitmapRect(srcRect, dstRect)
        invalidate()
    }

    companion object {
        // 绘制唱片相关变量
        // 中间图片默认半径
        private const val DEFAULT_PICTURE_RADIUS = 400

        // 唱片旋转默认速度，其实是通过每次旋转叠加的角度来控制速度
        private const val DEFAULT_DISK_ROTATE_SPEED = 0f

        // 绘制唱针相关变量
        private const val PLAY_DEGREE = -15 // 播放状态时唱针的旋转角度
        private const val PAUSE_DEGREE = -45 // 暂停状态时唱针的旋转角度
    }

    init {

        // 读取xml文件属性
        val typedArray =
            context.obtainStyledAttributes(attrs, R.styleable.lm_gramophone_view)
        pictureRadius = typedArray.getDimension(
            R.styleable.lm_gramophone_view_picture_radius,
            DEFAULT_PICTURE_RADIUS.toFloat()
        ).toInt()
        diskRotateSpeed = typedArray.getFloat(
            R.styleable.lm_gramophone_view_disk_rotate_speed,
            DEFAULT_DISK_ROTATE_SPEED
        )
        val drawable = typedArray.getDrawable(R.styleable.lm_gramophone_view_src)
        bitmap = if (drawable == null) {
            BitmapFactory.decodeResource(getContext().resources, R.mipmap.lm_play_default_picture)
        } else { (drawable as BitmapDrawable).bitmap }
        typedArray.recycle()

        // 初始化唱片变量
        ringWidth = pictureRadius shr 1
        discPaint = Paint()
        discPaint.color = Color.BLACK
        discPaint.style = Paint.Style.STROKE
        discPaint.strokeWidth = ringWidth.toFloat()
        srcRect = Rect()
        dstRect = Rect()
        setBitmapRect(srcRect, dstRect)
        clipPath = Path()
        clipPath.addCircle(0f, 0f, pictureRadius.toFloat(), Path.Direction.CW)
        diskDegreeCounter = 0f

        // 初始化唱针变量
        bigCircleRadius = smallCircleRadius shl 1
        shortHeadLength = (pictureRadius + ringWidth) / 15
        longHeadLength = shortHeadLength shl 1
        shortArmLength = longHeadLength shl 1
        longArmLength = shortArmLength shl 1
        needlePaint = Paint()
        needleDegreeCounter = PAUSE_DEGREE
    }
}