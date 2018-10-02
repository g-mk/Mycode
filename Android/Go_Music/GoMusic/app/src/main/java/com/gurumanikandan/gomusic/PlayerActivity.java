package com.gurumanikandan.gomusic;

import android.Manifest;
import android.accounts.Account;
import android.accounts.AccountManager;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
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
import android.widget.TextView;

public class PlayerActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_player);
        playerFragment = new PlayerFragment();
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        if(checkPermission(ACCOUNT_ACCESS))
            accountUpdate();
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.setDrawerListener(toggle);
        toggle.syncState();
        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);
        View header=navigationView.getHeaderView(0);
        if(account!=null);
        {
            TextView userMail = (TextView) header.findViewById(R.id.userMail);
            userMail.setText(account);
        }
        gotoPlayerFragment();
        PlayerFragment.startRecognition();
    }
    public void accountUpdate()
    {
        Account[] account = AccountManager.get(getApplicationContext()).getAccounts();
        if(account.length==0)
            Log.d("GURU","Account Empty");
            this.account = account[0].name;

    }
    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        }else {
            super.onBackPressed();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.player, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_exit) {
            new AlertDialog.Builder(this)
                    .setTitle("Exit")
                    .setMessage("Do you really want to Exit?")
                    .setIcon(android.R.drawable.ic_dialog_alert)
                    .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int whichButton) {
                            PlayerFragment.stop();
                            finish();
                        }})
                    .setNegativeButton("No", null).show();
        }

        return super.onOptionsItemSelected(item);
    }

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        // Handle navigation view item clicks here.
        int id = item.getItemId();

        if (id == R.id.nav_playlist) {
            gotoPlayListFragment();

        } else if (id == R.id.nav_album) {
            if(checkPermission(MEDIA_ACCESS))
                gotoAlbumFragment();
        }
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        switch (requestCode) {
            case MEDIA_ACCESS: {
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                } else {
                    Log.d(getApplicationContext().toString(),"Error in Permissions");
                }
            }
            break;
            case ACCOUNT_ACCESS: {
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    accountUpdate();
                } else {
                    Log.d(getApplicationContext().toString(),"Error in Permissions");
                }
            }
            break;
            case RECORD_ACCESS: {
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    PlayerFragment.startSpeechRecognition();
                } else {
                    Log.d("GURU","Error in Permissions");
                }
            }


        }
    }
    private void gotoPlayListFragment() {
        try {
            setTitle(R.string.app_name);
            PlayListFragment fragment = new PlayListFragment();
            FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();
            fragmentTransaction.replace(R.id.frame, fragment, "PlayListFragment").addToBackStack("fragBack");
            fragmentTransaction.commit();
        }
        catch(Exception ex)
        {
            Log.d("GURU",ex.getMessage());
        }
    }
    private void gotoPlayerFragment(){
        PlayerFragment fragment = new PlayerFragment();
        FragmentManager fragmentManager = getSupportFragmentManager();
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
        Bundle args = new Bundle();
        args.putString("Album", null);
        args.putString("SongIndex", 0 + "");
        fragment.setArguments(args);
        fragmentTransaction.replace(R.id.frame, fragment, "PlayerFragment").addToBackStack("fragBack");
        fragmentTransaction.commit();
    }
    private void gotoAlbumFragment() {
        try {
                setTitle(R.string.app_name);
                AlbumFragment fragment = new AlbumFragment();
                FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();
                fragmentTransaction.replace(R.id.frame, fragment, "AlbumFragment").addToBackStack("fragBack");
                fragmentTransaction.commit();
        }
        catch(Exception ex)
        {
            Log.d("GURU",ex.getMessage());
        }
    }
    public boolean checkPermission(int PermissionCheck){
        switch(PermissionCheck) {
            case MEDIA_ACCESS:
                if (ContextCompat.checkSelfPermission(PlayerActivity.this,
                        Manifest.permission.READ_EXTERNAL_STORAGE)
                        != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(PlayerActivity.this,
                            new String[]{Manifest.permission.READ_EXTERNAL_STORAGE}, MEDIA_ACCESS);
                }
                else
                    return true;
                break;
            case ACCOUNT_ACCESS:
                if (ContextCompat.checkSelfPermission(PlayerActivity.this,
                        Manifest.permission.GET_ACCOUNTS)
                        != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(PlayerActivity.this,
                            new String[]{Manifest.permission.GET_ACCOUNTS},ACCOUNT_ACCESS);
                } else {
                    return true;
                }
                break;
            case RECORD_ACCESS:
                if (ContextCompat.checkSelfPermission(this,
                        Manifest.permission.RECORD_AUDIO)
                        != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(this,
                            new String[]{Manifest.permission.RECORD_AUDIO},RECORD_ACCESS);
                } else {
                    return true;
                }
                break;
        }
        return false;
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
    }
    private static final int MEDIA_ACCESS = 100;
    private static final int ACCOUNT_ACCESS = 200;
    private static final int RECORD_ACCESS = 300;
    public static PlayerFragment playerFragment;
    private String account;
}
