package com.bqlion.Before.Java.Reusableclass;
//The Protected keyword

class Villain{
    private int i;
    protected int read(){return i;}
    protected void set(int ii){i = ii;}
    public Villain(int ii){i = ii;}
    public int value(int m){return m*i; }
}
public class Orc extends Villain{
    private int j;
    public Orc(int jj){super (jj); j = jj;}
    public void change(int x){set(x);}
}
    /*      类内部  本包  子类  外部包
public      Y       Y     Y     Y
protected   Y       Y     Y     N
default     Y       Y     N     N
private     Y       N     N     N
     */