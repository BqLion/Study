package com.bqlion.Java.initialization;

import static net.mindview.util.Print.print;


public class OptionalTrailingArguments
{
    static void f(int required,String...trailing){
    print("required: " + required + " ");
    for(String s :trailing)
        print(s + " " + "\n");
    }

    public static void main(String[] args) {
        f(1,"one");
        f(2,"two","three");
        f(0);
    }
}
