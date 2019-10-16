package com.bqlion.Before.Java.TestRegularExpression;
import java.util.regex.*;
import java.util.*;

public class TheadAnalyzer {
    static String threatData =
    "58.27.82.1412@02/10/2002\n" +
    "28.27.52.1412@02/10/2022\n" +
    "23.45.82.1452@02/10/2022\n" +
    "58.27.82.1562@02/10/2032\n" +
    "46.27.42.1242@02/30/2302\n" +
    "[Next log section with different data format]";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(threatData);
        String pattern = "(\\d+[.]\\d+[.]\\d+[.]\\d+)@" + "(\\d{2}/\\d{2}/\\d{4})";
        while(scanner.hasNext(pattern)){
            scanner.next(pattern);
            MatchResult match = scanner.match();
            String ip = match.group(1);
            String date = match.group(2);
            System.out.format("Thread on %s from %s \n",date,ip);
        }
    }
}
