package com.bqlion.Before.DataStructure.List;

public class Node<E> {
    public E data;      //data就是储存的数据
    public Node<E>next; //Node<E>就是节点对象。java中不能知道操作对象，操作的是指向对象的指针（地址）。 Node<E>型数据就是指针型数据。

    public Node(E data,Node<E> next){       //构造函数，外部调用本函数后可构造Node节点
        this.data = data;
        this.next = next;
    }
    public Node(E data){
        this(data,null);
    }//缺省构造函数
    public Node(){
        this(null,null);
    }//缺省构造函数
}

