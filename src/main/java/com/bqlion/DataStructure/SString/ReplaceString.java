package com.bqlion.DataStructure.SString;

import com.bqlion.DataStructure.SString.StringAlgorithm.BruteFroce;

public class ReplaceString {
    public static String replace(String source,String sub,String replacement){
        int i = BruteFroce.indexOf(source,sub,0);   //用BF算法返回sub与source首次匹配的位置
        while(i != -1){     //在能匹配的情况下循环做：
            source = source.substring(0,i) +replacement + source.substring(i + sub.length()); //
            i = BruteFroce.indexOf(source,sub,i + 1);
        }
        return source;
    }
}
