package com.bqlion.study.Chapter08.Collection;
import java.util.*;

public class AddingGroups {
    public static void main(String[] args) {
        Collection<Integer>collection =
                new ArrayList<Integer>(Arrays.asList(1,2,3,4,5));   //Array.asList 方法可接受一个数组或者用逗号分隔的元素列表
    Integer[] moreInts  = {6,7,8,9,10};                  //创建一个Integer型数组
    collection.addAll(Arrays.asList(moreInts));          //容器添加元素使用addAll(Arrays.asList(Intergr))
    Collections.addAll(collection,11,12,13,14,15);
    Collections.addAll(collection,moreInts);
    List<Integer> list = Arrays.asList(16,17,18,19,20);
    list.set(1,99);
    System.out.println(collection);
    }
}
