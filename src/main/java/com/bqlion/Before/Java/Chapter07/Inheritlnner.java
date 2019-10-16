package com.bqlion.Before.Java.Chapter07;

class WithInner{
    class Inner{}
}

public class Inheritlnner
    extends WithInner.Inner{      //继承内部类就是 extends 外部类.内部类
    Inheritlnner(WithInner wi){     //对内部类的扩展
        wi.super();
    }

    public static void main(String[] args) {
        WithInner wi = new WithInner();
        Inheritlnner ii  = new Inheritlnner(wi);
    }
}
