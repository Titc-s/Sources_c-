package org.fattili.luckymusic.data.db

/**
 * 2020/10/28
 * @author dengzhenli
 * 数据库管理
 */
object LuckyMusicDatabase {

    private var songDao: SongDao? = null

    private var songsDao: SongsDao? = null

    private var playSongDao: PlaySongDao? = null

    fun getSongsDao(): SongsDao {
        if (songsDao == null) {
            songsDao = SongsDao()
        }
        return songsDao as SongsDao
    }

    fun getSongDao(): SongDao {
        if (songDao == null) {
            songDao = SongDao()
        }
        return songDao!!
    }

    fun getPlaySongDao(): PlaySongDao {
        if (playSongDao == null) {
            playSongDao = PlaySongDao()
        }
        return playSongDao!!
    }

}