package com.bqlion.DataStructure.Tree;


/* *
 * Created by BqLion on 2019/4/18
 */
public class BTreeLeaf<K extends Comparable<K>>extends AbstractBTreeNode<K> {
    private final Object[] keys;
    private int nkey;

    /**
     *  inti an BTreeLeaf
     * @param degree the degree of the node
     * keys array is the (2n - 1) of the degree
     */
    BTreeLeaf(int degree){
        super(degree);
        keys = new Object[2 * degree - 1];
    }

    @Override
    protected boolean isLeaf(){
        return true;
    }

    /**
     * return pointer of key,return null if failure to find key
     * @param key the key to search
     * @return return the pointer of the matching key,or null if failed to find
     */
    @Override
    K search(K key){
        int index = indexOfKey(key);
        if(index >= 0)
            return (K)keys[index];
        return null;
    }

    @Override
    K getKey(int idx){
        return (K)keys[idx];
    }

    @Override
    protected K setKey(K newKey,int oldKeyIndex) {
        K old = (K) keys[oldKeyIndex];
        keys[oldKeyIndex] = newKey;
        return old;
    }

    @Override
    protected void setChild(AbstractBTreeNode<K>sub,int index){
        throw  new RuntimeException("Counld not set child of leaf node");
        }

    @Override
    AbstractBTreeNode<K>getChild(int index){
        return null;
    }

    @Override
    protected void splitChild(int child){
        throw new RuntimeException("could not split child of leaf node");
    }

    @Override protected int setNKey(int nkey){
        int old = this.nkey;
        this.nkey = nkey;
        return old;
    }

    @Override int nkey(){
        return nkey;
    }

    @Override int nchild(){
        return 0;
    }

    @Override
    protected int setNchild(int nchild){
        throw new RuntimeException("could set Nchild of leaf node ");
    }

    @Override
    void insertNotFull(K key){
        checkNotFull();         //if full ,throws
        this.insertKey(key);
    }

    @Override
    void deleteNotEmpty(K key){
        this.deleteKey(key);
    }

    @Override
    protected K splitSelf(AbstractBTreeNode<K> newNode){
        if(!(newNode instanceof BTreeLeaf)){
            throw new RuntimeException("Instance not match");
        }
        if(!isFull()){
            throw new RuntimeException("Node is not full");
        }
        K middle  = (K)keys[degree - 1];
        BTreeLeaf<K>node = (BTreeLeaf)newNode;
        int i = 0;
        while(i < degree - 1){
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
    protected void merge(K middle,AbstractBTreeNode<K>sibling) {
    if(!(sibling instanceof BTreeLeaf)){
        throw new RuntimeException("Sibling is not leaf node");
    }
    BTreeLeaf node = (BTreeLeaf)sibling;
    this.insertKey(middle);
    for(int i = 0;i < node.nkey();i++){
        this.insertKey((K)node.keys[i]);
    }
    }

    @Override
    public String toString(){
        StringBuffer sb = new StringBuffer();
        sb.append("Leaf---").append("size: ").append(nkey).append("keys").append("[");
        for(int i = 0;i < nkey; i++){
            sb.append(keys[i]).append(",");
        }
        sb.append("]");
        return sb.toString();
    }
}
