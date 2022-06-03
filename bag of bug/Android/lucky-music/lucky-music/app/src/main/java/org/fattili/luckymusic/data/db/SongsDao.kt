package org.fattili.luckymusic.data.db

import org.fattili.luckymusic.data.model.play.Songs
import org.litepal.LitePal

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌单
 */
class SongsDao {

    fun getSongsList(): MutableList<Songs> = LitePal.findAll(Songs::class.java)

    fun saveSongsList(songsList: List<Songs>?) {
        if (songsList != null && songsList.isNotEmpty()) {
            LitePal.saveAll(songsList)
        }
    }

    fun getSongs(songsId: Long): Songs? {
        return LitePal.find(Songs::class.java, songsId)
    }

    fun addSongs(songs: Songs): Boolean {
        return songs.save()
    }

    fun update(songs: Songs): Boolean {
        return songs.update(songs.id) > 0
    }

    fun delete(id: Long): Int {
        return LitePal.find(Songs::class.java, id).delete()
    }


}