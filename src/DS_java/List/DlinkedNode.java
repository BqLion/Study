package com.bqlion.Before.DataStructure.List;
                                        //定义Node首先是Node本体里装的东西，然后是构造函数和缺省构造函数。
public class DlinkedNode<E>{            //Node是容器类，里边装的是泛型E
    public E data;
    public DlinkedNode<E>prev,next;

    public DlinkedNode(E element,DlinkedNode<E>prev,DlinkedNode<E>next){
        this.data = element;
        this.prev = prev;
        this.next = next;
    }
    public DlinkedNode(E element){
        this(element,null,null);            //缺省函数
    }

    public DlinkedNode(){
        this(null,null,null);
    }

}
