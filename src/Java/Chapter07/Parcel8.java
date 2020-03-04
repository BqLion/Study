package com.bqlion.Before.Java.Chapter07;
//初始化匿名内部类

public class Parcel8 {
    public Destination dest(final String dest){
        return new Destination(){           //没有名字的new Destination  在定义额外的变量和函数时同时做了初始化。
            private String label = dest;
            public String readLabel(){return label;}
        };
    }

    public static void main(String[] args) {
        Parcel8 p = new Parcel8();
        Destination d = p.dest("Tanzania");
    }
}
