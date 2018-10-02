/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package checkpalindrome;

import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author Guru Manikandan
 */
public class CheckPalindrome {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        Integer count;
        HashMap<Character,Integer> occr = new HashMap<>();
        String word = in.nextLine();
        System.out.println(word);
        for (char c: word.toCharArray() ) {
            count=0;
            if(occr.containsKey(c))
               count = occr.get(c);
            occr.put(c, ++count);
        }
        count =0;
        for(Integer val:occr.values())
        {
            if(count <3 && val%2!=0)
                count++;
        }
        if(count>1)
            System.out.println("Palindrome cannot be formed");
        else if(word.length()%2!=0 && count ==1)
            System.out.println("Palindrome can be formed");
        else
            System.out.println("Palindrome can be formed");
    }

}
