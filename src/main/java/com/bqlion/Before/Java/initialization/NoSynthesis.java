package com.bqlion.Before.Java.initialization;

class Bird2{
    Bird2(int i){}
    Bird2(double d){}               //一个类下的两个不同重载方法。
}

public class NoSynthesis {
    public static void main(String[] args) {
        Bird2  b2 = new Bird2(1);
        Bird2  b3 = new Bird2(1.2);
    }
}
