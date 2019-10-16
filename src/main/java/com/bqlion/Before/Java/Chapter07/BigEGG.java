package com.bqlion.Before.Java.Chapter07;
// A inner Class cannot be overriden like a method
class Egg {
    protected class Yolk{
        public Yolk(){
            System.out.println("Egg.Yolk");
        }
    }

    private Yolk y;
    public Egg(){
        System.out.println("New Egg()");
        y = new Yolk();
    }
}

public class BigEGG extends Egg{
    public class Yolk{
        public Yolk(){
            System.out.println("BigEgg.YOLK()");
        }
    }

    public static void main(String[] args) {
        new BigEGG();
    }
}