package org.fattili.luckymusic.data.db

import org.fattili.luckymusic.data.model.play.PlaySong
import org.litepal.LitePal

/**
 * 2020/10/28
 * @author dengzhenli
 * 播放队列
 */
class PlaySongDao {

    /**
     * 获取列表
     */
    fun getSongList(): MutableList<PlaySong> {
        return LitePal.findAll(PlaySong::class.java)
    }

    fun saveSongList(songList: List<PlaySong>) {
        LitePal.saveAll(songList)
    }

    fun getSong(target: String): PlaySong? {
        val list = LitePal.where("target=? ", target)
            .find(PlaySong::class.java)
        if (list.isEmpty()) {
            return null
        }
        return list[0]
    }

}