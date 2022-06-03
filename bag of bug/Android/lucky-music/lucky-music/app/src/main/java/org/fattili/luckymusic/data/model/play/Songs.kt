package org.fattili.luckymusic.data.model.play

import org.fattili.luckymusic.data.constant.ConstantParam
import org.litepal.annotation.Column
import org.litepal.crud.LitePalSupport

/**
 * 2020/10/28
 * @author dengzhenli
 * 歌曲列表
 */
class Songs : LitePalSupport {

    var id: Long

    /**
     * 名称
     */
    @Column(nullable = false)
    var name: String

    /**
     * 类型
     */
    @Column
    var type: Int = ConstantParam.SONGS_TYPE_SONGS

    /**
     * 歌曲
     */
    @Column
    var songList: MutableList<Song> = arrayListOf()

    /**
     * 创建时间
     */
    @Column
    var create_time: Long = System.currentTimeMillis()

    constructor() : this(0, "", ConstantParam.SONGS_TYPE_SONGS) {}

    constructor(
        name: String,
        type: Int
    ) : this(0, name, type) {}

    constructor(
        id: Long,
        name: String,
        type: Int
    ) {
        this.id = id
        this.name = name
        this.type = type
    }

}