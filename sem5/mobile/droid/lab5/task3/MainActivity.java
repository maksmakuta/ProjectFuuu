package ua.vnu.test.droidapp;

import android.app.ListActivity;
import android.content.Context;
import android.content.res.Resources;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends ListActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Resources r = getResources();
        String[] stationsArray = r.getStringArray(R.array.stations);
        ArrayAdapter<String> aa = new ArrayAdapter<String>(
                this, R.layout.item, stationsArray);
        setListAdapter(aa);

        getListView().setOnItemClickListener((parent, v, position, id) -> {
            CharSequence text = ((TextView) v).getText();
            int duration = Toast.LENGTH_LONG;
            Context context = getApplicationContext();
            Toast.makeText(context, text, duration).show();
        });
    }

}