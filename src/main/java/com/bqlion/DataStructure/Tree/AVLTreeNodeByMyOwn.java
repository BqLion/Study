package com.bqlion.DataStructure.Tree;

import org.checkerframework.checker.units.qual.A;

/* *
 * Created by BqLion on 2019/
 */
public class AVLTreeNodeByMyOwn<T extends Comparable>{      //T占位符要求可比较

    public AVLTreeNodeByMyOwn<T>left;

    public AVLTreeNodeByMyOwn<T>right;

    public int height;

    public T data;

    public AVLTreeNodeByMyOwn(AVLTreeNodeByMyOwn<T>left,AVLTreeNodeByMyOwn<T>right,T data,int height){
        this.left = left;
        this.right = right;
        this.data = data;
        this.height = height;
    }

    public AVLTreeNodeByMyOwn(T data){
        this(null,null,data,0);
    }
}
