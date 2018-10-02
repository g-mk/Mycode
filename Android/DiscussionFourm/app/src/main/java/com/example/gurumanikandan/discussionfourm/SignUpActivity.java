package com.example.gurumanikandan.discussionfourm;

import android.app.Activity;
import android.content.Intent;
import android.os.StrictMode;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

import org.apache.http.NameValuePair;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SignUpActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_up);
        Button register = (Button)findViewById(R.id.btnReg);
        Name = (EditText)findViewById(R.id.txtUserName);
        EmailId = (EditText)findViewById(R.id.txtUserMail);
        Password = (EditText)findViewById(R.id.txtUserPassword);
        confirmPassword = (EditText)findViewById(R.id.txtUserConfirmPassword);
        DOB = (DatePicker)findViewById(R.id.datePickerDOB);
        Mobile = (EditText)findViewById(R.id.txtUserMobile);
        register.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                registerUserMySQL(view);
            }
        });
        Name.setOnFocusChangeListener(new View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View view, boolean b) {
                String Val = Name.getText().toString();
                Pattern namePatter = Pattern.compile("^[a-zA-Z ]+$");
                Matcher matchName = namePatter.matcher(Val);
                if(Val.equals(""))
                    Name.setError("Field should not be Empty");
                else if(!matchName.matches())
                    Name.setError("Name should contain only Alphabet");
            }
        });
        EmailId.setOnFocusChangeListener(new View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View view, boolean b) {
                String Val = EmailId.getText().toString();
                if(Val.equals(""))
                    EmailId.setError("Field should not be Empty");
                else if(!Validator.checkText(Val))
                    EmailId.setError("Enter a valid Email ID");

            }
        });
        Password.setOnFocusChangeListener(new View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View view, boolean b) {
                String Val = Password.getText().toString();

                if(Val.equals(""))
                    Password.setError("Field should not be Empty");
                else if(Val.length()<6)
                    Password.setError("Password length should be greater than 5");
                else if(!Validator.checkPassword(Val))
                    Password.setError("Password should contain at least one Upper,Lower,Numeric and Symbol Character");
            }
        });
        confirmPassword.setOnFocusChangeListener(new View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View view, boolean b) {
                String password = Password.getText().toString();
                String cPassword = confirmPassword.getText().toString();
                if(!password.equals(cPassword))
                    confirmPassword.setError("Password Mismatch");
            }
        });
        Mobile.setOnFocusChangeListener(new View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View view, boolean b) {
                if(Mobile.getText().toString().equals(""))
                {
                    Mobile.setError("Enter Your Mobile Number");
                }
                if(Mobile.getText().toString().length()!=10)
                {
                    Mobile.setError("Enter a Valid Mobile Number");
                }
            }
        });
    }
    public void redirectToLogin()
    {
        Intent i = new Intent(SignUpActivity.this,LoginActivity.class);
        startActivity(i);
        finish();
    }
    public void registerUser(View view){
        RadioGroup radioGroup = (RadioGroup) findViewById(R.id.rdbGroupGender);
        int selectedRadio = radioGroup.getCheckedRadioButtonId();
        if(Name.getError()==null && EmailId.getError()==null && Password.getError()==null &&
                confirmPassword.getError()==null && selectedRadio !=-1 && Mobile.getError()==null) {
            Gender = (RadioButton) findViewById(selectedRadio);
            DatabaseHandler forumDb = new DatabaseHandler(getApplicationContext());
            String dob = DOB.getYear() + "-" + (DOB.getMonth() + 1) + "-" + DOB.getDayOfMonth();
            User user = new User();
            user.seteMailId(String.valueOf(EmailId.getText()));
            user.setName(String.valueOf(Name.getText()));
                user.setPassword(String.valueOf(Password.getText()));
            user.setGender(String.valueOf(Gender.getText()));
            user.setDOB(dob);
            user.setMobile(Mobile.getText().toString());
            String Status = forumDb.addUser(user);
            Toast.makeText(this, Status, Toast.LENGTH_LONG).show();
            if (Status.equals(DatabaseHandler.REG_SUCCESS))
                redirectToLogin();
        }
        else
            Toast.makeText(this,"Provide All Necessary Information to Register",Toast.LENGTH_LONG).show();;

    }
    public void registerUserMySQL(View view){
        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        RadioGroup radioGroup = (RadioGroup) findViewById(R.id.rdbGroupGender);
        int selectedRadio = radioGroup.getCheckedRadioButtonId();
        StrictMode.setThreadPolicy(policy);
        String email = String.valueOf(EmailId.getText());
        String name = String.valueOf(Name.getText());
        String dob = DOB.getYear() + "-" + (DOB.getMonth() + 1) + "-" + DOB.getDayOfMonth();
        String mobile = String.valueOf(Mobile.getText());
        String password = String.valueOf(Password.getText());
        Gender = (RadioButton) findViewById(selectedRadio);
        String gender = String.valueOf(Gender.getText());
        ArrayList<NameValuePair> paraList = new ArrayList<NameValuePair>();
        paraList.add(new BasicNameValuePair("name",name));
        paraList.add(new BasicNameValuePair("email",email));
        paraList.add(new BasicNameValuePair("mobile",mobile));
        paraList.add(new BasicNameValuePair("dob",dob));
        paraList.add(new BasicNameValuePair("password",password));
        paraList.add(new BasicNameValuePair("gender",gender));

        try{
            HttpClient httpClient=new DefaultHttpClient();
            HttpPost req=new HttpPost("http://172.16.6.142/register.php");
            req.setEntity(new UrlEncodedFormEntity(paraList));
            httpClient.execute(req);
            Toast.makeText(getApplicationContext(),"Inserted Successfully",Toast.LENGTH_LONG).show();
        }
        catch(Exception e1){
            Log.e("Error1", e1.toString());
            Toast.makeText(getApplicationContext(),e1.toString(),Toast.LENGTH_LONG).show();
            Toast.makeText(getApplicationContext(),"Please Check your Ip address",Toast.LENGTH_LONG).show();
        }
    }
    public EditText Name;
    public EditText EmailId;
    public EditText Password;
    public EditText confirmPassword;
    public RadioButton Gender;
    public DatePicker DOB;
    public EditText Mobile;
}
