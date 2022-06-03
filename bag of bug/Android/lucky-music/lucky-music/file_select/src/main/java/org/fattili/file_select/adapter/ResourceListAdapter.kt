package org.fattili.file_select.adapter

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.BaseAdapter
import android.widget.CheckBox
import android.widget.ImageView
import android.widget.TextView
import com.bumptech.glide.Glide
import org.fattili.file_select.R
import org.fattili.file_select.entity.ResourceListBean
import org.fattili.file_select.util.AndroidUtils
import org.fattili.file_select.util.FileUtils
import java.io.File
import java.util.*

class ResourceListAdapter(
    val context: Context,
    private var resourceList: ArrayList<ResourceListBean>,
    private var showCheckBox: Boolean = false
) : BaseAdapter() {

    private val mInflater: LayoutInflater = LayoutInflater.from(context)

    var choosePosition = 0
        set(position) {
            field = position
            notifyDataSetChanged()
        }


    fun upData(resourceList: ArrayList<ResourceListBean>) {
        this.resourceList = resourceList
        notifyDataSetChanged()
    }

    override fun getCount(): Int {
        return resourceList.size
    }

    override fun getItem(position: Int): Any {
        return resourceList[position]
    }

    override fun getItemId(position: Int): Long {
        return position.toLong()
    }

    override fun getView(position: Int, convertView: View?, parent: ViewGroup?): View {
        var view = convertView
        var holder: ViewHolder? = null
        if (view == null) {
            view = mInflater.inflate(R.layout.file_select_item_resource, parent, false) //加载布局
            holder = ViewHolder()
            holder.checkBox = view.findViewById(R.id.file_select_item_resource_checkBox)
            holder.path = view.findViewById(R.id.file_select_item_resource_path)
            holder.time = view.findViewById(R.id.file_select_item_resource_time)
            holder.image = view.findViewById(R.id.file_select_item_resource_image)
            view.tag = holder
        } else {
            holder = view.tag as ViewHolder
        }
        holder.checkBox?.isChecked = resourceList[position].isSelect
        holder.path?.text = FileUtils.pathGetName(resourceList[position].path)
        holder.time?.text =
            resourceList[position].time + "   " + resourceList[position].fileNumber
        if (!showCheckBox) {
            holder.checkBox?.visibility = View.GONE
        }
        val file = File(resourceList[position].path)
        if (file.isDirectory) {
            holder.image?.setImageResource(R.drawable.file_select_file)
            holder.checkBox?.visibility = View.GONE
        } else {
            holder.checkBox?.visibility = View.VISIBLE
            when (FileUtils.pathGetType(resourceList[position].path).toLowerCase()) {
                "mp3" -> holder.image?.setImageResource(R.drawable.file_select_music)
                "txt" -> holder.image?.setImageResource(R.drawable.file_select_txt)
                "zip" -> holder.image?.setImageResource(R.drawable.file_select_zip)
                "mp4","avi" -> holder.image?.setImageResource(R.drawable.file_select_video)
                "jpg", "png", "gif", "jpeg" -> Glide.with(context)
                    .load(resourceList[position].path)
                    .error(R.drawable.file_select_image)
                    .into(holder.image!!)
                "apk" -> holder.image?.setImageResource(R.drawable.file_select_apk)
                else -> holder.image?.setImageResource(R.drawable.file_select_unknown)
            }
        }
        return view!!
    }

    private inner class ViewHolder {
        var path: TextView? = null
        var time: TextView? = null
        var image: ImageView? = null
        var checkBox: CheckBox? = null
    }



}