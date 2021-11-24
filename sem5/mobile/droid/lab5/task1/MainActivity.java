package ua.vnu.test.droidapp;

import android.app.TabActivity;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.widget.TabHost;

public class MainActivity extends TabActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Resources res = getResources();
        String tab1Indicator = res.getString(R.string.tab1_indicator);
        String tab2Indicator = res.getString(R.string.tab2_indicator);
        String tab3Indicator = res.getString(R.string.tab3_indicator);
        TabHost tabHost = getTabHost();
        TabHost.TabSpec spec;
        Intent intent;
        intent = new Intent().setClass(this, StudentActivity.class);
        spec = tabHost.newTabSpec("students").setIndicator(tab1Indicator)
                .setContent(intent);
        tabHost.addTab(spec);
        intent = new Intent().setClass(this, TeacherActivity.class);
        spec = tabHost.newTabSpec("teachers").setIndicator(tab2Indicator)
                .setContent(intent);
        tabHost.addTab(spec);
        intent = new Intent().setClass(this, ClassesActivity.class);
        spec = tabHost.newTabSpec("class").setIndicator(tab3Indicator)
                .setContent(intent);
        tabHost.addTab(spec);
        tabHost.setCurrentTab(1);
    }

}