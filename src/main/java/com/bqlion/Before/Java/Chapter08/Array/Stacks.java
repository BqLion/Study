package com.bqlion.Before.Java.Chapter08.Array;
import java.util.*;

public class Stacks {
    static String[] months = {
            "January","February","March","April",
            "May","June","July","August","September",
            "October","November","Deceber"};

    public static void main(String[] args) {
        Stack stk = new Stack();
        for(int i =0; i <months.length; i++)
            stk.push(months[i] + " ");
        System.out.println("stk = " + stk);
        stk.addElement("The last line");
        System.out.println(
                "Element 5 = " + stk.elementAt(5));
        System.out.println("popping elements:");
        while(!stk.empty())
            System.out.println(stk.pop());
    }
    }

