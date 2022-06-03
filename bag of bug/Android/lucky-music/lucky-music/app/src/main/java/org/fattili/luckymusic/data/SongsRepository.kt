package org.fattili.luckymusic.data

import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import org.fattili.luckymusic.MainApp
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.constant.ConstantParam
import org.fattili.luckymusic.data.db.SongsDao
import org.fattili.luckymusic.data.model.play.Song
import org.fattili.luckymusic.data.model.play.Songs

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌单数据
 */
class SongsRepository private constructor(private val songsDao: SongsDao) {

    suspend fun getSongsList() = withContext(Dispatchers.IO) {
        var list = songsDao.getSongsList()
        if (list.isEmpty()) {
            // 保存系统歌单
            list.add(Songs(ConstantParam.SONGS_ID_LOCAL, MainApp.context.getString(R.string.lm_songs_list_local), ConstantParam.SONGS_TYPE_LOCAL))
            list.add(Songs(ConstantParam.SONGS_ID_MARK, MainApp.context.getString(R.string.lm_songs_list_mark), ConstantParam.SONGS_TYPE_MARK))
            songsDao.saveSongsList(list)
        }
        list
    }

    fun getLocalSongsList():MutableList<Songs> {
        return songsDao.getSongsList()

    }

    fun addSongs(songs: Songs) :Boolean {
        return songsDao.addSongs(songs)
    }

    fun getSongs(songsId: Long) :Songs? {
        return songsDao.getSongs(songsId)
    }

    fun edit(songs: Songs): Boolean {
        return songsDao.update(songs)
    }
    fun delete(songsId: Long) :Int {
        return songsDao.delete(songsId)
    }

    companion object {
        private var instance: SongsRepository? = null
        fun getInstance(playDao: SongsDao): SongsRepository {
            if (instance == null) {
                synchronized(SongsRepository::class.java) {
                    if (instance == null) {
                        instance = SongsRepository(playDao)
                    }
                }
            }
            return instance!!
        }
    }

}