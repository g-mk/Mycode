/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thread;

import java.util.logging.Level;
import java.util.logging.Logger;
class MyRunnable implements Runnable{
    public void run(){
        
        for (int i = 0; i < 10; i++) {
            try {
            Thread.sleep(500);
        } catch (InterruptedException ex) {
            Logger.getLogger(MyRunnable.class.getName()).log(Level.SEVERE, null, ex);
        }
            System.out.println(i);
        }
    }
}

class SampleThread extends Thread
{

    @Override
    public void run() {
        
        for (int i = 0; i < 10; i++) {
            try {
            this.sleep(500);
        } catch (InterruptedException ex) {
            Logger.getLogger(SampleThread.class.getName()).log(Level.SEVERE, null, ex);
        }
            System.out.println(this.getName()+" "+i);
        }
    }
    
}
/**
 *
 * @author Guru Manikandan
 */
public class MyThread {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        SampleThread t1 = new SampleThread();
      
    }
    
}
