/*
    Interface 示范，Interface是只有方法名、自变量列表、返回类型的类。不定义方法主体。
    接口Interface这样描述自己：所有实现我的类都应该长我这样子。
    接口与相符的类之间的关系与父类与子类关系相似。
    接口与类之间用implement关键字链接
 */
package com.bqlion.study.Polymorphism;
import java.util.*;

interface Instrunment5{         //和父类的定义相似
    int i = 5;                  //接口中的基本数据默认为 static 和 final
    void play();                //接口中的方法默认为public
    String what();
    void adjust();
}

class Wind5 implements Instrunment5{
    public void play(){
        System.out.println("Wind5.play()");
    }
    public String what(){return "Wind5";}
    public void adjust(){}
}

    class Percussion5 implements Instrunment5{
        public void play(){
            System.out.println("Percusiion5.play()");
        }
        public String what(){return "Stringed5";}
        public void adjust(){}
    }

    class Stringed5 implements Instrunment5{
        public void play(){
            System.out.println("Stringed5.play()");
        }
        public String what(){return "Stringed 5";}
        public void adjust(){}
    }

    class Brass5 extends Wind5{
    public void play(){
        System.out.println("Brass5.adjust()");
    }
    }

    class Woodwind5 extends Wind5{
    public void play(){
        System.out.println("Woodwind5.play()");
    }
    public String what(){return "WoodWind5";}
    }

public class Music5 {
    static void tune(Instrunment5 i){
        i.play();
    }

    static void tuneAll(Instrunment5[] e){
        for (int i = 0; i < e.length; i++)
            tune(e[i]);
    }

    public static void main(String[] args) {
        Instrunment5[] orchestra = new Instrunment5[5];
        int i = 0;
        orchestra[i++] = new Wind5();
        orchestra[i++] = new Percussion5();
        orchestra[i++] = new Stringed5();
        orchestra[i++] = new Brass5();
        orchestra[i++] = new Woodwind5();
        tuneAll(orchestra);
    }
}
