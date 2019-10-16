package com.bqlion.Coursera.AlgorithmsPart1.WEEK2;

/* *****************************************************************************
 *  Name:   BqLion
 *  Date:   2019.6.11
 *  Description:   A Study Project on Coursera
 **************************************************************************** */

//A double-ended queue or deque (pronounced “deck”) is a generalization of a
// stack and a queue that supports adding and removing items from
// either the front or the back of the data structure.
/**


import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {
    private Node first;
    private Node last;
    private int n;

    private class Node{
        Item item;
        Node front;
        Node next;

        Node(){
            item = null;
            front = null;
            next = null;
        }
    }
    public Deque() {                           // construct an empty deque
        first = null;
        last = null;
        n = 0;
    }

    public boolean isEmpty() {                 // is the deque empty?
        return(n == 0);
    }

    public int size(){ return n; }                      // return the number of items on the deque

    public void addFirst(Item item){
        Node node = new Node();

        if(item == null)
            throw new java.lang.IllegalArgumentException();

        if(n == 0) {
            last = node;
            first = node;
            node.item = item;
            node.next = null;
            node.front = null;
            n++;
        }

        else if(n > 0){
            node.item = item;
            node.next = first;
            node.front = null;
            first.front = node;
            first = node;
            n ++;
        }

    }          // add the item to the front

    public void addLast(Item item){
        Node node = new Node();

        if(item == null)
            throw new java.lang.IllegalArgumentException();


        if(n == 0) {
            last = node;
            first = node;
            node.item = item;
            node.next = null;
            node.front = null;
            n++;
        }

        else if(n > 0){
            node.item = item;
            node.front = last;
            node.next = null;
            last.next = node;
            last = node;
            n ++;
        }
    }           // add the item to the end

    public Item removeFirst() {
        Node node = new Node();

        if(n == 0)
            throw new java.util.NoSuchElementException();

        else if (n == 1) {
            node.item = first.item;
            first = null;
            last = null;
            n--;
            return node.item;
        }

        else {
            node.item = first.item;
            first = first.next;
            first.front.next = null;
            first.front = null;
            n--;
            return node.item;
        }

    }
    // remove and return the item from the front

    public Item removeLast(){
        Node node = new Node ();

        if(n == 0)
            throw new java.util.NoSuchElementException();

        else if (n == 1) {
            node.item = last.item;
            first = null;
            last = null;
            n--;
            return node.item;
        }

        else {
            node.item = last.item;
           last= last.front;
           last.next.front = null;
           last.next = null;
            n--;
            return node.item;
        }

    }                 // remove and return the item from the end
    public Iterator<Item> iterator(){return new QueueIterator();}         // return an iterator over items in order from front to end

    private class QueueIterator implements Iterator<Item> {
        private Node current = first;

        public boolean hasNext() {
            return current != null;
        }

        public void remove() {
            throw new java.lang.UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext())
                throw new NoSuchElementException();

            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    public void display(){
        Node pointer1 = first;
        System.out.println("the queue is :");
        while(pointer1 != null) {
            System.out.print(pointer1.item);
            pointer1 = pointer1.next;
        }
        System.out.println();
     }
}

*/