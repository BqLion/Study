package com.bqlion.Java.Chapter09.Coffee;
import java.util.*;

class Customer{
    private static long counter = 1;
    private final long id = counter++;
    private Customer(){}
    public String toString(){return "Customer " + id;}
    public static Generator<Customer> generator(){           //装着Customer的容器Gene
        return new Generator<Customer>() {                  //返回 new Gene
            public Customer next(){return new Customer();}  //多出一些定义是匿名内部类 ：
            };                                              //返回next Customer。
        }
    }

    class Teller {
        private static long counter = 1;
        private final long id = counter++;

        private Teller() {
        }

        public String toString() {
            return "Teller " + id;
        }

        public static Generator<Teller> generator = new Generator<Teller>() {
            public Teller next() {
                return new Teller();
            }

        };
    }
public class BankTeller {
    public static void serve(Teller t,Customer c){
        System.out.println(t + "serves " + c);
    }

    public static void main(String[] args) {
        Random rand = new Random(47);
            Queue<Customer>Line = new LinkedList<Customer>();
            Generators.fill(Line,Customer.generator(),15);
            List<Teller>tellers = new ArrayList<Teller>();
            Generators.fill(tellers,Teller.generator,4);
            for(Customer c : Line)
                serve(tellers.get(rand.nextInt(tellers.size())),c);
    }
    }
