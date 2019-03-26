package com.bqlion.study.initialization;
//函数名相同参数也相同的重载用函数的参数顺序来区分
import net.mindview.util.Print.*;

import static net.mindview.util.Print.print;

public class OverloadingOrder {
    static void f(String s,int i){
        print("String1 :" + s + " , int : " + i);
    }
    static void f(int i,String s){
        print("int :" + i + " .  int : " + s);
    }

    public static void main(String[] args) {
        f("String1 first",11);
        f(22,"Int first");
    }
}
