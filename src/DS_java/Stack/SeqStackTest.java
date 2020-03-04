package com.bqlion.Before.DataStructure.Stack;

public class SeqStackTest {
    public static void main(String[] args) {
        SeqStack<Integer> Seq = new SeqStack<Integer>(10);
        System.out.println("the fact of  stack is empty are : " + Seq.isEmpty());
        System.out.println("stack now is :" );Seq.show();

        Seq.push(0);
        Seq.push(1);
        Seq.push(2);
        Seq.push(3);
        Seq.push(4);

        Seq.show();

        Seq.pop();
        Seq.pop();
        Seq.pop();
        Seq.pop();

        System.out.println("after four pops, Seq now is :");
        Seq.show();

        Seq.pop();
        System.out.println("one more pop: ");
        Seq.show();
      }
}
