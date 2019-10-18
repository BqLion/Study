package com.bqlion.After.DataStruct.StackAndQueues;

import com.bqlion.After.DataStruct.List.LinkedListIterator;
import com.bqlion.After.DataStruct.List.SingleLinkedList;
import com.bqlion.After.DataStruct.List.SingleLinkedListNode;

public class LinkedQueue implements Queue{
/********************field**********************************/
    private SingleLinkedListNode frontPointer;
    private SingleLinkedListNode endPointer;
    private int sizeOfQueue;

/********************field**********************************/


/********************Constructor****************************/
    public LinkedQueue(){
        frontPointer = new SingleLinkedListNode();
        endPointer = frontPointer;
        sizeOfQueue = 0;
    }

/********************Constructor****************************/


/********************Method*********************************/
    public int getSize(){
        return sizeOfQueue;
    }

    public boolean isEmpty(){
        return sizeOfQueue == 0;
    }

    public Object dequeue() throws QueueEmptyException{
        if(sizeOfQueue < 1)
            throw new QueueEmptyException("错误,队列为空");
        SingleLinkedListNode issedBeingDeleted = frontPointer.getNext();
        frontPointer.setNext(issedBeingDeleted.getNext());
        sizeOfQueue --;
        if (sizeOfQueue < 1)endPointer = frontPointer;
        return issedBeingDeleted.getData();
    }

    public void enqueue(Object issueBeingPushed){
        SingleLinkedListNode temp = new SingleLinkedListNode(issueBeingPushed,null);
        endPointer.setNext(temp);
        endPointer = temp;
        sizeOfQueue ++;
    }

    public Object peek()throws QueueEmptyException{
        if (sizeOfQueue < 1)
            throw new QueueEmptyException("错误队列为空");
        return frontPointer.getNext().getData();
    }
/********************Method*********************************/
}
