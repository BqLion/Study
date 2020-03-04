package com.bqlion.After.DataStruct.StackAndQueues;

public interface Queue {
/********************field**********************************/

/********************field**********************************/


/********************Constructor****************************/

/********************Constructor****************************/


/********************Method*********************************/
    public int getSize();
    public boolean isEmpty();
    public void enqueue(Object beingPushedIssue);
    public Object dequeue()throws QueueEmptyException;
    public Object peek()throws QueueEmptyException;
/********************Method*********************************/
}
