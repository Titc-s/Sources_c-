package org.fattili.luckymusic.player

/**
 * 2020/10/28
 * @author dengzhenli
 * 播放方式
 */
enum class PlayType {
    /**
     * 随机
     */
    RANDOM,

    /**
     * 列表
     */
    LIST,

    /**
     * 单曲循环
     */
    SINGLE_LOOP,

    /**
     * 列表循环
     */
    LIST_LOOP;

    fun next(): PlayType {
        val list = values()
        var index = list.indexOf(this)
        return list[++index % list.size]
    }
}