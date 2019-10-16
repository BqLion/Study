package com.bqlion.Java.Chapter07;
//可传递参数的匿名内部类
public class Parcel7 {
    public Wapping warp(int x){
        return new Wapping(x){          //return后边跟了一个大括号里边多出了一些新的值和函数
            public int value(){         //
                return super.value()*47;
            }
        };
    }

    public static void main(String[] args) {
        Parcel7 p = new Parcel7();      //先NEW了一个Parcel7对象
        Wapping w = p.warp(10);      //匿名类的父类wapping new一个新对象 w = Parcel7对象.warp函数（10）。
    }                                   //warp函数返回 匿名类的对象 newWarpping extends warpping
}
