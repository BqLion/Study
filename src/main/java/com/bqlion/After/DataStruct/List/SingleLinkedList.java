package com.bqlion.After.DataStruct.List;

public class SingleLinkedList {
/********************field**********************************/
private SingleLinkedListNode head;
private int nodeNumberInList;
/********************field**********************************/


/********************Constructor****************************/
public SingleLinkedList(){
    head = new SingleLinkedListNode();
    nodeNumberInList = 0;
}
/********************Constructor****************************/


/********************Method*********************************/
public void insert(int position,Object newMember)throws IndexOutOfBoundsException{
    if(position < 0 || position > nodeNumberInList)
        throw new IndexOutOfBoundsException("错误,指定的插入越界");
    SingleLinkedListNode previousNode = getPreNode(position);
    SingleLinkedListNode newGuy = new SingleLinkedListNode(newMember,previousNode.getNext());
    previousNode.setNext(newGuy);
}

public SingleLinkedListNode getPreNode(int position){
    if(position < 0 || position > nodeNumberInList)
        throw new IndexOutOfBoundsException("错误,指定的插入越界");
    SingleLinkedListNode pointer = head;
    for(int i = 0; i < position; i++)
        pointer = pointer.getNext();
    return pointer;
}

public Object remove(int position)throws IndexOutOfBoundsException{
    if(position < 0 || position >=nodeNumberInList)
        throw new IndexOutOfBoundsException("错误,删除的序号越界");
    SingleLinkedListNode p = getPreNode(position);
    Object obj = p.getNext().getData();
    p.setNext(p.getNext().getNext());
    nodeNumberInList--;
    return obj;
}

public Object repalce(int position,Object newGuy)throws IndexOutOfBoundsException {
    if (position < 0 || position >= nodeNumberInList)
        throw new IndexOutOfBoundsException("错误,指定位置越界");
    SingleLinkedListNode temp = getPreNode(position).getNext();
    Object oldGuys = temp.getData();
    temp.setData(newGuy);
    return oldGuys;
}

public Object get(int i)throws IndexOutOfBoundsException{
if(i < 0 || i >= nodeNumberInList)
    throw new IndexOutOfBoundsException("错误,制定的位置越界");
    SingleLinkedListNode p = getPreNode(i).getNext();
    return p.getData();
    }

    public boolean isEmpty() {
    if (nodeNumberInList == 0)
        return true;
    else
        return false;
    }

    public SingleLinkedListNode getFirst() {
    return head;
    }

    public SingleLinkedListNode last() {
    SingleLinkedListNode temp = head;
        for(int i  = 0; i <nodeNumberInList;i++)
        temp = temp.getNext();

        return temp;
    }

    public SingleLinkedListNode getNext(SingleLinkedListNode current) {
    return current.getNext();
}


/********************Method*********************************/
}
