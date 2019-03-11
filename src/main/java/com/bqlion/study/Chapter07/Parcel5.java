package com.bqlion.study.Chapter07;
//展示如何在任意作用域内嵌套一个内部类

public class Parcel5 {
    private void internalTracking(boolean b){
        if(b){
            class TrackingShip{
                private String id;
                TrackingShip(String s){
                    id  = s;
                }
                String getShip(){return id;}
            }
            TrackingShip ts =  new TrackingShip("ship");
            String s = ts.getShip();
        }
    }
    public void track(){internalTracking(true);}

    public static void main(String[] args) {
        Parcel5 p = new Parcel5();
        p.track();
    }
}
