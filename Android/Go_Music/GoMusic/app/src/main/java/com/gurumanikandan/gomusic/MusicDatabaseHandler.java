package com.gurumanikandan.gomusic;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteStatement;
import android.util.Log;
import java.util.ArrayList;
import java.util.TreeMap;

/**
 * Created by Guru Manikandan on 25-09-2017.
 */

public class MusicDatabaseHandler extends SQLiteOpenHelper {


    public MusicDatabaseHandler(Context context)
    {
        super(context,DATABASE_NAME,null,1);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        String createPlaylistTable = "CREATE TABLE "+PLAYLIST_TABLE_NAME+" ( "+PLAYLIST_COLUMN_NAME+" VARCHAR(20) );";
        String createSongListTable = "CREATE TABLE "+ SONG_LIST_TABLE_NAME +" ( "+SONG_LIST_COLUMN_ID+" INTEGER PRIMARY KEY AUTOINCREMENT, "+ SONG_LIST_COLUMN_TITLE +" VARCHAR(30), " +
                SONG_LIST_COLUMN_PATH +" VARCHAR(90), "+ SONG_LIST_COLUMN_PLAYLIST +" VARCHAR(20)," +
                " FOREIGN KEY("+ SONG_LIST_COLUMN_PLAYLIST +") REFERENCES "+PLAYLIST_TABLE_NAME+"("+PLAYLIST_COLUMN_NAME+"));" ;
        sqLiteDatabase.execSQL(createPlaylistTable);
        sqLiteDatabase.execSQL(createSongListTable);

    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

    }
    public boolean checkPlaylist(String name)
    {
        boolean retStatus = true;
        try {
            SQLiteDatabase sqLiteDatabase = this.getReadableDatabase();
            String query = "SELECT * FROM " + PLAYLIST_TABLE_NAME + " WHERE " + PLAYLIST_COLUMN_NAME + " = '" + name + "';";
            Cursor cur = sqLiteDatabase.rawQuery(query, null);
            retStatus = cur.moveToNext();
        }catch (Exception ex) {
            Log.d("Guru",ex.getMessage());
        }finally {
         return retStatus;
        }

    }
    public String addPlaylist(String name)
    {
        String retVal = "";
        SQLiteDatabase sqLiteDatabase=null;
        SQLiteStatement stmt=null;
        if(!checkPlaylist(name)) {
            try {
                String query = "INSERT INTO " + PLAYLIST_TABLE_NAME + " VALUES (?);";
                sqLiteDatabase = this.getWritableDatabase();
                stmt = sqLiteDatabase.compileStatement(query);
                stmt.bindString(1, name);
                if (stmt.executeInsert() > 0)
                    retVal = ADD_PLAYLIST_SUCCES;
                else
                    retVal = ADD_PLAYLIST_FAILED;
            }catch(Exception ex) {

                Log.d("GURU",ex.getMessage());
            }
            finally {
                stmt.close();
                sqLiteDatabase.close();
            }
        }
        else
            retVal = ADD_PLAYLIST_AVAILABLE;
        return retVal;
    }
    public ArrayList<String> getAllPlaylist(){
        ArrayList<String> playlist = new ArrayList<>();
        SQLiteDatabase sqLiteDatabase = null;
        Cursor cur = null;
        try {
            sqLiteDatabase = this.getWritableDatabase();
            String query = "SELECT * FROM " + PLAYLIST_TABLE_NAME + ";";
            cur = sqLiteDatabase.rawQuery(query, null);
            while (cur.moveToNext()) {
                playlist.add(cur.getString(cur.getColumnIndex(PLAYLIST_COLUMN_NAME)));
            }
        }catch (Exception ex){
            Log.d("GURU",ex.getMessage());
        }
        finally {
            sqLiteDatabase.close();
            cur.close();
            return playlist;
        }
    }
    public int addSongsToPlaylist(ArrayList<Song> songs,String playlist){
        int statCount=0;
        String query = "INSERT INTO "+SONG_LIST_TABLE_NAME+"("+SONG_LIST_COLUMN_TITLE+","+SONG_LIST_COLUMN_PATH+","+SONG_LIST_COLUMN_PLAYLIST+") VALUES (?,?,?);";
        SQLiteDatabase sqLiteDatabase=null;
        SQLiteStatement stmt=null;
        try{
            sqLiteDatabase = this.getWritableDatabase();
            for(Song song:songs) {
                stmt = sqLiteDatabase.compileStatement(query);
                stmt.clearBindings();
                stmt.bindString(1, song.getTitle());
                stmt.bindString(2,song.getPath());
                stmt.bindString(3,playlist);
                if(stmt.executeInsert()>0)
                    statCount++;
                stmt.close();
            }
        }catch (Exception ex) {
            Log.d("GURU",ex.getMessage());
        }
        finally {
            sqLiteDatabase.close();
            return statCount;
        }
    }
    public String removePlaylist(String playlist){
        String retVal=null;
        String queryClearPlaylist = "DELETE FROM "+SONG_LIST_TABLE_NAME+" WHERE "+SONG_LIST_COLUMN_PLAYLIST+" = '"+playlist+"';";
        String queryRemovePlaylist = "DELETE FROM "+PLAYLIST_TABLE_NAME+" WHERE "+PLAYLIST_COLUMN_NAME+" = '"+playlist+"';";
        SQLiteDatabase sqLiteDatabase = null;
        try{
            sqLiteDatabase = this.getWritableDatabase();
            SQLiteStatement stmt = sqLiteDatabase.compileStatement(queryClearPlaylist);
            stmt.executeUpdateDelete();
            stmt.close();
            stmt = sqLiteDatabase.compileStatement(queryRemovePlaylist);
            if(stmt.executeUpdateDelete()>0)
                retVal = REMOVE_PLAYLIST_SUCCES;
            else
                retVal = REMOVE_PLAYLIST_FAILED;
            stmt.close();
        }catch (Exception ex){
            Log.d("GURU",ex.getMessage());
        }
        finally {
            sqLiteDatabase.close();
        }
        return retVal;
    }
    public ArrayList<TreeMap<String, String>> getPlaylist(String playlist){
        ArrayList<TreeMap<String, String>> songList = new ArrayList<TreeMap<String, String>>();
        String query = "SELECT * FROM "+SONG_LIST_TABLE_NAME+" WHERE "+SONG_LIST_COLUMN_PLAYLIST+" ='"+
                playlist+"';";
        SQLiteDatabase sqLiteDatabase = null;
        try{
            sqLiteDatabase = this.getWritableDatabase();
            Cursor cur = sqLiteDatabase.rawQuery(query,null);
            while(cur.moveToNext()){
                TreeMap<String, String> song = new TreeMap<>();
                song.put("TITLE", cur.getString(cur.getColumnIndex(MusicDatabaseHandler.SONG_LIST_COLUMN_TITLE)));
                song.put("PATH", cur.getString(cur.getColumnIndex(MusicDatabaseHandler.SONG_LIST_COLUMN_PATH)));
                songList.add(song);
            }
        }catch (Exception ex){
            Log.d("GURU",ex.getMessage());
        }
        finally {
            sqLiteDatabase.close();
            return songList;
        }
    }
    public String removeSongFromPlaylist(long index){
        String retVal="";
        String query = "DELETE FROM "+SONG_LIST_TABLE_NAME+" WHERE "+SONG_LIST_COLUMN_ID+" IN ( SELECT "+
                SONG_LIST_COLUMN_ID+" FROM "+SONG_LIST_TABLE_NAME+" LIMIT 1 OFFSET ?);";
        SQLiteDatabase sqLiteDatabase = null;
        SQLiteStatement stmt = null;
        try {
            sqLiteDatabase = this.getWritableDatabase();
            stmt = sqLiteDatabase.compileStatement(query);
            stmt.bindLong(1,index);
            int stat = stmt.executeUpdateDelete();
            if(stat>0)
                retVal = REMOVE_SONG_SUCCES;
            else
                retVal = REMOVE_SONG_FAILED;
        }catch (Exception ex){
            Log.d("GURU",ex.getMessage());
        }
        finally {
            stmt.close();
            sqLiteDatabase.close();
            return retVal;
        }
    }
    public static final String DATABASE_NAME = "music.db";
    public static final String PLAYLIST_TABLE_NAME = "playlist";
    public static final String PLAYLIST_COLUMN_NAME = "name";
    public static final String SONG_LIST_TABLE_NAME = "songs_list";
    public static final String SONG_LIST_COLUMN_ID = "id";
    public static final String SONG_LIST_COLUMN_TITLE = "title";
    public static final String SONG_LIST_COLUMN_PATH = "path";
    public static final String SONG_LIST_COLUMN_PLAYLIST = "playlist";
    public static final String ADD_PLAYLIST_SUCCES = "Playlist created successfully";
    public static final String REMOVE_PLAYLIST_SUCCES = "Playlist removed successfully";
    public static final String REMOVE_SONG_SUCCES = "Song removed from the playlist";
    public static final String ADD_PLAYLIST_FAILED = "Playlist not created";
    public static final String REMOVE_PLAYLIST_FAILED = "Playlist not removed";
    public static final String REMOVE_SONG_FAILED = "Song not removed from the playlist";
    public static final String ADD_PLAYLIST_AVAILABLE = "Playlist already available";

}
