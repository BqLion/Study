package com.bqlion.Before.Java.Reusableclass;

class Value{
    int i = 1;
}

public class FinalData {
    final int i1 = 9;
    static final int i2 = 99;
    public static final int i3 = 39;
    final int i4 = (int)(Math.random()*20);
    static final int i5 = (int)(Math.random()*20);

    Value v1 = new Value();
    final Value v2 = new Value();
    static final Value v3 = new Value();

    final int a[] = {1,2,3,4,5,6};

    public void print(String id){
        System.out.println(
                id + ": " + "i4 = " + i4 + ", i5 = " + i5);
    }

    public static void main(String[] args) {
        FinalData fd1 = new FinalData();

        fd1.v2.i++;
        fd1.v1 = new Value();
        for(int i = 0; i < fd1.a.length;i++)
            fd1.a[i]++;
        fd1.print("fd1");               // fd1中的i4  i5 都是随机数
        System.out.println("Creating new FinalData");       //创建fd2 i4 i5按说要再一次随机
        FinalData fd2 = new FinalData();
        fd1.print("fd1");               //fd1的i4（final int） i5(static final int)变量未发生变化
        fd2.print("fd2");               //i4 发生变化，   i5未发生变化
    }                                   //按说i4  i5 作为final变量值是唯一的
                                        //区别是i4作为final int  在每一次创建对象时初始化
                                        //      i5是static final int，在载入时就初始化。
}
