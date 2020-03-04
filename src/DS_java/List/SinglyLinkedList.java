package com.bqlion.Before.DataStructure.List;

public class SinglyLinkedList<E>implements List<E> {
    protected Node<E> head;     //首先是单链表的头节点指针。

    public SinglyLinkedList() {
        this.head = null;
    }

    public SinglyLinkedList(Node<E> head) {           //如上构造函数参数为空则头结点为空，本函数把头结点设置为参数节点。
        this.head = head;
    }

    public boolean isEmpty() {
        return this.head == null;
    }

    public int length() {
        int i = 0;
        Node<E> pointer = this.head;     //指针指向头结点，当指针非空时持续往后移动直至pointer为null这时返回计数器。
        while (pointer != null) {
            i++;
            pointer = pointer.next;
        }
        return i;
    }

    public E get(int index) {
        if (this.head != null && index >= 0) {         //首先过滤非法数值排除空表和空查询。
            int j = 0;
            Node<E> pointer = this.head;
            //for(int i = 0; i <=index; i++)
            while (pointer != null && j < index) {
                j++;
                pointer = pointer.next;
            }
            if (pointer != null)
                return (E) pointer.data;
        }
        return null;           //写完了上边的if过滤条件后先跳下来写这个return null免得后边忘记。
    }

    public E set(int index, E element) {
        if (this.head != null && index >= 0 && element != null) {      //头结点不空，插入位置有效，插入元素非空。
            int i = 0;          //i是计数器计算往前移动了几步
            Node<E> pointer = this.head;    //指针指向头结点
            while (i <= index) {            //在计数器小于位置数值时往前移动
                pointer = pointer.next;
                i++;
            }
            if (pointer != null) {           //单链表没法知道表中有多少个元素，只能等移动过去后看是不是空的如果不是就返回其原值
                E old = (E) pointer.data;
                pointer.data = element;     //三元素互赋值。set进去后把element装进去
                return old;
            }
        }
        return null;
    }

    public boolean add(int index, E element) {
        if (element == null)
            return false;

        if (this.head == null || index <= 0) { //头节点前插入修正为在头结点插入。头结点本身为空。
            this.head = new Node<E>(element, this.head);  //空表或头插是将next指向原头结点，往后挤一位。
        } else {
            int j = 1;
            Node<E> pointer = this.head;
            while (pointer != null && j < index) {        //见笔记本SinglyLinkedList.add的图。
                j++;
                pointer = pointer.next;    //指针就位
            }
            /*
            Node<E>addable = new Node<E>(element,pointer.next);
            pointer.next = addable;
            */
            pointer.next = new Node<E>(element, pointer.next); //上边两句可浓缩为此一句：指针所指Node的next指针指向新节点，新节点next指向下一个。
        }
        return true;
    }

    public boolean add(E element) {
        return add(Integer.MAX_VALUE, element);      //没有指定插入位置就插入在表尾。如上函数，指针就位循环的终结条件就是到达位置或者抵达终点，integer.maxvalue保证能抵达终点。
    }

    public E remove(int index) {
        E old = null;
        if (this.head != null && index >= 0) {
            if (index == 0) {
                old = (E)this.head.data;        //old是个指针，指向原头节点里边装的东西，不管装的什么要强制转换为E类型
                this.head = this.head.next;
            } else {
                int j = 0;
                Node<E> pointer = this.head;
                while (j < index - 1) {
                    j++;
                    pointer = pointer.next;
                }
                if (pointer.next != null) {
                    old = (E) pointer.next.data;
                    pointer.next = pointer.next.next;
                }
            }
        }
    return old;
}

public void clear(){
        this.head = null;
}

public String toString(){
        String str = "(";
        Node<E>p = this.head;
        while(p != null){
            str += p.data.toString();
            p = p.next;
            if(p!=null)
                str += ", ";
        }
        return str+")";
}

}
