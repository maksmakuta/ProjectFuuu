package ua.vnu.test.droidapp;

import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    EditText userName;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        userName = (EditText) findViewById(R.id.user_name);
        userName.setOnKeyListener((v, keyCode, event) -> {
            if ((event.getAction() == KeyEvent.ACTION_DOWN)
                    && (keyCode == KeyEvent.KEYCODE_ENTER)) {
                Toast.makeText(getApplicationContext(),
                        userName.getText(),
                        Toast.LENGTH_SHORT).show();
                return true;
            }
            return false;
        });
    }

    public void onClear(View view) {
        userName.setText(null);
    }
}