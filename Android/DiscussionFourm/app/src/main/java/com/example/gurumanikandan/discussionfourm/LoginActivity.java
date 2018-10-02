package com.example.gurumanikandan.discussionfourm;

import android.Manifest;
import android.app.PendingIntent;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.StrictMode;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Random;

public class LoginActivity extends AppCompatActivity {
    public String OTP;

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        switch (requestCode) {
            case 1: {
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    Log.d("GURU","Granted Sucess");
                    sendSMS();
                } else {

                }
            }

        }

    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        OTP="";
        final EditText uMail = (EditText)findViewById(R.id.txtEmail);
        final EditText uPassword = (EditText)findViewById(R.id.txtPassword);
        Button clear = (Button)findViewById(R.id.btnClear);
        Button login = (Button)findViewById(R.id.btnLogin);
        clear.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                clearAction(view);
            }
        });
        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(uMail.getError()==null&&uPassword.getError()==null)
                    checkLoginMySQL(view);
            }
        });
        uMail.setOnFocusChangeListener(new View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View view, boolean b) {
                if(uMail.getText().toString().equals(""))
                    uMail.setError("Enter User Name");
            }
        });
        uPassword.setOnFocusChangeListener(new View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View view, boolean b) {
                if(uPassword.getText().toString().equals(""))
                    uPassword.setError("Enter Password");
            }
        });
    }
    public void clearAction(View v) {
        EditText mail = (EditText) findViewById(R.id.txtEmail);
        mail.setText("");
        EditText password = (EditText) findViewById(R.id.txtPassword);
        password.setText("");
    }
    public void sendSMS()
    {
        AlertDialog.Builder builder = new AlertDialog.Builder(LoginActivity.this);
        final View mView = getLayoutInflater().inflate(R.layout.dialog_otp_send,null);
        builder.setView(mView);
        final AlertDialog dialog = builder.create();
        Button sendOTP = (Button)mView.findViewById(R.id.btnOtpSend);
        sendOTP.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                try {
                    DatabaseHandler databaseHandler = new DatabaseHandler(getApplicationContext());
                    EditText otpEmail = (EditText) mView.findViewById(R.id.txtOtpEmail);
                    User user =databaseHandler.getDetails(otpEmail.getText().toString());
                    if(!user.getMobile().equals("")) {
                        user.setPassword(generateOTP()+"");
                        databaseHandler.changePassword(user);
                        OTP="Your One Time Password is "+user.getPassword()+"\nChange Once You are Logged in.";
                        SmsManager smsManager = SmsManager.getDefault();
                        PendingIntent sentPI;
                        String SENT = "SMS_SENT";
                        sentPI = PendingIntent.getBroadcast(getApplicationContext(), 0, new Intent(SENT), 0);
                        smsManager.sendTextMessage(user.getMobile(), null, OTP.toString(), sentPI, null);
                    }
                }catch(Exception ex)
                {
                    Log.d("GURU:",ex.getMessage());
                }
                finally {
                    dialog.dismiss();
                }
            }
        });
        dialog.show();
    }
    public void OTP(View v)
    {
        if (ContextCompat.checkSelfPermission(LoginActivity.this,
                Manifest.permission.SEND_SMS)
                != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(LoginActivity.this,
                    new String[]{Manifest.permission.SEND_SMS}, 1);
        }
        else
            sendSMS();
    }
    public int generateOTP()
    {
        Random random = new Random();
        return (random.nextInt(99999));
    }
    public void checkLogin(View v)
    {
        EditText mail = (EditText)findViewById(R.id.txtEmail);
        EditText password = (EditText)findViewById(R.id.txtPassword);
        DatabaseHandler forumDb = new DatabaseHandler(getApplicationContext());
        String userName = forumDb.checkLogin(mail.getText().toString(),password.getText().toString());
        if(!userName.equals(""))
        {
            Intent i = new Intent(LoginActivity.this,UserPageActivity.class);
            i.putExtra("uName",userName);
            i.putExtra("uMail",mail.getText().toString());
            startActivity(i);
            forumDb.close();
            finish();
        }
        else
        {
            Toast.makeText(this,"Invalid User Name Or Password",Toast.LENGTH_LONG).show();
        }
    }

    public void checkLoginMySQL(View view)
    {
        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);
        EditText mail = (EditText)findViewById(R.id.txtEmail);
        EditText password = (EditText)findViewById(R.id.txtPassword);
        InputStream is=null;
        String result=null;
        String line=null;
        StringBuilder sb;
        String output="";
        ArrayList<NameValuePair> paraList = new ArrayList<NameValuePair>();
        try {
            paraList.add(new BasicNameValuePair("email",mail.getText().toString()));
            paraList.add(new BasicNameValuePair("password",password.getText().toString()));
            HttpClient httpClient = new DefaultHttpClient();
            HttpPost req = new HttpPost("http://172.16.6.142/checkLogin.php");
            req.setEntity(new UrlEncodedFormEntity(paraList));
            HttpResponse response = httpClient.execute(req);
            HttpEntity entity = response.getEntity();
            is = entity.getContent();
            BufferedReader reader = new BufferedReader(new InputStreamReader(is, "iso-8859-1"),8);
            sb = new StringBuilder();
            while ((line = reader.readLine()) != null) {
                sb.append(line + "\n");
            }
            is.close();
            result = sb.toString();
            JSONObject jSonObj = new JSONObject(result);
            JSONArray jArray = jSonObj.getJSONArray("login");
            if(jArray.length()>0)
            {
                JSONObject c = jArray.getJSONObject(0);
                Object name = c.get("username");
                if(!name.toString().equals(""))
                {
                    Intent i = new Intent(LoginActivity.this,UserPageActivity.class);
                    i.putExtra("uName",name.toString());
                    i.putExtra("uMail",mail.getText().toString());
                    startActivity(i);
                    finish();
                }
                else {
                    Toast.makeText(this,"Invalid User Name Or Password",Toast.LENGTH_LONG).show();
                }
            }
        }
        catch (Exception e1)
        {
            Log.e("Error1", e1.toString());
        }
    }
}
