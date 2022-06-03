package org.fattili.luckymusic.ui.adapter;

import android.content.Context;

import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentPagerAdapter;

/**
 * 2020/10/28
 * @author dengzhenli
 *
 */
public class SectionsPagerAdapter extends FragmentPagerAdapter {

    private Fragment[] fragments;
    private String[] titles;
    private final Context mContext;

    public SectionsPagerAdapter(Context context, FragmentManager fm, Fragment[] fragments) {
        this(context, fm, fragments, null);
    }

    public SectionsPagerAdapter(Context context, FragmentManager fm, Fragment[] fragments, String[] titles) {
        super(fm, BEHAVIOR_RESUME_ONLY_CURRENT_FRAGMENT);
        this.fragments = fragments;
        this.titles = titles;
        mContext = context;
    }

    @Override
    public Fragment getItem(int position) {
        return fragments[position];
    }

    @Nullable
    @Override
    public CharSequence getPageTitle(int position) {

        if (titles == null) return "";
        return titles[position];
    }

    @Override
    public int getCount() {
        return fragments.length;
    }
}