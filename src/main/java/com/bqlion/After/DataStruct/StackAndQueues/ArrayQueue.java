package com.bqlion.After.DataStruct.StackAndQueues;

import javafx.beans.binding.ObjectExpression;

import javax.management.openmbean.OpenMBeanAttributeInfo;
import javax.swing.*;

public class ArrayQueue {

/********************field**********************************/
    private static final int LENGTH_OF_QUEUE = 7;
    private Object[] arrayOfQueue;
    private int sizeOfArrayOfQueue;
    private int pointerHead;
    private int pointerEnd;
/********************field**********************************/


/********************Constructor****************************/
    public ArrayQueue(){
        this(LENGTH_OF_QUEUE);
    }

    public ArrayQueue(int LENGTH_OF_QUEUE){
        sizeOfArrayOfQueue = LENGTH_OF_QUEUE + 1;
        arrayOfQueue = new Object[sizeOfArrayOfQueue];
        pointerEnd = pointerHead = 0;
    }
/********************Constructor****************************/


/********************Method*********************************/
    public int getSize(){
        return (pointerEnd - pointerHead + sizeOfArrayOfQueue)%sizeOfArrayOfQueue;
    }

    public boolean isEmpty(){
        return pointerEnd == pointerHead;
    }

    public void enqueue(Object beingPushedIssue){
        if(getSize() == sizeOfArrayOfQueue - 1)
            expandSpace();
        arrayOfQueue[pointerEnd] = beingPushedIssue;
        pointerEnd  = (pointerEnd+1)%sizeOfArrayOfQueue;
    }
    private void expandSpace() {
        Object[] tempQueue = new Object[sizeOfArrayOfQueue * 2];
        int i = pointerHead;
        int j = 0;
        while (i != pointerEnd) {
            tempQueue[j++] = arrayOfQueue[i];
            i = (i + 1) % sizeOfArrayOfQueue;
        }
        arrayOfQueue = tempQueue;
        sizeOfArrayOfQueue = arrayOfQueue.length;
        pointerHead = 0;
        pointerEnd = j;
    }


    public Object dequeue() throws QueueEmptyException {
        if (isEmpty())
            throw new QueueEmptyException("错误:队列为空");
        Object issueBeingThrowed = arrayOfQueue[pointerHead];
        arrayOfQueue[pointerHead] = null;
        pointerHead = (pointerHead+1)%sizeOfArrayOfQueue;
        return issueBeingThrowed;
    }


    public Object peek()throws QueueEmptyException{
        if(isEmpty())
            throw new QueueEmptyException("错误,队列为空");
        return arrayOfQueue[pointerHead];
    }
/********************Method*********************************/
}
