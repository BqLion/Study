package com.bqlion.DataStructure.Queue;
import com.bqlion.DataStructure.List.Node;
public class LinkedQueue<E> implements Queue<E>{
    private Node<E>front,rear;

    public LinkedQueue(){
        this.front = this.rear = null;      //链队初始化，头尾指针置为空
    }
    public boolean isEmpty(){
        return this.front == null && this.rear == null;
    }
    public boolean enqueue(E element){
        if(element == null)
            return false;
        Node<E>p = new Node<E>(element);        //把element放进node，next指针暂不设置
        if(!isEmpty()){
            this.rear.next = p;
            this.rear = p;
        }
        else
            this.front = this.rear = p;
        return true;
    }

    public E dequeue(){
        E temp = this.front.data;

        if(isEmpty())
            return null;
        else
            front = front.next;
        if(front == null)
            rear = null;
        return temp;
    }
    public void display(){
        if(isEmpty())
            System.out.println("queue is empty!");

        Node<E>p = this.front;
        while(p != null) {
            System.out.println(p.data);
            p = p.next;
        }
    }}
