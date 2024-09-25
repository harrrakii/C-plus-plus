package com.example.animatiti;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
    }

    public void startFrameAct(View v) {
        Intent intent = new Intent(this, FrameAnimation.class);
        startActivity(intent);
    }

    public void startTweenAct(View v) {
        Intent intent = new Intent(this, TweenAnimation.class);
        startActivity(intent);
    }
}