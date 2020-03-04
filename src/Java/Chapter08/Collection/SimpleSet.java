package com.bqlion.Before.Java.Chapter08.Collection;
import java.util.*;

public class SimpleSet {
    public static void main(String[] args) {
        Set<Integer> c = new HashSet<Integer>();
        for(int i = 0; i < 10; i++)
            c.add(i);
        for(Integer i : c)
            System.out.println(i+ " , ");
    }
}
