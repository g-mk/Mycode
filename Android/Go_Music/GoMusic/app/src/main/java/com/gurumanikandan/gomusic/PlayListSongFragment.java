package com.gurumanikandan.gomusic;


import android.content.DialogInterface;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AlertDialog;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.TreeMap;


/**
 * A simple {@link Fragment} subclass.
 */
public class PlayListSongFragment extends Fragment {
    MusicDatabaseHandler musicDatabaseHandler;
    private ListView List;
    private String playlist;
    private SongManager songManager;
    public PlayListSongFragment() {

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        Bundle args = this.getArguments();
        playlist = args.getString("Playlist");
        View v =inflater.inflate(R.layout.fragment_song, container, false);
        musicDatabaseHandler = new MusicDatabaseHandler(getContext());
        songManager = new SongManager(getActivity());
        List = (ListView)v.findViewById(R.id.songList);
        updatePlaylistSong();
        List.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                PlayerFragment.stop();
                Bundle args = new Bundle();
                args.putString("Album",null);
                args.putString("Playlist",playlist);
                args.putString("SongIndex",i+"");
                PlayerActivity.playerFragment.setArguments(args);
                FragmentTransaction fragmentTransaction = getFragmentManager().beginTransaction();
                fragmentTransaction.replace(R.id.frame, PlayerActivity.playerFragment, "PlayerFragment").addToBackStack("fragBack");
                fragmentTransaction.addToBackStack(null);
                fragmentTransaction.commit();
            }
        });
        List.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> adapterView, View view, int i, long l) {
                final long index = (long)i;
                new AlertDialog.Builder(getContext())
                        .setTitle("Playlist")
                        .setMessage("Do you want to remove this song from the playlist?")
                        .setIcon(android.R.drawable.ic_input_delete)
                        .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int whichButton) {
                                String stat = musicDatabaseHandler.removeSongFromPlaylist(index);
                                Toast.makeText(getContext(),stat,Toast.LENGTH_LONG).show();
                                updatePlaylistSong();
                            }})
                        .setNegativeButton("No", null).show();
                return true;
            }
        });
        return v;
    }

    private void updatePlaylistSong() {
        ArrayList<TreeMap<String, String>> songList = musicDatabaseHandler.getPlaylist(playlist);
        ArrayList<String> arr = new ArrayList<>();
        ArrayList<Bitmap> bitmaps = new ArrayList<>();
        for (TreeMap<String,String> song: songList) {
            arr.add(song.get("TITLE"));
            bitmaps.add(songManager.getAlbumArtWithPath(song.get("PATH")));
        }
        final SongListAdapter adapter = new SongListAdapter(getContext(),arr,bitmaps);
        List.setAdapter(adapter);
    }

}
