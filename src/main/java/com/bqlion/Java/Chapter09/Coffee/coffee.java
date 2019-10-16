package com.bqlion.Java.Chapter09.Coffee;

public class coffee {
    private static long counter = 0;
    private final long id = counter++;
    public String toString(){
        return getClass().getSimpleName() + " " + id;
    }
}


