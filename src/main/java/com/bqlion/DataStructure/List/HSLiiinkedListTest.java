package com.bqlion.DataStructure.List;

public class HSLiiinkedListTest {
    public static void main(String[] args) {
        HSLiinkedList<Integer>HSL = new HSLiinkedList<Integer>();

        System.out.println(HSL.isEmpty());

        System.out.println(HSL.length());

        HSL.add(5);
        HSL.add(4);
        HSL.add(3);
        HSL.add(1);
        HSL.add(2,2);

        System.out.println(HSL.toString());

        HSL.remove(4);
        HSL.remove(2);

        System.out.println(HSL);

        HSL.clear();

        System.out.println(HSL);
    }
}
