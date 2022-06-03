package org.fattili.luckymusic.ui.view.main.setting

import android.media.MediaMetadataRetriever
import android.os.Environment.getExternalStorageDirectory
import androidx.databinding.ObservableField
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import org.fattili.luckymusic.MainApp
import org.fattili.luckymusic.R
import org.fattili.luckymusic.data.SongRepository
import org.fattili.luckymusic.data.constant.ConstantParam
import org.fattili.luckymusic.player.PlayManager
import org.fattili.luckymusic.ui.base.BaseViewModel
import org.fattili.luckymusic.util.SongUtil
import java.io.File


/**
 * 2020/10/28
 * @author dengzhenli
 * 扫描歌曲
 */

class FindSongViewModel(
    private val songRepository: SongRepository
) : BaseViewModel() {

    /**
     * 当前扫描路径
     */
    var filePath: ObservableField<String> = ObservableField()

    /**
     * 扫描提示
     */
    var searchMsg: ObservableField<String> = ObservableField()

    private val points = arrayOf(".", "..", "...", "....", ".....") //提示后缀
    private var num = 0  // 导入歌曲数
    private var fileNum = 0 //扫描文件数
    private val showMargin = 10 //扫描时候显示的文件跨度

    override fun init() {}

    fun findFile() {
        val rootFile = getExternalStorageDirectory().absolutePath

        num = 0
        fileNum = 0

        searchMsg.set(MainApp.context.getString(R.string.lm_setting_searching))

        viewModelScope.launch {
            delay(500)
            searchFile(rootFile)
            filePath.set("共导入${num}首歌曲")
            searchMsg.set(MainApp.context.getString(R.string.lm_setting_search_end))
            PlayManager.getInstance().updatePlayList()
        }

    }

    /**
     * 递归扫描歌曲
     */
    private suspend fun searchFile(path: String) {
        var file = File(path)
        var fileList = file.listFiles()
        for (f in fileList) {
            //扫描速度控制，给用户一定肉眼效果
            if (fileNum % showMargin == 0) {
                delay(1)
                searchMsg.set(MainApp.context.getString(R.string.lm_setting_searching) + points[fileNum / showMargin % points.size])
            }
            fileNum ++
            filePath.set(f.absolutePath)
            if (!f.canRead()) continue
            if (f.isDirectory) {
                //不扫描隐藏文件夹
                if (!f.name.startsWith(".")) {
                    searchFile(f.absolutePath)
                }
            } else {
                if ("mp3" == f.extension) {
                    addSong(f)
                    delay(100)
                }
            }
        }
    }

    private fun addSong(file: File) {
        val mmr = MediaMetadataRetriever()
        var song = SongUtil.getSong(ConstantParam.SONGS_ID_LOCAL, mmr, file)
        if (songRepository.getSong(ConstantParam.SONGS_ID_LOCAL, file.path) == null) {
            songRepository.addSong(song)
            num++
        }
    }

}