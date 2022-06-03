package com.hzy.chinese.jchess;

import android.app.Application;

import com.blankj.utilcode.util.LogUtils;
import com.blankj.utilcode.util.Utils;

public class MainApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        Utils.init(this);
        LogUtils.getConfig().setLogSwitch(BuildConfig.DEBUG)
                .setLogHeadSwitch(false).setBorderSwitch(false);
    }
}
