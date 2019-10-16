package com.bqlion.After.DataStruct.List;
public interface Iterator {
    public void first();
    public void next();
    public boolean isDone();
    public Object currentItem();
}
