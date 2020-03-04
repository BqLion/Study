package com.bqlion.Before.Java.initialization;

class Rock{
    Rock(){
        System.out.print("rock ");
    }
}
public class SimpleConstructor {
    public static void main(String[] args) {
        for(int i = 0; i<10;i++)
        {
            new Rock();
        }
    }
}
