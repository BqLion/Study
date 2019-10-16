package com.bqlion.DataStructure.List;

public class SeqList<E>implements List<E>  {                //SeqList是对List接口的实现。
    private Object[] table;                                 //table是私有的Object数组，现性表的主体
    private int n;                                          //n是私有变量代表线性表的长度

    public SeqList(int capacity){                           //SeqList是初始化线性表的函数
        this.table = new Object[Math.abs(capacity)];        //传递进来的capacity参数 设置为申请的数组长度
        this.n = 0;                                         //n长度初始化为0
    }

    public boolean isEmpty(){           //实现接口的第一个函数，判定线性表是否为空
        return this.n == 0;
    }

    public int length(){
        return this.n;
    }
    public E get(int index){
        if(index >= 0 && index <= this.n)      //写get函数必须要养成习惯，判断index是否合法。
           return (E)this.table[index];        //这里为什幺加E？不是在函数名那里就有E了吗，需要强制转换？
        return null;
    }

    public E set(int index,E element) {         //set函数用于把element E 添加到位置index上
        if (index >= 0 && index < this.n && element != null) {  //开局过滤掉异常输入：index只能在合理区间内，插入的值不能有问题。
            E old = (E) this.table[index];                      // 线性表里的原元素被放到old里
            this.table[index] = element;                        //新元素添加进入。
            return old;
        }
        return null;
    }

    public boolean add(int index,E element){
        if(this.n == table.length) {                //length是table数组的长度，属数组自带函数。
            Object[] temp = this.table;             //这个if的功能是判断线性表是否已经满了，如果满了就要扩容二倍
            this.table = new Object[temp.length*2];
            for(int j = 0; j <= temp.length; j++)
                this.table[j] = temp[j];
        }

        if(element != null){        //首先把不合法的插入位置和插入元素过滤掉返回false
            if(index < 0)
                index = 0;
            if(index > this.n)
                index = this.n;         //下标容错

            for(int i = this.n-1; i >= index; i--){
            this.table[i + 1] = this.table[i];
            }
            this.table[index] = element;
            this.n++;
            return true;
        }
        return false;
    }
    public boolean add(E element){      //没有指定插入位置的add函数直接插入在线性表尾部。 也就是this.n,五个元素的数组就是插入在第五个位置后边，这时如果线性表满了就需要对数组扩容
        return add(this.n,element);
    }

    public E remove(int index) {            //本函数就是实现删除功能。线性表的删除无非就是依次前移一格实现覆盖。
        if(index >=0 && index < this.n && n!=0) {     //index要大于零小于n，n本身不可等于0不然就等于是空列表无从移动起。
            E old = (E)this.table[index];
            for (int i = index; i < this.n - 1; i++)
                this.table[i] = this.table[i + 1];
            this.table[this.n - 1] = null;            //不要忘记都赋值完毕后把表尾处的元素置为null。
            this.n--;
            return old;
        }
        return null;
    }

    public void clear(){
        if(this.n!=0){
            for(int i = 0; i<= n-1;i++)
                this.table[i] = null;               //把数组中各个元素都清为null
            this.n = 0;                             //置空就是把元素个数n置为0
        }
    }

    public String toString(){
        String str = "(";
        if(this.n != 0){
            for(int i = 0; i<this.n-1;i++)
                str += this.table[i].toString()+",";        //递归需画图分析之。
            str += this.table[this.n-1].toString();
        }
        return str+")";
    }
}

