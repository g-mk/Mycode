package com.example.gurumanikandan.diceroll;

import android.graphics.drawable.Drawable;
import android.media.Image;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.appindexing.Thing;
import com.google.android.gms.common.api.GoogleApiClient;

import java.lang.Math;

import java.util.*;

public class MainActivity extends AppCompatActivity {

    private static final int GAME_POINT=100;
    private Button btnHoldClick;
    private Button btnRollClick;
    private Button btnResetClick;

    private TextView txtUsrScore;
    private TextView txtCompScore;
    private TextView txtRes;

    private ImageView imgDice;

    private int userScore = 0;
    private int compScore = 0;
    private int curUser = 0;
    private int curComp = 0;

    private Random rand = new Random();

    private Handler delay = new Handler();

    private HashMap<Integer, Integer> mapDice = new HashMap<Integer, Integer>();
    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    private GoogleApiClient client;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btnHoldClick = (Button) findViewById(R.id.btnHold);
        btnRollClick = (Button) findViewById(R.id.btnRoll);
        btnResetClick = (Button) findViewById(R.id.btnReset);
        txtUsrScore = (TextView) findViewById(R.id.usrScore);
        txtCompScore = (TextView) findViewById(R.id.compScore);
        txtRes = (TextView) findViewById(R.id.txtResult);
        imgDice = (ImageView) findViewById(R.id.img);
        mapDice.put(0, R.drawable.dice1);
        mapDice.put(1, R.drawable.dice2);
        mapDice.put(2, R.drawable.dice3);
        mapDice.put(3, R.drawable.dice4);
        mapDice.put(4, R.drawable.dice5);
        mapDice.put(5, R.drawable.dice6);
        btnResetClick.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onReset();
            }
        });
        btnRollClick.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onRoll();
            }
        });
        btnHoldClick.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onHold();
            }
        });

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client = new GoogleApiClient.Builder(this).addApi(AppIndex.API).build();
    }

    public void update(int uScore, int cScore) {
        curComp=0;
        curUser=0;
        txtCompScore.setText("Computer Score:" + cScore);
        txtUsrScore.setText("Your Score:" + uScore);
        if (cScore > 100) {
            Toast toast= Toast.makeText(getApplicationContext(),"Computer Won the Game",Toast.LENGTH_LONG);
            toast.show();
            txtRes.setText("Computer Won the Game :(");
            btnRollClick.setEnabled(false);
            btnHoldClick.setEnabled(false);

        }
        if (uScore > 100) {
            Toast toast = Toast.makeText(getApplicationContext(),"You Won the Game",Toast.LENGTH_LONG);
                    toast.show();
            txtRes.setText("You Won the Game!!!!!!!!!!!");
            btnRollClick.setEnabled(false);
            btnHoldClick.setEnabled(false);
        }

    }

    public void onRoll() {
        int dice = (Math.abs(rand.nextInt())) % 6;
        imgDice.setImageResource(mapDice.get(dice));
        if (dice == 0) {
            update(userScore,compScore);
            computerTurn();
        } else
            curUser += dice + 1;
    }

    public void onHold() {
        userScore += curUser;
        update(userScore, compScore);
        if(userScore<100)
            computerTurn();
    }

    public void onReset() {
        compScore = 0;
        userScore = 0;
        txtRes.setText("");
        update(userScore, compScore);
        btnHoldClick.setEnabled(true);
        btnRollClick.setEnabled(true);
    }

    public void computerTurn() {
        if(userScore<GAME_POINT) {
            btnRollClick.setEnabled(false);
            btnHoldClick.setEnabled(false);
            delay.postDelayed(new Runnable() {
                @Override
                public void run() {
                    int dice = (Math.abs(rand.nextInt())) % 6;
                    imgDice.setImageResource(mapDice.get(dice));
                    if (dice != 0 && curComp < 20) {
                        curComp += dice + 1;
                        computerTurn();
                    } else {
                        if (dice == 0)
                            curComp = 0;
                        else
                            compScore += curComp;
                        update(userScore, compScore);
                        btnRollClick.setEnabled(true);
                        btnHoldClick.setEnabled(true);
                    }


                }
            }, 2000);
        }
    }


}
