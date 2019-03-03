/* package com.bqlion.study.TestRegularExpression;
import javafx.beans.value.ObservableFloatValue;

import java.util.*;

public class IceCream {
    private static Random ramd = new Random(47);
    static final String[] FLAVORS = {
    "Chocolate","Strawberry","Vanilla Fudge Swirl","Mint Crip","Mocha Almod Fudge","Rum Raisin","Praline Cream,""Mud Pie"};
    public static String[] flavorSet(int n){
        if(n > FLAVORS.length)
            throw new IllegalArgumentException("Set too big");
        String[] result = new String[n];
        boolean[] picked = new boolean[FLAVORS.length];
        for(int i = 0;i < n;i++){
            int i;
            do {
                t = rand.nextInt(FLAVORS.length);
                while(picked[t]);
                results[i] = FLAVORS[t];
                picked[t]  = true;
            }
            return results;
        }
        public static void main(String[] args){
            for (int i = 0;i<7；i++)
                System.out.println(Array.toString(flavorSet(3)));
        }
    }
}
*/