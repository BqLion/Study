package com.bqlion.study.Chapter08.Array;
//Simple collection wiht Enumeration
import java.util.*;

class Cat2{
    private int catNumber;
    Cat2(int i){
        catNumber  = i;
    }
    void print(){
        System.out.println("Cat number " + catNumber);
    }
}

class Dog2{
    private int dogNumber;
    Dog2(int i){
        dogNumber = i;
    }
    void print(){
        System.out.println("Dog number " + dogNumber);
    }
}


public class CatAndDogs2 {
    public static void main(String[] args) {
        Vector cats = new Vector();
        for(int i = 0; i < 7; i++)
            cats.addElement(new Cat2(i));
        cats.addElement(new Dog2(7));
        Enumeration e = cats.elements();                //Enumeration 为举器，不必关心集合中的元素数量，所有工作由hasMoreElements  nextElenmentsg完成
        while(e.hasMoreElements())
            ((Cat2)e.nextElement()).print();
    }
}
