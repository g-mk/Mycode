package com.example.gurumanikandan.discussionfourm;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.database.sqlite.SQLiteStatement;

/**
 * Created by Guru Manikandan on 11-08-2017.
 */

public class DatabaseHandler extends SQLiteOpenHelper {

    public static final String DATABASE_NAME = "Database.db";
    public static final String USER_TABLE_NAME = "User_Table";
    public static final String UT_COLUMN_EMAIL = "email";
    public static final String UT_COLUMN_NAME = "name";
    public static final String UT_COLUMN_PASSWORD = "password";
    public static final String UT_COLUMN_GENDER = "gender";
    public static final String UT_COLUMN_DOB = "dob";
    public static final String UT_COLUMN_MOBILE = "mobile";
    public static final String QUERY_TABLE_NAME = "Query_Table";
    public static final String QT_COLUMN_QUERYID="query_id";
    public static final String QT_COLUMN_QUESTION = "question";
    public static final String QT_COLUMN_POSTBY = "posted_by";
    public static final String REG_SUCCESS = "Registration Successful";
    public static final String REG_FAILED = "Registration Unsuccessful";
    public static final String DACTV_SUCCESS =  "Deactivation Success";
    public static final String DACTV_FAILED ="Deactivation Failed!! Try again later!!!";
    public static final String CHANGE_PASS_SUCCESS = "Password Changed";
    public static final String CHANGE_PASS_FAILED = "Password Not Changed. Please Try Again Later!!!";
    private static final String QUERY_POST_SUCCESS = "Question Posted Successfully";
    private static final String QUERY_POST_FAILED = "Question Posted UnSuccessfully. Please Try Again Later!!!";

    public DatabaseHandler(Context context){
        super(context,DATABASE_NAME,null,1);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        String createUserTableQuery = "CREATE TABLE "+ USER_TABLE_NAME +" ( "+
                UT_COLUMN_EMAIL +" VARCHAR PRIMARY KEY, " +
                UT_COLUMN_NAME +" VARCHAR NOT NULL, " +
                UT_COLUMN_PASSWORD +" VARCHAR NOT NULL, " +
                UT_COLUMN_GENDER +" VARCHAR NOT NULL, " +
                UT_COLUMN_DOB +" DATE NOT NULL,"+
                UT_COLUMN_MOBILE +" NUMERIC );";

        String createQuestionTableQuery = "CREATE TABLE "+QUERY_TABLE_NAME+" ("+
                QT_COLUMN_QUERYID +" NUMERIC PRIMARY KEY AUTOINCREMENT, "+
                QT_COLUMN_QUESTION+" VARCHAR NOT NULL, "+
                QT_COLUMN_POSTBY +" VARCHAR NOT NULL, "+
                "FOREIGN KEY ("+QT_COLUMN_POSTBY+") REFERENCES "+USER_TABLE_NAME+"("+UT_COLUMN_NAME+"));";

        sqLiteDatabase.execSQL(createUserTableQuery);
        sqLiteDatabase.execSQL(createQuestionTableQuery);
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int older, int newer) {
        onCreate(sqLiteDatabase);
    }
    public User getDetails(String email){
        User user = new User();
        String query = "SELECT * FROM "+ USER_TABLE_NAME +" WHERE "+ UT_COLUMN_EMAIL +" = '"+email+"';";
        SQLiteDatabase sqLiteDatabase = getWritableDatabase();
        Cursor cur = sqLiteDatabase.rawQuery(query,null);
        if(cur.getCount()>0)
        {
            cur.moveToNext();
            user.setName(cur.getString(cur.getColumnIndex(UT_COLUMN_NAME)));
            user.setDOB(cur.getString(cur.getColumnIndex(UT_COLUMN_DOB)));
            user.setPassword(cur.getString(cur.getColumnIndex(UT_COLUMN_PASSWORD)));
            user.setGender(cur.getString(cur.getColumnIndex(UT_COLUMN_GENDER)));
            user.seteMailId(cur.getString(cur.getColumnIndex(UT_COLUMN_EMAIL)));
            user.setMobile(cur.getString(cur.getColumnIndex(UT_COLUMN_MOBILE)));
        }
        return user;

    }
    public boolean checkUser(String email){
        String query = "SELECT * FROM "+ USER_TABLE_NAME +" WHERE "+ UT_COLUMN_EMAIL +" = '"+email+"';";
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        Cursor cur = sqLiteDatabase.rawQuery(query,null);
        if(cur.getCount()>0)
        {
            return true;
        }
        return false;
    }
    public String checkLogin(String email, String password)
    {
        String query = "SELECT * FROM "+ USER_TABLE_NAME +" WHERE "+ UT_COLUMN_EMAIL +" = '"+email+"' AND "+
                UT_COLUMN_PASSWORD +"= '"+password+"';";
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        Cursor cur = sqLiteDatabase.rawQuery(query,null);
        if(cur.getCount()>0)
        {
            cur.moveToNext();
            return cur.getString(cur.getColumnIndex(DatabaseHandler.UT_COLUMN_NAME));
        }
        return "";
    }
    public String addUser(User user){
        String returnVal="";
        if(!checkUser(user.geteMailId())){
            String insQuery = "INSERT INTO"+ USER_TABLE_NAME +" VALUES(?,?,?,?,?,?);";
            SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
            SQLiteStatement stmt = sqLiteDatabase.compileStatement(insQuery);
            stmt.bindString(1,user.geteMailId());
            stmt.bindString(2,user.getName());
            stmt.bindString(3,user.getPassword());
            stmt.bindString(4,user.getGender());
            stmt.bindString(5,user.getDOB());
            stmt.bindString(6,user.getMobile());
            long result = stmt.executeInsert();
            if(result>0)
                returnVal = REG_SUCCESS;
            else
                returnVal = REG_FAILED;
            sqLiteDatabase.close();
        }
        else
            returnVal = "User Already Exist";
        return returnVal;
    }
    public String deleteUser(User user)
    {
        String status="";
        String insQuery = "DELETE FROM "+ USER_TABLE_NAME +" WHERE "+ UT_COLUMN_EMAIL +" = ?;";
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        SQLiteStatement stmt = sqLiteDatabase.compileStatement(insQuery);
        stmt.bindString(1,user.geteMailId());
        if(stmt.executeUpdateDelete()>0)
            status=DACTV_SUCCESS;
        else
            status=DACTV_FAILED;
        return status;
    }
    public String changePassword(User user){
        String status="";
        String insQuery = "UPDATE "+ USER_TABLE_NAME +" SET "+ UT_COLUMN_PASSWORD +" = ? WHERE "+ UT_COLUMN_EMAIL +" = ?;";
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        SQLiteStatement stmt = sqLiteDatabase.compileStatement(insQuery);
        stmt.bindString(1,user.getPassword());
        stmt.bindString(2,user.geteMailId());
        if(stmt.executeUpdateDelete()>0)
            status = CHANGE_PASS_SUCCESS;
        else
            status = CHANGE_PASS_FAILED;
        return status;
    }
    public String postQueries(String queries,String user)
    {
        String returnVal = "";
        String insQuery = "INSERT INTO "+ QUERY_TABLE_NAME +"("+QT_COLUMN_QUESTION+","+QT_COLUMN_POSTBY+") VALUES(?,?);";
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        SQLiteStatement stmt = sqLiteDatabase.compileStatement(insQuery);
        stmt.bindString(1,queries);
        stmt.bindString(2,user);
        long result = stmt.executeInsert();
        if(result>0)
            returnVal = QUERY_POST_SUCCESS;
        else
            returnVal = QUERY_POST_FAILED;
        sqLiteDatabase.close();
        return returnVal;
    }
}
