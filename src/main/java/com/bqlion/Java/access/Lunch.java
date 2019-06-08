package com.bqlion.Java.access;

class Soup {
    private Soup() {}                                //private函数只有类内部可以访问（如下函数makeSoup）

    public static Soup makeSoup() {                 //public makeSoup 类外函数可访问，可由此函数跳转到Soup
        return new Soup();
    }

    private static Soup ps1 = new Soup();
    public static Soup access() {
        return ps1;
    }
    public void f() {}
}
    class Sandwich{
    void f(){new Lunch();}
    }

    public class Lunch {
    void test(){
        Soup priv2 = Soup.makeSoup();
        Sandwich f1 = new Sandwich();
        Soup.access().f();
    }
}
