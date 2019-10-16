package com.bqlion.Java.Calculator;

import com.google.common.base.Strings;

import static net.mindview.util.Print.print;

public class TestMain {

    public static void main(String[] args) {
        String input = "5+(10/2)-7*(2*6)#";
        boolean isNullOrEmpty = Strings.isNullOrEmpty(input);
        print(isNullOrEmpty);
        Calculator calculator = new Calculator();
        print(calculator.calc(input));
    }


}
