package com.bqlion.After.DataStruct.Heap;

import com.sun.javafx.scene.control.skin.CellSkinBase;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Heap<E> {
    /********************field**********************************/
    private List<E> list = null;                       //线性表是堆的基本存储结构
    private HeapComparator<E> comparator = null;
    private boolean isMaxHeap = false;

/********************field**********************************/


    /********************Constructor****************************/

    public Heap() {
        list = new ArrayList<E>();
    }

    public Heap(HeapComparator<E> comparator) {
        list = new ArrayList<E>();
        this.comparator = comparator;
    }

    public Heap(HeapComparator<E> comparator, int size) {
        list = new ArrayList<E>(size);
        this.comparator = comparator;
    }


/********************Constructor****************************/


    /********************Method*********************************/
    public void add(E e) {
        list.add(e);

        int end = list.size() - 1;
        int begin = end / 2;

        while (true) {
            heapAdjust(begin, end);
            end = begin;
            if (end == 0) {
                break;
            }
            begin = (end - 1) / 2;
        }
    }


    public void remove(int index) {
        if (index >= list.size())
            throw new RuntimeException("超出长度");
        if (index == list.size() - 1) {
            list.remove(index);
            return;
        }
    }

    private void heapSort(){
        int begin = list.size() / 2 -1;

        while(begin  >= 0){
            heapAdjust(begin,list.size() - 1);
            begin--;
        }
    }

    private void heapAdjust(int begin,int end){
        if(comparator == null){
            throw new RuntimeException("比较器不能为空");
        }

        boolean flag = true;
        if (isMaxHeap){
             flag = true;
        }
        else {
            flag = false;
        }

        /**************************/

        int child = begin * 2 + 1;
        E temp = null;
        int replaceIndex = 0;

        while(child <= end){
            replaceIndex = child;
        }


        if (child + 1 <= end) {
            if (isMaxHeap) {
                // 返回更大的对象
                flag = comparator.isFirstLargerThanSecond(
                        list.get(child + 1), list.get(child));
                replaceIndex = flag == true ? child + 1 : child;
            } else {
                flag = comparator.isFirstLargerThanSecond(
                        list.get(child + 1), list.get(child));
                replaceIndex = flag == true ? child : child + 1;
            }

        }

        temp = list.get(begin);
        if ((isMaxHeap && comparator.isFirstLargerThanSecond(
                list.get(replaceIndex), temp))
                || (!isMaxHeap && !comparator.isFirstLargerThanSecond(
                list.get(replaceIndex), temp))) {
            list.set(begin, list.get(replaceIndex));
            list.set(replaceIndex, temp);
        }

        begin = replaceIndex;
        child = begin * 2 + 1;
    }


    public void createMaxHeap() {
        isMaxHeap = true;
        heapSort();
    }

    public void createMinHeap() {
        isMaxHeap = false;
        heapSort();
    }

    public void printHeap() {
        System.out.println(list);
    }

    public Iterator<E> getIterator() {
        return list.iterator();
    }

    public E get(int index) {
        return list.get(index);
    }

    /**
     * 返回底层的数据结构，方便直接使用原有List提供的功能
     *
     * @return
     */
    public List<E> getUnderlyingStructure() {
        return list;
    }

    public HeapComparator<E> getComparator() {
        return comparator;
    }

    public void setComparator(HeapComparator<E> comparator) {
        this.comparator = comparator;
    }
}


/********************Method*********************************/

