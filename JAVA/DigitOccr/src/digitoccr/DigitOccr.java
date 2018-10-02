/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package digitoccr;

import java.util.Scanner;

/**
 *
 * @author Guru Manikandan
 */
public class DigitOccr {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(new Scanner(System.in).nextLine());
        int occr[] = new int[10];
        while(scan.hasNext())
        {
            int val = scan.nextInt();
            occr[val]++;
        }
        
        for (int i = 0; i < 10; i++) {
            System.out.print(i+"\t");
            for (int j = 0; j < occr[i]; j++) {
                System.out.print("*");
            }
            System.out.print("\n");
        }
    }
    
}
