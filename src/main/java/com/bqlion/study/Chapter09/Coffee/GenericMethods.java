package com.bqlion.study.Chapter09.Coffee;

public class GenericMethods {
    public <T>void f(T x){          //泛型函数，函数参数的类型没有指定
        System.out.println(x.getClass().getName());
    }

    public static void main(String[] args) {
        GenericMethods gm = new GenericMethods();
        gm.f(" ");
        gm.f(1);
        gm.f(1.0);
        gm.f(1.0F);
        gm.f('c');
        gm.f(gm);

    }
}
