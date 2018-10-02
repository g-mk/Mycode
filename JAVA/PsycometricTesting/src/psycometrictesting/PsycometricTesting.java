/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package psycometrictesting;

import java.util.TreeSet;

/**
 *
 * @author Guru Manikandan
 */
public class PsycometricTesting {

    static int[] jobOffers(int[] scores, int[] lowerLimits, int[] upperLimits) {
        int op[] = new int[lowerLimits.length];
        TreeSet<Integer> val = new TreeSet<Integer>();
        int index = 0;
        for (int i = 0; i < lowerLimits.length; i++) {
            int count = 0;
            boolean flag = false;
            for (int score : scores) {
                if (score >= lowerLimits[i] && score <= upperLimits[i]) {
                    count++;
                }
                else if(score > upperLimits[i])
                    flag = true;
                if(flag)
                    break;
            }
            op[index++] = count;
        }
        return op;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    }

}
