package com.bqlion.Before.Java.TestRegularExpression;
import java.util.regex.*;
import net.mindview.util.*;

public class JGrep {
    public static void main(String[] args)throws Exception {
        if(args.length < 2){
            System.out.println("usage java JGrep file regex");
            System.exit(0);
        }
        Pattern p = Pattern.compile(args[1]);
        int index = 0;
        Matcher m = p.matcher("");
        for(String line : new TextFile(args[0])) {
            m.reset(line);
            while(m.find())
                System.out.println(index++ + ": " + m.group() + ": " + m.start());

        }
    }
}
