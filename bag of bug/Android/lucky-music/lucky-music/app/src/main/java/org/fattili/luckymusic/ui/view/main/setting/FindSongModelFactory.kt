package org.fattili.luckymusic.ui.view.main.setting

import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import org.fattili.luckymusic.data.SongRepository

/**
 * 2020/10/28
 * @author dengzhenli
 * 扫描歌曲
 */
class FindSongModelFactory(
    private val songRepository: SongRepository
) : ViewModelProvider.NewInstanceFactory() {

    @Suppress("UNCHECKED_CAST")
    override fun <T : ViewModel?> create(modelClass: Class<T>): T {
        return FindSongViewModel(songRepository) as T
    }
}