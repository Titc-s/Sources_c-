package org.fattili.file_select

import android.view.*
import android.widget.AdapterView.OnItemClickListener
import org.fattili.file_select.util.AndroidUtils
import org.fattili.file_select.util.FileUtils
import java.io.File

class ChooseFile : BaseChooseFile() {


    interface OnChooseFileBack {
        fun onChooseBack(path: String?, type: String?)
    }

    var chooseFileBack: OnChooseFileBack? = null


    override fun initView(inflater: LayoutInflater) {
        contentView = inflater.inflate(R.layout.file_select_popup_choose_file, null)
        back = contentView?.findViewById(R.id.file_select_back)
        rootPath = contentView?.findViewById(R.id.file_select_root_path)
        listView = contentView?.findViewById(R.id.file_select_file_list)
        exit = contentView?.findViewById(R.id.file_select_exit)
        noFile = contentView?.findViewById(R.id.file_select_no_file)
        back?.setOnClickListener(click)
        exit?.setOnClickListener(click)
        listView?.onItemClickListener = listClick
    }


    private val click =
        View.OnClickListener { v ->
            if (!AndroidUtils.isFastDoubleClick(100.toLong())) {
                val id = v.id
                if (id == R.id.file_select_back) {
                    goBack()
                } else if (id == R.id.file_select_exit) {
                    miss()
                }
            }
        }

    private val listClick = OnItemClickListener { parent, view, position, id ->
        val clickPath = resourceList[position].path
        val file = File(clickPath)
        if (file.isDirectory) {
            if (clickPath != null) {
                toPath(clickPath)
            }
        } else {
            if (chooseFileBack != null) {
                if (chooseExit) {
                    miss()
                }
                chooseFileBack?.onChooseBack(
                    clickPath,
                    FileUtils.pathGetType(resourceList[position].path)
                )
            }
        }
    }


}