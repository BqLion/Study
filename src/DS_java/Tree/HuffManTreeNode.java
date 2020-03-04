package com.bqlion.Before.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/12
 */


/*
哈夫曼编码就是用二叉树实现的带权综合最短路径（节点深度）的不定长编码合集
最常用的字符就在浅层
不常用的字符放在深层编码长度较长，使综合长度较短

树节点由权值，双亲节点所在位置，左右子树所在位置四个元素构成

 */
public class HuffManTreeNode {
    int weight,parent,left,right;

    public HuffManTreeNode(int weight){             //节点初始化无父母左右子树关系时默认值为-1。
        this.weight = weight;
        this.parent = this.left = this.right = -1;
    }
    public HuffManTreeNode(){               //缺省构造函数默认权值为0其他不变默认为-1
        this(0);
    }
}

