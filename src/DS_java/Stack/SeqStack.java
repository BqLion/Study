package com.bqlion.Before.DataStructure.Stack;

public class SeqStack<E>implements Stack<E> {
    private Object value[];         //成员变量value数组储存各元素
    private int top;                //top表示栈顶位置，空栈时top为-1。

    public SeqStack(int capacity){
        this.value = new Object[capacity];
        this.top = -1;                  //构造函数初始化各成员变量，数组是新申请的数组.top为-1；
    }
    public SeqStack(){
        this(10);
    }

    public boolean isEmpty(){
        return this.top == -1;
    }

    public boolean push(E element){
        if(element == null)             //首先插入元素不可以是null
            return false;
        if(this.top == value.length -1 ) {
                                             //如果栈顶元素的下标是数组的长度减一，代表数组容量已满，需要扩充容量。
                                             //下标是 0 1 2 3 4，数组长度是1,2,3,4,5
                                             //object[].length是可以直接调用的计算数组长度的函数。
        Object temp[] = this.value;
        this.value = new Object[temp.length * 2];
        for(int i = 0; i < temp.length; i++)
            this.value[i] = temp[i];
        }                                       //以上一个if是如果栈满扩容的操作。
        this.top++;
        this.value[this.top] = element;
        return true;                        //这三句是正常的压栈程序
    }

    public E pop(){
        if(!isEmpty())
            return (E)this.value[this.top--];   //弹栈，直接返回top指针所指，然后top--
        else
            return null;
    }

    public E get(){
        if(!isEmpty())
            return (E)this.value[this.top--];
        else
            return null;
    }

    public void show(){
        for(int i = 0; i <= this.top; i++)
            System.out.println(this.value[i]);
    }

}
