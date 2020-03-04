package com.bqlion.Before.Java.Chapter07;

abstract class Contents{
    abstract public int value();
}

interface Destination{
    String readLabel();
}

public class Parcel3 {
    private class PContents extends Contents{       //PC是privae。出了parcel3类之外任何都不可访问
        private int i= 11;
        public int value(){return i;}
    }
    protected class PDestination                    //PD是protected。包外不可访问
        implements Destination{
        private String label;
        private PDestination(String whereTo){
            label = whereTo;
        }
        public String readLabel(){return label;}
    }
    public Destination dest(String s){
        return new PDestination(s);
    }
    public Contents cont(){
        return new PContents();
    }
    }
    class Test{
        public static void main(String[] args) {
            Parcel3 p = new Parcel3();
            Contents c = p.cont();
            Destination d = p.dest("Tanzania");
        }
    }

