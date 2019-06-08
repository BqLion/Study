/*\
java的多重继承问题：
只有一个类能用extends，其他都用的是interface
 */

/*一个感慨：
   时间 : 2019.3.10  17:58
   地点 : 湖北省图书馆
   内容：
   我在上大学时就想要出国，我在深圳工地时就想离开，我在离开深圳后在家挣扎着想来武汉或者深圳每天在图书馆学习该多好。
   我现在正在图书馆坐着学习java，离开了工地，谋划着出国的事情。
   一切经过拖拖延延后发现还是不能带着妥协生活，最终走到了我想去的路线上。
   只是为什么要拖延呢，一切都晚了几年，一切都没有当初直接做容易了。

   正道直行哉。
 */
// Mutiple interfaces return to one big class
package com.bqlion.Java.Polymorphism;

interface CanFight{
    void fight();
}

interface  CanSwim{
    void swim();
}

interface CanFly{
    void fly();
}
class ActionCharacter{
    public void fight(){}
}

class Hero extends ActionCharacter
    implements CanFight,CanSwim,CanFly{
    public void swim(){}
    public void fly(){}
}

public class Adventure {
    static void t(CanFight x){x.fight();}
    static void u(CanSwim x){x.swim();}
    static void v(CanFly x){x.fly();}
    static void w(ActionCharacter x){x.fight();}
    public static void main(String[] args){
        Hero i = new Hero();
        t(i);
        u(i);
        v(i);
        w(i);
    }
}





