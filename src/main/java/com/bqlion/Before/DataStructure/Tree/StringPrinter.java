package com.bqlion.Before.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/5/19
 */
public class StringPrinter {


    public void print(String s){
        // 确认结束条件
        if(s.length() == 1) System.out.println(s);
        // 减小规模 ，进行递归
        print(s.substring(1));
        System.out.println(s.charAt(0));
    }



    public static void main(String[] args) {

        StringPrinter stringPrinter= new StringPrinter();
        stringPrinter.print("ABCDEF");


    }

}
