package com.bqlion.Coursera.AlgorithmsPart1.WEEK2;

/* *
 * Created by BqLion on 2019/6/12
 */
public class DequeTest {
    public static void main(String[] args) {
        Deque<Integer> deque = new Deque<Integer>();
        System.out.println(deque.isEmpty());
        System.out.println(deque.size());

        deque.addFirst(4);deque.addFirst(3);
        deque.addFirst(2);
        deque.addFirst(1);


        System.out.println(deque.isEmpty());
        System.out.println(deque.size());
        deque.display();

        deque.addLast(1);
        deque.addLast(2);
        deque.addLast(3);
        deque.addLast(4);
        deque.display();

        deque.removeFirst();
        deque.removeFirst();
        deque.display();

        deque.removeLast();
        deque.removeLast();
        deque.display();

      for(;deque.iterator().hasNext();deque.iterator().next())
      {
          System.out.println(1);
      }

    }
}
