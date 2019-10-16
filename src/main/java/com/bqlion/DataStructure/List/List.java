package com.bqlion.DataStructure.List;

public interface List<E> {          //一个List的接口，明确了List该有的功能。后边的seqlist,linkedlist,等都是本接口的实现。
    boolean isEmpty();              //判断是否为空
    int length();                   //长度
    E get(int index);               //get 函数，用于获得位置index的元素
    E set(int index,E element);    //set 函数，用于设置位置index处的元素为element
    boolean add(int index,E element);//增
    boolean add(E element);         //增，未明确增加元素的位置，默认在尾部
    E remove(int index);            //移除位置index处的元素
    void clear();                   //清除线性表
}
