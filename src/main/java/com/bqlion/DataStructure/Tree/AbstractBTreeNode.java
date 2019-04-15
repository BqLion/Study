package com.bqlion.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/15
 */
/*
    b树是一种m叉树，其中节点满足：一个节点最多有m个子树，根节点不是叶子时，至少有两颗子树。
                                除根节点外，所有非终端节点至少有m/2颗子树
                                有s个子树的非叶节点具有n = s-1个关键字
                                用抽象类先写出一个类的基本函数情况，再用如下文的绿色专业注解说明各个函数的情况
                                用@param @return等等注释，非常清晰明了。类似于C的头文件

 */
public abstract class AbstractBTreeNode<K extends Comparable<K>>{            //Comparable是排序类接口，实现了此接口的类可以被排序
                                                                            //可以用arrays.sort和collection.sort等方法来实现
    protected final int degree;         //B tree的节点的本体就是存储一个“度”。

    AbstractBTreeNode(int degree){
    if(degree < 2){
        throw new IllegalArgumentException("degree must >= 2");         //throwIleagArgu是抛出异常参数的意思，代表未接到合法参数
    }
    this.degree = degree;
     }

    /**
     * If the node is Leaf.
     * @return true is  Leaf,False is not.
     */
    abstract boolean isLeaf();

    /**
     * Search Key in B tree.
     *
     * @param key the key to search
     * @throws java.lang.RuntimeException if node is full.
     */
    abstract K search(K key);

    /**
     * Insert a key into a node when the node is not full
     *
     * @param key the key to insert
     * @throws java.lang.RuntimeException if node is full
     */
    abstract void insertNotFull(K key);


}


