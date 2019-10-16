package src.main.java.com.bqlion.Tools;

/* *
 * Created by BqLion on 2019/9/24
 */

import java.io.File;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ReadFile {
    public static void main(String args[]) {
        try { // 防止文件建立或读取失败，用catch捕捉错误并打印，也可以throw

            /* 读入TXT文件 */
            String pathname = "D:\\colName.txt"; // 绝对路径或相对路径都可以，这里是绝对路径，写入文件时演示相对路径

            File filename = new File(pathname); // 要读取以上路径的input。txt文件

            File writename = new File("D:\\output.txt");
            writename.createNewFile(); // 创建新文件
            BufferedWriter out = new BufferedWriter(new FileWriter(writename));

            InputStreamReader reader = new InputStreamReader(
                    new FileInputStream(filename)); // 建立一个输入流对象reader
            BufferedReader br = new BufferedReader(reader); // 建立一个对象，它把文件内容转成计算机能读懂的语言
            Pattern p =Pattern.compile("\"(.*?)\"");
            String line = "";
            line = br.readLine();
            while (line != null) {
                line = br.readLine(); // 一次读入一行数据


                    out.write(line); // \r\n即为换行


            }
            out.flush(); // 把缓存区内容压入文件
            out.close(); // 最后记得关闭文件

            /* 写入Txt文件 */

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

