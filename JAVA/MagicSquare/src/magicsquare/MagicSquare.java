/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package magicsquare;

import java.util.Scanner;

/**
 *
 * @author Guru Manikandan
 */
public class MagicSquare {
    public static boolean checkArray(int[] arr,int[] arr1)
    {
        if(arr[0]!=arr1[0])
            return false;
        for (int i = 0; i < arr.length-1; i++) {
            if(arr[i]!=arr[i+1] && arr1[i]!=arr1[i+1])
                return false;
        }
        return true;
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the Matrix Dimension");
        int n = scan.nextInt();
        int mat[][] = new int [n][n];
        int row[] = new int[n];
        int col[] = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = scan.nextInt();
                row[i] +=mat[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                col[i] +=mat[j][i];
            }
        }
        if(checkArray(col,row))
            System.out.println("Magic Square");
        else
            System.out.println("Not a Magic Square");
    }
    
}
