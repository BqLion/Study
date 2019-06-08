package com.bqlion.Java.initialization;   //构造器构造对象先于任何方法。本例方法外散落的三个构造对象先运行，然后才是方法内的w(33);

import static net.mindview.util.Print.print;

    class Window {
    Window(int marker) {         //window类里的window函数的作用是输出一个window字符加marker数字
        print("Window(" + marker + ")");
    }
}

    class House{
        Window w1 = new Window(1);      //house类初始化了一个window w1,w3（在函数中）,w2,w3;
        House(){
            print("House()");               //house函数作用是输出house()字符，以及初始化w3.
            w3 = new Window(33);
        }
        Window w2 = new Window(2);
        void f(){print("f()");}
        Window w3 = new Window(3);
    }

public class OrderOfInitialization {
    public static void main(String[] args) {
        House h = new House();
        h.f();
    }
}
