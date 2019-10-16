package com.bqlion.Before.AlgorithmsPart1.C01Basic;

/* *
 * Created by BqLion on 2019/5/22
 */
public class ThreeSum {
    public static int count(int[] a){
        int N = a.length;
        int cnt = 0;
        for(int i = 0;i < N; i++)
            for(int j = i + 1; j < N; j++)
                for(int k = j+1;k < N; k++)
                    if(a[i] - a[j] + a[k] == 0)             //如何让数组里的任何三个数做相加相减的算法：
                        cnt ++;                             //三个for，分别i= 0; j = i + 1;k = j + 2
                    return cnt;
    }
}
