package org.fattili.luckymusic.player

import org.fattili.luckymusic.data.model.play.PlaySong

/**
 * create by dengzhenli 2020/11/6
 * 播放记录数据
 */
class PlayData {

    /**
     * 歌曲标记
     */
    var target = ""

    /**
     * 进度
     */
    var progress = 0

    /**
     * 歌曲时长
     */
    var duration = 0

    /**
     * 播放模式
     */
    var playType: PlayType = PlayType.LIST

    /**
     * 播放队列
     */
    var playList: MutableList<PlaySong> = arrayListOf()

}