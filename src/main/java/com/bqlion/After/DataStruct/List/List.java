package com.bqlion.After.DataStruct.List;

public interface List {
    public void insert(int i,Object e)throws IndexOutOfBoundsException;
    //增
    public Object remove(int i)throws IndexOutOfBoundsException;
    //删
    public Object replace(int i,Object e)throws IndexOutOfBoundsException;
    //改
    public  Object get(int i)throws IndexOutOfBoundsException;
    //查
}

