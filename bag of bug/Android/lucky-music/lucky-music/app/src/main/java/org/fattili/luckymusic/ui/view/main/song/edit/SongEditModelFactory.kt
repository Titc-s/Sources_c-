package org.fattili.luckymusic.ui.view.main.song.edit

import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import org.fattili.luckymusic.data.SongRepository
import org.fattili.luckymusic.data.SongsRepository

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌曲编辑
 */
class SongEditModelFactory(
    private val repository: SongRepository
) : ViewModelProvider.NewInstanceFactory() {

    @Suppress("UNCHECKED_CAST")
    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return SongEditViewModel(
            repository
        ) as T
    }
}