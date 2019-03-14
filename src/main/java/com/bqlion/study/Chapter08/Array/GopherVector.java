package com.bqlion.study.Chapter08.Array;
import java.util.*;

class Gopher{
    private int gopherNumber;
    Gopher(int i){
        gopherNumber = i;
    }
    void print(String msg){
        if(msg != null)System.out.println(msg);
        System.out.println(
                "Gopher number " + gopherNumber);
    }
}

class GopherTrap{
    static void caughtYa(Gopher g){
        g.print("Caught one!");
    }
}

public class GopherVector {
    private Vector v = new Vector();            //设置为private的集合类 v，如果想添加元素需要通过
    public void addElement(Gopher m ){          //addElement 这个函数添加，此函数可过滤非期望类型
        v.addElement(m);                        //多了一道过滤，不会出现把狗添加进猫类的错误
    }
    public Gopher elementAt(int index){
        return(Gopher)v.elementAt(index);
    }
    public int size(){return v.size();}

    public static void main(String[] args) {
        GopherVector gophers = new GopherVector();
        for(int i = 0; i < 3; i++)
            gophers.addElement(new Gopher(i));
        for(int i = 0; i < gophers.size(); i++)
            GopherTrap.caughtYa(gophers.elementAt(i));
    }
}
