package ua.vnu.test.droidapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        toast("onCreate()");
    }

    @Override
    protected void onStart() {
        super.onStart();
        toast("onStart()");
    }

    @Override
    protected void onStop() {
        super.onStop();
        toast("onStop()");
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        toast("onRestart()");
    }

    private void toast(String text){
        Toast.makeText(this,text,Toast.LENGTH_LONG).show();
    }

}