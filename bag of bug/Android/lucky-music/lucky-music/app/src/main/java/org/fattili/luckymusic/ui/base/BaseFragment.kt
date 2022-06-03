package org.fattili.luckymusic.ui.base

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Toast
import androidx.fragment.app.Fragment
import org.fattili.luckymusic.MainApp

/**
 * 2020/10/28
 * @author dengzhenli
 */
abstract class BaseFragment : Fragment() {

    abstract val layoutId: Int

    lateinit var mView: View

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        super.onCreateView(inflater, container, savedInstanceState)
        mView = inflater.inflate(layoutId, container, false)
        return mView
    }

    fun showMsg(msg: String) {
        Toast.makeText(
            MainApp.context,
            msg,
            Toast.LENGTH_SHORT
        ).show()
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        initView()
        initData()
    }

    abstract fun initView()

    abstract fun initData()
}
