package com.bqlion.Before.DataStructure.List;

public class SeqListTest {
    public static void main(String[] args) {
        SeqList<Integer> seqlist = new SeqList<Integer>(10);
        System.out.println(seqlist.toString());

        seqlist.add(1,2);
        System.out.println("test add(1,2):" + seqlist.toString());

        seqlist.add(3);
        System.out.println("test add(3):"+ seqlist.toString());

        seqlist.remove(1);
        System.out.println("test remove(1):" + seqlist.toString());

        seqlist.clear();
        System.out.println("test.clear()"+ seqlist.toString());
    }

}
