package com.bqlion.Before.Java.Chapter07;
//creating inner classes

public class Parcel11 {
    class Contents{
        private int i = 11;
        public int value(){return i;}
    }
class Destination{
        private String label;
        Destination(String whereTo){
            label  = whereTo;
        }
        String readLabel(){return label;}
}

    public static void main(String[] args) {
        Parcel11 p = new Parcel11();            //想要创建内部类必须先创建内部类的外部类对象p
        Parcel11.Contents c = p.new Contents(); //外部类.内部类 c = p. new 内部类
        Parcel11.Destination d = p.new Destination("Tanzania");
    }
}
