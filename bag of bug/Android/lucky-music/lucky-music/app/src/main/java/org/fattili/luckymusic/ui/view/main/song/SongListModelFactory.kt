package org.fattili.luckymusic.ui.view.main.song

import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import org.fattili.luckymusic.data.SongRepository
import org.fattili.luckymusic.data.SongsRepository

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌曲列表
 */
class SongListModelFactory(
    private val repository: SongRepository,
    private val songsRepository: SongsRepository
) : ViewModelProvider.NewInstanceFactory() {

    @Suppress("UNCHECKED_CAST")
    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return SongListViewModel(
            repository, songsRepository
        ) as T
    }
}