package com.bqlion.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/18
 */
public class BTree<K extends Comparable<K>>{

    private final int degree;
    private AbstractBTreeNode<K>root;

    public BTree(int degree){
        if(degree < 2){
            throw new IllegalArgumentException("degree must >= 2");
        }
        this.degree = degree;
        root = new BTreeLeaf<>(degree);
    }

    public AbstractBTreeNode<K>getRoot(){
        return root;
    }

    public void insert(K key){
        AbstractBTreeNode<K>n = root;
        if(root.isFull()){
            AbstractBTreeNode<K>newRoot = new BTreeInternalNode<>(degree);
            newRoot.insertChild(n,0);
            newRoot.splitChild(0);
            n = newRoot;
            root  = newRoot;
        }
        n.insertNotFull(key);
    }

    public void delete(K key){
        AbstractBTreeNode<K>node = root;
        node.deleteNotEmpty(key);
        if(node.nkey() == 0){
            root = node.getChild(0);
            if(root == null){
                root  = new BTreeLeaf<>(degree);

            }
        }
    }

    @Override
    public String toString(){
        return AbstractBTreeNode.BTreeToString(this.root);
    }
}

