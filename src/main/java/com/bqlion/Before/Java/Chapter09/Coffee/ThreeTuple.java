package com.bqlion.Before.Java.Chapter09.Coffee;

public class ThreeTuple<A,B,C>extends TwoTuple<A,B> {
    public  final C third;
    public ThreeTuple(A a,B b,C c){
        super(a,b);         //super是指向最近父类的指针，这里是TwoTuple(a,b);
        third = c;
    }
    public String toString(){
        return "(" + first + ", " + second + ", " + third + ")";
    }
}

