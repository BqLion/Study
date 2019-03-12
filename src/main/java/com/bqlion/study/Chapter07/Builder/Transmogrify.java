package com.bqlion.study.Chapter07.Builder;

interface Actor{
    void act();
}

class HappyActor implements Actor{
    public void act(){
        System.out.println("Happy Actor");
    }
}

class SadActor implements Actor{
    public void act(){
        System.out.println("Sad Actor");
    }
}

class Stage{
    Actor a = new HappyActor();
    void change(){a = new SadActor();}
    void go(){a.act();}
        }

public class Transmogrify{
    public static void main(String[] args) {
        Stage s = new Stage();
        s.go();
        s.change();
        s.go();
    }
}