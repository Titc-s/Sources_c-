package org.fattili.luckymusic.ui.view.main.song

import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import org.fattili.luckymusic.data.SongRepository
import org.fattili.luckymusic.data.SongsRepository
/**
 * 2020/10/28
 * @author dengzhenli
 * 歌单列表
 */
class SongsListModelFactory(private val repository: SongsRepository,private val songRepository: SongRepository) : ViewModelProvider.NewInstanceFactory() {

    @Suppress("UNCHECKED_CAST")
    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return SongsListViewModel(repository,songRepository) as T
    }
}