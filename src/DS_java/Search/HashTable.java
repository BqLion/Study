package com.bqlion.Before.DataStructure.Search;

/* *
 * Created by BqLion on 2019/5/19
 */

/**
public class HashTable<E> {
    private SinglyLinkedList<E>[] table;
    public HashTable(int capacity){
        this.table = new SinglyLinkedList[Math.abs(capacity)];
        for(int i = 0; i < table.length; i++)
            table[i] = new SinglyLinkedList<E>();
    }

    public HashTable(){
        this(97);
    }
    public int hash(int key){
        return key % table.length;
    }

    public void insert(E element){
        int key = element.hashCode();
        int i = hash(key);
        table[i].add(0,element);
    }

    public String toString(){
        String str = "";
        for(int i = 0; i <table.length; i++)
            str += "table["+ i +"] = "+table[i].toString()+"\n";
        return str;
    }

    public Node<E>search(E element){
        int key = element.hashCode();
        int i = hash(key);
        return;
        // table[i].search(element);
    }

    public boolean contain(E element){
        return this.search(element)!= null;
    }

    public boolean remove(E element){
        int key = element.hashCode();
        int i = hash(key);
        return table[i].remove(element);
    }

    public static void main(String[] args) {

    }
}


*/