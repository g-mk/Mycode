package com.gurumanikandan.gomusic;


import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.media.MediaPlayer;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Bundle;
import android.os.Handler;
import android.speech.RecognizerIntent;
import android.speech.SpeechRecognizer;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.ActivityCompat;
import android.support.v4.app.Fragment;
import android.support.v4.content.ContextCompat;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Random;
import java.util.TreeMap;


/**
 * A simple {@link Fragment} subclass.
 */
public class PlayerFragment extends Fragment {
    public PlayerFragment() {
        isRepeat = false;
        isShuffle = false;
        isListening = false;
        mediaPlayer = new MediaPlayer();
        util = new Utilities();
        songList = new ArrayList<TreeMap<String, String>>();
        progressHandler = new Handler();
        speechHandler = new Handler();
        mediaPlayer.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            @Override
            public void onCompletion(MediaPlayer mediaPlayer) {
                if(isRepeat){
                    playSong(songIndex);
                } else if(isShuffle){
                    Random rand = new Random();
                    int index;
                    do {
                        index = rand.nextInt(songList.size());
                    }while(index==songIndex);
                    songIndex = index;
                    playSong(songIndex);
                } else{
                    if(songIndex < (songList.size() - 1)){
                        playSong(songIndex + 1);
                        songIndex = songIndex + 1;
                    }else{
                        songIndex = 0;
                        playOrPause.setImageResource(R.drawable.ic_play);
                        progressHandler.removeCallbacks(updateTask);
                        isCompleted = true;
                    }
                }
            }
        });
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_player, container, false);
        songManager = new SongManager(getActivity());
        musicDatabaseHandler = new MusicDatabaseHandler(getContext());
        context = getContext();
        Bundle args = this.getArguments();
        playerPanel = view.findViewById(R.id.playerPanel);
        playOrPause = (ImageButton) view.findViewById(R.id.btnPlayPause);
        ImageButton next = (ImageButton) view.findViewById(R.id.btnNext);
        ImageButton previous = (ImageButton) view.findViewById(R.id.btnPrevious);
        shuffle = (ImageButton)view.findViewById(R.id.btnShuffle);
        repeat = (ImageButton)view.findViewById(R.id.btnRepeat);
        speechRecognizeToggle = (ToggleButton)view.findViewById(R.id.speechRecognition);
        curTime = view.findViewById(R.id.currectTime);
        endTime = view.findViewById(R.id.eddTime);
        albumArt = view.findViewById(R.id.albumArt);
        songTitle = view.findViewById(R.id.songTitle);
        songProgressBar = view.findViewById(R.id.seekBar);
        songProgressBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int i, boolean b) {

            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
                progressHandler.removeCallbacks(updateTask);
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                int totalDuration = mediaPlayer.getDuration();
                int currentPosition = util.progressToTimer(seekBar.getProgress(), totalDuration);
                mediaPlayer.seekTo(currentPosition);
                updateProgressBar();
            }
        });
        speechRecognizeToggle.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ConnectivityManager connectivityManager = (ConnectivityManager)getContext()
                        .getSystemService(Context.CONNECTIVITY_SERVICE);
                NetworkInfo networkInfo = connectivityManager.getActiveNetworkInfo();
                if (speechRecognizeToggle.isChecked()) {
                    if(networkInfo.isConnected()) {
                        if (checkPermission(RECORD_ACCESS))
                            startSpeechRecognition();
                    }else {
                        Toast.makeText(getContext(),"Check your Network Connectivity",Toast.LENGTH_LONG).show();
                        speechRecognizeToggle.setChecked(false);
                    }
                }
                else {
                        stopSpeechRecognition();
                }
            }
        });
        playOrPause.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                playPauseToggle();
            }
        });
        next.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                nextLongClick();
                return true;
            }
        });
        previous.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                previousLongClick();
                return true;
            }
        });
        next.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                next();
            }
        });
        previous.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                previous();
            }
        });
        shuffle.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                shuffleToggle();
            }
        });
        repeat.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                repeatToggle();
            }
        });
        String album = args.getString("Album");
        String playlist = args.getString("Playlist");
        songIndex = Integer.parseInt(args.getString("SongIndex"));
        if(album!=null) {
            toPlayAtStart = true;
            songList = songManager.getTitleandPathFromAlbum(album);
        }
        else if(playlist!=null){
            toPlayAtStart = true;
            songList = musicDatabaseHandler.getPlaylist(playlist);
        }
        else{
            toPlayAtStart = false;
            ArrayList<String> defaultAlbum = songManager.getAllAlbum();
            if(defaultAlbum.size()>0)
            songList = songManager.getTitleandPathFromAlbum(defaultAlbum.get(0));
        }
        return view;
    }

    @Override
    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        if(!mediaPlayer.isPlaying())
            playSong(songIndex);
        speechRecognizeToggle.setChecked(true);

    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        switch (requestCode) {
            case RECORD_ACCESS: {
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    startSpeechRecognition();
                } else {
                    Log.d("GURU","Error in Permissions");
                }
            }
        }
    }
    public boolean checkPermission(int PermissionCheck){
        switch(PermissionCheck) {
            case RECORD_ACCESS:
                if (ContextCompat.checkSelfPermission(getContext(),
                        Manifest.permission.RECORD_AUDIO)
                        != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(getActivity(),
                            new String[]{Manifest.permission.RECORD_AUDIO},RECORD_ACCESS);
                } else {
                    return true;
                }
                break;
        }
        return false;
    }

    // Methods for Media Player Control
    public static void playSong(int currentIndex) {
        try {
            isCompleted = false;
            if(mediaPlayer.isPlaying())
                mediaPlayer.stop();
            String path = songList.get(currentIndex).get("PATH");
            mediaPlayer.reset();
            mediaPlayer.setDataSource(path);
            albumArt.setImageBitmap(Bitmap.createScaledBitmap(songManager.getAlbumArtWithPath(path),
                    480,680,false));
            mediaPlayer.prepare();
            songProgressBar.setProgress(0);
            songProgressBar.setMax(100);
            songTitle.setText(songList.get(currentIndex).get("TITLE"));
            curTime.setText(util.milliSecondsToTimer(0));
            endTime.setText(util.milliSecondsToTimer(mediaPlayer.getDuration()));
            if(toPlayAtStart) {
                mediaPlayer.start();
                playOrPause.setImageResource(R.drawable.ic_pause);
            }
        } catch (IOException e) {
            e.printStackTrace();
            Log.d("GURU", e.getMessage());
        } finally {
            updateProgressBar();
        }
    }

    public static void play(){
        if(!mediaPlayer.isPlaying())
            playPauseToggle();
    }

    public static void pause(){
        if(mediaPlayer.isPlaying())
            playPauseToggle();
    }

    public static void stop(){
        mediaPlayer.stop();
        progressHandler.removeCallbacks(updateTask);
        songProgressBar.setProgress(0);
        curTime.setText(util.milliSecondsToTimer(0));
    }

    public static void playPauseToggle(){

        if(isCompleted)
        {
            isCompleted=false;
            playSong(songIndex);
        }
        else if (!mediaPlayer.isPlaying()) {
            mediaPlayer.start();
            playOrPause.setImageResource(R.drawable.ic_pause);
        } else {
            mediaPlayer.pause();
            playOrPause.setImageResource(R.drawable.ic_play);
        }
    }

    public static void nextLongClick(){
        int currentPosition = mediaPlayer.getCurrentPosition();

        if (currentPosition + SEEK_FORWARD_TIME <= mediaPlayer.getDuration()) {

            mediaPlayer.seekTo(currentPosition + SEEK_FORWARD_TIME);
        } else {

            mediaPlayer.seekTo(mediaPlayer.getDuration());
        }
    }

    public static void previousLongClick(){
        int currentPosition = mediaPlayer.getCurrentPosition();
        if (currentPosition - SEEK_BACKWARD_TIME >= 0)
            mediaPlayer.seekTo(currentPosition - SEEK_BACKWARD_TIME);
        else
            mediaPlayer.seekTo(0);
    }

    public static void next(){
        if(!isShuffle) {
            if (songIndex < (songList.size() - 1)) {
                playSong(++songIndex);
            } else {
                playSong(0);
                songIndex = 0;
            }
        }
        else {
            Random rand = new Random();
            int index;
            do {
                index = rand.nextInt(songList.size());
            }while(index==songIndex);
            songIndex = index;
            playSong(songIndex);
        }
    }

    public static void previous(){
        if(!isShuffle) {
            if (songIndex > 0) {
                playSong(--songIndex);
            } else {
                // play last song
                playSong(songList.size() - 1);
                songIndex = songList.size() - 1;
            }
        }
        else{
            Random rand = new Random();
            int index;
            do {
                index = rand.nextInt(songList.size());
            }while(index==songIndex);
            songIndex = index;
            playSong(songIndex);
        }
    }

    public static void shuffleOn(){
        if(!isShuffle)
            shuffleToggle();
    }

    public static void shuffleOff(){
        if(isShuffle)
            shuffleToggle();
    }

    public static void repeatOn(){
        if(!isRepeat)
            repeatToggle();
    }

    public static void repeatOff(){
        if(isRepeat)
            repeatToggle();
    }

    public static void shuffleToggle(){
        isShuffle = !isShuffle;
        if(isShuffle)
            shuffle.setImageResource(R.drawable.ic_shuffle_pressed);
        else
            shuffle.setImageResource(R.drawable.ic_shuffle_released);
    }

    public static void repeatToggle(){
        isRepeat = !isRepeat;
        if(isRepeat)
            repeat.setImageResource(R.drawable.ic_repeat_pressed);
        else
            repeat.setImageResource(R.drawable.ic_repeat_released);
    }

    // Method that assign Handler to update the seekBar Progress

    private static void updateProgressBar() {
        progressHandler.postDelayed(updateTask, 100);
    }

    // Method to Initialize the Speech Recognizer variable and Recognizer Intent

    public static void initializeSpeechRecognition(){
        Log.d("GURU","Initializing");
        try {
            if (speech != null) {
                speech.destroy();
            }
            VoiceRecognitionListener voiceRecognitionListener = new VoiceRecognitionListener();
            speech = SpeechRecognizer.createSpeechRecognizer(context);
            speech.setRecognitionListener(voiceRecognitionListener);
            recognizerIntent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
            recognizerIntent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL,
                    RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);
            recognizerIntent.putExtra(RecognizerIntent.EXTRA_LANGUAGE, Locale.getDefault());
            recognizerIntent.putExtra(RecognizerIntent.EXTRA_MAX_RESULTS, 2);
            recognizerIntent.putExtra(RecognizerIntent.EXTRA_CALLING_PACKAGE, context.getPackageName());
        }catch(Exception ex)
        {
            Log.d("GURU",ex.getMessage());
        }
    }

    // Method to start the Speech Recognition Operation

    public static void startSpeechRecognition(){
        try {
            if(speechRecognizeToggle.isChecked()) {
                speechHandler.postDelayed(callSpeechListener, 1000);
            }
            else
                speechHandler.removeCallbacks(callSpeechListener);
        } catch (Exception a) {
            Log.d("GURU",a.getMessage());
        }
    }
    public static void startRecognition(){
        try {
            speechHandler.postDelayed(callSpeechListener, 1000);
        } catch (Exception a) {
            Log.d("GURU",a.getMessage());
        }
    }

    // Method to stop the Speech Recognition Operation
    public static void stopSpeechRecognition(){
        speech.stopListening();
        speechHandler.removeCallbacks(callSpeechListener);
    }

    //Runnable variables to Handle seekBar progress and Voice Recognizer Call

    private static Runnable updateTask = new Runnable() {
        @Override
        public void run() {
            long totalDuration = mediaPlayer.getDuration();
            long currentDuration = mediaPlayer.getCurrentPosition();
            curTime.setText(util.milliSecondsToTimer(currentDuration));
            int progress = (int) (util.getProgressPercentage(currentDuration, totalDuration));
            songProgressBar.setProgress(progress);
            progressHandler.postDelayed(this, 100);
        }
    };

    private static Runnable callSpeechListener = new Runnable() {
        @Override
        public void run() {

            Log.d("GURU",isListening+"");
            if(!isListening) {
                initializeSpeechRecognition();
                speech.startListening(recognizerIntent);
            }
            speechHandler.postDelayed(this,1000);
        }
    };
    private static final int RECORD_ACCESS = 200;
    MusicDatabaseHandler musicDatabaseHandler;
    private static SpeechRecognizer speech;
    private static Intent recognizerIntent;
    private static Handler progressHandler;
    private static Handler speechHandler;
    private static Utilities util;
    private static final int SEEK_FORWARD_TIME = 10000;
    private static final int SEEK_BACKWARD_TIME = 5000;
    private static boolean isRepeat;
    private static boolean isShuffle;
    private static boolean isCompleted;
    public static boolean isListening;
    public static boolean toPlayAtStart;
    RelativeLayout playerPanel;
    private static ImageButton playOrPause;
    private static ImageButton shuffle;
    private static ImageButton repeat;
    private static ToggleButton speechRecognizeToggle;
    private static TextView curTime;
    private static TextView endTime;
    private static TextView songTitle;
    private static ImageView albumArt;
    private static MediaPlayer mediaPlayer;
    private static SeekBar songProgressBar;
    private static SongManager songManager;
    private static Context context;
    private static int songIndex;
    private static ArrayList<TreeMap<String, String>> songList;
}
