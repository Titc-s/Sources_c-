package org.fattili.luckymusic.data.model.play

import org.litepal.annotation.Column
import org.litepal.crud.LitePalSupport

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌曲
 */
class Song : LitePalSupport {

    var id: Long = 0


    var songs_id: Long = 0

    /**
     * 名称
     */
    @Column(nullable = false)
    var name: String

    /**
     * 标题
     */
    @Column(nullable = false)
    var title: String

    /**
     * 专辑
     */
    var album: String

    /**
     * 作者
     */
    var artist: String

    /**
     * 路径
     */
    @Column(nullable = false)
    var path: String

    /**
     * 歌曲标记，目前都是本地歌曲，用路径标记
     */
    @Column(nullable = false)
    var target: String

    var duration: Int = 0


    constructor() : this(0,0, "", "",0, "", "","","") {}

    constructor(
        songs_id: Long,
        name: String,
        title: String,
        path: String
    ) : this(0,songs_id, name, path,0, path,title,"","") {
    }

    constructor(
        id: Long,
        songs_id: Long,
        name: String,
        target: String,
        duration: Int,
        path: String,
        title: String,
        artist: String,
        album: String
    ) {
        this.id = id
        this.songs_id = songs_id
        this.name = name
        this.title = title
        this.target = target
        this.album = album
        this.artist = artist
        this.duration = duration
        this.path = path
    }

    fun clone(cloneId: Boolean): Song {
        val newId = if (cloneId) id else 0
        return Song(newId, songs_id, name, target, duration, path, title, artist, album)
    }

    fun castSongPlay(): PlaySong {
        return PlaySong(name, target, duration, path, title, artist, album, id, songs_id)
    }

    companion object {
        fun cast(playSongs: List<PlaySong>): List<Song> {
            var list = arrayListOf<Song>()
            for (song in playSongs) {
                list.add(song.castSong())
            }
            return list
        }
    }
}