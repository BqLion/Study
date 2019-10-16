package com.bqlion.Java.Reusableclass;

class Cleanser{
    private String s = new String("Cleanser");
    public void append(String a){s += a; }
    public void dilute(){append("（dilute)");}
    public void apply(){append("apply");}
    public void scrub(){append("scrub");}
    public void print(){System.out.println(s);}

    public static void main(String[] args) {            //这是基类，可以有自己的main函数但是类型不能是public的一个编译单元只能有一个public类
        Cleanser x = new Cleanser();
        x.dilute();x.apply();x.scrub();
        x.print();
    }
}

public class Detergent extends Cleanser{            //这是继承的类，可以有自己的main函数，对基类的函数可以做改变或者定义新的函数
    public void scrub(){
        append("Detergent.scrub()");
        super.scrub();
    }
    public void foam(){append("foam()"); }

    public static void main(String[] args) {
        Detergent x = new Detergent();

        x.dilute();
        x.apply();
        x.scrub();
        x.foam();
        x.print();
        System.out.println("Testing base class: ");
        Cleanser.main(args);
    }
}
