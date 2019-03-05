package com.bqlion.study;

public class SeqStack {
    String[] StackElem;
    int top;

    public SeqStack(int MaxSize) {
        top = 0;
        StackElem = new String[MaxSize];
    }

    public void clear() {
        top = 0;
    }

    public boolean isEmpty() {
        if(top == 0)
            return true;
        else
            return false;
    }

    public int length() {
        return top;
    }

    public String peek() {
        if (isEmpty()) {
            return "0";
        }
        return StackElem[top-1];
    }

    public void push(String a) {
        StackElem[top++] = a;
    }

    public String pop() {
        if(isEmpty()){
            return "0";
        }
        return StackElem[--top];
    }
}