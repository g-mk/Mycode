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
public class SongFragment extends Fragment {

    private MusicDatabaseHandler musicDatabaseHandler;
    private SongManager songManager;
    private String album;
    public SongFragment() {

    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             final Bundle savedInstanceState) {
        musicDatabaseHandler = new MusicDatabaseHandler(getContext());
        songManager = new SongManager(getActivity());
        Bundle args = this.getArguments();
        album = args.getString("album");
        View v =inflater.inflate(R.layout.fragment_song, container, false);
        SongManager songManager = new SongManager(getActivity());
        final ListView List = (ListView)v.findViewById(R.id.songList);
        final ArrayList<Song> arrayList = songManager.getAlbum(album);
        ArrayList<String> arr = new ArrayList<>();
        ArrayList<Bitmap> bitmaps = new ArrayList<>();
        for (Song curSong: arrayList) {
            arr.add(curSong.getTitle());
            bitmaps.add(songManager.getAlbumArtWithPath(curSong.getPath()));
        }
        final SongListAdapter adapter = new SongListAdapter(getContext(),arr,bitmaps);
        List.setAdapter(adapter);
        List.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                PlayerFragment fragment = new PlayerFragment();
                Bundle args = new Bundle();
                PlayerFragment.stop();
                args.putString("Album",album);
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
                TextView albumTitle = (TextView) view.findViewById(R.id.title);
                final int loc = i;
                new AlertDialog.Builder(getContext())
                        .setTitle("Playlist")
                        .setMessage("Add to Playlist?")
                        .setIcon(android.R.drawable.ic_input_add)
                        .setPositiveButton("Existing", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int whichButton) {
                                promptForPlaylist(savedInstanceState, album, loc);
                            }
                        })
                        .setNegativeButton("New", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                try {
                                    PlayListFragment fragment = new PlayListFragment();
                                    FragmentTransaction fragmentTransaction = getFragmentManager().beginTransaction();
                                    fragmentTransaction.replace(R.id.frame, fragment, "PlayListFragment").addToBackStack("fragBack");
                                    fragmentTransaction.commit();
                                } catch (Exception ex) {
                                    Log.d("GURU", ex.getMessage());
                                }
                            }
                        }).show();
                return true;
            }
        });

        return v;
    }
    public void promptForPlaylist(Bundle savedInstanceState, final String album,final int loc)
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
                            .setMessage("Do you want to add the Song to "+playlist+" ?")
                            .setIcon(android.R.drawable.ic_input_add)
                            .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int whichButton) {
                                    if(addSongToPlaylist(playlist,album,loc)>0)
                                        playlistDialog.cancel();
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
    public int addSongToPlaylist(String playlist,String album,int loc){
        Song curSong = songManager.getSongInAlbum(album,loc);
        ArrayList<Song> songs = new ArrayList<Song>();
        songs.add(curSong);
        int count = musicDatabaseHandler.addSongsToPlaylist(songs,playlist);
        if(count>0)
            Toast.makeText(getContext(),count +" Songs are added to "+playlist,Toast.LENGTH_LONG).show();
        else
            Toast.makeText(getContext(),"Some Error has occured. Please try again sometimes!!!",Toast.LENGTH_LONG).show();
        return count;
    }
}
