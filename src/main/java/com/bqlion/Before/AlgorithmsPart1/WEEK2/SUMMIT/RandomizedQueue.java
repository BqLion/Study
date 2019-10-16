package com.bqlion.Before.AlgorithmsPart1.WEEK2;

import java.util.Iterator;
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

    private void resize(int newSize){
        Item[] temp = (Item[])new Object[newSize];
        for(int i =0; i <= Rqueue.length; i++)
            temp[i] = Rqueue[i];

        Rqueue = temp;
    }

    public void enqueue(Item item){

        if(item == null)
            throw new java.lang.IllegalArgumentException();
        else
        {
            if (count == Rqueue.length)
            {
                resize(2 * Rqueue.length);
            }
            Rqueue[count++] = item;
        }
    }

    public Item dequeue(){

        Item itemD = Rqueue[count];

        if(count == 0)
            throw new IllegalArgumentException();

        else
        {
            int deleteNum = StdRandom.uniform(count);
            Rqueue[deleteNum] = Rqueue[count];
            Rqueue[count] = null;
        }

        if(count > 0 && count == Rqueue.length / 4)
            resize(Rqueue.length/2);

        return itemD;
    }


    public Item sample(){
        if(count == 0)
            throw new java.util.NoSuchElementException();
        else

        return Rqueue[StdRandom.uniform(count)];
    }                     // return a random item (but do not remove it)

    public Iterator<Item> iterator(){
        return new QueueIterator();
    }

    private class QueueIterator implements Iterator<Item>
    {
        private int current = count; // current表示数组中有效数据个数
        private Item[] iterItemArray;
        public QueueIterator() {
            iterItemArray = (Item[])new Object[current];
            for (int i = 0; i < current; i++)
                iterItemArray[i] = Rqueue[i];
            // StdRandom.shuffle(iterItemArray);
        }

        public boolean hasNext()
        {

            return current != 0;
        }

        public Item next()
        {
            if (!hasNext())
            {
                throw new java.util.NoSuchElementException();
            }
            else
            {
                int findi = StdRandom.uniform(current);
                Item itemi = iterItemArray[findi];
                --current;
                iterItemArray[findi] = iterItemArray[current];
                iterItemArray[current] = itemi;

                return itemi;
            }
        }


        public void remove()
        {
            throw new java.lang.UnsupportedOperationException("remove method is unsupported");
        }
    }

    public static void main(String[] args){}
}