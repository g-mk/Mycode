/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package passagemanipulation;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

/**
 *
 * @author Guru Manikandan
 */
public class PassageManipulation {
    public static boolean isVowel(char c)
    {
        String vowel = "aeiouAEIOU";
        return vowel.contains(c+"");
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String line = new String();
        StringBuilder passage = new StringBuilder();
        String newLine="";
        Scanner scan = new Scanner(System.in);
        while((line = scan.nextLine()) != null && line.length()!=0)
        {
            for (StringTokenizer stringTokenizer = new StringTokenizer(line); stringTokenizer.hasMoreTokens();) {
                String token = stringTokenizer.nextToken();
                if(isVowel(token.charAt(0)))
                    newLine += token+" ";
                else if(isVowel(token.charAt(token.length()-1)))
                {
                    StringBuilder reversed = new StringBuilder();
                    reversed.append(token);
                    reversed.reverse();
                    passage.append(reversed+" ");
                }
                else
                    passage.append(token+" ");
            }
            passage.append('\n');
        }
        System.out.println(newLine);
        System.out.println(passage);
    }
    
}
