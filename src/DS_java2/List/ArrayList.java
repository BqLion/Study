package com.bqlion.After.DataStruct.List;

import javafx.beans.binding.ObjectExpression;

public class ArrayList implements List{
    private final int DEFAULT_LENGTH = 8;          //数组默认大小
    private int numberOfElementInArray;                   //线性表当前元素个数
    private Object[] elements;          //元素数组

    public ArrayList(){
        this.numberOfElementInArray = 0;
        this.elements = new Object[DEFAULT_LENGTH];
    }

    public void insert(int postion,Object BeingInserted)throws IndexOutOfBoundsException{
        if(postion < 0 || postion >numberOfElementInArray)
            throw new IndexOutOfBoundsException("插入的地址越界");
        if(numberOfElementInArray >= elements.length)
            expandSpace();
        for(int pointer = numberOfElementInArray;pointer > postion;pointer--)
            elements[pointer] = elements[pointer - 1];
        elements[postion] = BeingInserted;
        numberOfElementInArray++;
        return;
    }

    private void expandSpace(){
        Object[] newArray = new Object[elements.length * 2];
                for(int i = 0;i < elements.length;i++)
                    newArray[i] = elements[i];
                elements = newArray;
    }

    public Object remove(int removedPosition)throws IndexOutOfBoundsException{
        if(removedPosition < 0 || removedPosition >= numberOfElementInArray)
            throw new ArrayIndexOutOfBoundsException("错误,制定的位置越界");
        Object beingRemovedIssus = elements[removedPosition];
        for(int j = removedPosition;j < numberOfElementInArray - 1;j++)
            elements[j] = elements[j+1];
        elements[--numberOfElementInArray] = null;
        return beingRemovedIssus;
    }

    public Object replace(int replacedPosition,Object newGuys)throws IndexOutOfBoundsException{
        if(replacedPosition < 0 || replacedPosition > numberOfElementInArray)
            throw new IndexOutOfBoundsException("错误,制定的位置越界");
        Object oldGuys = elements[replacedPosition];
        elements[replacedPosition] = newGuys;
        return oldGuys;
    }

    public Object get(int position)throws IndexOutOfBoundsException{
        if(position < 0 || position >=  numberOfElementInArray)
            throw new IndexOutOfBoundsException("错误,制定的序号越界");
        return elements[position];
    }
    public int getSize(){
        return numberOfElementInArray;
    }
}
