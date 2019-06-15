package com.bqlion.Coursera.AlgorithmsPart1.WEEK2;

import java.util.Iterator;
import java.util.NoSuchElementException;
import edu.princeton.cs.algs4.StdRandom;

/* *
 * Created by BqLion on 2019/6/14
 */
public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] Rqueue;
    int count;

    public RandomizedQueue(){
        Rqueue = (Item[])new Object[1];
        count = 0;
    }// construct an empty randomized queue


    public boolean isEmpty(){
        return count == 0;
    }                 // is the randomized queue empty?
    public int size(){
        return count;
    }                        // return the number of items on the randomized queue
    public void enqueue(Item[] theArray,Item item){
        if((count ++) == theArray.length)      //if full
            resize(2 * theArray.length);      //double the array

        theArray[count++] = item;             //value the array[size]
        count++;                            //count ++
    }           // add the item

    private int theCountOfTheArray(Item[] theArray){
        if(theArray == Rqueue)return count;

        else if(theArray == ) return rank;
        else return 0;
    }


    private void resize(int newSize){
        Item[] temp = (Item[])new Object[newSize];
        for(int i =0; i <= Rqueue.length; i++)
            temp[i] = Rqueue[i];

        Rqueue = temp;
    }

    public Item dequeue(Item[] theArray){
        int n = StdRandom.uniform(count) + 1;
        exchange(theArray,1,n);  // n范围是从1到n

        Item temp = theArray[1];
        theArray[1] = null;
        theCountOfTheArray(theArray[]);

        if(count < theArray.length/4)
            resize(theArray.length / 2);

        return temp;
    }                    // remove and return a random item

    private void exchange(Item[] theArray,int position1,int position2){
        theArray[0] = theArray[position1];
        theArray[position1] = theArray[position2];
        theArray[position2] = theArray[0];
    }
    public Item sample(){
        return Rqueue[StdRandom.uniform(Rqueue.length + 1)];
    }                     // return a random item (but do not remove it)

    public Iterator<Item> iterator(){
        return new RandomIterator();
    }

    public getIteratorArray(){
        return iterator();
    }


    private class RandomIterator implements Iterator<Item>{
        private int rank;
        Item[] IteratorArray;


        public RandomIterator(){
            rank = count;
            Item[] IteratorArray = (Item[])new Object[rank];
            for(int i = 0; i < rank; i++)
                IteratorArray[i] = Rqueue[i];
        }

        public Item[] getIteratorArray() {
            return IteratorArray;
        }

        @Override
        public boolean hasNext() {

            return rank == 0;
        }

        @Override
        public Item next() {
            if (rank == 0)
                throw new NoSuchElementException("there are no more items!");

            int m = StdRandom.uniform(rank + 1);
            exchange(IteratorArray,1,m);
            rank --;
            return dequeue(IteratorArray);
        }
    }

    // return an independent iterator over items in random order
    public static void main(String[] args)   // unit testing (optional)
}