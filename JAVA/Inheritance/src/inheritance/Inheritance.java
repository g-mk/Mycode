/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package inheritance;

import java.awt.FileDialog;
import java.awt.Toolkit;
import java.awt.Window;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Stack;
import java.util.TreeSet;
import java.lang.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.imageio.ImageIO;
import javax.swing.JFileChooser;
import javax.swing.JFrame;

public class Inheritance {
    public static void zigzag(int [][] mat)
    {
        int m = mat.length;
        int length = m*m;
        int [] val = new int[length];
        int turn = 0;
        int i=0,j=0;
        int n=0;
        int temp = mat[0][0];
        while(n<length)
        {
            try{
                val[n++] = temp;
                if(turn%2==0){
                    i--;j++;
                }
                else{
                    i++;j--;
                }
                temp = mat[i][j];
            }catch(ArrayIndexOutOfBoundsException ex)
            {
                if(i<0)
                {
                    i++;
                    j = Math.min(j,m-1);
                }
                else if(j<0)
                {
                    i = Math.min(i,m-1);
                    j++;
                }
                temp = mat[i][j];
                turn++;
            }
        }
        for (int k = 0; k < val.length; k++) {
            System.out.print(val[k] +" ");
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ArrayList<Integer> zigzag = new ArrayList<>();
        int mat[][] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        zigzag(mat);
    }

}
