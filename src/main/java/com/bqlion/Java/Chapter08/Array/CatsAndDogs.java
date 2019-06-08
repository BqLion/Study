package com.bqlion.Java.Chapter08.Array;
import java.util.*;

//四种集合类: Vector矢量，BitSet位集，Stack堆栈，HashTable散列表

class Cat{
    private int catNumber;
    Cat(int i){
        catNumber = i;
    }
    void print(){
        System.out.println("Cat #" + catNumber);
    }
}

class Dog{
private int dogNumber;
        Dog(int i){
        dogNumber=i;
        }
        void print(){
        System.out.println("Dog #"+dogNumber);
        }
}

public class CatsAndDogs {
    public static void main(String[] args) {
        Vector cats = new Vector();     //Vector矢量集 包含cat猫类。
        for(int i = 0; i < 7; i++)
            cats.addElement(new Cat(i));//addElement 是object的操作，一切对象继承自object
        cats.addElement(new Dog(7));  //狗虽然可以放进猫的集合类里，但是运行时还是会报错：Class Case Exception,类型违例。
        for(int i = 0; i < cats.size();i++)
            ((Cat)cats.elementAt(i)).print();

    }
}
