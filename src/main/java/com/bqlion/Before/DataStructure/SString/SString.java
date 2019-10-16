package com.bqlion.Before.DataStructure.SString;

public interface SString {
    int length();                   //返回字符串长度
    char charAt(int index);         //返回第index个字符
    String concat(String1 str);      //返回当前串与str串合并的串
    String substring(int begin,int end);//返回当前串从begin起到end处的子串
    int indexOf(String1 pattern);        //返回pattern串在当前串第一次匹配的位置。
}
