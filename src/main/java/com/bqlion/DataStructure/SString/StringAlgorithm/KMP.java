/*
1.KMP算法目标串不回溯，一直向前滑动。时间复杂度 O(m + n)
2.找出部分模式串的对称性（next数组），充分利用已比较的成果（下一次 j= 多少）。
 */
package com.bqlion.DataStructure.SString.StringAlgorithm;

public class KMP {
    public static int indexOf(String target,String pattern,int start){
        if(target != null && pattern!= null && pattern.length() > 0 && target.length()>=pattern.length()){
            int i = start,j = 0;
            int[] next = getNext(pattern);
            while(i < target.length()){
                if(j == -1 || target.charAt(i) == pattern.charAt(j)){
                    i++;        //i是目标串，只增不减，加到头就是匹配失败
                    j++;
                }
                else
                    j = next[j];        //充分利用模式串的内对称性，模式串从哪个字符开始匹配由next数组决定

                if (j == pattern.length())  //模式串完全匹配返回匹配地点
                    return i - j;
            }
        }
        return -1;
    }
    private static int[] getNext(String pattern){
        int j = 0,k = -1;                           //k前j后
        int [] next = new int[pattern.length()];
        next[0] = -1;                               //数组第一项等于-1
        while(j <pattern.length()-1){
            if(  k == -1 || pattern.charAt(j) == pattern.charAt(k)){   //首次运行或所有元素均相同时持续自增
                j++;                                        //圆规两脚并拢前移
                k++;
                if(pattern.charAt(j) != pattern.charAt(k))
                    next[j] = k;            //打破不同则数组值等于前指针
                else
                    next[j] = next[k];      //持续相同则数组前值持续传给后值
            }
            else
                k = next[k];                    //圆规后脚不动前脚回到开头
        }
        return next;
    }
}
