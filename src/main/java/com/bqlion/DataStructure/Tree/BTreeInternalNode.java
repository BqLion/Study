package com.bqlion.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/16
 */
class BTreeInternalNode <K extends Comparable<K>> extends AbstractBTreeNode<K> {   //实现节点：
    private final Object[] keys;                //keys数组，放的是键值
    private final AbstractBTreeNode<K>[] children;//node数组放的是孩子指针
    private int nkey = 0;           //孩子和键的数量
    private int nchild = 0;

    BTreeInternalNode(int degree){
        super(degree);
        keys = new Object[2 * degree -1];
        children = new AbstractBTreeNode[2 *  degree];
    }

    @Override
    protected boolean isLeaf(){
        return false;
    }

    @Override
    K getKey(int idx){
        return (K)keys[idx];
    }

    @Override
    protected K setKey(K newKey,int oldKeyIndex){
        K old = (K)keys[oldKeyIndex];
        keys[oldKeyIndex] = newKey;
        return old;
    }
    @Override
    protected void setChild(AbstractBTreeNode<K>sub,int index){
        children[index] = sub;
    }

    @Override
    AbstractBTreeNode<K>getChild(int index){
        if(index >= 0 && index < children.length){
            return children[index];
        }
        return null;
    }

    @Override
    protected int setNKey(int nkey){            //在增加或者删除了键值或者孩子之后，还需要修改nkey，nchild值
        int old = this.nkey;                    //一个函数最好只实现一个功能，修改固定值和删除增加操作分成两个函数
        this.nkey = nkey;                       //降低耦合度，清晰明了
        return old;
    }

    @Override
    int nkey(){
        return nkey;
    }

    @Override
    int nchild(){
        return nchild;
    }

    @Override
    protected int setNchild(int nchild){
        int old = this.nchild;
        this.nchild = nchild;
        return old;
    }

    @Override
    K search(K key) {
        int index = indexOfKey(key);
        if (index >= 0) {
            return (K) keys[index];
        }
        index = 0;
        while (key.compareTo((K) keys[index++]) > 0) ;
        return children[index].search(key);
    }

    @Override
    void insertNotFull(K key){
        checkNotFull();
        this.insertKey(key);
    }

    @Override
    void deleteNotEmpty(K key){
        this.deleteKey(key);
    }


    @Override
    protected void splitChild(int child) {
        AbstractBTreeNode<K> old = children[child];
        AbstractBTreeNode<K> neo = old.isLeaf()
                ? new BTreeLeaf<>(degree)
                : new BTreeInternalNode<>(degree);
        K middle = old.splitSelf(neo);
        this.insertKey(middle);
        this.insertChild(neo, child + 1);
    }

    @Override
    protected K splitSelf(AbstractBTreeNode<K> newNode){
        if(!(newNode instanceof BTreeLeaf)){        //如果newNode是BTreeLeaf的一个实例则返回true
            throw new RuntimeException("Instance not match");
        }
        if(!isFull()){
            throw new RuntimeException("Node is not full");     //在节点非满的情况下throws
        }
        K middle  = (K)keys[degree - 1];            //拆分节点返回的是节点的中间键。
        BTreeLeaf<K>node = (BTreeLeaf)newNode;      //node是一个新的节点
        int i = 0;
        while(i <degree - 1){
            node.keys[i] = this.keys[i + degree];
            this.keys[i + degree] = null;
            i++;
        }
        this.keys[degree - 1] = null;
        this.nkey = degree - 1;
        node.nkey = degree - 1;
        return middle;
    }

    @Override
    protected void merge(K middle,AbstractBTreeNode<K> sibling){
        if(!(sibling instanceof BTreeLeaf)){
            throw new RuntimeException(("Sibling is not a leaf"));
        }
        BTreeLeaf node = (BTreeLeaf)sibling;
        this.insertKey(middle);
        for(int i = 0;i < node.nkey(); i++){
            this.insertKey((K)node.keys[i]);            //解除耦合：merge依赖于insert，insert依赖于set
        }
    }

    @Override
    public String toString(){
        StringBuffer sb = new StringBuffer();
        sb.append("Leaf----").append("size : ").append(nkey).append("keys: ").append(" [ ");
        for(int i = 0;i < nkey; i++){
            sb.append(keys[i]).append(", ");
        }
        sb.append("]");
        return sb.toString();
    }

}
