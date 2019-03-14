package com.bqlion.study.Chapter08.Collection;
import java.util.*;

public class SimpleCollection {
    public static void main(String[] args) {
        Collection<Integer> c = new ArrayList<Integer>();       //Collection限定为储存Interger的容器。用ArrayList表示
        for(int i = 0; i < 10; i++)
            c.add(i);
        for(Integer i : c)
            System.out.println(i+ " , ");
    }
}
