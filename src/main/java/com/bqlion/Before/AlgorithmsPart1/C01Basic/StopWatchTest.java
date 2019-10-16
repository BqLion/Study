package com.bqlion.Before.AlgorithmsPart1.C01Basic;

import java.util.Random;
/* *
 * Created by BqLion on 2019/5/22
 */
public class StopWatchTest {
    public static double timeTrial(int N){
        int MAX = 1000000;
        int[] a = new int[N];
        Random  rand = new Random();
        for(int i = 0;i < N; i++)
            a[i] = rand.nextInt(MAX);
        StopWatch timer = new StopWatch();
        int cnt = ThreeSum.count(a);
        System.out.println(cnt);
        return timer.elapsedTime();
    }

    public static void main(String[] args) {
        for(int N = 250;true;N += N){
            double time = timeTrial(N);
            System.out.println(N + " "  + time);
        }
    }
}
