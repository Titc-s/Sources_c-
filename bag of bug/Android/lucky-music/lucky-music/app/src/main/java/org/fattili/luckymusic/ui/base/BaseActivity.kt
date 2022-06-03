package org.fattili.luckymusic.ui.base

import android.os.Bundle
import android.widget.ImageButton
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import org.fattili.luckymusic.MainApp
import org.fattili.luckymusic.R

/**
 * 2020/10/28
 * @author dengzhenli
 */
abstract class BaseActivity: AppCompatActivity(){

    abstract val layoutId: Int

    open val openBind = false

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        if (!openBind){
            setContentView(layoutId)
        }
        initView()
        initTitle()
        initData()
    }

    abstract fun initView()

    abstract fun initData()

    fun setTitleName(title: String) {
        findViewById<TextView>(R.id.lm_common_title_tv)?.text = title
    }

    fun showMsg(msg: String) {
        Toast.makeText(
            MainApp.context,
            msg,
            Toast.LENGTH_SHORT
        ).show()
    }

    private fun initTitle(){
        findViewById<ImageButton>(R.id.lm_common_title_back_bt)?.setOnClickListener {
            finish()
        }
    }
}
