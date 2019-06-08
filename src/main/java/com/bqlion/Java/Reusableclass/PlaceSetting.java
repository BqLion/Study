package com.bqlion.Java.Reusableclass;
class Plate{
    Plate(int i){
        System.out.println("Plate constructor");
    }
}
class DinnerPlate extends Plate{
    DinnerPlate(int i){
        super(i);
        System.out.println("DinnerPlate constructor");
    }
}
class Utensil{
    Utensil(int i){
        System.out.println("Spoon constructor");
    }
}
class Knife extends Utensil{
    Knife(int i){
        super(i);
        System.out.println("Knife constructor");
    }
}
class Custom{
    Custom(int i){
        System.out.println("Custom Constructor");
    }
}

public class PlaceSetting extends Custom{
    Knife kn;
    DinnerPlate pl;
    PlaceSetting(int i){
        super(i + 1);
        kn = new Knife(i + 4);
        pl = new DinnerPlate(i + 5);
        System.out.println("PlaceSetting constructor");
    }

    public static void main(String[] args) {
        PlaceSetting  x = new PlaceSetting(9);
    }
}

