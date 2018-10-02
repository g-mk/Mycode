package com.gurumanikandan.gomusic;

/**
 * Created by Guru Manikandan on 10-09-2017.
 */

public class Song {

    public String getAlbum() {
        return Album;
    }

    public void setAlbum(String album) {
        Album = album;
    }

    public String getArtist() {
        return Artist;
    }

    public void setArtist(String artist) {
        Artist = artist;
    }

    public String getTitle() {
        return Title;
    }

    public void setTitle(String title) {
        Title = title;
    }
    public String getPath() {
        return Path;
    }

    public void setPath(String path) {
        Path = path;
    }
    private String Album;
    private String Artist;
    private String Title;
    private String Path;
}
