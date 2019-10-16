package com.bqlion.Java.TestRegularExpression;
import java.util.regex.*;
import java.util.*;
import static net.mindview.util.Print.*;

public class split {
    public static void main(String[] args) {
        String input =
        "This !!unusual use!!of exclamation!!1points";
        print(Arrays.toString(Pattern.compile("!!").split(input)));
        print(Arrays.toString(Pattern.compile("!!").split(input,3)));
    }
}
