/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package patternprint;

import java.util.Scanner;

/**
 *
 * @author Guru Manikandan
 */
public class PatternPrint {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int out;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < n-i; j++) {
                System.out.print(" ");
            }
            int loop = 2*i+1;
            out = n-i+1;
            while(out<=n)
                System.out.print(out++);
            System.out.print("0");
            for (int j = 0; j < loop/2; j++) {
                System.out.print(--out);
            }
            System.out.print("\n");
        }
    }
    
}
