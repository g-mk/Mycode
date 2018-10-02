package com.example.gurumanikandan.discussionfourm;

import android.content.Intent;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class HomeActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);
        Button login = (Button)findViewById(R.id.btnGotoLogin);
        Button signup = (Button)findViewById(R.id.btnGotoSignUp);
        login.setOnClickListener(new View.OnClickListener(){
            public void onClick(View V){
                goLogin(V);
            }
        });
        signup.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                goSignUp(view);
            }
        });
    }
    public void goLogin(View view)
    {
        Intent i = new Intent(this,LoginActivity.class);
        startActivity(i);
        finish();
    }
    public void goSignUp(View view)
    {
        Intent i = new Intent(this,SignUpActivity.class);
        startActivity(i);
        finish();
    }
}
