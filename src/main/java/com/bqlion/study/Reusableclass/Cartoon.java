package com.bqlion.study.Reusableclass;
class Art{
    Art(){
        System.out.println("Art Constructor");      //Art构造器
    }
}
class Drawing extends Art{
    Drawing(){
        System.out.println("Drawing construcor");
    }
}

public class Cartoon extends Drawing{
    Cartoon(){
        System.out.println("Cartoon constructor");
    }


    public static void main(String[] args) {
        Cartoon x = new Cartoon();

        Drawing y = new Drawing();
    }
}
