package com.bqlion.Before.Java.Polymorphism;
class NoteX{
    public static final int
    MIDDLE_C = 0,C_SHARP = 1,C_FLAT = 2;
}
class InstrunmentX{
    public void play(int NoteX){
        System.out.println("InstrumentX.play()");
    }
}

class WindX extends InstrunmentX{
    public void play(NoteX n){
        System.out.println("WinxX.play(NoteX n)");
    }
}

public class WindError {
    public static void tune(InstrunmentX i){
        i.play(NoteX.MIDDLE_C);
    }

    public static void main(String[] args) {
        WindX flute = new WindX();
        tune(flute);
    }
}
