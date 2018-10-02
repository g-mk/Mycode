/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package election;

import java.lang.reflect.Array;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
/**
 *
 * @author Guru Manikandan
 */
public class Election {

  static String electionWinner(String[] votes) {
      //TreeMap is just like Hash Map but the value will be in ascending order
        TreeMap<String,Integer> t = new TreeMap<String,Integer>();
        for (String vote : votes) {
            if(!t.containsKey(vote))
                t.put(vote, 1);
            else
                t.replace(vote, t.get(vote)+1);
        }
        System.out.println(t);
        int max = 0;
        String Winner= "";
        //Tree Set is the collection of Distinct values which will also be in ascending order
        TreeSet<String> Winners = new TreeSet<String>();
        for(String name:t.keySet())
        {
            int val = t.get(name);
            if(val>max)
                max = val;
        }
        for(String name:t.keySet())
        {
            int val = t.get(name);
            if(val==max)
                Winners.add(name);
        }
        return Winners.last();
    }


    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String []vote = {"Guru","Mani","Mani","Guru","Kandan"};
        String Result = electionWinner(vote);
        System.out.println(Result);
    }

}
