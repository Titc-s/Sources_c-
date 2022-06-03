package org.fattili.luckymusic.ui.view.main.song

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.launch
import org.fattili.luckymusic.data.SongRepository
import org.fattili.luckymusic.data.SongsRepository
import org.fattili.luckymusic.data.constant.ConstantParam
import org.fattili.luckymusic.data.constant.ShowMsg
import org.fattili.luckymusic.data.model.play.PlaySong
import org.fattili.luckymusic.data.model.play.Songs
import org.fattili.luckymusic.player.PlayManager
import org.fattili.luckymusic.ui.base.BaseViewModel

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌单列表
 */

class SongsListViewModel(
    private val repository: SongsRepository,
    private val songRepository: SongRepository
) : BaseViewModel() {

    var list: MutableList<Songs> = mutableListOf()
    var dataChanged = MutableLiveData<Int>()


    fun getSongsList() {
        launch {
            list.clear()
            list.addAll(repository.getSongsList())
        }
    }

    fun getSongs(id: Long): Songs? {
        val song = repository.getSongs(id)
        song?.songList = songRepository.getLocalSongList(id)
        return song
    }

    fun delete(id: Long): Int {
        val ret = repository.delete(id)
        if (ret > 0) {
            list.remove(list.find { songs ->  songs.id == id})
            dataChanged.value = dataChanged.value?.plus(1)
        }
        return ret
    }

    fun add(name: String): Boolean {
        var songs = Songs(name, ConstantParam.SONGS_TYPE_SONGS)
        val ret = repository.addSongs(songs)
        if (ret) {
            list.add(songs)
            dataChanged.value = dataChanged.value?.plus(1)
        }
        return ret
    }

    fun play(songsId:Long){
        val songs = getSongs(songsId)
        val list = songs?.songList
        list?.let {
            PlayManager.getInstance()
                .updatePlayList(PlaySong.cast(it) as MutableList<PlaySong>)
        }
    }

    fun prePlay(songsId:Long){
        val songs = getSongs(songsId)
        val list = songs?.songList
        list?.let {
            PlayManager.getInstance().addPlayList(PlaySong.cast(it) as MutableList<PlaySong>)
        }
    }
    private fun launch(block: suspend () -> Unit) = viewModelScope.launch {
        try {
            block()
            dataChanged.value = dataChanged.value?.plus(1)
        } catch (e: Throwable) {
            e.printStackTrace()
        }
    }

    override fun init() {

    }


}