package com.example.animatiti;

import android.content.Intent;
import android.graphics.drawable.AnimationDrawable;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class FrameAnimation extends AppCompatActivity {

    private ImageView animationIV;
    private Button startBtn;
    private Button pauseBtn;
    private AnimationDrawable frameAnimation;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_frame_animation);

        animationIV = findViewById(R.id.animImageView);
        startBtn = findViewById(R.id.startBtn);
        pauseBtn = findViewById(R.id.pauseBtn);

        frameAnimation = (AnimationDrawable) animationIV.getDrawable();

        startBtn.setOnClickListener(v -> {
            if (!frameAnimation.isRunning()) {
                frameAnimation.start();
            }
        });

        pauseBtn.setOnClickListener(v -> {
            if (frameAnimation.isRunning()) {
                frameAnimation.stop();
            }
        });
    }
    public void CanselToMain(View v) {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }
}
