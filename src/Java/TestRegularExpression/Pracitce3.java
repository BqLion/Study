package com.bqlion.Before.Java.TestRegularExpression;
import java.util.*;

import static net.mindview.util.Print.print;

public class Pracitce3 {
    public static String Set(int a,int b,int down,int up){
        Random rand = new Random();
        double[][] Ar = new double[a][b];
        for(int i = 0;i < Ar.length; i++){
            for(int j = 0; j < Ar[i].length; j++){
            Ar[i][j] = (up - down)*(rand.nextDouble()) + down;            }
        }
        return (Arrays.deepToString(Ar));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        print("Please put Array`s Long and Width,MinValue and MaxValue");
        int l = sc.nextInt();
        int w = sc.nextInt();
        int min = sc.nextInt();
        int max = sc.nextInt();

        print(Set(l,w,min,max));
    }
}
