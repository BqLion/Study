package com.bqlion.After.DataStruct.Tree;

import com.bqlion.After.DataStruct.List.Node;
import com.bqlion.Before.DataStructure.Tree.BinaryTree;
import org.omg.CORBA.OBJ_ADAPTER;

public class BinaryTreeNode implements Node {

/********************field**********************************/
    private Object data;                    //数据域
    private BinaryTreeNode parent;
    private BinaryTreeNode lChild;
    private BinaryTreeNode rChild;
    private int height;                     //以此节点为根的树的高度
    private int size;                       //该节点子孙数量(包含自己)

/********************field**********************************/


/********************Constructor****************************/
    public BinaryTreeNode(){this(null);}

    public BinaryTreeNode(Object e){
        data = e;
        height = 0;
        size = 1;
        parent = lChild = rChild = null;
    }
/********************Constructor****************************/


/********************Method*********************************/
    public Object getData(){return this.data;}

    public void setData(Object e){this.data = e;}

    public boolean hasLeftChild(){return lChild != null;}

    public boolean hasRightChild(){return rChild != null;}

    public boolean hasParent(){return parent != null;}

    public BinaryTreeNode getlChild(){return lChild;}

    public BinaryTreeNode getrChild(){return rChild;}

    public BinaryTreeNode getParent() {return parent;}

/********************Method*********************************/

}

