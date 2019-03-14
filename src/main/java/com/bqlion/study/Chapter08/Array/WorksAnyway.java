package com.bqlion.study.Chapter08.Array;
import java.util.*;
class Mouse{
    private int mouseNumber;
    Mouse(int i){
        mouseNumber = i;
    }
    public String toString(){
        return "This is a Mouse #" + mouseNumber;
    }
    void print(String msg){
        if (msg != null)System.out.println(msg);
        System.out.println(
                "Mousenumber " + mouseNumber);
    }
}
class MouseTrap{
    static void caughtYa(Object m){
        Mouse mouse = (Mouse)m;
        mouse.print("Caught one!");
    }
}

public class WorksAnyway {
    public static void main(String[] args) {
        Vector mice = new Vector();
        for(int i = 0; i < 3; i++)
            mice.addElement(new Mouse(i));
        for(int i = 0; i < mice.size(); i++){
            System.out.println(
                    "Free mouse:" + mice.elementAt(i));
            MouseTrap.caughtYa(mice.elementAt(i));
        }
    }
}
