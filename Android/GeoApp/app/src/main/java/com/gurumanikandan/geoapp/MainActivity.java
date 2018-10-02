package com.gurumanikandan.geoapp;

import android.location.Address;
import android.location.Geocoder;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import java.io.IOException;
import java.util.List;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void getAddress(View view)
    {
        EditText txtLatitude = (EditText)findViewById(R.id.txtLatitude);
        EditText txtLongitude = (EditText)findViewById(R.id.txtLongitude);
        double latitude = Double.parseDouble(txtLatitude.getText().toString());
        double longitude = Double.parseDouble(txtLongitude.getText().toString());
        Geocoder geocoder = new Geocoder(getApplicationContext(),Locale.UK);
        List<Address> locations = null;
        try {
            locations = geocoder.getFromLocation(latitude,longitude,1);
            if(locations.size()!=0)
            {
                String address = "Address: "+ locations.get(0).getAddressLine(0) +",";
                address += locations.get(0).getAddressLine(1)+"\n";
                String country = "Country: "+ locations.get(0).getCountryName();
                Toast.makeText(getApplicationContext(),address+"\n"+country,Toast.LENGTH_LONG).show();
            }
            else {
                Toast.makeText(getApplicationContext(),"Not Available",Toast.LENGTH_LONG).show();
            }
        } catch (IOException e) {
            Toast.makeText(getApplicationContext(),e.getMessage(),Toast.LENGTH_LONG).show();
        }

    }
    public void getLatLong(View view)
    {
        EditText txtAddress = (EditText)findViewById(R.id.txtLoaction);
        EditText txtLatitude = (EditText)findViewById(R.id.txtLatitude);
        EditText txtLongitude = (EditText)findViewById(R.id.txtLongitude);
        String location = String.valueOf(txtAddress.getText());
        Geocoder geocoder = new Geocoder(getApplicationContext(), Locale.getDefault());
        List<Address> locations = null;
        try{
            locations = geocoder.getFromLocationName(location,1);
            if(locations.size()!=0){
                txtLatitude.setText(locations.get(0).getLatitude()+"");
                txtLongitude.setText(locations.get(0).getLongitude()+"");
            }
            else {
                Toast.makeText(getApplicationContext(),"Not Available",Toast.LENGTH_LONG).show();
            }
        } catch (IOException e) {
            Toast.makeText(getApplicationContext(),e.getMessage(),Toast.LENGTH_LONG).show();
        }
    }
}
