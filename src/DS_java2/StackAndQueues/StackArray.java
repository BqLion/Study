package com.bqlion.After.DataStruct.StackAndQueues;

public class StackArray {
/********************field**********************************/
    private final int STACK_LENGTH = 8;
    private Object[] elements;
    private int pointerOfStackTop;
/********************field**********************************/


/********************Constructor****************************/
    public StackArray(){
        pointerOfStackTop = -1;
        elements = new Object[STACK_LENGTH];
    }
/********************Constructor****************************/


/********************Method*********************************/
    public int getSize(){
        return pointerOfStackTop + 1;
    }

    public boolean isEmpty(){
        return pointerOfStackTop < 0;
    }

    public void push(Object beingPushedIssue){
        if(getSize() >= elements.length)
            stackExpandSpace();
        elements[pointerOfStackTop++] = beingPushedIssue;
    }

    private void stackExpandSpace(){
        Object[] tempStack = new Object[elements.length * 2];
        for(int i = 0;i < elements.length; i++)
            tempStack[i] = elements[i];
        elements = tempStack;
     }

     public Object pop()throws StackOverflowError{
        if(getSize() < 1)
            throw new StackOverflowError("错误,堆栈为空");
        Object beingPoppedIssue = elements[pointerOfStackTop];
        elements[pointerOfStackTop--] = null;
        return beingPoppedIssue;
     }


     public Object peek()throws StackOverflowError{
        if(getSize() < 1)
            throw new StackOverflowError("错误,堆栈为空");;

            return elements[pointerOfStackTop];
     }
/********************Method*********************************/
}
