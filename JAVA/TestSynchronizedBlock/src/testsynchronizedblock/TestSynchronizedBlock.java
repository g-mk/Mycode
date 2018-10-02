/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testsynchronizedblock;

class Table {

    void printTable(int n) {
        System.out.println(Thread.currentThread().getName() + " "+ Thread.currentThread().getState());
        synchronized (this) {//synchronized block  
            for (int i = 1; i <= 10; i++) {
                System.out.println(Thread.currentThread().getName() + " "+ Thread.currentThread().getState());
                System.out.println(n * i);
                try {
                    Thread.sleep(400);
                } catch (Exception e) {
                    System.out.println(e);
                }
            }
        }
        System.out.println(Thread.currentThread().getName() + " "+ Thread.currentThread().getState());
    }//end of the method  
}

class TableFiveThread extends Thread {

    Table t;
    TableFiveThread(Table t) {
        this.t = t;
    }

    public void run() {
        t.printTable(5);
    }

}

class TableTenThread extends Thread {

    Table t;
    TableTenThread(Table t) {
        this.t = t;
    }

    public void run() {
        t.printTable(10);
    }
}

/**
 *
 * @author Guru Manikandan
 */
public class TestSynchronizedBlock {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Table table = new Table();
        TableFiveThread fiveTable = new TableFiveThread(table);
        TableTenThread tenThread = new TableTenThread(table);
        fiveTable.start();
        tenThread.start();
    }

}
