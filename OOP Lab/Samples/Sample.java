import java.io.*;
import java.util.*;
public class Sample
{
    public static void main(String agrs[])
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int [] a = new int [n];
        for(int i=0;i<a.length;i++)
            a[i]=in.nextInt();
        System.out.println("Enter the no to find : ");
        int key = in.nextInt();
        System.out.println("At pposition "+ Arrays.binarySearch(a,2,4,key));
        //a.sort;
        int i=0;
        for(int j:a)
            System.out.println("value "+ ++i +" "+ j);
        System.out.println("Hello World" + n);
    }
}
