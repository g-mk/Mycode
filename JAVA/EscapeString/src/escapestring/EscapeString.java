/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package escapestring;

/**
 *
 * @author Guru Manikandan
 */
public class EscapeString {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String input = "\nab\bsi\rha";
        char [] token = input.toCharArray();
        for (int i = 0; i < token.length; i++) {
            System.out.print(token[i]);
        }
    }
    
}
