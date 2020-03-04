package com.bqlion.Before.Java.Reusableclass;
//Inheritance,constructors and arguments

class Game{
    Game(int i){
        System.out.println("Game constructor");
    }
}
class BoardGame extends Game{
    BoardGame(int i){
        super(i);
        System.out.println("BoardGame Constructor");
    }
}

public class Chess extends BoardGame {
    Chess(){
        super(11);                            //super是对父类的引用，this指的是对本类的引用
        System.out.println("Chess Constructor");
    }

    public static void main(String[] args) {
        Chess x = new Chess();
    }
}
