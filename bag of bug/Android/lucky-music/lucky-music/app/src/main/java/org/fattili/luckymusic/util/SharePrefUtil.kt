package org.fattili.luckymusic.util

import android.content.Context
import android.content.SharedPreferences
import org.fattili.luckymusic.MainApp

/**
 * 2018/8/21
 * create by dzl
 * 类中文名：SharePref工具类
 * 作用(说明)：
 */
object SharePrefUtil {
    const val appPref = "lmusic"

    /**
     * 保存字符串
     * @param fileName
     * @param key
     * @param value
     */
    fun saveData(fileName: String, key: String, value: String) {
        val sharedPreferences: SharedPreferences = MainApp.context.getSharedPreferences(fileName, Context.MODE_PRIVATE)
        sharedPreferences.edit().putString(key, value).apply()
    }

    /**
     * 获取字符串
     * @param fileName
     * @param key
     * @return
     */
    fun getData(fileName: String, key: String): String {
        val sharedPreferences: SharedPreferences = MainApp.context.getSharedPreferences(fileName, Context.MODE_PRIVATE)
        return sharedPreferences.getString(key, "")?:""
    }

    /**
     * 保存int
     * @param fileName
     * @param key
     * @param value
     */
    fun saveData(fileName: String, key: String, value: Int) {
        val sharedPreferences: SharedPreferences = MainApp.context.getSharedPreferences(fileName, Context.MODE_PRIVATE)
        sharedPreferences.edit().putInt(key, value).apply()
    }

    /**
     * 获取int
     * @param fileName
     * @param key
     * @return
     */
    fun getIntData(fileName: String, key: String): Int {
        val sharedPreferences: SharedPreferences = MainApp.context.getSharedPreferences(fileName, Context.MODE_PRIVATE)
        return sharedPreferences.getInt(key, 0)
    }

    /**
     * 保存布尔值
     * @param fileName
     * @param key
     * @param value
     */
    fun saveData(fileName: String, key: String, value: Boolean) {
        val sharedPreferences: SharedPreferences = MainApp.context.getSharedPreferences(fileName, Context.MODE_PRIVATE)
        sharedPreferences.edit().putBoolean(key, value).apply()
    }

    /**
     * 获取布尔值
     * @param fileName
     * @param key
     * @return
     */
    fun getBooleanData(fileName: String, key: String): Boolean {
        val sharedPreferences: SharedPreferences = MainApp.context.getSharedPreferences(fileName, Context.MODE_PRIVATE)
        return sharedPreferences.getBoolean(key, false)
    }
}