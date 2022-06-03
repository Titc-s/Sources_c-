package org.fattili.luckymusic.ui.view.main.song.edit

import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import org.fattili.luckymusic.data.SongRepository
import org.fattili.luckymusic.data.SongsRepository
/**
 * 2020/10/28
 * @author dengzhenli
 * 歌单编辑
 */
class SongsEditModelFactory(private val repository: SongsRepository
) : ViewModelProvider.NewInstanceFactory() {

    @Suppress("UNCHECKED_CAST")
    override fun <T : ViewModel?> create(modelClass: Class<T>): T { return SongsEditViewModel(repository) as T }
}