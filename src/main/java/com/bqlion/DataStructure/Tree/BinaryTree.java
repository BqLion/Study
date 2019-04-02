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
    public BinaryTree(String str){
        //
    }

    public boolean isEmpty(){
        return root == null;
    }

    public BinaryTreeNode<E>search(E element){
        LinkedStack<BinaryTreeNode<E>> stack = new LinkedStack<BinaryTreeNode<E>>();
        BinaryTreeNode<E>p = this.root;
        BinaryTreeNode<E>q = null;      //p指针遍历随动，q指针等匹配成功时记录p的位置，p随后还会遍历。
        while(p != null || !stack.isEmpty()) {        //p不null说明没到底，stack不null说明查找未结束可pop
            if (p != null){                            //没到底持续压栈
                stack.push(p);
            }
            else{
                p = stack.pop();                        //到底了出栈
                if (p.data.equals(element)) {
                    q = p;
                    return q;           //如果树里的元素有不止一个匹配，那就返回第一个匹配成功的节点。
                }
                p = p.right;                         //到底 -- 回退一格 -- 右一格 -- 再次尝试到底 -- 回退一格 --右一格
            }                                        //即用栈实现的深度优先遍历
        }
            return q;
    }

    public boolean add(E element, E index,String where){            //待添加的data，添加在哪个根节点下，左还是右
        BinaryTreeNode<E> p = search(index);
        if (p == null)
            return false;           //工作指针就位，就位失败返回false

        BinaryTreeNode<E>q = new BinaryTreeNode<E>(element);        //待添加元素给他申请一个节点
        if(where == "left"){                //q插在p的左下
            q.left = p.left;
            p.left = q;
            return true;
        }
        else if(where == "right"){
            q.right = p.right;
            p.right = q;
            return true;
        }
        else
            return false;
    }

    public boolean remove(E index,String where){        //删除index所指的元素的左或右子树
        BinaryTreeNode<E> p = search(index);
        if(p  == null)
            return false;

        if(where == "left") {
            p.left = null;
            return true;
        }
        else if(where == "right"){
            p.right = null;
            return true;
        }
        else
            return false;
    }

    public boolean exchange(E index,E element){     //改：把第一个index元素替换成element
        if(element == null)
            return false;

        BinaryTreeNode<E> p = search(index);
        if(p == null)
            return false;
        else
        p.data = element;
        return true;
    }
}
