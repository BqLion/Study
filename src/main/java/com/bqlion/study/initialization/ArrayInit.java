package com.bqlion.study.initialization;
import java.util.*;

public class ArrayInit {
    public static void main(String[] args) {
        Integer a[] = {
                new Integer(1),
                new Integer(2),
                3,
        };
        Integer b[] = new Integer[]{
                new Integer(1),
                new Integer(2),
                3,
        };
        System.out.print(Arrays.toString(a));
        System.out.print(Arrays.toString(b));
    }
}
