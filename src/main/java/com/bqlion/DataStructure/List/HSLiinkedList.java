package com.bqlion.DataStructure.List;

public class HSLiinkedList<E>implements List<E> {
    protected Node<E>head;          //头指针
    protected Node<E>rear;          //尾指针
    protected int n;                //线性表长度

    public HSLiinkedList(){
        this.head = new Node<E>(null);      //构造函数，初始化头指针指向新申请节点
        this.rear = this.head;
        this.n = 0;
    }
    public boolean isEmpty(){
        return this.head.next ==null;
    }
    public int length(){
        return this.n;
    }

    public E get(int index){
        int i = 1;
        Node<E>pointer = this.head;
        if(index >=0 && this.head.next != null)
        {
            while(i <=index) {
                i++;
                pointer = pointer.next;
            }
        if(pointer != null)
            return pointer.data;
        }
        return null;
    }

    public E set(int index,E element){
        Node<E>pointer = this.head;
        if(index >0 && index <=n && element != null){
        for(int i = 0; i<index;i++)
            pointer = pointer.next;
        }
        if(pointer != null)
            pointer.data = element;
            return null;
    }

    public boolean add(E element){
        if(element == null)
            return false;
        this.rear.next = new Node(element);     //尾插入，rear的next等于新插入节点，新节点的next指针指向null
        this.rear = this.rear.next;                         //rear指针就位
        this.n++;                                           //列表n扩充
        return true;
    }

    public boolean add(int index,E element){
        if(element == null)         //空元素停止插入
            return false;
        if(index >= this.n)              //插入位置越界则尾插调用上个函数
            return this.add(element);
        else{
            int j = 0;
            Node<E>pointer = this.head;
            while(pointer.next != null && j <index){
                j++;
                pointer = pointer.next;
            }
            Node<E>q = new Node(element,pointer.next);
            pointer.next = q;
            this.n++;
            return true;
        }
    }
    public E remove(int index){
        E old = null;
        if(index >=0){
            int j = 0;
            Node<E>pointer = this.head;
            while(pointer.next!= null && j <index){
                j++;
                pointer = pointer.next;
            }
            if(pointer.next ==this.rear)
                this.rear = pointer;
            pointer.next = pointer.next.next;
            this.n--;
        }
        return old;
    }
    public void clear(){
        this.head.next = null;
        this.rear = this.head;
        this.n = 0;
    }
    public String toString(){
        String str = "(";
        Node<E>p = this.head.next;
        while(p != null){
            str += p.data.toString();
            p = p.next;
            if(p!=null)
                str += ", ";
        }
        return str+")";

    }
}
