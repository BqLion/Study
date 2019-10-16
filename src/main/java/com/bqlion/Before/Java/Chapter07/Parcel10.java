package com.bqlion.Before.Java.Chapter07;
abstract class Contents2{
    abstract public int value();
}

interface Destination2{
    String readLabel();
}

public class Parcel10{
    private static class PContents
    extends Contents2{
        private int i = 11;
        public int value(){return i;}
    }
    protected static class PDestination
        implements Destination2{
        private String label;
        private PDestination(String whereTo){
            label = whereTo;
        }
        public String readLabel(){return label;}
    }
    public static Destination2 dest(String s){
        return new PDestination(s);
    }
    public static Contents2 cont(){
        return new PContents();
    }

    public static void main(String[] args) {
        Contents2 c = cont();
        Destination2 d = dest("Tanzania");
    }
}
