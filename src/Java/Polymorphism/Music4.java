package com.bqlion.Before.Java.Polymorphism;
//abstract class
//抽象类是给衍生类提供了接口的类。
//抽象方法是只有方法名没有实施细节的方法，包含抽象方法的类必须定义为抽象类

abstract class Instrunment4{
    int i;
    public abstract void play();        //抽象方法无主体
    public String what(){               //非抽象方法也可包含在抽象类之中
        return "Instrunment4";
    }
    public abstract void adjust();
}

class Wind4 extends Instrunment4{
    public void play(){
        System.out.println("Wind4.play()");
    }
    public String what(){return "Wind4.play()";}
    public void adjust(){}
}

class Percussion4 extends Instrunment4{
    public void play(){
        System.out.println("Percussion4.play()");
    }
    public String what(){return "Percusiion4";}
    public void adjust(){}
}

class Stringed4 extends Instrunment4{
    public void play(){
        System.out.println("String4.play()");
    }
    public String what(){return "Stringed4";}
    public void adjust(){}
}

class Brass4 extends Wind4{
    public void play(){
        System.out.println("Brass4.play()");
    }
    public void adjust(){
        System.out.println("Brass4.adjsut");
    }
}

class WoodWind4 extends Wind4{
    public void play(){
        System.out.println("WoodWind4.play()");
    }
    public String what(){return "WoodWind4";}
}

public class Music4 {
    static void tune(Instrunment4 i){
        i.play();
    }
    static void tuneAll(Instrunment4[] e){
        for(int i = 0; i < e.length; i++)
            tune(e[i]);
    }

    public static void main(String[] args) {
        Instrunment4[] orchestra = new Instrunment4[5];
        int i = 0;
        orchestra[i++] = new Wind4();
        orchestra[i++] = new Percussion4();
        orchestra[i++] = new Stringed4();
        orchestra[i++] = new Brass4();
        orchestra[i++] = new WoodWind4();
        tuneAll(orchestra);
    }

}
