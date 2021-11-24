package ua.vnu.test.droidapp;

import android.os.Bundle;
import android.view.View;
import android.widget.RadioButton;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onRadioButtonClicked(View view) {
        RadioButton rb = (RadioButton) view;
        Toast.makeText(this, "Вибраний звір: " + rb.getText(),
                Toast.LENGTH_SHORT).show();
    }
}