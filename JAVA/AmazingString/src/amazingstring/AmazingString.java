/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amazingstring;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author Guru Manikandan
 */
public class AmazingString {
    static int[] minimalOperations(String[] words) {
        int op[] = new int [words.length];
        int index=0;
        for(String word: words)
        {
            int count=0;
            char [] letter = word.toCharArray();
            for(int i=0;i<letter.length-1;i++)
            {
                if(letter[i] == letter[i+1])
                {
                    letter[i++] = '-';
                    count++;
                }
            }
            op[index++]=count;
        }
        return op;
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int res[];
        int n;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        String words[] = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = scan.next();
        }
        res = minimalOperations(words);
        for (int i = 0; i < n; i++) {
            System.out.println(res[i]);
        }

    }
    
}
