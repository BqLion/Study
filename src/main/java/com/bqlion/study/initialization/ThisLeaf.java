package com.bqlion.study.initialization;
//This关键字： 代表调用方法的那个对象。
//静态方法不能用This，因为静态方法不属于类的实例。
public class ThisLeaf {
    int i = 0;
    ThisLeaf increment(){           //返回一个ThisLeaf型的结果
        i++;
        return this;                //返回的是正在调用ThisLeaf方法的那个对象
    }
    void print(){
        System.out.println("i = " + i);
    }

    public static void main(String[] args) {
        ThisLeaf x = new ThisLeaf();                //一个新的ThisLeaf对象x

        x.increment().increment().increment().print(); //x调用increnment函数，调用三次，每次返回的都是This,正在调用方法的那个对象也就是x自己
                                                       //调用了三次，i = 3，打印出痕迹。
    }
}
