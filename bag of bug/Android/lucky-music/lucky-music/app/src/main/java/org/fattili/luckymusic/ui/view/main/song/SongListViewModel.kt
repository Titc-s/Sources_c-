package org.fattili.luckymusic.ui.view.main.song

import android.media.MediaMetadataRetriever
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.launch
import org.fattili.luckymusic.data.SongRepository
import org.fattili.luckymusic.data.SongsRepository
import org.fattili.luckymusic.data.constant.ConstantParam
import org.fattili.luckymusic.data.constant.ShowMsg
import org.fattili.luckymusic.data.model.play.Song
import org.fattili.luckymusic.data.model.play.Songs
import org.fattili.luckymusic.player.PlayManager
import org.fattili.luckymusic.ui.base.BaseViewModel
import org.fattili.luckymusic.util.SongUtil
import java.io.File
import java.util.ArrayList

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌曲列表
 */
class SongListViewModel(private val repository: SongRepository,private val songsRepository: SongsRepository) : BaseViewModel() {
    var songsId: Long = 0
    var list: MutableList<Song> = mutableListOf()
    var dataChanged = MutableLiveData<Int>()

    fun getSongList() {

        launch {
            list.clear()
            list.addAll(repository.getSongList(songsId))
        }
    }

    fun addSong(song: Song):Boolean {
        if (repository.getSong(song.songs_id, song.target) != null){
            return false
        }
        repository.addSong(song)
        list.add(song)
        return true
    }

    fun getTitle(): String? {
        var songs = songsRepository.getSongs(songsId)
        return songs?.name
    }

    fun getSongsList(): MutableList<Songs> {
        return songsRepository.getLocalSongsList()
    }

    fun getSong(id: Long): Song? {
        return repository.getSong(id)
    }

    fun delete(id: Long): Boolean {
        val ret = repository.delete(id)
        if (ret) {
            list.remove(list.find { song ->  song.id == id})
            dataChanged.value = dataChanged.value?.plus(1)
        }
        return ret
    }

     fun addFile(paths: ArrayList<String?>?) {
        if (paths != null) {
            var mmr = MediaMetadataRetriever()
            for (path in paths) {
                if (path != null) {
                    val file = File(path)
                    var song = SongUtil.getSong(songsId, mmr, file)
                    addSong(song)
                }
            }
            dataChanged.value = dataChanged.value?.plus(1)
            PlayManager.getInstance().updatePlayList()
        }
    }

     fun play(pos:Int) {
         val id = list[pos].id
         if (id == PlayManager.getInstance().getPlaySong()?.songId) {
             if (PlayManager.getInstance().getPlaying()) {
                 PlayManager.getInstance().pause()
             } else {
                 PlayManager.getInstance().play()
             }
         } else {
             val song = getSong(id)
             song?.let {
                 PlayManager.getInstance().addSong(
                     song.castSongPlay(),
                     PlayManager.getInstance().getCurrentIndex()
                 )
             }
             PlayManager.getInstance().goto(PlayManager.getInstance().getCurrentIndex())
         }

     }

    fun prePlay(songId:Long) {
        val song = getSong(songId)
        song?.let {
            PlayManager.getInstance().addSong(
                song.castSongPlay(),
                PlayManager.getInstance().getCurrentIndex() + 1
            )
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