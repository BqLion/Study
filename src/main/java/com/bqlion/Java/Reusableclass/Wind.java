package com.bqlion.Java.Reusableclass;

class instrument{
    public void play(){}
    static void tune(instrument i){
        i.play();
    }
}

public class Wind extends instrument{
    public static void main(String[] args) {
        Wind flute = new Wind();
        instrument.tune(flute);             //wind可直接调用父类中的函数instrument，因为wind是insrument的一种，谓之上溯造型（upcasting）

    }
}
