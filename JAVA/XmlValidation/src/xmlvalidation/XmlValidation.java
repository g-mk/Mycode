/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package xmlvalidation;

import java.util.Scanner;
import java.util.Stack;

/**
 *
 * @author Guru Manikandan
 */
public class XmlValidation {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Stack<String> s = new Stack<>();
        String tag="";
        Scanner scan = new Scanner(System.in);

            String string = scan.nextLine();
                for(int i=0;i<string.length();i++)
                {
                    if(string.charAt(i)=='<')
                    {
                        tag=string.substring(i,i=string.indexOf('>'));
                        tag+=">";
                        s.push(tag); 
                    }
                }
                System.out.println(s);                

    }
    
}
