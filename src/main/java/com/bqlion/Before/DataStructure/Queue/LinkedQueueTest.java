package com.bqlion.Before.DataStructure.Queue;

public class LinkedQueueTest {
    public static void main(String[] args) {
        LinkedQueue<Integer>link = new LinkedQueue<Integer>();
        System.out.println(link.isEmpty());

        link.enqueue(0);
        link.enqueue(1);
        link.enqueue(2);
        link.enqueue(3);
        link.display();

        link.dequeue();
        link.dequeue();
        link.dequeue();
        link.display();
    }
}
