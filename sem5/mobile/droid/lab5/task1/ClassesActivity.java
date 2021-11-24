package ua.vnu.test.droidapp;

import android.content.res.Resources;
import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class ClassesActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Resources res = getResources();
        String contentText = res.getString(R.string.tab3_content);
        TextView textView = new TextView(this);
        textView.setText(contentText);
        setContentView(textView);
    }

}
