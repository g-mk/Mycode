/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package emmasquare;

import java.util.Scanner;

/**
 *
 * @author Guru Manikandan
 */
public class EmmaSquare {
    static int[] getMinimumUniqueSum(String[] arr) {
        int ret[] = new int[arr.length];
        int index=0;
        for(String in:arr)
        {
            Scanner scan = new Scanner(in);
            int a = scan.nextInt();
            int b = scan.nextInt();
            int count = 0;
            for(int i = a;i<=b;i++)
            {
                double val = Math.sqrt(i);
                int floor = (int)val;
                if(i==floor*floor)
                {
                    count++;
                    i +=(floor<<1);
                }
                    
                    
            }
            ret[index++] = count;
        }
        return ret;
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    }
    
}
