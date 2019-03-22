package com.bqlion.DataStructure.List;

public class CHDoublyLinkedListTest {
    public static void main(String[] args) {
        CHDoublyLinkedList<Integer>CHD = new CHDoublyLinkedList<Integer>();

        CHD.add(5);
        CHD.add(4);
        CHD.add(3);
        CHD.add(2);
        CHD.add(1);
        System.out.println(CHD.toString());

        CHD.remove(1);
        CHD.remove(0);
        System.out.println(CHD.remove(0));
        System.out.println(CHD);

        CHD.set(1,100);
        System.out.println(CHD);

        System.out.println(CHD.search(100));
        System.out.println(CHD.search(50));

    }
}
