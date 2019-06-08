package com.bqlion.Java.Chapter09.Coffee;
import net.mindview.util.*;
import net.mindview.util.FourTuple;
import net.mindview.util.ThreeTuple;
import net.mindview.util.TwoTuple;

public class Tuple {
    public <A,B> net.mindview.util.TwoTuple<A,B> tuple(A a, B b){        //第一个<A,B>代表泛型函数的参数列表，第二个<A,B>是函数类型
        return new TwoTuple<A,B>(a,b);
    }

    public static<A,B,C> net.mindview.util.ThreeTuple<A,B,C> tuple(A a, B b, C c){
        return new ThreeTuple<A,B,C>(a,b,c);
    }

    public static<A,B,C,D> net.mindview.util.FourTuple<A,B,C,D> tuple(A a, B b, C c, D d){
        return new FourTuple<A,B,C,D>(a,b,c,d);
    }

    public static<A,B,C,D,E> FiveTuple<A,B,C,D,E>tuple(A a,B b,C c,D d,E e){
        return new FiveTuple<A,B,C,D,E>(a,b,c,d,e);
    }
}
