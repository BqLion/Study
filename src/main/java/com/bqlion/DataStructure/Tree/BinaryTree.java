package com.bqlion.DataStructure.Tree;

import com.bqlion.DataStructure.Stack.LinkedStack;

/* *
 * Created by BqLion on 2019/4/1
 */
public class BinaryTree <E>{
    private BinaryTreeNode<E> root;     //根节点是二叉树的本体

    public BinaryTree(){
        root = null;
    }
    public BinaryTree(BinaryTreeNode<E> root){
        this.root = root;
    }

    public boolean isEmpty(){
        return root == null;
    }

    public BinaryTreeNode<E>search(E element){
        LinkedStack<BinaryTreeNode<E>> stack = new LinkedStack<BinaryTreeNode<E>>();
        BinaryTreeNode<E>p = this.root;
        BinaryTreeNode<E>q = null;      //p指针遍历随动，q指针等匹配成功时记录p的位置，p随后还会遍历。
        while(p != null || !stack.isEmpty())
            if(p!=null){
                stack.push(p);
            }
            else{
            p = stack.pop();
            if(p.data.equals(element)){
                q = p;
                return q;           //如果树里的元素有不止一个匹配，那就返回第一个匹配成功的节点。
            }
            p = p.right;
            }
            return q;
    }

    public boolean add(E element, BinaryTreeNode<E> index,String where){            //待添加的data，添加在哪个根节点下，左还是右
        BinaryTreeNode<E> p = search(index.data);
        if (p == null)
            return false;           //工作指针就位，就位失败返回false


        BinaryTreeNode<E>q = new BinaryTreeNode<E>(element);        //待添加元素给他申请一个节点
        if(where == "left"){                //q插在p的左下
            q.left = p.left;
            p.left = q;
        }
        else
        {
            q.right = p.right;
            p.right = q;
        }
        return true;
    }

}
