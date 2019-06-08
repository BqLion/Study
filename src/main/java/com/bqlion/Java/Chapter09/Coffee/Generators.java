package com.bqlion.Java.Chapter09.Coffee;
import java.util.*;

public class Generators {
    public static<T> Collection<T>
    fill(Collection<T>coll,Generator<T>gen,int n){
        coll.add(gen.next());
        return coll;
    }

    public static void main(String[] args) {
        Collection<coffee> coffee = fill(new ArrayList<coffee>(),new CoffeeGenerator(),4);
        for(coffee c : coffee)
        System.out.println(c);
        Collection<Integer>fnumbers = fill(new ArrayList<Integer>(), new Fibonacci(), 12);
        for(int i: fnumbers)
            System.out.print(i + ", ");
    }
}
