package com.bqlion.After.DataStruct.StackAndQueues;

import com.bqlion.After.DataStruct.List.SingleLinkedListNode;

public class LinkedStack implements Stack{
/********************field**********************************/
    private SingleLinkedListNode pointerOfTop;
    private int sizeOfStack;

/********************field**********************************/


/********************Constructor****************************/
    public LinkedStack(){
        pointerOfTop = null;
        sizeOfStack = 0;
    }
/********************Constructor****************************/


/********************Method*********************************/
    public int getSize(){
        return sizeOfStack;
    }

    public boolean isEmpty(){
        return sizeOfStack == 0;
    }

    public void push(Object beingPushedIssue){
        SingleLinkedListNode tempNode = new SingleLinkedListNode(beingPushedIssue,pointerOfTop);
        pointerOfTop = tempNode;
        sizeOfStack++;
    }

    public Object pop()throws StackOverflowError{
        if (sizeOfStack < 1)
            throw new StackOverflowError("错误堆栈为空");
        Object beingPoppedIssue = pointerOfTop.getData();
        pointerOfTop = pointerOfTop.getNext();
        sizeOfStack --;
        return beingPoppedIssue;
    }

    public Object peek()throws StackOverflowError{
        if(sizeOfStack < 1)
            throw new StackOverflowError("error,stack is empty");
        return pointerOfTop.getData();
    }
/********************Method*********************************/

}
