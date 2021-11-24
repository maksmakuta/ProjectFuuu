package ua.vnu.test.droidapp;

import android.os.Bundle;
import android.view.View;
import android.widget.Toast;
import android.widget.ToggleButton;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onCheckBoxClicked(View view) {
        if (((CheckBox) view).isChecked()) {
            Toast.makeText(this, "Відмічено", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(this, "Не відмічено", Toast.LENGTH_SHORT).show();
        }
    }
}
