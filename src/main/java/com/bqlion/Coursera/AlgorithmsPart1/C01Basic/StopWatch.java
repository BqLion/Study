package com.bqlion.Coursera.AlgorithmsPart1.C01Basic;



/* *
 * Created by BqLion on 2019/5/22
 */
public class StopWatch {
    private long start;

    StopWatch(){
        start = System.currentTimeMillis();
    }

    public double elapsedTime(){
        long now = System.currentTimeMillis();
        return (now - start)/1000.0;
    }

}
