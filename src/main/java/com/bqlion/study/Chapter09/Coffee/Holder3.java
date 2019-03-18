package com.bqlion.study.Chapter09.Coffee;

public class Holder3<T>{
    private T a;
    public Holder3(T a){this.a = a; }           //this表示Holder类的成员变量
    public void set(T a){this.a = a; }
    public T get(){return a; }

    public static void main(String[] args) {
        Holder3<Automobile>h3 =
                new Holder3<Automobile>(new Automobile());
        Automobile a = h3.get();
    }
}

