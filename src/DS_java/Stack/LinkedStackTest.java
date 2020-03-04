package com.bqlion.Before.DataStructure.Stack;

public class LinkedStackTest {
    public static void main(String[] args) {
        LinkedStack<Integer>link = new LinkedStack<Integer>();
        System.out.println(link.isEmpty());

        link.push(0);
        link.display();
        link.pop();
        link.display();

        link.push(1);
        link.push(2);
        link.push(3);
        link.push(4);
        link.push(5);
        link.display();

        link.pop();
        link.pop();
        link.pop();
        link.display();
    }
}
