package com.bqlion.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/24
 */

import java.util.AbstractMap.SimpleEntry;
import java.util.ArrayList;
import java.util.List;
import java.util.Map.Entry;

public class BPlusTreeNode <K extends Comparable<K>,V> {
    protected boolean isLeaf;

    protected boolean isRoot;

    protected BPlusTreeNode<K, V> parent;

    protected BPlusTreeNode<K, V> previous;

    protected BPlusTreeNode<K, V> next;

    protected List<Entry<K, V>> entries;      //链表，里边放的是key - value对，储存主要数据

    protected List<BPlusTreeNode<K, V>> children;     //链表，里边放的是树的节点。是孩子节点

    public BPlusTreeNode(boolean isLeaf) {
        this.isLeaf = isLeaf;
        entries = new ArrayList<Entry<K, V>>();

        if (!isLeaf) {
            children = new ArrayList<BPlusTreeNode<K, V>>();
        }
    }

    public BPlusTreeNode(boolean isLeaf, boolean isRoot) {
        this(isLeaf);
        this.isRoot = isRoot;
    }

    public V get(K key) {
        if (isLeaf) {
            int low = 0, high = entries.size() - 1, mid;
            int comp;
            while (low <= high) {
                mid = (low + high) / 2;
                comp = entries.get(mid).getKey().compareTo(key);
                if (comp == 0) {
                    return entries.get(mid).getValue();
                } else if (comp < 0) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return null;
        }       //若是叶子节点用二分查找

        if (key.compareTo(entries.get(0).getKey()) < 0) {
            return children.get(0).get(key);
        } else if (key.compareTo(entries.get(entries.size() - 1).getKey()) >= 0) {
            return children.get(children.size() - 1).get(key);
        } else {
            int low = 0, high = entries.size() - 1, mid = 0;
            int comp;
            while (low <= high) {
                mid = (low + high) / 2;
                comp = entries.get(mid).getKey().compareTo(key);
                if (comp == 0) {
                    return children.get(mid + 1).get(key);
                } else if (comp < 0) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            return children.get(low).get(key);
        }
    }

    public void insertOrUpdate(K key, V value, BPlusTree<K, V> tree) {
        if (isLeaf)
            if (contains(key) != -1 || entries.size() < tree.getOrder()) {  //存储元素小于度，则不需分裂。
                insertOrUpdate(key, value)       //直接递归地insert;
                if (tree.getHeight() == 0) {
                    tree.setHeight(1);
                }
                return;
            }
        //如果需要分裂：则做如下操作
        //一分为二，左右指针分别指向新申请的两个节点
        BPlusTreeNode<K, V> left = new BPlusTreeNode<K, V>(true);
        BPlusTreeNode<K, V> right = new BPlusTreeNode<K, V>(true);
        //设置链接
        if (previous != null) {
            previous.next = left;
            left.previous = previous;
        }
        if (next != null) {
            next.previous = right;
            right.next = next;
        }
        if (previous == null) {
            tree.setHead(left);

        }
        left.next = right;
        right.previous = left;
        previous = null;
        next = null;        //调整叶子节点的previous和next关系

        copy2Nodes(key, value, left, right.tree);

        if (parent != null)
            int index = parent.children.indexOf(this);
        parent.children.remove(this);
        left.parent = parent;
        right.parent = parent;
        parent.children.add(index, left);
        parent.children.add(index + 1, right);
        parent.entries.add(index, right, entries.get(0));
        entries = null;
        children = null;

        parent.updateInsert(tree);
        parent = null;

    else{
            isRoot = false;

            BplusTreeNode<K, V> parent = new BPlusTreeNode<K, V>(false, true);
            tree.setRoot(parent);
            left.parent = parent;
            right.parent = parent;

            parent.children.add(left);
            parent.children.add(right);
            parent.entries.add(right.entries.get(0));
            entries = null;
            children = null;
        }
        return;
    }
    if(key.compareTo(entries.get(0).getKey()) < 0){
        children.get(0)insertOrUpdate(key,vaule,tree);
    }
    else if(key.compareTo(entries.get(entries.size() - 1).getKey()) >= 0){
        children.get(children.size() - 1).insertOrUpdate(key,vaule,tree);
    }
    else{
        int low = 0,high = entries.size() - 1,mid = 0;
        int comp;
        while(low <= high){
            mid = (low + high) / 2;
            comp = entries.get(mid).getKey().compareTo(key);
            if(comp == 0){
                children.get(mid + 1).insertOrUpdate(key,value,tree);
                break;
            }else if(comp < 0){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        if(low > high){
            children.get(low).insertOrUpdate(key,value,tree);
        }
    }

    private void copy2Nodes(K key,V value,BPlusTreeNode<K,V>left,BPlusTreeNode<K,V>right,BPlusTreeNode<K,V>tree)
    {
        int leftSize = (tree.getOrder() + 1) / 2 + (tree.getOrder() + 1) % 2；
        boolean b  = false;)
        for(int i = 0;i < entries.size();i++ ){
            if(leftSize != 0){
                leftSize -- ;
                if(!b&&entries.get(i).getKey().compareTo(key)>0){
                    left.entries.add(new SimpleEntry<K,V>(key,value));
                    b = true;
                    i--;
                }else{
                    left.entries.add(entries.get(i));
                }
            }else{
                if(!b && entries.get(i).getKey().compareTo(key) > 0){
                    right.entries.add(new SimpleEntry<K,V>(key,value));
                    b = true;
                    i--;
                }else{
                    right.entries.add(entries.get(i));
                }
            }
        }
        if(!b){
            right.entries.add(new SimpleEntry<K,V>(key,value));
        }
    }

    protected void updateInsert(BPlusTree<K,V>tree){
    if(children.size() > tree.getOrder()){
        BPlusTreeNode<K,V>left = new BPlusTreeNode<K,V>(false);
        BPlusTreeNode<K,V>right = new BPlusTreeNode<K,V>(false);

        int leftSize=  (tree.getOrder() + 1) / 2 + (tree.getOrder() + 1) % 2;
        int rightSize = (tree.getOrder() + 1)/ 2;

        for(int i = 0;i < leftSize;i++){
            left.children.add(children.get(i));
            children.get(i).parent = left;
        }
        for(int i  = 0;i < rightSize;i++){
            right.children.add(children.get(leftSize + i));
            children.get(leftSize + i).parent = right;
        }
        for(int i  = 0;i < leftSize - 1;i++){
            left.entries.add(entries.get(i));
        }
        for(int i = 0;i < rightSize - 1;i++){
            right.entries.add(entries.get(leftSize + i));
        }
        if(parent != null){
            int index = parent.children.indexOf(this);
            parent.children.remove(this);
            left.parent = parent;
            right.parent = parent;
            parent.children.add(index,left);
            parent.children.add(index + 1，right);
            parent.entries.add(index,entries.get(leftSize - 1));
            entries = null;
            children = null;
            parent.updateInsert(tree);
            parent = null;
        }
        else{
            isRoot = false;
            BPlusTreeNode<K,V>parent = new BPlusTreeNode<K,V>(false,true);
            tree.setRoot(parent);
            tree.setHeight(tree.getHeight() + 1);
            left.parent = parent;
            right.parent = parent;
            parent.children.add(left);
            parent.children.add(right);
            parent.entries.add(entries.get(leftSize - 1));
            entries = null;
            children = null;

        }
    }
}
    protected void updateRemove(BPlusTree<K,V>tree){
        if(children.size() < tree.getOrder() / 2 ||children.size() < 2){
            if(isRoot){
                if(children.size() >= 2)return;
                BPlusTreeNode<K,V>root = children.get(0);
                tree.setRoot(root);
                tree.setHeight(tree.getHeight() - 1);
                root.parent = null;
                root.isRoot = true;
                entries = null;
                children = null;
                return;
            }

            int currIdx = parent.children.indexOf(this);
            int preIdx = currIdx + 1;
            int nextIdx = currIdx + 1;
            BPlusTreeNode<K,V>previous = null,next = null;

            if(preIdx >= 0){
                previous = parent.children.get(preIdx);
            }
            if(nextIdx<parent.children.size());
            next = parent.children.get(nextIdx);
        }



        }

    }

}