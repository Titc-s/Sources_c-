package org.fattili.luckymusic.util

import android.media.MediaMetadataRetriever
import android.util.Log
import org.fattili.luckymusic.data.model.play.Song
import org.fattili.luckymusic.player.PlayManager
import java.io.File

/**
 * 2020/10/28
 * @author dengzhenli
 */
object SongUtil {

    fun getSong(songsId:Long, mmr: MediaMetadataRetriever, file: File):Song {
        var song = Song(songsId, file.name, file.nameWithoutExtension, file.path)
        try {
            mmr.setDataSource(file.path)
            val title = mmr.extractMetadata(MediaMetadataRetriever.METADATA_KEY_TITLE)
            title?.let {if (it.isNotBlank()) song.title = title }
            val album = mmr.extractMetadata(MediaMetadataRetriever.METADATA_KEY_ALBUM)
            album?.let {if (it.isNotBlank()) song.album = album }
            val artist = mmr.extractMetadata(MediaMetadataRetriever.METADATA_KEY_ARTIST)
            artist?.let {if (it.isNotBlank()) song.artist = artist }
            val duration = mmr.extractMetadata(MediaMetadataRetriever.METADATA_KEY_DURATION) // 播放时长单位为毫秒
            song.duration = duration?.toInt()?:0
        } catch (e: Exception) {
            e.printStackTrace()
        }
        return song
    }

    fun getImage(mmr: MediaMetadataRetriever, path: String): ByteArray? {
        try {
            mmr.setDataSource(path)
            return mmr.embeddedPicture
        } catch (e: Exception) {
            e.printStackTrace()
        }
        return null
    }

    fun checkIsPlay(song: Song?): Boolean? {
        var playSong = PlayManager.getInstance().getPlaySong()
        playSong?.let {
            Logger.d(PlayManager.getInstance().getPlaying().toString())
            return song?.id == playSong.songId && PlayManager.getInstance().getPlaying()
        }
        return false
    }
}