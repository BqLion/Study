package com.bqlion.DataStructure.Tree;

/**
 * Avl树是一种自平衡的二叉搜索树，每次增删元素时都会检测本节点左右子树高度是否相差超过1，若超过会引发
 * 旋转的操作，根据插入元素位置为右右，左左，左右，右左，分别对应为左旋右旋左右旋右左旋
 *
 */

/* *
 * Created by BqLion on 2019/5/6
 */
public class AVLTreeByMyOwn<T extends Comparable> {
    private AVLTreeNodeByMyOwn<T> root;

    public AVLTreeByMyOwn(){
        this.root = null;
    }

    public AVLTreeByMyOwn(AVLTreeNodeByMyOwn<T> root){
        this.root = root;
    }

    public  AVLTreeNodeByMyOwn rotateRR(AVLTreeNodeByMyOwn p){      //单次右旋是p所指节点的左子树的左子树导致失衡
        AVLTreeNodeByMyOwn w = p.left;          //工作指针w指向p的左孩子

        p.left = w.right;

        w.right = p;

        return w;
    }

    public AVLTreeNodeByMyOwn rotateLL(AVLTreeNodeByMyOwn p){
        AVLTreeNodeByMyOwn w = p.right;

        p.right = w.left;

        w.left = p;

        return w;
    }

    public AVLTreeNodeByMyOwn rotateLR(AVLTreeNodeByMyOwn P){

    }


}
