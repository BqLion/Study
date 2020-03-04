package src.main.java.com.bqlion.After.DataStruct.Sort;

import java.util.ArrayList;
import java.util.Arrays;

/* *
 * Created by BqLion on 2019/11/10
 */
public class countSort {

    public static void main(String[] args) {
        int[] arr = {2,4,5,6,7,4,6,7,8,9,4,3,2,2};
        int[] result  = sort(arr);
        System.out.println(Arrays.toString(result));
    }


        public  static int[] sort(int[] arr){
        int[] result = new int[arr.length];
        int[] count = new int[10];
        for(int i = 0; i < arr.length;i++){
            count[arr[i]]++;
        }
        System.out.println(Arrays.toString(count));
        for(int i = 0,j= 0;i <count.length;i++){
            while(count[i]-- > 0)result[j++] = i;
        }
        return  result;
    }



}
