package com.bqlion.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/24
 */
import java.util.ArrayList;
import java.util.List;
import java.util.Random;


public class BPlusTree<K extends Comparable<K>,V> {     //key和value两个泛型，key是可以比较的
    /**
     * root node
     */
    protected BplusNode<K,V>root;

    /**
     * degree of tree
     */
    protected int order;

    /**
     * head node of children`s chain
     */
    protected BPlusTree<K,V>head;

    /**
     * height of tree
     */
    protected int height = 0;       //protected关键字：只有本包和继承者才可以访问

    /**
     * get head node
     * @return return head node
     */
    public BplusNode<K,V>getHead(){
        return head;
    }

    /**
     * set head node
     * @param head is the object being setted.
     */
    public void setHead(BplusNode<K,V>head){
        this.head = head;
    }

    /**
     * get root node
     */
    public BplusNode<K,V>getRoot(){
        return root;
    }

    /**
     * set root node
     * @param root being setted
     */
    public void setRoot(BPlusNode<K,V>root){
        this.root = root;
    }

    public int getOrder(){
        return order;
    }

    public void setOrder(int order){
        this.order = order;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getHeight(){
        return height;
    }

    public V get(K key){
        return root.get(key);
    }

    public V remove(K key){
        return root.remove(key,this);
    }

    public void insertOrUpdata(K key,V value){
        root.insertOrUpdata(key,value,this);
    }

    public BplusTree(int order){
        if(order < 3){
            System.out.println("order should be larger than 3");
            System.exit(0);
        }
        this.order = order;
        root = new BplusNode<K,V>(true,true);
        head = root;
    }

}
