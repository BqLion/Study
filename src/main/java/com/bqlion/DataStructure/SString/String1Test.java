package com.bqlion.DataStructure.SString;

public class String1Test {
    public static void main(String[] args) {
        System.out.println(" ");
        char[] chars = {'a', 'b', 'c', 'd', 'e'};    //数组的初始化用{a,b,c,d,e}
        String1 str = new String1(chars);
        chars[0] = 'y';
        str = str.concat(str.substring(1, 3));
        System.out.println(str.toString());
    }
    }

