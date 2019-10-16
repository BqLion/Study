package com.bqlion.DataStructure.SString.StringAlgorithm;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

/* *
 * Created by BqLion on 2019/3/29
 */
public class Txt2String {
    public static String Txt2String(File file){
        StringBuilder result = new StringBuilder();

        try{
            BufferedReader br = new BufferedReader(new FileReader(file));
            String s = null;
            while((s = br.readLine())!=null){
                result.append(s);
            }
            br.close();
        }catch(Exception e){
            e.printStackTrace();
        }
        return result.toString();
    }
}

