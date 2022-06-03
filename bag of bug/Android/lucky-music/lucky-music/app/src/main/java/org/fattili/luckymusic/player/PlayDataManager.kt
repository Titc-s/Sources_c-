package org.fattili.luckymusic.player

import org.fattili.luckymusic.data.constant.ConstantParam
import org.fattili.luckymusic.data.db.LuckyMusicDatabase
import org.fattili.luckymusic.data.model.play.PlaySong
import org.fattili.luckymusic.util.Logger
import org.fattili.luckymusic.util.SharePrefUtil

/**
 * create by dengzhenli 2020/11/6
 * 播放记录管理
 */
object PlayDataManager {
    private const val keyName = "playManage"

    /**
     * 通过target找到下标
     */
    fun getIndex(target: String, playList: MutableList<PlaySong>): Int {
        return playList.indexOf(playList.find { it.target == target })
    }

    /**
     * 读取记录
     */
    fun read(): PlayData {
        var info = PlayData()
        info.duration = readDuration()
        info.progress = readProgress()
        info.target = readTarget()
        info.playType = readPlayType()
        info.playList = readPlayList()
        return info
    }

    /**
     * 保存记录
     */
    fun write(playData: PlayData) {
        writeDuration(playData.duration)
        writeProgress(playData.progress)
        writeTarget(playData.target)
        writePlayType(playData.playType)
        writePlayList(playData.playList)
    }

    private fun readDuration(): Int {
        return SharePrefUtil.getIntData(keyName, "duration")
    }

    private fun writeDuration(duration: Int) {
        return SharePrefUtil.saveData(keyName, "duration", duration)
    }


    private fun readProgress(): Int {
        return SharePrefUtil.getIntData(keyName, "progress")
    }

    private fun writeProgress(progress: Int) {
        return SharePrefUtil.saveData(keyName, "progress", progress)
    }


    private fun readTarget(): String {
        return SharePrefUtil.getData(keyName, "target")
    }

    fun writeTarget(index: String) {
        return SharePrefUtil.saveData(keyName, "target", index)
    }

    private fun readPlayType(): PlayType {
        try {
            return PlayType.valueOf(SharePrefUtil.getData(keyName, "playType"))
        } catch (e: Exception) {
            Logger.e(e)
        }
        return PlayType.LIST
    }

    fun writePlayType(playType: PlayType) {
        return SharePrefUtil.saveData(keyName, "playType", playType.name)
    }

    private fun readPlayList(): MutableList<PlaySong> {
        var list = LuckyMusicDatabase.getPlaySongDao().getSongList()
        if (list.isEmpty()) {
            list = PlaySong.cast(LuckyMusicDatabase.getSongDao().getSongList(ConstantParam.SONGS_ID_LOCAL)) as MutableList<PlaySong>
        }
        return list
    }


    fun writePlayList(playList: MutableList<PlaySong>) {
        LuckyMusicDatabase.getPlaySongDao().saveSongList(playList)
    }

}