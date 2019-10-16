package com.bqlion.Java.Reusableclass;

class Homer{
    char doh(char c){
        System.out.println("doh(char)");
        return 'd';
    }
    float doh(float f){
        System.out.println("doh(float)");
        return 1.0f;
    }
}
class Millhouse{}

class Bart extends Homer{
    void doh(Millhouse m){}
}

public class Hide {
    public static void main(String[] args) {
        Bart b = new Bart();
        b.doh(1);
        b.doh('x');
        b.doh(1.0f);
        b.doh(new Millhouse());
    }
}
