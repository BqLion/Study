package com.bqlion.DataStructure.Tree;
import com.bqlion.DataStructure.Stack.LinkedStack;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

/* *
 * Created by BqLion on 2019/4/6
 */
public class BinaryTree <E>{
    private BinaryTreeNode<E> root;     //根节点是二叉树的本体

    public BinaryTree(){
        root = null;
    }       //构造函数，缺省参数 则根为null
    public BinaryTree(BinaryTreeNode<E> root){
        this.root = root;
    }//构造函数，给定node为根
    public BinaryTree(E[] preorder){ this.root = create(preorder); }//构造函数。给定先序遍历空位null的E[]数组
    int i = 0;
    private BinaryTreeNode<E> create(E[] preorder){
        BinaryTreeNode<E> p = null;     //根部为null
        if(i < preorder.length){
            E elem = preorder[i];
            i ++;
            if(elem != null){
                p = new BinaryTreeNode<E>(elem);
                p.left = create(preorder);
                p.right = create(preorder);
            }
        }
        return p;
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

    public int height(){
        return height(root);
    }

    public int height(BinaryTreeNode<E> p) {
        if (p != null) {
            int ld = height(p.left);
            int rd = height(p.right);
            return (ld >= rd) ? ld + 1 : rd + 1;
        }
        return 0;
    }

 /*   public void display(){
        for (int i = 0; i <= height(); i++){
            for(int j = 0; j <= (2^j - 1); j++){
                System.out.println();
            }
            System.out.println("/n");
        }
    }
    */                                  //没有思路，只会迭代写不下去了。考虑问题要善用数据结构，如下队列：

    public ArrayList<ArrayList<Object>> display(){
        ArrayList<ArrayList<Object>> result = new ArrayList<>();        //输出树可类比矩阵，二维数组好用
        if(root == null){
            return result;
        }

        Queue<BinaryTreeNode>q = new LinkedList<BinaryTreeNode>();      //
        q.add(root);
        while(!q.isEmpty()){
            int current = 0;
            int size = q.size();                           //root先入队，当队列非空时，入队的根全出，子节点全入
            ArrayList<Object>value = new ArrayList<>();
            Iterator<BinaryTreeNode>it = q.iterator();
            while(it.hasNext()){
                value.add(it.next().data);     //把队列里的所有元素加入一维数组
            }
            result.add(value);
            while(current < size){             //本层节点全出，子节点全入
            BinaryTreeNode node = q.poll();
            if(node.left != null)q.add(node.left);
            if(node.right != null)q.add(node.right);
            current++;
            }
        }
        return result;
    }

    public void PrintTree(ArrayList tree){
        for(int i = 0; i < tree.size(); i++){
            System.out.println(tree.toArray()[i]);
        }
    }
}
