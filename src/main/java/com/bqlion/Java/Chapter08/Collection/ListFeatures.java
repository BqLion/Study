package com.bqlion.Java.Chapter08.Collection;
import java.util.*;
import static net.mindview.util.Print.*;

public class ListFeatures {
    public static void main(String[] args) {
        Random rand = new Random(47);
        List<Pet>pets = Pets.arrayList(7);
        print("1: " + pets);
        Hamster h = new Hamster();
        pets.add(h);
        print("2 :"+ pets);
        print("3 :"+ pets.contains(h));
        pets.remove(h);
        Pet p = pets.get(2);
        print("4: " + p + " " + pets.indexOf(p));
        Pet cymic = new Cymric();
        print("5:" + pets.indexOf(cymic));
        print("6:" + pets.remove(cymic));
        print("7:" + pets.remove(p));
        print("8:" + pets);
        pets.add(3,new Mouse());
        print("9:" + pets);
        List<Pet>sub = pets.subList(1,4);           //subList:切取1到4
        print("SubList: " + sub);
        print("10: " + pets.containsAll(sub));     //contains:查看目标是否在列表中
        Collections.sort(sub);
        print("Sort sublist "+ sub);
        print("11: " + pets.containsAll(sub));
        Collections.shuffle(sub,rand);
        print("12: " + pets.containsAll(sub));
        List<Pet>copy = new ArrayList<Pet>(pets);
        sub = Arrays.asList(pets.get(1),pets.get(4));
        print("sub : " + sub);
        copy.retainAll(sub);
        print("13 : " + copy);
        copy = new ArrayList<Pet>(pets);
        copy.remove(2);
        print("14 :" + copy);
        copy.removeAll(sub);
        print("15 : " + copy);
        copy.set(1,new Mouse());
    }
}
