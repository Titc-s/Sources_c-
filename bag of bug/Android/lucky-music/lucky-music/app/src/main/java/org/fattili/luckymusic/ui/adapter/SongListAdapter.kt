package org.fattili.luckymusic.ui.adapter

import android.content.Context
import android.media.MediaMetadataRetriever
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.model.play.Song
import org.fattili.luckymusic.ui.widget.RoundImageView
import org.fattili.luckymusic.util.SongUtil

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌曲列表适配器
 */
class SongListAdapter(list: List<Song?>?) :
    CommonRecycleAdapter<SongListAdapter.ViewHolder?, Song?>(list as MutableList<Song?>) {
    private var context: Context? = null
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        context = parent.context
        return ViewHolder(
            LayoutInflater.from(context).inflate(R.layout.lm_song_item_song_list, parent, false)
        )
    }
    private lateinit var moreListener: (Int) -> Unit

    fun setMoreClickListener(listener: (Int) -> Unit) {
        this.moreListener = listener
    }
    private lateinit var playListener: (Int) -> Unit

    fun setPlayClickListener(listener: (Int) -> Unit) {
        this.playListener = listener
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {

        list[position]?.let {
            var artist = ""
            if (it.artist.isNotEmpty()) {
                artist = list[position]?.artist.toString()
            }
            if (it.album.isNotEmpty()) {
                if (artist.isNotEmpty()) artist += " - "
                artist += list[position]?.album.toString()
            }

            holder.artistTv.text = artist
            holder.nameTv.text = it.title

            holder.itemView.setOnClickListener { clickListener?.invoke(position) }
            holder.moreBt.setOnClickListener { moreListener.invoke(position) }
            holder.playBt.setOnClickListener { playListener.invoke(position) }
            holder.playBt.setImageResource(
                if (SongUtil.checkIsPlay(list[position]) == true) R.drawable.lm_common_ic_pause_24
                else R.drawable.lm_common_ic_play_24)

            context?.let { it1 ->
                Glide.with(it1)
                    .load(SongUtil.getImage(MediaMetadataRetriever(), it.path))
                    .error(R.mipmap.lm_dog)
                    .into(holder.image)
            }
        }

    }

    inner class ViewHolder(itemView: View) :
        RecyclerView.ViewHolder(itemView) {
        var nameTv: TextView = itemView.findViewById(R.id.lm_song_item_song_list_name_tv)
        var artistTv: TextView = itemView.findViewById(R.id.lm_song_item_song_list_artist_tv)
        var image: RoundImageView = itemView.findViewById(R.id.lm_song_item_song_list_avatar_iv)
        var moreBt: ImageView = itemView.findViewById(R.id.lm_song_item_song_list_more_bt)
        var playBt: ImageView = itemView.findViewById(R.id.lm_song_item_song_list_play_bt)
    }
}