package com.bqlion.Before.DataStructure.Tree;

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

    public AVLTreeByMyOwn() {
        this.root = null;
    }

    public AVLTreeByMyOwn(AVLTreeNodeByMyOwn<T> root) {
        this.root = root;
    }

    public int deep(AVLTreeNodeByMyOwn<T> p){
        if (p == null)
            return 0;
        else {
            int left = deep(p.left);
            int right = deep(p.right);
            return 1 + Math.max(left,right);
        }
        }

     public int height(AVLTreeNodeByMyOwn<T>p){
        return (deep(root) - deep(p));

     }

    public AVLTreeNodeByMyOwn rotateRR(AVLTreeNodeByMyOwn p) {      //单次右旋是p所指节点的左子树的左子树导致失衡
        AVLTreeNodeByMyOwn w = p.left;          //工作指针w指向p的左孩子

        p.left = w.right;

        w.right = p;

        return w;
    }

    public AVLTreeNodeByMyOwn rotateLL(AVLTreeNodeByMyOwn p) {
        AVLTreeNodeByMyOwn w = p.right;

        p.right = w.left;

        w.left = p;

        return w;
    }

    public AVLTreeNodeByMyOwn rotateLR(AVLTreeNodeByMyOwn p) {
        AVLTreeNodeByMyOwn w = p.left;
        w = rotateLL(w);
        p = rotateRR(p);
        return p;
    }

    public AVLTreeNodeByMyOwn rotateRL(AVLTreeNodeByMyOwn p) {
        AVLTreeNodeByMyOwn w = p.right;
        w = rotateRR(w);
        p = rotateLL(p);
        return p;
    }

    public AVLTreeNodeByMyOwn<T> insert(T data, AVLTreeNodeByMyOwn p) {
        if (p == null) {
            p = new AVLTreeNodeByMyOwn<T>(data);
        } else if (data.compareTo(p.data) < 0) {
            p.left = insert(data, p.left);   //递归地找到插入位置

            if (height(p.left) - height(p.right) == 2) {
                if (data.compareTo(p.left.data) < 0)
                    p = rotateRR(p);
            } else
                p = rotateLR(p);
        } else if (data.compareTo(p.data) > 0)
            p.right = insert(data, p.right);

        if (height(p.right) - height(p.left) == 2) {
            if (data.compareTo(p.right.data) < 0) {
                p = rotateRL(p);
            } else {
                p = rotateLR(p);
            }
        } else
            ;
        p.height = Math.max(height(p.left), height(p.right)) + 1;
        return p;
    }                                   //插入点是左左，右右，左右，右左分别对应不同的策略。

    private AVLTreeNodeByMyOwn<T> remove(T data,AVLTreeNodeByMyOwn<T> p){

        if(p ==null)
            return null;

        int result=data.compareTo(p.data);

        if(result<0){
            p.left=remove(data,p.left);

            if(height(p.right)-height(p.left)==2){
                AVLTreeNodeByMyOwn<T> currentNode=p.right;
                if(height(currentNode.left)>height(currentNode.right)){
                    p=rotateRR(p);
                }else{
                    p=rotateLL(p);
                }
            }

        }
        else if(result>0){
            p.right=remove(data,p.right);

            if(height(p.left)-height(p.right)==2){
                AVLTreeNodeByMyOwn<T> currentNode=p.left;

                if(height(currentNode.right)>height(currentNode.left)){
                    p=rotateRR(p);
                }else{

                    p=rotateLL(p);
                }
            }
        }
        else if(p.right!=null&&p.left!=null){

  //          p.data=findMin(p.right).data;

            p.right = remove( p.data, p.right );
        }
        else {
            p=(p.left!=null)? p.left:p.right;
        }

        if(p!=null)
            p.height = Math.max(height( p.left ), height( p.right ) ) + 1;
        return p;
    }

}




