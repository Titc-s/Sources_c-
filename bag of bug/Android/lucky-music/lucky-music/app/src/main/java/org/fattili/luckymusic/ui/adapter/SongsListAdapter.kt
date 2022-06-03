package org.fattili.luckymusic.ui.adapter

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.constant.ConstantParam
import org.fattili.luckymusic.data.model.play.Songs
/**
 * 2020/10/28
 * @author dengzhenli
 * 歌单列表适配器
 */
class SongsListAdapter(list: List<Songs?>?) :
    CommonRecycleAdapter<SongsListAdapter.ViewHolder?, Songs?>(list as MutableList<Songs?>) {

    private lateinit var moreListener: (Int) -> Unit

    fun setMoreClickListener(listener: (Int) -> Unit) {
        this.moreListener = listener
    }

    private var context: Context? = null

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        context = parent.context
        return ViewHolder(
            LayoutInflater.from(context).inflate(R.layout.lm_song_item_songs_list, parent, false)
        )
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        //设置textView显示内容为list里的对应项
        holder.textView.text = list[position]?.name
        //子项的点击事件监听
        holder.itemView.setOnClickListener { clickListener?.invoke(position) }
        holder.moreImage.setOnClickListener { moreListener.invoke(position) }
        holder.label.setImageResource(
            when (list[position]?.id) {
                ConstantParam.SONGS_ID_LOCAL -> R.drawable.lm_song_ic_songs_local
                ConstantParam.SONGS_ID_MARK -> R.drawable.lm_song_ic_songs_mark
                else -> R.drawable.lm_song_ic_songs_list
            }
        )
    }

    //这里定义的是子项的类，不要在这里直接对获取对象进行操作
    inner class ViewHolder(itemView: View) :
        RecyclerView.ViewHolder(itemView) {
        var textView: TextView = itemView.findViewById(R.id.lm_song_item_songs_list_name_tv)
        var moreImage: ImageView = itemView.findViewById(R.id.lm_song_item_songs_list_more_iv)
        var label: ImageView = itemView.findViewById(R.id.lm_song_item_songs_list_label_iv)
    }

}