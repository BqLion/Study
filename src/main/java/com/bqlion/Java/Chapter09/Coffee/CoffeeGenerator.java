package com.bqlion.Java.Chapter09.Coffee;
import java.util.*;

public  class CoffeeGenerator
implements Generator<coffee>,Iterable<coffee>{
    private Class[] types = {Latte.class,Mocha.class,Cappuccino.class,Americano.class,Brevo.class,};
    private static Random rand = new Random(47);
    public CoffeeGenerator(){}
    private int size = 0;
    public CoffeeGenerator(int sz){size = sz;}
    public coffee next(){
        try {
            return(coffee)
                types[rand.nextInt(types.length)].newInstance();
        }catch (Exception e){
            throw new RuntimeException(e);
        }
    }
    class CoffeeIterator implements Iterator<coffee>{
        int count = size;
        public boolean hasNext(){return count > 0;}
        public coffee next() {
            count--;
            return CoffeeGenerator.this.next();
        }
        public void remove(){
            throw new UnsupportedOperationException();
        }
    };
    public Iterator<coffee>iterator(){
        return new CoffeeIterator();
    }

    public static void main(String[] args) {
        CoffeeGenerator gen  = new CoffeeGenerator();
        for(int i = 0; i < 5 ;i++)
            System.out.println(gen.next());
        for(coffee c : new CoffeeGenerator(5))
            System.out.println(c);
    }

}
