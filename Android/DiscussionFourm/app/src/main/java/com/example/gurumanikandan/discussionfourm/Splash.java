package com.example.gurumanikandan.discussionfourm;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.animation.Animation;
import android.view.animation.AnimationSet;
import android.view.animation.AnimationUtils;
import android.view.animation.RotateAnimation;
import android.widget.ImageView;
import android.widget.TextView;

public class Splash extends AppCompatActivity {
    private TextView welcometitle;
    private ImageView welcomelogo;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);
        final Intent i = new Intent(Splash.this,HomeActivity.class);
        welcomelogo = (ImageView)findViewById(R.id.welcomelogo);
        welcometitle = (TextView)findViewById(R.id.welcometitle);
        RotateAnimation imageRotate = new RotateAnimation(0,360,Animation.RELATIVE_TO_SELF, 0.5f, Animation.RELATIVE_TO_SELF, 0.5f);
        Animation myanim = AnimationUtils.loadAnimation(this,R.anim.splash);
        AnimationSet set = new AnimationSet(false);
        set.addAnimation(myanim);
        set.addAnimation(imageRotate);
        imageRotate.setDuration(1500);
        imageRotate.setFillAfter(true);
        welcomelogo.startAnimation(set);
        welcometitle.startAnimation(myanim);
        Thread timer = new Thread(){
            public void run()
            {
                try {
                    sleep(7000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                finally {
                    startActivity(i);
                    finish();
                }
            }
        };
        timer.start();
    }
}
