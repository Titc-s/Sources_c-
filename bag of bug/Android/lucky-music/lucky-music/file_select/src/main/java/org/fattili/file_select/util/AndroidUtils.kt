package org.fattili.file_select.util

import android.Manifest
import android.app.Activity
import android.content.pm.PackageManager
import android.widget.Toast
import androidx.core.app.ActivityCompat

/**
 * 事件点击工具类，设置事件点击的响应时间间隔
 */
object AndroidUtils {
    private var lastClickTime: Long = 0

    fun isFastDoubleClick(diff: Long): Boolean {
        val time = System.currentTimeMillis()
        val timeD = time - lastClickTime
        if (lastClickTime > 0 && timeD < diff) {
            return true
        }
        lastClickTime = time
        return false
    }

    private const val REQUEST_WRITE_EXTERNAL_STORAGE = 0

    fun checkPermission(activity: Activity) {
        //检查权限（NEED_PERMISSION）是否被授权 PackageManager.PERMISSION_GRANTED表示同意授权
        if (ActivityCompat.checkSelfPermission(
                activity,
                Manifest.permission.WRITE_EXTERNAL_STORAGE
            )
            != PackageManager.PERMISSION_GRANTED
        ) {
            //用户已经拒绝过一次，再次弹出权限申请对话框需要给用户一个解释
            if (ActivityCompat.shouldShowRequestPermissionRationale(
                    activity,
                    Manifest.permission.WRITE_EXTERNAL_STORAGE
                )
            ) {
                Toast.makeText(activity, "请开通相关权限，否则无法正常使用本应用！", Toast.LENGTH_SHORT).show()
            }
            //申请权限
            ActivityCompat.requestPermissions(
                activity,
                arrayOf(Manifest.permission.WRITE_EXTERNAL_STORAGE),
                REQUEST_WRITE_EXTERNAL_STORAGE
            )
        } else {
        }
    }

}