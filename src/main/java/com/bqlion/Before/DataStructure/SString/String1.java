package com.bqlion.Before.DataStructure.SString;

public final class String1 {
    private final char[] value;

    public String1(){
        this.value = new char[0];       //缺省构造函数创建一个char【0】数组
    }
    public String1(char[]value){
        this.value  = new char[value.length];           //申请的value数组为传进来的参数数组那么长的数组
        for(int i = 0;i<value.length;i++)
        this.value[i] = value[i];                       //把传进来的char数组转换成String1形式
    }
    public String1(String1 str){
        this(str.value);
    }
    public int length(){
        return this.value.length;
    }
    public char charAt(int index){
        if((index < 0) || (index >= this.value.length))
            throw new StringIndexOutOfBoundsException(index);
        return this.value[index];
    }
    public String1 concat(String1 str){
        if(str == null || str.length() ==0)     //如果待合并的字符串为空或者长度为0则返回现在的字符串
            return this;

        char[] buffer = new char[this.value.length + str.length()];
        int i;
        for(i = 0;i<this.value.length;i++)
            buffer[i] = this.value[i];
        for(int j = 0;j < str.length();j++)
            buffer[i+j] = str.value[j];
        return new String1(buffer);
    }
    public String1 substring(int begin,int end){
        if(begin < 0)
            throw new StringIndexOutOfBoundsException(begin);
        if(end > value.length)
            throw new StringIndexOutOfBoundsException(end);
        if(begin > end)
            throw new StringIndexOutOfBoundsException((end - begin));

        if(begin == 0 && end ==value.length)
            return this;
        else{
            char[] buffer = new char[end - begin];
            for(int i = 0; i < buffer.length; i++)          //数组都自带length函数
                buffer[i] = this.value[i+begin];
            return new String1(buffer);                 //记得返回String1型数据，不是返回char[]
        }
    }
    public String1 substring(int begin){
        return substring(begin,this.value.length);
    }

    public String insert(String source,int index,String str){
     return source.substring(0,index) + str + source.substring(index);
    }

    public String delete(String source,int begin,int end){
        return source.substring(0,begin)+source.substring(end);
    }

    public int indexOf(String1 pattern){
        int i = 0;
        return i;
    }

    public char get(int index){
        return this.value[index];

    }
    public String toString(){
        return new String(this.value);
    }
}
