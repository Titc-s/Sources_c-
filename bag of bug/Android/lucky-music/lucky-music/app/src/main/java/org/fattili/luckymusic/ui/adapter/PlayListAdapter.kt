package org.fattili.luckymusic.ui.adapter

import android.content.Context
import android.media.MediaMetadataRetriever
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.BaseAdapter
import android.widget.ImageView
import android.widget.TextView
import com.bumptech.glide.Glide
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.model.play.PlaySong
import org.fattili.luckymusic.player.PlayManager
import org.fattili.luckymusic.ui.widget.RoundImageView
import org.fattili.luckymusic.util.SongUtil

/**
 * 播放列表适配器
 */
class PlayListAdapter(val context: Context, private var songList: List<PlaySong>) : BaseAdapter() {

    private val mInflater: LayoutInflater = LayoutInflater.from(context)


    private lateinit var deleteListener: (Int) -> Unit

    fun setDeleteListener(listener: (Int) -> Unit) {
        this.deleteListener = listener
    }

    fun upData(songList: List<PlaySong>) {
        this.songList = songList
        notifyDataSetChanged()
    }

    fun upData() {
        notifyDataSetChanged()
    }

    override fun getCount(): Int {
        return songList.size
    }

    override fun getItem(position: Int): Any {
        return songList[position]
    }

    override fun getItemId(position: Int): Long {
        return position.toLong()
    }

    override fun getView(position: Int, convertView: View?, parent: ViewGroup?): View {
        var view = convertView
        var holder: ViewHolder?
        if (view == null) {
            view = mInflater.inflate(R.layout.lm_play_item_playlist, parent, false) //加载布局
            holder = ViewHolder()
            holder.singer = view.findViewById(R.id.lm_play_item_playlist_singer_tv)
            holder.name = view.findViewById(R.id.lm_play_item_playlist_name_tv)
            holder.image = view.findViewById(R.id.lm_play_item_playlist_iv)
            holder.deleteImage = view.findViewById(R.id.lm_play_item_playlist_delete_iv)
            holder.playImage = view.findViewById(R.id.lm_play_item_playlist_playing_iv)
            view.tag = holder
        } else {
            holder = view.tag as ViewHolder
        }

        holder.image?.let {
            Glide.with(context)
                .load(SongUtil.getImage(MediaMetadataRetriever(), songList[position].path))
                .error(R.mipmap.lm_dog)
                .into(it)
        }
        holder.playImage?.visibility =
            if (PlayManager.getInstance().getCurrentIndex() == position) View.VISIBLE
            else View.INVISIBLE

        holder.name?.text = songList[position].title
        holder.singer?.text = songList[position].artist
        holder.deleteImage?.setOnClickListener { deleteListener.invoke(position) }
        return view as View
    }

    private inner class ViewHolder {
        var singer: TextView? = null
        var name: TextView? = null
        var image: RoundImageView? = null
        var deleteImage: ImageView? = null
        var playImage: ImageView? = null
    }



}