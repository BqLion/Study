package com.bqlion.Java.Chapter07;

public class Parcel4 {
    public Destination1 dest(String s){
        class PDestination1             //PD class属于dest函数，而非class Parcel4
        implements Destination1{        //PD 不可从dest函数之外被访问
            private String label;
            private PDestination1(String whereTo){
                label = whereTo;
            }
            public String readLabel(){return label;}
        }
        return new PDestination1(s);
    }

    public static void main(String[] args) {
        Parcel4 p = new Parcel4();
        Destination1 d = p.dest("Tanzania");
    }
}
