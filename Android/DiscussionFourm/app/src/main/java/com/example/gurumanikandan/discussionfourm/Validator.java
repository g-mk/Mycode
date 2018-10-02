package com.example.gurumanikandan.discussionfourm;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Guru Manikandan on 20-08-2017.
 */

public class Validator {
    public static boolean checkText(String Val)
    {
        Pattern mailPatter = Pattern.compile("^[a-z0-9]+\\@[a-z]+\\.[a-z.]+$");
        Matcher matchMail = mailPatter.matcher(Val);
        return matchMail.matches();
    }
    public static boolean checkPassword(String Val)
    {
        Pattern passwordPattern = Pattern.compile("^(?=.*[\\d])(?=.*[a-z])(?=.*[A-Z])(?=.*[!@#$%^&*])[\\w!@#$%^&*]{6,}$");
        Matcher matchPassword = passwordPattern.matcher(Val);
        return matchPassword.matches();
    }

}
