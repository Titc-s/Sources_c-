package org.fattili.luckymusic.util

import android.widget.Toast
import org.fattili.luckymusic.MainApp

/**
 * create by dengzhenli 2020/11/5
 *
 */
object ToastUtil {
    fun show(msg: String) {
        Toast.makeText(MainApp.context, msg, Toast.LENGTH_SHORT).show()
    }
}