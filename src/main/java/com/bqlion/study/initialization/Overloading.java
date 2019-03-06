package com.bqlion.study.initialization;
import static net.mindview.util.Print.*;

class Tree {                    //在同一个类下，函数名相同，用不同的参数来区分重载。就像用洗车和洗澡来区分这洗这个字的重载的不同功能。
    int height;
    Tree() {
        print(" Planting a Seeding");
        height = 0;
    }
    Tree(int initalHeight){
        height = initalHeight;
        print("Creat a Tree that is" + height + " feet height");
    }
    void info(){
        print("Tree is "+ height + " feet tall");
    }

    void info(String s){
        print(s + ":Tree is " + height + " feet tall");
    }
}

public class Overloading {
    public static void main(String[] args) {
        for(int i = 0; i < 5; i++)
        {
            Tree t = new Tree(i);           //Tree 类的新对象
            t.info();
            t.info("overload method");
        }
        new Tree();
    }
}

