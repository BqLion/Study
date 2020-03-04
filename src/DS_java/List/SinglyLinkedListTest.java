package com.bqlion.Before.DataStructure.List;

public class SinglyLinkedListTest {
    public static void main(String[] args) {
        SinglyLinkedList<Integer>TestLinkedList = new SinglyLinkedList<Integer>(new Node<Integer>(100));

        System.out.println(TestLinkedList.isEmpty());

        System.out.println((TestLinkedList.get(0)));

        TestLinkedList.add(1,1);
        TestLinkedList.add(2,2);

        System.out.println(TestLinkedList);

        TestLinkedList.remove(0);

        System.out.println(TestLinkedList);

        TestLinkedList.clear();

        System.out.println(TestLinkedList);
    }
}
