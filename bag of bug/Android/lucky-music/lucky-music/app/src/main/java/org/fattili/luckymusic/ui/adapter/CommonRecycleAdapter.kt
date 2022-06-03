package org.fattili.luckymusic.ui.adapter

import androidx.recyclerview.widget.RecyclerView

/**
 * 2020/10/28
 * @author dengzhenli
 * 通用recycle 的适配器
 */
abstract class CommonRecycleAdapter<VH : RecyclerView.ViewHolder?, T>(protected var list: MutableList<T>) :
    RecyclerView.Adapter<VH>() {


    override fun getItemCount(): Int {
        return list.size
    }

    var clickListener: ((Int) -> Unit)? = null

    //在指定位置插入，原位置的向后移动一格
    fun addItem(position: Int, data: T): Boolean {
        if (position < list.size && position >= 0) {
            list.add(position, data)
            notifyItemInserted(position)
            return true
        }
        return false
    }

    //去除指定位置的子项
    fun removeItem(position: Int): Boolean {
        if (position < list.size && position >= 0) {
            list.removeAt(position)
            notifyItemRemoved(position)
            return true
        }
        return false
    }

    //清空显示数据
    fun clearAll() {
        list.clear()
        notifyDataSetChanged()
    }

    fun update(list: MutableList<T>) {
        this.list = list
        notifyDataSetChanged()
    }

    fun update() {
        notifyDataSetChanged()
    }

     open fun getItem(position: Int): T {
        return list[position]
    }
}