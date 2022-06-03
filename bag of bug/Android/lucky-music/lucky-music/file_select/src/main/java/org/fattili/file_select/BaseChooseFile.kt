package org.fattili.file_select

import android.app.Activity
import android.content.Context
import android.os.Environment
import android.view.*
import android.widget.*
import org.fattili.file_select.adapter.ResourceListAdapter
import org.fattili.file_select.entity.ResourceListBean
import org.fattili.file_select.util.AndroidUtils
import org.fattili.file_select.util.FileUtils
import java.io.File
import java.text.SimpleDateFormat
import java.util.*

abstract class BaseChooseFile {
    private var pWindow: PopupWindow? = null
    private var window: Window? = null
    private val pathString = ArrayList<String?>()

    var context: Context? = null
    //选择完后回调是否关闭弹窗，如果不关闭，可以手动调用miss()关闭
    var chooseExit = true

    var resourceListAdapter: ResourceListAdapter? = null
    var resourceList = ArrayList<ResourceListBean>()


    var contentView: View? = null
    var back: ImageView? = null
    var rootPath: TextView? = null
    var listView: ListView? = null
    var exit: Button? = null
    var noFile: LinearLayout? = null

    var whiteList: List<String>? = null


    fun miss() {
        if (pWindow != null && pWindow?.isShowing == true) {
            pWindow?.dismiss()
        }
    }

    val isShowing: Boolean
        get() = pWindow != null && pWindow?.isShowing == true

    fun popupChoose(
        activity: Activity,
        v: View?,
        window: Window?,
        inflater: LayoutInflater,
        chooseExit: Boolean
    ) {
        AndroidUtils.checkPermission(activity)
        context = activity
        this.window = window
        this.chooseExit = chooseExit
        if (pWindow != null && pWindow?.isShowing == true) {
            miss()
        } else {
            initView(inflater)
            initData()
            pWindow = PopupWindow(contentView, -1, -1)
            pWindow?.animationStyle = R.style.file_select_pop_animation
            pWindow?.inputMethodMode = PopupWindow.INPUT_METHOD_NEEDED
            pWindow?.softInputMode = WindowManager.LayoutParams.SOFT_INPUT_ADJUST_RESIZE
            pWindow?.isClippingEnabled = true
            backgroundAlpha(0.5f)
            pWindow?.showAtLocation(v, Gravity.TOP, 0, 0)
            pWindow?.setOnDismissListener { backgroundAlpha(1.0f) }
        }
    }


    fun backgroundAlpha(bgAlpha: Float) {
        val lp = window?.attributes
        lp?.alpha = bgAlpha // 0.0-1.0
        window?.attributes = lp
    }

    open fun initData() {
        if (context == null) return
        pathString.clear()
//        val nowPath = context?.getExternalFilesDir(null)?.absolutePath
        val nowPath =
            Environment.getExternalStorageDirectory().absolutePath
        pathString.add(nowPath)
        rootPath?.text = nowPath
        resourceList.clear()
        resourceListAdapter = ResourceListAdapter(context!!, resourceList)
        listView?.adapter = resourceListAdapter
        upListAdapter()
    }

    open fun upListAdapter() {
        resourceList.clear()
        val l = pathString.size
        if (l < 1) {
            return
        }
        rootPath?.text = pathString[l - 1]
        val directory = File(pathString[l - 1])
        val files = directory.listFiles()
        if (files != null) {
            if (files.isEmpty()) {
                noFile?.visibility = View.VISIBLE
            } else {
                noFile?.visibility = View.GONE
            }
            var resourceListBean: ResourceListBean
            for (file2 in files) {
                resourceListBean = ResourceListBean()
                resourceListBean.path = file2.path
                val time = Date(file2.lastModified())
                val formatter = SimpleDateFormat("yyyy-MM-dd HH:mm")
                resourceListBean.time = formatter.format(time)
                if (file2.isDirectory) {
                    val fileNumber = file2.listFiles()
                    if (fileNumber != null) {
                        resourceListBean.fileNumber = fileNumber.size.toString() + "项"
                    } else {
                        resourceListBean.fileNumber = 0.toString() + "项"
                    }
                    resourceList.add(resourceListBean)
                } else {
                    val type = FileUtils.pathGetType(file2.path)
                    resourceListBean.fileNumber = type + "文件"
                    if (whiteList != null) {
                        if (FileUtils.filter(type, whiteList)) {
                            resourceList.add(resourceListBean)
                        }
                    } else {
                        resourceList.add(resourceListBean)
                    }
                }
            }
        }
        resourceListAdapter?.notifyDataSetChanged()
    }

    abstract fun initView(inflater: LayoutInflater)

    //上一目录
    fun goBack() {
        if (pathString.size > 1) {
            pathString.removeAt(pathString.size - 1)
        }
        upListAdapter()
    }

    fun toPath(clickPath: String) {
        pathString.add(clickPath)
        rootPath?.text = clickPath
        upListAdapter()
    }
}