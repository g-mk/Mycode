package com.gurumanikandan.gomusic;

import android.content.Context;
import android.graphics.Bitmap;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by Guru Manikandan on 10-09-2017.
 */

public class AlbumListAdapter extends ArrayAdapter<String> {

    ArrayList<Bitmap> albumBitMaps;
    public AlbumListAdapter(@NonNull Context context, @NonNull ArrayList<String> album, ArrayList<Bitmap> bitmaps) {
        super(context,0, album);
        albumBitMaps = bitmaps;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        if(convertView == null)
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.album_row_layout, parent, false);
        TextView albumName = (TextView)convertView.findViewById(R.id.title);
        ImageView albumArt = (ImageView)convertView.findViewById(R.id.imgAlbumArt);
        albumArt.setImageBitmap(albumBitMaps.get(position));
        albumName.setText(getItem(position));
        return convertView;
    }
}
