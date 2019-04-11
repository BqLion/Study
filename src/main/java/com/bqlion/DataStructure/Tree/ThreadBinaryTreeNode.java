package com.bqlion.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/8
 */

/*
tag若是0指向孩子节点，若是1指向前驱或者后继节点。
 */

public class ThreadBinaryTreeNode<E> {
    public E data;
    public ThreadBinaryTreeNode<E> left, right;
    public int ltag, rtag;

    public ThreadBinaryTreeNode(E data,ThreadBinaryTreeNode<E>left,ThreadBinaryTreeNode<E>right){
        this.data = data;
        this.left = left;
        this.right = right;
        this.ltag = this.rtag = 0;

    }
    public ThreadBinaryTreeNode(E data){
        this(data,null,null);
    }
    public ThreadBinaryTreeNode(){
        this(null,null,null);
    }
}
