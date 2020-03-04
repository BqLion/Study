package com.bqlion.Before.Java.initialization;

class Rock2{
    Rock2(int i){
        System.out.print("Rock " + i + " ");
    }
}

public class SimpleConstuctor2
{
    public static void main(String[] args) {
        for(int i = 0; i < 8;i++)
        {
            new Rock2(i);
        }
    }
}
