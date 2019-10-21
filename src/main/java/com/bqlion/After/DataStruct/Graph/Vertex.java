package com.bqlion.After.DataStruct.Graph;

import com.bqlion.Before.DataStructure.List.HSLiinkedList;

/* *
 * Created by BqLion on 2019/5/14
 */
public class Vertex<E> {
    public E data;
    public HSLiinkedList<Edge>adjlink;

    public Vertex(E data,HSLiinkedList<Edge>adjlink){
        this.data = data;
        this.adjlink = adjlink;
    }

    public Vertex(E data){
        this(data,new HSLiinkedList<Edge>());
    }

    public String toString(){
        return this.data.toString();
    }

}
