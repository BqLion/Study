package com.bqlion.Before.Java.Chapter07;

public class Parcel6 {
    public Contents cont(){
        return new Contents(){          //匿名内部类
            private  int i = 11;        //返回的是一个contents，但是同时又定义了额外的变量和函数
            public int value(){return i;}   //等于
        };                                  //class newContents extends Contents
    }                                       //private int i =11;
                                            //public int value(){return i;}
                                            //return new newContents();
    public static void main(String[] args) {
        Parcel6 p = new Parcel6();
        Contents c = p.cont();
    }
}
