package com.example.animatiti;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.graphics.drawable.AnimationDrawable;
import android.os.Bundle;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageView;

import android.media.MediaPlayer;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class TweenAnimation extends AppCompatActivity {

    private ImageView img;
    private Button startBtn;
    private Button pauseBtn;
    private MediaPlayer mediaPlayer;
    private Animation blinkAnimation;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_tween_animation);

        img = findViewById(R.id.img_blink);
        startBtn = findViewById(R.id.start_tween);
        pauseBtn = findViewById(R.id.pause_tween);

        // Загружаем анимацию
        blinkAnimation = AnimationUtils.loadAnimation(this, R.anim.blink_animation);

        // Загружаем музыкальный файл
        mediaPlayer = MediaPlayer.create(this, R.raw.symphony);

        // Объединяем оба действия в одном обработчике для startBtn
        startBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Запускаем анимацию
                img.startAnimation(blinkAnimation);

                // Запускаем или приостанавливаем музыку
                if (mediaPlayer.isPlaying()) {
                    mediaPlayer.pause();
                } else {
                    mediaPlayer.start();
                }
            }
        });

        // Остановка анимации по нажатию на pauseBtn
        pauseBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                img.clearAnimation(); // Останавливаем анимацию
                if (mediaPlayer.isPlaying()) {
                    mediaPlayer.pause(); // Приостанавливаем музыку, если она играет
                }
            }
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (mediaPlayer != null) {
            mediaPlayer.release(); // Освобождаем ресурсы MediaPlayer при уничтожении Activity
            mediaPlayer = null;
        }
    }

    // Метод для перехода на главный экран
    public void CanselToMain(View v) {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }
}
