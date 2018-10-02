/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication25;

import java.util.ArrayList;
import java.util.Collection;
import java.util.TreeMap;
import java.util.TreeSet;

/**
 *
 * @author Guru Manikandan
 */
public class JavaApplication25 {
    /*static int[] sort(int [] nums)
    {
        for(int i=0;i<nums.length;i++)
        {
            for(int j=1;j<nums.length-i;j++)
            {
                if(nums[j-1]>nums[j])
                {
                    int temp = nums[j-1];
                    nums[j-1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums;
    }*/
    static int[] counts(int[] nums, int[] maxes) {
        int count;
        int [] out = new int[maxes.length];
        TreeMap<Integer,Integer> number = new TreeMap<Integer,Integer>();
        for(int num:nums)
        {
            if(!number.containsKey(num))
                number.put(num, 1);
            else
            {
                int repeat = 1+number.get(num);
                number.replace(num, repeat);
            }
        }
        for(int j=0;j<maxes.length;j++)
        {
            count=0;
            for (int val : number.keySet()) {
                if(val<=maxes[j])
                   count+=number.get(val);
                else
                    break;
            }
            out[j]=count;
        }
        return out;
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int [] num = {2,1,5,4,6,6};
        int [] max = {5,3};
        for(int i : counts(num, max))
            System.out.println(i);
    }
    
}
