package com.bqlion.After.DataStruct.Heap;

public interface HeapComparator<E> {

    /**
         * 第一个元素比第二个大的话，返回true
         *
         * @param elem1
         * @param elem2
         * @return
         */
        boolean isFirstLargerThanSecond(E elem1, E elem2);
    }

