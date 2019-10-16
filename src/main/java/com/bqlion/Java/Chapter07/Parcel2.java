package com.bqlion.Java.Chapter07;

public class Parcel2
{
    class Contents{
        private int i = 11;
        public int value(){return i;}
    }
    class Destination{
        private String label;
        Destination(String whereTo){
            label = whereTo;
        }
        String readLabel(){return label;}
    }
    public Destination to(String s){
        return new Destination(s);
    }
    public Contents cont(){
        return new Contents();
    }
    public void ship(String dest){
        Contents c = cont();
        Destination d = to(dest);
    }
    public static void main(String[] args){
        Parcel2 p = new Parcel2();
        p.ship("Tanzani a");
        Parcel2 q = new Parcel2();
        Parcel2.Contents c = q.cont();              //外部类名+内部 类名
        Parcel2.Destination d = q.to("Borneo");
    }
}
