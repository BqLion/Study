package com.bqlion.Before.AlgorithmsPart1.WEEK2;

/* *
 * Created by BqLion on 2019/6/15
 */
/**
 *


import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Permutation {
    public static void main(String[] args) {
        int k = Integer.parseInt(args[0]);

        RandomizedQueue<String> myRandomizedQueue = new RandomizedQueue<String>();
        while (!StdIn.isEmpty())
            myRandomizedQueue.enqueue(StdIn.readString());
        for (int i = 0; i < k; ++i)
            StdOut.println(myRandomizedQueue.dequeue());
    }
}

 */