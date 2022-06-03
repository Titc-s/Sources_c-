package org.fattili.luckymusic

import android.media.MediaMetadataRetriever
import androidx.test.platform.app.InstrumentationRegistry
import androidx.test.ext.junit.runners.AndroidJUnit4
import org.fattili.luckymusic.player.PlayType
import org.fattili.luckymusic.util.Logger

import org.junit.Test
import org.junit.runner.RunWith

import org.junit.Assert.*

/**
 * Instrumented test, which will execute on an Android device.
 *
 * See [testing documentation](http://d.android.com/tools/testing).
 */
@RunWith(AndroidJUnit4::class)
class ExampleInstrumentedTest {
    @Test
    fun useAppContext() {
        // Context of the app under test.
        val appContext = InstrumentationRegistry.getInstrumentation().targetContext
        assertEquals("org.fattili.luckymusic", appContext.packageName)


    }

     @Test
    fun testKotlin() {
         val title :String? = "1"
         title?.let { if (it.isNotBlank()) Logger.d("ss")  }
    }

     @Test
    fun testPlayType() {
         Logger.e(PlayType.LIST.name)
         Logger.e(PlayType.valueOf(PlayType.LIST.name).name)
    }

}