/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bitoperation;

/**
 *
 * @author Guru Manikandan
 */
public class BitOperation {
    static int maxXor(int left, int right, int k) {
        int max = 0;
        for(int i = left;i<=right;i++)
        {
            for(int j=i+1;j<=right;j++)
            {
                int localmax = i^j;
                if(max<localmax && localmax <=k)
                    max = localmax;
                    
            }
        }
        return max;

    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        System.out.println(maxXor(2, 4, 8));
    }
    
}
