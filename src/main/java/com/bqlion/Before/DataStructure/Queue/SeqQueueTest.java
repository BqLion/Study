package com.bqlion.Before.DataStructure.Queue;

public class SeqQueueTest {
    public static void main(String[] args) {
        SeqQueue<Integer>seq = new SeqQueue<Integer>(10);
        System.out.println(seq.isEmpty());
        seq.enqueue(1);
        System.out.println(seq.isEmpty());
        seq.display();
        seq.enqueue(2);
        seq.enqueue(3);
        seq.enqueue(4);
        seq.enqueue(5);
        seq.display();
        seq.dequeue();
        seq.dequeue();
        seq.dequeue();
        seq.display();
    }
}
