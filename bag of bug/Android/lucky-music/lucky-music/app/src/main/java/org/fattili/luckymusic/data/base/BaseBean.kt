package org.fattili.luckymusic.data.base

import org.fattili.luckymusic.data.constant.MessageType

/**
 * 2018/8/21
 * create by dzl
 * 类中文名：
 * 作用(说明)：
 */
class BaseBean {
    var messageType: MessageType
    var msg: String? = null

    constructor(messageType: MessageType, msg: String?) {
        this.messageType = messageType
        this.msg = msg
    }


    constructor(messageType: MessageType) {
        this.messageType = messageType
    }
}