package com.gurumanikandan.gomusic;


import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AlertDialog;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;


/**
 * A simple {@link Fragment} subclass.
 */
public class PlayListFragment extends Fragment {


    MusicDatabaseHandler musicDatabaseHandler;
    ListView playlistView;
    public PlayListFragment() {
        // Required empty public constructor
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             final Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view= inflater.inflate(R.layout.fragment_play_list, container, false);
        ImageButton imageButton = (ImageButton)view.findViewById(R.id.btnCreatePlayList);
        final TextView createLable = (TextView)view.findViewById(R.id.txtCreatePlayList);
        imageButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                createPlaylist(savedInstanceState);
            }
        });
        createLable.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                createPlaylist(savedInstanceState);
            }
        });
        musicDatabaseHandler = new MusicDatabaseHandler(getContext());
        playlistView = (ListView)view.findViewById(R.id.playListView);
        updatePlaylist();
        playlistView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                TextView Playlist = (TextView)view.findViewById(R.id.txtPlayList);
                PlayListSongFragment fragment = new PlayListSongFragment();
                Bundle args = new Bundle();
                args.putString("Playlist",Playlist.getText().toString());
                fragment.setArguments(args);
                FragmentTransaction fragmentTransaction = getFragmentManager().beginTransaction();
                fragmentTransaction.replace(R.id.frame, fragment, "PlayListSongFragment").addToBackStack("fragBack");
                fragmentTransaction.addToBackStack(null);
                fragmentTransaction.commit();
            }
        });
        playlistView.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> adapterView, final View view, int i, long l) {
                new AlertDialog.Builder(getContext())
                        .setTitle("Playlist")
                        .setMessage("Do you want to delete the playlist?")
                        .setIcon(android.R.drawable.ic_input_delete)
                        .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int whichButton) {
                                TextView playlistName = (TextView)view.findViewById(R.id.txtPlayList);
                                String stat = musicDatabaseHandler.removePlaylist(playlistName.getText().toString());
                                Toast.makeText(getContext(), stat,Toast.LENGTH_LONG).show();
                                updatePlaylist();
                            }})
                        .setNegativeButton("No", null).show();
                return true;
            }
        });
        return view;
    }

    public void updatePlaylist()
    {
        ArrayList<String> playlist = musicDatabaseHandler.getAllPlaylist();
        if(playlist.size()>0) {
            PlayListAdapter arrayAdapter = new PlayListAdapter(getContext(),playlist);
            playlistView.setAdapter(arrayAdapter);
        }
    }
    public void createPlaylist(Bundle savedInstanceState)
    {
        AlertDialog.Builder builder = new AlertDialog.Builder(getContext());
        final View mView = getLayoutInflater(savedInstanceState).inflate(R.layout.dialog_create_playlist,null);
        builder.setView(mView);
        final AlertDialog dialog = builder.create();
        final TextView playlistName = (TextView)mView.findViewById(R.id.txtPlaylistName);
        playlistName.setOnFocusChangeListener(new View.OnFocusChangeListener() {
            @Override
            public void onFocusChange(View view, boolean b) {
                if(playlistName.getText().toString().equals(""))
                    playlistName.setError("Enter Playlist Name");
            }
        });
        Button createButton = (Button)mView.findViewById(R.id.btnAddPlaylist);
        createButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(playlistName.getError()==null)
                {
                    String name = playlistName.getText().toString();
                    String status = musicDatabaseHandler.addPlaylist(name);
                    Toast.makeText(getContext(), status,Toast.LENGTH_LONG).show();
                    if(status.equals(MusicDatabaseHandler.ADD_PLAYLIST_SUCCES)) {
                        dialog.dismiss();
                        updatePlaylist();
                    }
                }
            }
        });
        dialog.show();
    }
}
