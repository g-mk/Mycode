package com.gurumanikandan.gomusic;


import android.content.DialogInterface;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AlertDialog;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;


/**
 * A simple {@link Fragment} subclass.
 */
public class AlbumFragment extends Fragment {
    private SongManager songManager;
    private MusicDatabaseHandler musicDatabaseHandler;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             final Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_album, container, false);
        songManager = new SongManager(getActivity());
        musicDatabaseHandler = new MusicDatabaseHandler(getContext());
        ArrayList<String> arrayList = songManager.getAllAlbum();
        ArrayList<Bitmap> bitmaps = new ArrayList<>();
        for(String curAlbum: arrayList)
        {
            bitmaps.add(songManager.getAlbumArtWithAlbum(curAlbum));
        }
        final ListView albumList = (ListView)v.findViewById(R.id.albumList);
        AlbumListAdapter adapter = new AlbumListAdapter(getContext(),arrayList,bitmaps);
        albumList.setAdapter(adapter);
        albumList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                TextView albumTitle = (TextView)view.findViewById(R.id.title);
                SongFragment fragment = new SongFragment();
                Bundle args = new Bundle();
                args.putString("album",albumTitle.getText().toString());
                fragment.setArguments(args);
                FragmentTransaction fragmentTransaction = getFragmentManager().beginTransaction();
                fragmentTransaction.replace(R.id.frame, fragment, "SongFragment").addToBackStack("fragBack");
                fragmentTransaction.addToBackStack(null);
                fragmentTransaction.commit();

            }
        });
        albumList.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> adapterView, View view, int i, long l) {
                TextView albumTitle = (TextView)view.findViewById(R.id.title);
                final String album = albumTitle.getText().toString();
                new AlertDialog.Builder(getContext())
                        .setTitle("Playlist")
                        .setMessage("Add to Playlist?")
                        .setIcon(android.R.drawable.ic_input_add)
                        .setPositiveButton("Existing", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int whichButton) {
                                promptForPlaylist(savedInstanceState,album);
                            }})
                        .setNegativeButton("New", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                try {
                                    PlayListFragment fragment = new PlayListFragment();
                                    FragmentTransaction fragmentTransaction = getFragmentManager().beginTransaction();
                                    fragmentTransaction.replace(R.id.frame, fragment, "PlayListFragment").addToBackStack("fragBack");
                                    fragmentTransaction.commit();
                                }
                                catch(Exception ex)
                                {
                                    Log.d("GURU",ex.getMessage());
                                }
                            }
                        }).show();
                return true;
            }
        });
        return v;
    }
    public void promptForPlaylist(Bundle savedInstanceState, final String album)
    {
        AlertDialog.Builder builder = new AlertDialog.Builder(getContext());
        final View mView = getLayoutInflater(savedInstanceState).inflate(R.layout.dialog_add_to_playlist,null);
        builder.setView(mView);
        final AlertDialog playlistDialog = builder.create();
        ListView playListView = (ListView)mView.findViewById(R.id.selectPlayListView);
        ArrayList<String> playlist = musicDatabaseHandler.getAllPlaylist();
        if(playlist.size()>0) {
            ArrayAdapter adapter = new ArrayAdapter(getContext(),android.R.layout.simple_list_item_1,playlist);
            playListView.setAdapter(adapter);
            playListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                @Override
                public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                    final String playlist = ((TextView)view).getText().toString();
                    new AlertDialog.Builder(getContext())
                            .setTitle("Playlist")
                            .setMessage("Do you want to add the Album to "+playlist+" ?")
                            .setIcon(android.R.drawable.ic_input_add)
                            .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int whichButton) {
                                    addAlbumToPlaylist(playlist,album);
                                        playlistDialog.dismiss();
                                }})
                            .setNegativeButton("No", null).show();
                }
            });
            playlistDialog.show();
        }
        else{
            Toast.makeText(getContext(),"No Playlist are available. Create a new Playlist and try!!!",Toast.LENGTH_LONG).show();
        }
    }
    public int addAlbumToPlaylist(String playlist,String album){
        ArrayList<Song> songs = songManager.getAlbum(album);
        int count = musicDatabaseHandler.addSongsToPlaylist(songs,playlist);
        if(count>0)
            Toast.makeText(getContext(),count +" Songs are added to "+playlist,Toast.LENGTH_LONG).show();
        else
            Toast.makeText(getContext(),"Some Error has occured. Please try again sometimes!!!",Toast.LENGTH_LONG).show();
        return count;
    }
}
