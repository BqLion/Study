package com.bqlion.Before.DataStructure.Stack;
import com.bqlion.Before.DataStructure.List.Node;

public class LinkedStack<E>implements Stack<E> {
    private Node<E>top;

    public LinkedStack(){
        this.top = null;            //构造链式栈，头结点为空。
    }

    public boolean isEmpty(){
        return this.top ==null;
    }

    public boolean push(E element){
        if(element ==null)
            return false;
        this.top = new Node(element,this.top);  //压栈标准操作，让top指针指向新申请的节点，新节点的next指向当前的top
        return true;
    }

    public E pop(){
        if(!isEmpty()){
            E temp = this.top.data;
            this.top = this.top.next;       //链式栈是从左往右指过去。push就是新申请的节点的next指向top
            return temp;                    //pop就是top = top.next
        }                                   //要返回E类型的数据，这里返回temp，temp不可写在前边否则会提前终结程序
        return null;
    }

    public E get(){                 //get函数get的是栈顶元素
        if(!isEmpty())
        return  this.top.data;
        return null;
    }
    //栈的删除和插入操作都在栈顶执行，所以时间复杂度是n（1）

    public void display(){
        System.out.println("The element in stack are: ");
        for(Node<E> p  = top;p != null;p = p.next)
        {
            System.out.println(p.data + ",");
        }

        System.out.println();
    }
}
