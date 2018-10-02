/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package expressioncheck;

import java.util.Scanner;
import java.util.Stack;

/**
 *
 * @author Guru Manikandan
 */
public class ExpressionCheck {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String operators = "+-*/";
        Scanner scan = new Scanner(System.in);
        boolean valid = true;
        String exp = scan.nextLine();
        Stack<Character> s = new Stack<>();
        for (int i = 0; valid && i < exp.length(); i++) {
            char token = exp.charAt(i);
            if(token=='(')
                s.push(token);
            else if(operators.contains(token+""))
            {
                s.push(token);
                char next = (i<exp.length()-1)?exp.charAt(i+1):token;
                if(operators.contains(next+"") || next == ')' )
                    valid = false;
            }
            else if(token == ')')
            {
                char out='\0';
                while(!s.isEmpty() && (out = s.pop())!='(' );
                if(out!='(')
                    valid = false;
            }
            else
                s.push(token);
        }
        if(valid)
            System.out.println("Valid Expression");
        else
            System.out.println("Not a Valid Expression");
    }
    
}
