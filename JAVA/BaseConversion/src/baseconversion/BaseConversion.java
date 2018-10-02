/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package baseconversion;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author Guru Manikandan
 */
public class BaseConversion {
    public static ArrayList<Integer> convertToBinary(int to ,int number)
    {
        ArrayList<Integer> converted = new ArrayList<Integer>();
        while(number>0)
        {
            int rem = number%to;
            converted.add(rem);
            number /= to;
        }
        return converted;
    }
    public static int convertToDecimal(int number,int base)
    {
        int val = 0,i=0;
            while(number!=0)
            {
                int mod = number%10;
                val += mod*Math.pow(base,i);
                number/=10;
                i++;
            }
            return val;
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        String input;
        System.out.print("Enter the base of the number: ");
        int base = scan.nextInt();
        System.out.print("Enter the number: ");
        scan.nextLine();
        input = scan.nextLine();
        int number = Integer.parseInt(input, base);
        System.out.print("Enter the to base number to convert: ");
        int toBase  = scan.nextInt();
        ArrayList<Integer> con;
        //System.out.println(Integer.toString(number, base));
        if(base==10)
        {    con = convertToBinary(toBase, number);
            for (int i = con.size()-1; i >=0 ; i--) {
                int val = con.get(i);
                if(val<10)
                    System.out.print(val);
                else
                    System.out.print((char)('A'+(val%10)));
                 //System.out.print((val<10)?val:(char)('A'+(val%10)));
            }
        }
        else if(toBase==10)
        {
            System.out.println("Decimal Value is "+number);
        }
        else
        {
            int val = convertToDecimal(number, base);
            con = convertToBinary(toBase, number);
            for (int i = con.size()-1; i >=0 ; i--) {
                int num = con.get(i);
                if(num<10)
                    System.out.print(num);
                else
                    System.out.print((char)('A'+(num%10)));
                 //System.out.print((val<10)?val:(char)('A'+(val%10)));
            }
        }
    }
    
}
