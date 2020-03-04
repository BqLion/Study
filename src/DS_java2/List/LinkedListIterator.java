package com.bqlion.After.DataStruct.List;

public class LinkedListIterator {
/********************field**********************************/
    private SingleLinkedList list;
    private SingleLinkedListNode current;

/********************field**********************************/

/********************Constructor****************************/
public LinkedListIterator(SingleLinkedList list) {
    this.list = list;
    if (list.isEmpty())
        current = null;
    else
        current = list.getFirst();
}
/********************Constructor****************************/


/********************Method*********************************/
    public void first(){
        if(list.isEmpty())
            current = null;
        else
            current = list.getFirst();
    }

    public void next()throws IndexOutOfBoundsException{
        if(isDone())
            throw new IndexOutOfBoundsException("错误已经没有元素");
        if (current==list.last()) current = null;
        else current = list.getNext(current);
    }

    public boolean isDone(){
        return current == null;
    }

    public Object currentItem()throws IndexOutOfBoundsException{
        if(isDone())
            throw new IndexOutOfBoundsException("错误,已经没有了元素");
        return current.getData();
    }
/********************Method*********************************/
}
