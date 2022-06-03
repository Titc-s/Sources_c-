package org.fattili.luckymusic.ui.view.common

import android.content.Context
import android.view.View
import android.widget.Button
import android.widget.TextView
import org.fattili.luckymusic.R
import org.fattili.luckymusic.ui.base.BaseDialog

/**
 * 2020/10/28
 * @author dengzhenli
 * 通用弹窗
 */
class CommonDialog(context: Context) : BaseDialog(context, R.style.lm_dialog_base) {
    override val layoutId: Int
        get() = R.layout.lm_common_dialog

    private var titleTv: TextView? = null
    private var messageTv: TextView? = null
    private var measureBt: Button? = null
    private var candleBt: Button? = null

    override fun initView() {
        titleTv = view?.findViewById(R.id.lm_common_dialog_title_tv)
        messageTv = view?.findViewById(R.id.lm_common_dialog_message_tv)
        measureBt = view?.findViewById(R.id.lm_common_dialog_measure_bt)
        candleBt = view?.findViewById(R.id.lm_common_dialog_candle_bt)

    }

    class Builder(context: Context) {
        var commonDialog: CommonDialog? = null
        fun setTitle(title: String?): Builder {
            commonDialog?.titleTv?.text = title
            return this
        }

        fun setMessage(message: String?): Builder {
            commonDialog?.messageTv?.text = message
            return this
        }

        fun setPositiveButton(text: CharSequence?, listener: View.OnClickListener?): Builder {
            text?.let { commonDialog?.measureBt?.text = it }
            val onClickListener =
                View.OnClickListener { v ->
                    listener?.onClick(v)
                    commonDialog?.dismiss()
                }
            commonDialog?.measureBt?.setOnClickListener(onClickListener)
            return this
        }

        fun setNegativeButton(text: CharSequence?, listener: View.OnClickListener?): Builder {
            text?.let { commonDialog?.candleBt?.text = it }
            val onClickListener =
                View.OnClickListener { v ->
                    listener?.onClick(v)
                    commonDialog?.dismiss()
                }
            commonDialog?.candleBt?.setOnClickListener(onClickListener)
            return this
        }

        fun show() {
            commonDialog?.show()
        }

        init {
            if (commonDialog == null) {
                commonDialog = CommonDialog(context)
                commonDialog?.init()
            }
        }
    }
}