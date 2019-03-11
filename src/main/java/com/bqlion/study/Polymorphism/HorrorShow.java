package com.bqlion.study.Polymorphism;
//通过继承扩展接口
interface Monster{
    void menace();
}

interface DangerourMonster extends Monster{         //interface除了可以被继承也可以被扩展
    void destroy();
}

interface Lethal{
    void kill();
}

class DragonZill implements DangerourMonster{
    public void menace(){}
    public void destroy(){}
}

interface Vampire extends DangerourMonster,Lethal{
    void drinkBlood();
}

class HorrorShow {
    static void u(Monster b){b.menace();}
    static void v(DangerourMonster d){
        d.menace();
        d.destroy();
    }

    public static void main(String[] args) {
        DragonZill if2 = new DragonZill();
        u(if2);
        v(if2);
    }
}
