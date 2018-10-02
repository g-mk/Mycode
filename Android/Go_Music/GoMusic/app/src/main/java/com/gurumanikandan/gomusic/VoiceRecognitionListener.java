package com.gurumanikandan.gomusic;

import android.os.Bundle;
import android.speech.RecognitionListener;
import android.speech.SpeechRecognizer;
import android.util.Log;
import java.util.ArrayList;
import static com.gurumanikandan.gomusic.PlayerFragment.*;

/**
 * Created by Guru Manikandan on 23-09-2017.
 */

public class VoiceRecognitionListener implements RecognitionListener {

    @Override
    public void onReadyForSpeech(Bundle bundle) {
        isListening = true;
        Log.d("GURU","Ready");
    }

    @Override
    public void onBeginningOfSpeech() {
        Log.d("GURU","Begin");
    }

    @Override
    public void onRmsChanged(float v) {

    }

    @Override
    public void onBufferReceived(byte[] bytes) {

    }

    @Override
    public void onEndOfSpeech() {
        Log.d("GURU","End");
    }

    @Override
    public void onError(int i) {
        isListening = false;
        String error = getErrorText(i);
        Log.d("GURU","ERROR: "+error);
    }

    @Override
    public void onResults(Bundle bundle) {
        ArrayList<String> matches = bundle
                .getStringArrayList(SpeechRecognizer.RESULTS_RECOGNITION);
        String command = matches.get(0);
        command = command.toLowerCase();
        isListening =false;
        if(command!=null) {
            if(isCommandOn) {
                if (command.equals(COMMAND_PLAY))
                    play();
                else if (command.equals(COMMAND_PAUSE))
                    pause();
                else if (command.equals(COMMAND_STOP))
                    stop();
                else if (command.equals(COMMAND_NEXT))
                    next();
                else if (command.equals(COMMAND_PREVIOUS))
                    previous();
                else if (command.equals(COMMAND_FORWARD))
                    nextLongClick();
                else if (command.equals(COMMAND_BACKWARD))
                    previousLongClick();
                else if (command.equals(COMMAND_SHUFFLE_ON))
                    shuffleOn();
                else if (command.equals(COMMAND_SHUFFLE_OFF))
                    shuffleOff();
                else if (command.equals(COMMAND_REPEAT_ON))
                    repeatOn();
                else if (command.equals(COMMAND_REPEAT_OFF))
                    repeatOff();
                else if(command.equals(COMMAND_OFF))
                    isCommandOn = false;
            }
            if(command.equals(COMMAND_ON))
                isCommandOn = true;
        }else
            Log.d("GURU","Error");
        Log.d("GURU",command);

    }

    @Override
    public void onPartialResults(Bundle bundle) {
        Log.d("GURU","Partial");
    }

    @Override
    public void onEvent(int i, Bundle bundle) {

    }

    public static String getErrorText(int errorCode) {
        String message;
        switch (errorCode) {
            case SpeechRecognizer.ERROR_AUDIO:
                message = ERROR_AUDIO_TEXT;
                break;
            case SpeechRecognizer.ERROR_CLIENT:
                message = ERROR_CLIENT_TEXT;
                break;
            case SpeechRecognizer.ERROR_INSUFFICIENT_PERMISSIONS:
                message = ERROR_INSUFFICIENT_PERMISSIONS_TEXT;
                break;
            case SpeechRecognizer.ERROR_NETWORK:
                message = ERROR_NETWORK_TEXT;
                break;
            case SpeechRecognizer.ERROR_NETWORK_TIMEOUT:
                message = ERROR_NETWORK_TIMEOUT_TEXT;
                break;
            case SpeechRecognizer.ERROR_NO_MATCH:
                message = ERROR_NO_MATCH_TEXT;
                break;
            case SpeechRecognizer.ERROR_RECOGNIZER_BUSY:
                message = ERROR_RECOGNIZER_BUSY_TEXT;
                break;
            case SpeechRecognizer.ERROR_SERVER:
                message = ERROR_SERVER_TEXT;
                break;
            case SpeechRecognizer.ERROR_SPEECH_TIMEOUT:
                message = ERROR_SPEECH_TIMEOUT_TEXT;
                break;
            default:
                message = ERROR_NOTHING;
                break;
        }
        return message;
    }
    private static boolean isCommandOn = false;
    private static final String ERROR_AUDIO_TEXT ="Audio recording error";
    private static final String ERROR_CLIENT_TEXT ="Client side error";
    private static final String ERROR_INSUFFICIENT_PERMISSIONS_TEXT ="Insufficient permissions";
    private static final String ERROR_NETWORK_TEXT ="Network error";
    private static final String ERROR_NETWORK_TIMEOUT_TEXT ="Network timeout";
    private static final String ERROR_NO_MATCH_TEXT ="No match";
    private static final String ERROR_RECOGNIZER_BUSY_TEXT = "RecognitionService busy";
    private static final String ERROR_SERVER_TEXT = "Error From Server";
    private static final String ERROR_SPEECH_TIMEOUT_TEXT = "No Speech Input";
    private static final String ERROR_NOTHING = "Didn't understand, please try again.";
    private static final String COMMAND_PLAY = "play";
    private static final String COMMAND_PAUSE = "freeze";
    private static final String COMMAND_STOP = "stop";
    private static final String COMMAND_NEXT = "next";
    private static final String COMMAND_PREVIOUS = "previous";
    private static final String COMMAND_FORWARD = "forward";
    private static final String COMMAND_BACKWARD = "backward";
    private static final String COMMAND_REPEAT_ON = "repeat on";
    private static final String COMMAND_REPEAT_OFF = "repeat of";
    private static final String COMMAND_SHUFFLE_ON = "shuffle on";
    private static final String COMMAND_SHUFFLE_OFF = "shuffle of";
    private static final String COMMAND_ON = "voice command on";
    private static final String COMMAND_OFF = "voice command of";

}
