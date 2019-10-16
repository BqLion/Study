package com.bqlion.Before.DataStructure.SString.StringAlgorithm;

import java.io.File;

/* *
 * Created by BqLion on 2019/3/29
 */
public class TestAlgo {
    public static void main(String[] args) {

        BruteFroce bf = new BruteFroce();
        KMP kmp = new KMP();
        Txt2String t2s = new Txt2String();
        File pattern = new File("D:/Workplace/JavaWorkplace/J2SE/Study/src/test/java/KMPAndBFAlgoTestData/Pattern.txt");
        File target = new File("D:/Workplace/JavaWorkplace/J2SE/Study/src/test/java/KMPAndBFAlgoTestData/Target.txt");
        //类的实例

        String patternStr = t2s.Txt2String(pattern);
        String targetStr = t2s.Txt2String(target);
        //调用转换方法将测试用txt文件转换成字符串

        long KMPstartTime =  System.currentTimeMillis();
        long KMPResult = kmp.indexOf(targetStr, patternStr, 0);
        long KMPendTime =  System.currentTimeMillis();

        long BFstartTime =  System.currentTimeMillis();
        long BFResult = bf.indexOf(targetStr, patternStr, 0);
        long BFendTime =  System.currentTimeMillis();

        System.out.println("KMP result is："+ KMPResult + "  KMP runing time is : " + (KMPendTime - KMPstartTime) );
        System.out.println("BF result is: " + BFResult  + "  BF runing time is : " + (BFendTime - BFstartTime));

    }
}

