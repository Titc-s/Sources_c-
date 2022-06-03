package org.fattili.luckymusic.util

import org.fattili.luckymusic.data.SongRepository
import org.fattili.luckymusic.data.SongsRepository
import org.fattili.luckymusic.data.db.LuckyMusicDatabase
import org.fattili.luckymusic.ui.view.main.play.PlayModelFactory
import org.fattili.luckymusic.ui.view.main.setting.FindSongModelFactory
import org.fattili.luckymusic.ui.view.main.song.SongListModelFactory
import org.fattili.luckymusic.ui.view.main.song.SongsListModelFactory
import org.fattili.luckymusic.ui.view.main.song.edit.SongEditModelFactory
import org.fattili.luckymusic.ui.view.main.song.edit.SongsEditModelFactory

/**
 * 2020/10/28
 * @author dengzhenli
 *
 */
object InjectorUtil {

    private fun getSongRepository() = SongRepository.getInstance(LuckyMusicDatabase.getSongDao())
    private fun getSongsRepository() = SongsRepository.getInstance(LuckyMusicDatabase.getSongsDao())

    fun getSongsModelFactory() = SongsListModelFactory(getSongsRepository(), getSongRepository())
    fun getSongModelFactory() = SongListModelFactory(getSongRepository(), getSongsRepository())
    fun getPlayModelFactory() = PlayModelFactory(getSongRepository(), getSongsRepository())
    fun getFindSongModelFactory() = FindSongModelFactory(getSongRepository())

    fun getSongEditModelFactory() = SongEditModelFactory(getSongRepository())
    fun getSongsEditModelFactory() = SongsEditModelFactory(getSongsRepository())

}