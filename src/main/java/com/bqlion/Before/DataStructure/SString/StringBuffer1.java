package com.bqlion.Before.DataStructure.SString;
//StringBuffer1是一个顺序存储结构的字符串。
//String是字符串长度等于数组容量，合并字符串是两个数组合并
//StringBuffer数组容量大于字符串长度，合并字符串可将数据直接写入后续数组中。

public final class StringBuffer1 {
    private char[] value;       //申请数组，容量由构造函数传递进来的参数确定
    private int n;              //串的长度

    public StringBuffer1(int capacity){
        value = new char[capacity];
        n = 0;
    }

    public StringBuffer1(){
        this(16);       //缺省构造函数，this指代之，默认容量16
    }
    public StringBuffer1(String1 str){
        this(str.length()+16);
        for(int i = 0; i<str.length(); i++){
            this.value[i] = str.get(i);
        }
    }
    public int length(){
        return n;
    }
    void expandCapacity(int minimumCapacity){           //扩充容量
        if(minimumCapacity > value.length){             //若参数容量大于目前数组容量则 容量更新为两倍
            int newCapacity = (value.length + 1)*2;     //
            if(newCapacity < 0)
                newCapacity = Integer.MAX_VALUE;        //更新为两倍容量越界则设定为int最大值
            else if(minimumCapacity > newCapacity);     //若两倍容量仍小于期望容量，则更新为参数期望的容量
            newCapacity = minimumCapacity;

            char[] temp = value;
            value = new char[newCapacity];
             for(int i = 0; i < temp.length; i++)
                 value[i] = temp[i];
        }
    }
    public synchronized StringBuffer1 insert(int index,String str){
        if((index < 0) || (index >length()))
            throw new StringIndexOutOfBoundsException(index);
        if(str == null)
            str = "null";
    int len = str.length();
    int newCount = n + len;         //新计数是老字符串加新字符串长度，长度若越界则调用扩充函数
    if(newCount > value.length)
        expandCapacity(newCount);

    for(int i = n-1;i >=index; i--)
        value[len+i] = value[i];            //原串插入后段后移
    for(int i = 0;i < len;i++)
        value[index + i] = str.charAt(i);   //插入
    n = newCount;
    return this;
    }
    public synchronized  StringBuffer1 insert(int index,boolean b){
        return b ? insert(index,"true"):insert(index,"false");      //参数b是真的就insert true否则insertfalse
    }

    public synchronized StringBuffer1 append(String str){           //append就是在字符串尾部insert
        return insert(n,str);
    }

    public synchronized StringBuffer1 deleate(int begin,int end){
        if(begin < 0)
            begin = 0;
        if(end > n)
            end = n;

        if(begin > end)
            throw new StringIndexOutOfBoundsException(end - begin);

        for(int i = 0; i< n - n - end; i++)
            value[begin + i] = value[end + i];
        n -= end - begin;
        return this;
    }
}
