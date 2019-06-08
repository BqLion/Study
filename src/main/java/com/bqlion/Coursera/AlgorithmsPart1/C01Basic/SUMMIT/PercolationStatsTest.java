//妈卖批终于调通了，以后一定要注意用一维数组表示二维数组的时候第一行最右和第二行最左实际连通的事实。
//这样isFull测试时第二行第一列等就不会错误报true了

package com.bqlion.Coursera.AlgorithmsPart1.C01Basic.SUMMIT;

public class PercolationStatsTest {
    public static void main(String[] args) {
        Percolation p = new Percolation(6);
        p.open(1, 6);
        p.open(2, 6);
        p.open(3, 6);
        p.open(4, 6);
        p.open(5, 6);
        p.open(5, 5);
        p.open(4, 4);
        p.open(3, 4);
        p.open(2, 4);
        p.open(2, 3);
        p.open(2, 2);
        p.open(2, 1);
        p.display();
        System.out.println(p.isOpen(2, 1));
        System.out.println(p.isFull(2, 1));


        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++)
                System.out.print(p.isFull(i, j) + " ");
            System.out.println();
            System.out.println();
        }

        int m = p.condition.length;
            for (int n = 0; n < m; n++){
                System.out.print(p.condition[n] + " ");
                if((n+1) % 6 == 0) System.out.println();
            }
        }

    }
