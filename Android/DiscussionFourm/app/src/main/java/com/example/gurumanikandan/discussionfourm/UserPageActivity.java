package com.example.gurumanikandan.discussionfourm;

import android.Manifest;
import android.content.ActivityNotFoundException;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.support.annotation.NonNull;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v4.app.ActivityCompat;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AlertDialog;
import android.util.Log;
import android.view.View;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Date;
public class UserPageActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {
    private User curUser;
    public DatabaseHandler databaseHandler;
    private static final int INTERNET_ACCESS = 100;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_page);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                try {
                    Snackbar.make(view, databaseHandler.postQueries("What is your Name?", curUser.getName()), Snackbar.LENGTH_LONG)
                            .setAction("Action", null);
                }catch (Exception ex)
                {
                    Log.d("GURU",ex.getMessage());
                }
            }
        });
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.setDrawerListener(toggle);
        toggle.syncState();
        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);
        Bundle b = getIntent().getExtras();
        String uname = b.getString("uName");
        String email = b.getString("uMail");
        databaseHandler = new DatabaseHandler(getApplicationContext());
        curUser=databaseHandler.getDetails(email);
        View header=navigationView.getHeaderView(0);
        TextView name = (TextView)header.findViewById(R.id.name);
        TextView mail =  (TextView)header.findViewById(R.id.mail);
        name.setText(uname);
        mail.setText(email);
    }

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.user_page, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if(id == R.id.action_changepass)
        {
           AlertDialog.Builder builder = new AlertDialog.Builder(UserPageActivity.this);
            final View mView = getLayoutInflater().inflate(R.layout.dialog_change_password,null);
            builder.setView(mView);
            final AlertDialog dialog = builder.create();
            final EditText oPassword = (EditText)mView.findViewById(R.id.txtOPassword);
            final EditText nPassword = (EditText)mView.findViewById(R.id.txtNPassword);
            final EditText cnPassword = (EditText)mView.findViewById(R.id.txtCNPassword);
            Button changePass = (Button)mView.findViewById(R.id.btnChangePass);
            oPassword.setOnFocusChangeListener(new View.OnFocusChangeListener() {
                @Override
                public void onFocusChange(View view, boolean b) {
                    if(oPassword.getText().toString().equals(""))
                        oPassword.setError("Enter Old Password");
                }
            });
            nPassword.setOnFocusChangeListener(new View.OnFocusChangeListener() {
                @Override
                public void onFocusChange(View view, boolean b) {
                    String Val = nPassword.getText().toString();
                    if(Val.equals(""))
                        nPassword.setError("Field should not be Empty");
                    else if(Val.length()<6)
                        nPassword.setError("Password length should be greater than 5");
                    else if(!Validator.checkPassword(Val))
                        nPassword.setError("Password should contain at least one Upper,Lower,Numeric and Symbol Character");
                }
            });
            cnPassword.setOnFocusChangeListener(new View.OnFocusChangeListener() {
                @Override
                public void onFocusChange(View view, boolean b) {
                    String npassword = nPassword.getText().toString();
                    String cnpassword = cnPassword.getText().toString();
                    if(!npassword.equals(cnpassword))
                        cnPassword.setError("Password Mismatch");
                }
            });
            changePass.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    if(cnPassword.getError()==null && nPassword.getError()==null && oPassword.getError()==null)
                    {
                        if(oPassword.getText().toString().equals(curUser.getPassword()))
                        {
                            curUser.setPassword(nPassword.getText().toString());
                            String stat = databaseHandler.changePassword(curUser);
                            Toast.makeText(getApplicationContext(), stat, Toast.LENGTH_SHORT).show();
                            if(stat.equals(DatabaseHandler.CHANGE_PASS_SUCCESS))
                            {
                                checkInternet();
                                dialog.dismiss();
                            }
                            else
                            {
                                oPassword.setText("");
                                nPassword.setText("");
                                cnPassword.setText("");
                            }
                        }
                        else
                        {
                            Toast.makeText(getApplicationContext(), "Password Incorrect",
                                    Toast.LENGTH_SHORT).show();
                        }
                    }
                }
            });
            dialog.show();
        } else if (id == R.id.action_deactivate) {
            new AlertDialog.Builder(this)
                    .setTitle("Deactivate")
                    .setMessage("Are you sure?")
                    .setIcon(android.R.drawable.ic_dialog_alert)
                    .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int whichButton) {
                            String stat = databaseHandler.deleteUser(curUser);
                            Toast.makeText(getApplicationContext(),stat,Toast.LENGTH_LONG).show();
                            if(stat.equals(DatabaseHandler.DACTV_SUCCESS))
                                logout();
                        }})
                    .setNegativeButton(android.R.string.no, null).show();
        }else if (id == R.id.action_logout)
        {
            new AlertDialog.Builder(this)
                    .setTitle("Logout")
                    .setMessage("Do you really want to Logout?")
                    .setIcon(android.R.drawable.ic_dialog_alert)
                    .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int whichButton) {
                            logout();
                        }})
                    .setNegativeButton("No", null).show();
        }
        return super.onOptionsItemSelected(item);
    }
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        switch (requestCode) {
            case INTERNET_ACCESS: {
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    sendMailAlert();
//                    sendMailThroughApp();
                } else {
                    Log.d(getApplicationContext().toString(),"Error in Permissions");
                }
            }

        }

    }
    public void checkInternet()
    {
        if (ContextCompat.checkSelfPermission(UserPageActivity.this,
                Manifest.permission.INTERNET)
                != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(UserPageActivity.this,
                    new String[]{Manifest.permission.INTERNET}, INTERNET_ACCESS);
        }
        else
            sendMailAlert();
//        sendMailThroughApp();
    }
    private void sendMailAlert() {
        String Subject = "Discussion Forum Alert";
        String Body = "Dear "+curUser.getName()+",\n";
        Body+="\tYour Account Password Has been Changed on "+new Date().toString()
                +".\nIf You find this as suspicious account access then recover it immediately.";
        try {
            GMailSender sender = new GMailSender("theycallmegm300796@gmail.com", "GuruMk@30796");
            sender.sendMail(Subject,
                    Body, "theycallmegm300796@gmail.com",curUser.geteMailId());
        } catch (Exception e) {
            Log.e("SendMail", e.getMessage(), e);
        }
    }
    public void sendMailThroughApp(){
        String Subject = "Discussion Forum Alert";
        String Body = "Dear "+curUser.getName()+",\n";
        Body+="\tYour Account Password Has been Changed on "+new Date().toString()
                +".\nIf You find this as suspicious account access then recover it immediately.";
        Intent mailIntent = new Intent(Intent.ACTION_SEND);
        mailIntent.setType("text/plain");
        mailIntent.putExtra(Intent.EXTRA_EMAIL,new String[]{curUser.geteMailId()});
        mailIntent.putExtra(Intent.EXTRA_SUBJECT,Subject);
        mailIntent.putExtra(Intent.EXTRA_TEXT,Body);
        try{
            startActivity(Intent.createChooser(mailIntent,"Alert"));
        }catch(ActivityNotFoundException ex)
        {
            Toast.makeText(this,"Alert Can't done through Mail",Toast.LENGTH_LONG).show();
        }
    }
    public void logout()
    {
        Intent i = new Intent(UserPageActivity.this,LoginActivity.class);
        Bundle b = getIntent().getExtras();
        b.clear();
        startActivity(i);
        finish();
    }
    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        // Handle navigation view item clicks here.
        int id = item.getItemId();
        if (id == R.id.nav_home) {
            setTitle("Discussion Forum");
            HomeFragment fragment = new HomeFragment();
            FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();
            fragmentTransaction.replace(R.id.frame,fragment,"HomeFragment");
            fragmentTransaction.commit();
        }
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }
}
