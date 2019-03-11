package com.bqlion.study.Chapter07;

public class Parcel9 {
    public Destination
    dest(final String dest,final float price){
        return new Destination(){           //匿名内部类
            private int cost;           //定义一个变量
            {
                cost = Math.round(price);       //定义匿名内部类时如果使用了 外部的对象，本例子就是Math.round(Price)
                if(cost > 100)                  //可直接使用，但外部对象对象通过函数参数传递进来时必须是final属性
                    System.out.println("Over budget!");
            }
            private String label = dest;
            public  String readLabel(){return label;}
        };
            }

    public static void main(String[] args) {
        Parcel9 p = new Parcel9();
        Destination d = p.dest("Tandania",101.396F);
    }
    }

