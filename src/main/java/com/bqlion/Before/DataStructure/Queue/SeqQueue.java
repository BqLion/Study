package com.bqlion.Before.DataStructure.Queue;

/*
    循环队列顺序存储结构。
    front指向第一个元素，
    rear指向最后元素的下一个空位，代表下次插入位置。
    为避免rear假溢出，rear = （rear+1）%value.length
    这里对%做一个思维建模:
    rear是指针指向数组的2号位置。
    length长度是5，5那么长的数组一行行摆开，
    【】【】【】【】【】
    【】【】【】【】【】
    【】【】【】【】【】
    rear = （rear+1）%value.length
    即是
    rear是否等于rear+1在 第一行的位置？
 */
public class SeqQueue<E> implements Queue<E>{
    private Object value[];
    private int front,rear;

    public SeqQueue(int capacity){
        this.value = new Object[capacity];
        this.front = this.rear = 0;
    }
    public SeqQueue(){
        this(10);           //缺省函数：调用自身直接this(补全缺省参数)
    }
    public boolean isEmpty(){
        return this.front == this.rear;     //判空条件为front是否等于rear？
    }
    public boolean enqueue(E element){      //数据结构添加元素的常见思路:
        if(element == null)                 //添加进去的元素是否有问题？不可是空
        return false;                       //列表本身不可有问题，若满则扩
        if(this.front == (this.rear+1 % this.value.length)) {        //判满的条件是rear+1 是否等于front？加上循环一圈
            Object[] temp = this.value;
            this.value = new Object[temp.length * 2];
            int i = this.front;
            while (i != this.rear) {
                this.value[i] = temp[i];
                i = (i + 1) % temp.length;
            }
            this.front = 0;
            this.rear = this.value.length / 2;
        }
        this.value[this.rear] = element;
        this.rear = (this.rear+1) % this.value.length;

        return true;
    }
    public E dequeue(){
        if(!isEmpty()){
            E temp = (E)this.value[front];
            front = (front + 1)%this.value.length;
            return temp;
        }
        return null;
    }
    public void display(){
        System.out.println("the elements in Queue are:");
        int i = this.front;
        while(i != this.rear){
            System.out.println(this.value[i]);
            i = (i + 1)%this.value.length;
        }
    }
}
