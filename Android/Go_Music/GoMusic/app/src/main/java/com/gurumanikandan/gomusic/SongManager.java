package com.gurumanikandan.gomusic;

import android.content.ContentResolver;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.MediaMetadataRetriever;
import android.net.Uri;
import android.provider.MediaStore;
import android.support.v4.app.FragmentActivity;
import java.util.ArrayList;
import java.util.Set;
import java.util.TreeMap;

/**
 * Created by Guru Manikandan on 10-09-2017.
 */

public final class SongManager {

    private FragmentActivity currentActivity;

    public SongManager(FragmentActivity activity){
        currentActivity = activity;
    }

    public TreeMap<String,ArrayList<Song>> getAllMusic()
    {
        TreeMap<String,ArrayList<Song>> songList = new TreeMap<String,ArrayList<Song>>();
        ContentResolver contentResolver = currentActivity.getContentResolver();
        Uri songUri = MediaStore.Audio.Media.EXTERNAL_CONTENT_URI;
        Cursor songCursor = contentResolver.query(songUri,null,null,null,null);
        if(songCursor != null && songCursor.moveToFirst()){
            int songAlbum = songCursor.getColumnIndex(MediaStore.Audio.Media.ALBUM);
            int songTitle = songCursor.getColumnIndex(MediaStore.Audio.Media.TITLE);
            int songArtist = songCursor.getColumnIndex(MediaStore.Audio.Media.ARTIST);
            int songPath = songCursor.getColumnIndex(MediaStore.Audio.Media.DATA);
            do{
                Song song = new Song();
                song.setAlbum(songCursor.getString(songAlbum));
                song.setTitle(songCursor.getString(songTitle));
                song.setArtist(songCursor.getString(songArtist));
                song.setPath(songCursor.getString(songPath));
                if(songList.get(song.getAlbum())==null){
                    ArrayList<Song> list = new ArrayList<>();
                    list.add(song);
                    songList.put(song.getAlbum(),list);
                }
                else
                    songList.get(song.getAlbum()).add(song);
            }while(songCursor.moveToNext());
        }
        return songList;
    }
    public ArrayList<String>getAllAlbum(){
        TreeMap<String,ArrayList<Song>> songList = getAllMusic();
        return setToArrayList(songList.keySet());
    }
    public ArrayList<Song>getAlbum(String album){
        TreeMap<String,ArrayList<Song>> songList = new TreeMap<String,ArrayList<Song>>();
        songList = getAllMusic();
        for(String curAlbum:songList.keySet()){
            if(!curAlbum.equals(album))
                continue;
            return songList.get(curAlbum);
        }
        return null;
    }

    public Song getSongInAlbum(String album,int loc)
    {
       ArrayList<Song> songList = new ArrayList<Song>();
        songList = getAlbum(album);
            if(songList.size()>=loc)
                return songList.get(loc);
        return null;
    }
    public static ArrayList<String> setToArrayList(Set<String> set)
    {
        ArrayList<String> list = new ArrayList<>();
        for (String val:set)
            list.add(val);
        return list;
    }
    public Bitmap getAlbumArtWithAlbum(String album)
    {
        MediaMetadataRetriever metadataRetriever = new MediaMetadataRetriever();
        ArrayList<Song> songList = getAlbum(album);
        metadataRetriever.setDataSource(songList.get(0).getPath());
        byte []art = metadataRetriever.getEmbeddedPicture();
        Bitmap songImage = BitmapFactory.decodeByteArray(art,0,art.length);
        return songImage;
    }
    public Bitmap getAlbumArtWithPath(String path)
    {
        MediaMetadataRetriever metadataRetriever = new MediaMetadataRetriever();
        metadataRetriever.setDataSource(path);
        byte []art = metadataRetriever.getEmbeddedPicture();
        Bitmap songImage = BitmapFactory.decodeByteArray(art,0,art.length);
        return songImage;
    }
    public  ArrayList<TreeMap<String, String>> getTitleandPathFromAlbum(String album)
    {
        ArrayList<TreeMap<String, String>> songList = new  ArrayList<TreeMap<String, String>>();
        ArrayList<Song> albumSongList = getAlbum(album);
        for (Song curSong : albumSongList) {
            TreeMap<String, String> song = new TreeMap<>();
            song.put("TITLE", curSong.getTitle());
            song.put("PATH", curSong.getPath());
            songList.add(song);
        }
        return songList;
    }
}
