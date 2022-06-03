package org.fattili.file_select


import android.view.*
import android.widget.*
import android.widget.AdapterView.OnItemClickListener
import org.fattili.file_select.util.AndroidUtils
import java.io.File
import java.util.*

class ChooseFileMultiple : BaseChooseFile() {


    private val paths = ArrayList<String?>()
    var yesText: TextView? = null

    interface OnChooseFileBack {
        fun onChooseBack(paths: ArrayList<String?>?)
    }

    var chooseFileBack: OnChooseFileBack? = null
    override fun initView(inflater: LayoutInflater) {
        contentView = inflater.inflate(R.layout.file_select_popup_choose_file_multiple, null)
        back = contentView?.findViewById(R.id.file_select_back)
        rootPath = contentView?.findViewById(R.id.file_select_root_path)
        listView = contentView?.findViewById(R.id.file_select_file_list)
        exit = contentView?.findViewById(R.id.file_select_exit)
        yesText = contentView?.findViewById(R.id.file_select_file_yes)
        noFile = contentView?.findViewById(R.id.file_select_no_file)

        back?.setOnClickListener(click)
        exit?.setOnClickListener(click)

        yesText?.setOnClickListener(click)
        listView?.onItemClickListener = listClick
    }

    override fun initData() {
        paths.clear()
        super.initData()
    }

    override fun upListAdapter() {
        paths.clear()
        super.upListAdapter()
        yesText?.text = "确认(" + paths.size + ")"
    }


    private val click =
        View.OnClickListener { v ->
            if (!AndroidUtils.isFastDoubleClick(100L)) {
                val id = v.id
                if (id == R.id.file_select_back) { //上一目录
                    goBack()
                } else if (id == R.id.file_select_exit) {
                    miss()
                } else if (id == R.id.file_select_file_yes) {
                    if (paths.size > 0) {
                        miss()
                        if (chooseFileBack != null) {
                            chooseFileBack?.onChooseBack(paths)
                        }
                    } else {
                        Toast.makeText(context, "还未选择文件", Toast.LENGTH_SHORT).show()
                    }
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
            if (resourceList[position].isSelect) {
                paths.remove(resourceList[position].path)
                resourceList[position].isSelect = false
                resourceListAdapter?.notifyDataSetChanged()
            } else {
                paths.add(resourceList[position].path)
                resourceList[position].isSelect = true
                resourceListAdapter?.notifyDataSetChanged()
            }
        }
        yesText?.text = "确认(" + paths.size + ")"
    }

}