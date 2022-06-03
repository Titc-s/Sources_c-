
package org.fattili.luckymusic.ui.view.main.song.edit

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.launch
import org.fattili.luckymusic.data.SongRepository
import org.fattili.luckymusic.data.SongsRepository
import org.fattili.luckymusic.data.model.play.Song
import org.fattili.luckymusic.data.model.play.Songs
import org.fattili.luckymusic.ui.base.BaseViewModel
import org.fattili.luckymusic.util.Logger

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌单编辑
 */
class SongsEditViewModel(private val repository: SongsRepository) : BaseViewModel() {
    var songsId = 0L

    var songs: Songs? = null

    override fun init() {
        songs = getSongs(songsId)
        Logger.d("init:${songsId}")
    }
    fun getTitle(): String {
        return songs?.name ?: ""
    }

    fun save() {
        songs?.let { repository.edit(it) }
    }
    fun getSongs(songsId: Long): Songs? {
        return repository.getSongs(songsId)
    }
}