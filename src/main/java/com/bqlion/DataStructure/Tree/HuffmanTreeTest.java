package com.bqlion.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/15
 */
public class HuffmanTreeTest {
    public static void main(String[] args) {
        int[] initArray = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        HuffmanTree hfmt = new HuffmanTree(initArray);
        String[] temp = hfmt.huffmanCode();
        for(int i = 0; i < temp.length ; i++)
        System.out.println(temp[i]);
    }
}
