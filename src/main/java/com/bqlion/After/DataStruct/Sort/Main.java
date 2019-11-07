package com.bqlion.After.DataStruct.Sort;
import com.sun.xml.internal.ws.api.model.wsdl.WSDLOutput;

import java.util.Scanner;


public class Main {
    /********************field**********************************/
    public static final int N = 100;
    public static int[] queen = new int[N];
    public static int n;
    public static int sum = 0;
/********************field**********************************/

    /********************Method*********************************/

    static boolean attack(int row, int col) {
        for (int i = 0; i < row; ++i) {
            if ((queen[i] == col) || Math.abs(queen[i] - col) == Math.abs(i - row))
        }
        return false;
    }//检查是否冲突


    public static void main (String[]args){
        Main test = new Main();
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        place(0);
        System.out.println("总共有：" + sum);
    }


    static void place(int cur) {
        //cur代表当前行，queen【】存储棋子放在哪一列上
        for (int i = 0; i < n; i++) {
            if (attack(cur, i)) {
                queen[cur] = i;
                if (cur == n - 1) {
                    char temp[][] = new char[n][n];
                    for (int m = 0; m < n; ++m) {

                        temp[m][queen[m]] = '#';

                    }
                    for (int m = 0; m < n; ++m) {
                        for (int g = 0; g < n; ++g) {
                            if (temp[m][g] != '#')
                                temp[m][g] = '&';
                            System.out.println(temp[m][g]);
                        }
                        System.out.println();
                    }
                    System.out.println();
                    sum++;
                } else
                    place(cur + 1);
            }
        }



/********************Method*********************************/

    }
}