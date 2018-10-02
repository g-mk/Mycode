/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package findduplicates;

import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author Guru Manikandan
 */
public class FindDuplicates {

    public static int findDuplicate(String str)
    {
        Set<Character> set = new HashSet<Character>();
        for (char c : str.toCharArray()) {
            if(!set.add(c))
                System.out.println("Duplicate Character is "+ c);
        }
        return str.length()-set.size();
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String s = "Guru Manikandan";
        System.out.println(findDuplicate(s));
        
        
    }
    
}
