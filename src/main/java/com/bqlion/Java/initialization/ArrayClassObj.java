package com.bqlion.Java.initialization;
import  java.util.*;
import net.mindview.util.Print.*;
//初始化一个非基本类型的数组
import static net.mindview.util.Print.print;

public class ArrayClassObj {
    public static void main(String[] args) {
        Random rand = new Random(47);
        Integer a[] = new Integer[rand.nextInt(20)];            //创造了一个Integer 型数组，长度是Raddom.nextInt20
        print("length of array a is " + a.length);

        for(int i = 0;i < a.length; i++)

            a[i] = rand.nextInt(500);
         print(Arrays.toString(a));

    }
}
