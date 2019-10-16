package com.bqlion.Java.Chapter08.Collection;
import java.util.*;

public class SimpleIteration {
    public static void main(String[] args) {
        List<Pet>pets = Pets.arrayList(12);
        Iterator<Pet>it = pets.iterator();      //新建pets这个列表的一个枚举器
        while(it.hasNext()){
            Pet p = it.next();
            System.out.println(p.id() + ":" + p + " ");
        }
        System.out.println();
        for(Pet p : pets)
            System.out.println(p.id() + ":" + p + " ");
        System.out.println();
        it = pets.iterator();
        for(int i = 0; i < 6; i++){
            it.next();
            it.remove();
        }
        System.out.println(pets);
    }
}
