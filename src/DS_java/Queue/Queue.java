package com.bqlion.Before.DataStructure.Queue;

public interface Queue<E> {
    boolean isEmpty();
    boolean enqueue(E element);
    E dequeue();
}
