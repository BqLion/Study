package com.bqlion.After.DataStruct.Sort;

import java.util.ArrayList;

public class quickSort {

    public static void quickSort(int[] arr,int low,int high){
        int i,j,temp,t;
        if(low > high) {
            return;
        }
        i = low;
        j = high;
        temp  = arr[low];


        while(i < j){
            while(temp <=arr[j] && i < j){
                j--;
            }

            while(temp>=arr[i] && i < j){
                i++;
            }

            if(i < j){
                t  =arr[j];
                arr[j] = arr[i];
                arr[i] = t;
            }
        }
        //左右指针依次往中间移动,遇见符合条件的数字就互换所指对象
        //直到左右指针相遇,将基准与相遇处对象互换

        arr[low]  = arr[i];
        arr[i] = temp;

        quickSort(arr,low,j - 1);
        quickSort(arr,j+1,high);
    }


    public static void main(String[] args) {
        int[] arr = {10,7,4,3,5,6,7,8,5,5};
        quickSort(arr,0,arr.length-1);
        for(int i = 0;i < arr.length;i++)
            System.out.println(arr[i]);
    }
}

