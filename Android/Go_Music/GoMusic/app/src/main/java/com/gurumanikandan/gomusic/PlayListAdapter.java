package com.gurumanikandan.gomusic;

import android.content.Context;
import android.graphics.Bitmap;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by Guru Manikandan on 01-10-2017.
 */

public class PlayListAdapter extends ArrayAdapter<String> {

    public PlayListAdapter(@NonNull Context context, @NonNull ArrayList<String> playlist) {
        super(context,0, playlist);
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        if(convertView == null)
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.playlist_layout, parent, false);
        TextView playlistName = (TextView)convertView.findViewById(R.id.txtPlayList);
        playlistName.setText(getItem(position));
        return convertView;
    }
}
