package com.bqlion.DataStructure.Stack;

public interface Stack<E> {
    boolean isEmpty();
    boolean push(E element);
    E pop();
    E get();
}
