package com.bqlion.After.DataStruct.StackAndQueues;

public interface Stack {
/********************field**********************************/

/********************field**********************************/

/********************Constructor****************************/

/********************Constructor****************************/


/********************Method*********************************/
    public int getSize();
    public boolean isEmpty();
    public void push(Object e);
    public Object pop()throws StackOverflowError;
    public Object peek() throws StackOverflowError;

/********************Method*********************************/


}
