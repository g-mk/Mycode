package com.example.gurumanikandan.discussionfourm;

/**
 * Created by Guru Manikandan on 12-08-2017.
 */

public class User {

    public User() {
        Name = "";
        eMailId = "";
        Password = "";
        Gender = "";
        DOB = "";
        mobile ="";
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public String geteMailId() {
        return eMailId;
    }

    public void seteMailId(String eMailId) {
        this.eMailId = eMailId;
    }

    public String getPassword() {
        return Password;
    }

    public void setPassword(String password) {
        Password = password;
    }

    public String getGender() {
        return Gender;
    }

    public void setGender(String gender) {
        Gender = gender;
    }

    public String getDOB() {
        return DOB;
    }

    public void setDOB(String DOB) {
        this.DOB = DOB;
    }

    public String getMobile() {
        return mobile;
    }

    public void setMobile(String mobile) {
        this.mobile = mobile;
    }
    private String Name;
    private String eMailId;
    private String Password;
    private String Gender;
    private String DOB;
    private String mobile;
}
