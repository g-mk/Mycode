/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testsynchronizationmethod;

class Table {

    synchronized void printTable(int n) {//synchronized method  
        for (int i = 1; i <= 10; i++) {
            System.out.println(n * i);
            try {
                Thread.sleep(400);
            } catch (Exception e) {
                System.out.println(e);
            }
        }

    }
}

class MyThread1 extends Thread {

    Table t;

    MyThread1(Table t) {
        this.t = t;
    }

    public void run() {
        t.printTable(5);
    }

}

class MyThread2 extends Thread {

    Table t;

    MyThread2(Table t) {
        this.t = t;
    }

    public void run() {
        t.printTable(7);
    }
}

/**
 *
 * @author Guru Manikandan
 */
public class TestSynchronizationMethod {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Table table = new Table();
        Table table1 = new Table();
        MyThread1 myThread1 = new MyThread1(table);
        MyThread2 myThread2 = new MyThread2(table1);
        myThread1.start();
        myThread2.start();
    }

}
