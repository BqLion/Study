package com.bqlion.Before.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/1
 */
public class BinaryTreeNode<E> {
    public E data;
    public BinaryTreeNode<E> left;
    public BinaryTreeNode<E> right;

    public BinaryTreeNode(E data,BinaryTreeNode<E>left,BinaryTreeNode<E>right){
        this.data = data;
        this.left = left;
        this.right = right;
    }

    public BinaryTreeNode(E data){
        this(data,null,null);
    }

    public BinaryTreeNode(){
        this(null,null,null);
    }
}
