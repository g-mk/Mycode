/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pushzero;

/**
 *
 * @author Guru Manikandan
 */
public class PushZero {

    public static int[] pushZeroRight(int array[])
    {
        int n = array.length;
        int beg=0;
        for (int i = 0; i < n; i++) {
            if(array[i]!=0)
                array[beg++] = array[i];
        }
        while(beg<n)
            array[beg++] = 0;
        return array;
    }
   public static int[] pushZeroLeft(int [] array)
   {
       int n = array.length;
       int end = n-1;
       for (int i = end; i >=0; i--) {
           if(array[i]!=0)
               array[end--] = array[i];
       }
       while(end>=0)
           array[end--]=0;
       return array;
   }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int arr[] = {1,3,2,0,3,0,0,0,5,6,0,3,6};
        arr = pushZeroRight(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
//        arr = pushZeroLeft(arr);
//        for (int i = 0; i < arr.length; i++) {
//            System.out.print(arr[i]+" ");
//        }
        
    }
    
}
