package com.bqlion.After.DataStruct.List;

public class SingleLinkedListNode {

/********************field**********************************/
    private Object element;
    private SingleLinkedListNode next;

/********************field**********************************/


/********************Constructor****************************/

 public SingleLinkedListNode(){
        this(null,null);
    }


 public SingleLinkedListNode(Object newGuys,SingleLinkedListNode next){
    this.element = newGuys;
    this.next = next;
    }

/********************Constructor****************************/


/********************Method*********************************/
 public SingleLinkedListNode getNext(){
    return next;
 }

 public void setNext(SingleLinkedListNode next){
    this.next = next;
 }

 public Object getData(){
     return element;
 }

 public void setData(Object obj){
     element = obj;
 }
/********************Method*********************************/
}
