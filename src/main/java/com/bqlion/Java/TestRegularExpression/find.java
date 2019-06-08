package com.bqlion.Java.TestRegularExpression;
import java.util.regex.*;
import static net.mindview.util.Print.*;

public class find {
    public static void main(String[] args){
        Matcher m = Pattern.compile("\\w+").matcher("Evening is full of the linnet`s wings");
        while(m.find())
            printnb(m.group() + " ");
        print();
        int i = 0;
        while(m.find(i)){
            printnb(m.group() + " ");
            i++;
        }
    }
}
