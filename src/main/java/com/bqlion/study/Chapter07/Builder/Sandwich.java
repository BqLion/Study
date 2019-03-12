package com.bqlion.study.Chapter07.Builder;

class Meal{
    Meal(){System.out.println("Meal()");}
}

class Bread{
    Bread(){System.out.println("Bread");}
}

class Cheese{
    Cheese(){System.out.println("Cheese()");}
}

class Lettuce{
    Lettuce(){System.out.println("Lettuce()");}
}

class Lunch extends Meal{
    Lunch(){System.out.println("Lunch()");}
}

class PortableLunch extends Lunch{
    PortableLunch(){
        System.out.println("Portable Lunch");
    }
}

public class Sandwich extends PortableLunch{            //不同层次继承关系调用顺序：
    Bread b = new Bread();                              //1.从根部开始依次调用基础类
    Cheese c =  new Cheese();                           //2.按声明顺序调用成员初始化模板
    Lettuce l = new Lettuce();                          //3.调用衍生类本身主体
    Sandwich(){
        System.out.println("Sandwich()");
    }

    public static void main(String[] args) {
        new Sandwich();
    }
}
