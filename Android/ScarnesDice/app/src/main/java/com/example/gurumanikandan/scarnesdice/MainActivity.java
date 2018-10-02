package com.example.gurumanikandan.scarnesdice;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.HashMap;
import java.util.Random;

import android.os.Handler;


public class MainActivity extends AppCompatActivity {

    private int userTotalScore;
    private int userCurrentScore;
    private int compTotalScore;
    private int compCurrentScore;

    Random random = new Random();

    ImageView image;
    TextView uScore,cScore;
    Button btnRoll,btnHold,btnReset;
    HashMap<Integer,Integer> numberToImage = new HashMap<Integer, Integer>();
    // create handler for time delay
    Handler handler= new Handler();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        image = (ImageView) findViewById(R.id.image);

        uScore=(TextView) findViewById(R.id.userScore);
        cScore=(TextView) findViewById(R.id.computerScore);

        btnRoll = (Button) findViewById(R.id.btnRoll);
        btnHold = (Button) findViewById(R.id.btnHold);
        btnReset = (Button) findViewById(R.id.btnReset);

        // map numbers to images

        numberToImage.put(1,R.drawable.dice1);
        numberToImage.put(2,R.drawable.dice2);
        numberToImage.put(3,R.drawable.dice3);
        numberToImage.put(4,R.drawable.dice4);
        numberToImage.put(5,R.drawable.dice5);
        numberToImage.put(6,R.drawable.dice6);

        // listeners for buttons
        btnRoll.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
            int number = onRoll();
                int imageNumber = numberToImage.get(number);
                image.setImageResource(imageNumber);
                if(number == 1)
                {
                    userCurrentScore=0;
                    userTotalScore+=userCurrentScore;
                    update();
                    btnRoll.setEnabled(false);
                    btnHold.setEnabled(false);
                    btnReset.setEnabled(false);
                    turnOfCpu();
                }
                else
                {
                    userCurrentScore += number;
                }
            }
        });

        btnHold.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                userTotalScore+=userCurrentScore;
                update();
                btnRoll.setEnabled(false);
                btnHold.setEnabled(false);
                btnReset.setEnabled(false);
                turnOfCpu();



            }
        });

        btnReset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                btnRoll.setEnabled(true);
                btnHold.setEnabled(true);
                btnReset.setEnabled(true);
                userTotalScore=0;
                compTotalScore=0;
                userCurrentScore=0;
                compCurrentScore=0;
                update();

            }
        });
    }



    public int onRoll()
    {
     return (Math.abs(random.nextInt())%6 +1);
    }

    public void update()
    {
        userCurrentScore=0;
        compCurrentScore=0;
        uScore.setText(""+userTotalScore);
        cScore.setText(""+compTotalScore);
    }

    public void turnOfCpu()
    {
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                int number = onRoll();
                int imageNumber = numberToImage.get(number);
                image.setImageResource(imageNumber);
                if(number == 1)
                {
                    compCurrentScore=0;
                    compTotalScore+=compCurrentScore;
                    update();
                    btnRoll.setEnabled(true);
                    btnHold.setEnabled(true);
                    btnReset.setEnabled(true);
                }
                else
                {
                    if(compCurrentScore < 20)
                    {
                        compCurrentScore+=number;
                        turnOfCpu();
                    }
                    else
                    {
                        compTotalScore+=compCurrentScore;
                        update();
                        btnRoll.setEnabled(true);
                        btnHold.setEnabled(true);
                        btnReset.setEnabled(true);
                    }
                }
            }
        },1000);
    }

}
