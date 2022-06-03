package org.fattili.luckymusic

import android.app.Application
import android.content.Context
import androidx.multidex.MultiDex
import org.fattili.luckymusic.player.PlayManager
import org.litepal.LitePal

/**
 *
 *
 */
class MainApp :Application(){
    override fun onCreate() {
        super.onCreate()
        context = this
        instance = this

        LitePal.initialize(this)
        initPlay()
    }

    override fun attachBaseContext(base: Context?) {
        super.attachBaseContext(base)
        MultiDex.install(this);
    }

    private fun initPlay(){
        PlayManager.getInstance().init()
    }

    fun onExit(){
        PlayManager.getInstance().exit()
    }


    companion object {
        lateinit var context: Context
        lateinit var instance: MainApp
    }

}