package com.bqlion.Java.Chapter07;

public class Parcel1 {
    class Contents{
        private int i = 11;
        public int value(){return i;}
    }       //填写目录和目的地这两个类包含于 包裹类内部，属于内部类
    class Destination{
        private String label;
        Destination(String whereTo){
            label = whereTo;
        }
        String readLabel(){return label;}
    }
    public void ship(String dest){
        Contents c = new Contents();
        Destination d = new Destination(dest);
    }

    public static void main(String[] args) {
        Parcel1 p = new Parcel1();
        p.ship("Tanzania");
    }
}
