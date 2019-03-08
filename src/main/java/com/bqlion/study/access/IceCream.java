package com.bqlion.study.access;
class Sundae{
    private Sundae(){}          //private的圣代函数禁止类外成员调用他，用普通的构造器new也不行
    static Sundae makeASundae(){
    return new Sundae();        //必须使用类名.圣代同名函数来调用之，
    }
}
public class IceCream {
    public static void main(String[] args) {
        Sundae x = Sundae.makeASundae();
    }
}
