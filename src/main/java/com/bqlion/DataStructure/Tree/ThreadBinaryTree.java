package com.bqlion.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/8
 */
public class ThreadBinaryTree<E> {
    private ThreadBinaryTreeNode<E> root;

    public ThreadBinaryTree() {
        root = null;
    }

    public ThreadBinaryTree(E[] preorder) {
        root = create(preorder);            //跟节点指向依据数组建立的二叉树
        inorderThread(root);                //对根节点进行线索化。建立二叉树、对ltag rtag线索化分为不同函数实现
    }

    int i = 0;          //递归的变量

    private ThreadBinaryTreeNode<E> create(E[] preorder) {
        ThreadBinaryTreeNode<E> p = null;
        if (i < preorder.length) {
            E element = preorder[i];
            i++;
            if (element != null) {
                p = new ThreadBinaryTreeNode<E>(element);
                p.left = create(preorder);
                p.right = create(preorder);
            }
        }
        return p;
    }

    private ThreadBinaryTreeNode<E> front = null;        //p的前驱节点front置为空,为一工作指针和双向循环链表类似

    private void inorderThread(ThreadBinaryTreeNode<E> p) {      //create是建立线索二叉树的left  right指针，本函数处理两个tag
        // 确认结束条件
        if (p == null) return;

        // 确认递归条件，进行递归
        // 根据传入参数p 减小规模
        inorderThread(p.left);          //递归地处理p的左右子树
        if (p.left == null) {            //左或者右子树为空，则tag为1，
            p.ltag = 1;
            p.left = front;              //front指针方便p指向前方
        }
        if (p.right == null)
            p.rtag = 1;                 //right为空则指向中序遍历的next
        if (front != null && front.rtag == 1)    //
            front.right = p;            //front的right指过来
        front = p;                      //front前进一步
        inorderThread(p.right);

    }

    public ThreadBinaryTreeNode<E> inNext(ThreadBinaryTreeNode<E> p) {
        if (p.rtag == 1)
            p = p.right;
        else {
            p = p.right;                     //中序遍历的逻辑就是先右子树一格，然后尝试左转到底
            while (p.ltag == 0)
                p = p.left;
        }
        return p;
    }

    public void inOrder() {
        ThreadBinaryTreeNode<E> p = root;
        if (p != null) {
            System.out.println("中根次序遍历：  ");
            while (p.ltag == 0)
                p = p.left;
            do {
                System.out.println(p.data + " ");
                p = inNext(p);
            } while (p != null);

            System.out.println();
        }
    }

}




