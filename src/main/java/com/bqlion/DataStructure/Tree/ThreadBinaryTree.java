package com.bqlion.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/8
 */
public class ThreadBinaryTree<E>{
    private ThreadBinaryTreeNode<E> root;
    public ThreadBinaryTree(){
        root = null;
    }
    public ThreadBinaryTree(E[] preorder){
        root = create(preorder);            //跟节点指向依据数组建立的二叉树
        inorderThread(root);                //对根节点进行线索化。建立二叉树、对ltag rtag线索化分为不同函数实现
    }

    int i = 0;          //递归的变量
    private ThreadBinaryTreeNode<E>create(E[] preorder){
        ThreadBinaryTreeNode<E> p = null;
        if(i < preorder.length){
            E element = preorder[i];
            i++;
            if(element != null){
                p = new ThreadBinaryTreeNode<E>(element);
                p.left = create(preorder);
                p.right = create(preorder);
            }
        }
        return p ;
    }

    private ThreadBinaryTreeNode<E>front = null;        //p的前驱节点front置为空,为一工作指针和双向循环链表类似
    private void inorderThread(ThreadBinaryTreeNode<E> p){      //create是建立线索二叉树的left  right指针，本函数处理两个tag
        if(p != null){
            inorderThread(p.left);
            if(p.left == null) {
                p.ltag = 1;
                p.left = front;
            }
            if(p.right == null)
                p.rtag = 1;
            if(front != null && front.rtag == 1)
                front.right = p;
            front = p;
            inorderThread(p.right);
            }
        }
    }


}
