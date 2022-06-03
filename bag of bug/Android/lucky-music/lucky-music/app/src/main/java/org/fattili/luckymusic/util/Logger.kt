package org.fattili.luckymusic.util

import android.util.Log

/**
 * 2020/10/28
 * @author dengzhenli
 */
object Logger {
        private const val TAG = "lmusic"

        private var DEBUG_ON = true

        fun d(msg: String?) {
            if (DEBUG_ON) {
                if (msg != null) {
                    Log.d(TAG, msg)
                }
            }
        }

        fun e(msg: String?) {
            if (DEBUG_ON) {
                if (msg != null) {
                    Log.e(TAG, msg)
                }
            }
        }

        fun e(e: Throwable?) {
            e("", e)
        }

        fun e(msg: String?, e: Throwable?) {
            if (DEBUG_ON) {
                Log.e(TAG, msg, e)
            }
        }
}