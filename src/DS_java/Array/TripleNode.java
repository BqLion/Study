package com.bqlion.Before.DataStructure.Array;

/* *
 * Created by BqLion on 2019/4/1
 */
public class TripleNode<E> {
    public E data;
    public TripleNode<E> child;
    public TripleNode<E> next;

    public TripleNode(E data,TripleNode<E>child,TripleNode<E>next){
        this.data = data;
        this.child = child;
        this.next = next;
    }

    public TripleNode(E data){
        this(data,null,null);
    }

    public TripleNode(){
        this(null,null,null);
    }
}
