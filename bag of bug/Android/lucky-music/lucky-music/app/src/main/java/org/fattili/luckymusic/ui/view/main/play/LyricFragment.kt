package org.fattili.luckymusic.ui.view.main.play

import android.os.Bundle
import androidx.lifecycle.ViewModelProvider
import org.fattili.luckymusic.R
import org.fattili.luckymusic.ui.base.BaseFragment

/**
 * 2020/10/28
 * @author dengzhenli
 *
 */
class LyricFragment : BaseFragment() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        pageViewModel = ViewModelProvider(this).get(PageViewModel::class.java)
        var index = 1
        arguments?.let { index = it.getInt(ARG_SECTION_NUMBER) }

        pageViewModel?.setIndex(index)
    }

    override val layoutId: Int
        get() = R.layout.lm_play_fragment_lyric

    override fun initView() {
//        val textView = mView.findViewById<TextView>(R.id.section_label)
//        pageViewModel.text.observe(this, Observer { s ->
//            if (textView != null) {
//                textView.text = s
//            }
//        })
    }

    override fun initData() {
    }

    private var pageViewModel: PageViewModel? = null


    companion object {
        private const val ARG_SECTION_NUMBER = "section_number"
        fun newInstance(index: Int): LyricFragment {
            val fragment = LyricFragment()
            val bundle = Bundle()
            bundle.putInt(ARG_SECTION_NUMBER, index)
            fragment.arguments = bundle
            return fragment
        }
    }
}