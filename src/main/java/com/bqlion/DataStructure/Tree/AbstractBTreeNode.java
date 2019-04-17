package com.bqlion.DataStructure.Tree;
import java.util.LinkedList;
import java.util.Queue;

/* *
 * Created by BqLion on 2019/4/15
 */
/*
    b树是一种m叉树，其中节点满足：一个节点最多有m个子树，根节点不是叶子时，至少有两颗子树。
                                除根节点外，所有非终端节点至少有m/2颗子树
                                有s个子树的非叶节点具有n = s-1个关键字
                                用抽象类先写出一个类的基本函数情况，再用如下文的绿色专业注解说明各个函数的情况
                                用@param @return等等注释，非常清晰明了。类似于C的头文件

    为什么本文件要写成抽象类：
    因为有些方法的具体实现不确定
    比如B数的节点的插入工作，有可能直接就插入了，也可能要拆分父节点重新调整结构。
    不确定的方法就用抽象方法先写着他们相同的部分，不同的部分可以留着具体实现时写



 */
public abstract class AbstractBTreeNode<K extends Comparable<K>>{            //Comparable是排序类接口，实现了此接口的类可以被排序
                                                                            //可以用arrays.sort和collection.sort等方法来实现
    protected final int degree;         //B tree的节点的本体就是存储一个“度”。

    AbstractBTreeNode(int degree){
    if(degree < 2){
        throw new IllegalArgumentException("degree must >= 2");         //throwIleagArgu是抛出异常参数的意思，代表未接到合法参数
    }
    this.degree = degree;
     }

    /**
     * If the node is Leaf.
     * @return true is  Leaf,False is not.
     */
    abstract boolean isLeaf();

    /**
     * Search Key in B tree.
     *
     * @param key the key to search
     * @throws java.lang.RuntimeException if node is full.
     */
    abstract K search(K key);

    /**
     * Insert a key into a node when the node is not full
     *
     * @param key the key to insert
     * @throws java.lang.RuntimeException if node is full
     */
    abstract void insertNotFull(K key);

    /**
     * <p>Delete a key when the{@code keys >= degree.}</p></>
     * If the key to delete does not exist in current node,internal node will find a subtree
     * tree the key may exist in,find the key in subtree and delete,the leaf will do nothing
     * if the key to delete is not exist.
     * @param key the key to delete
     */
    abstract void deleteNotEmpty(K key);

    void insertKey(K key){
        checkNotFull();
        int i = this.nkey();        //
        while(i > 0 && key.compareTo(this.getKey(i - 1)) < 0){
            this.setKey(this.getKey(i -1),i);
            i--;                        //数组倒序地依次后移，拉出一个空位
        }
        this.setkey(key,i);             //空位set，计数器加一
        this.setNKey(this.nkey() + 1);
    }

    /**
     * <p>get a key with index of{@code idx}in current node</p>
     * @param idx idx of key to get
     * @return key of given index
     * @throws java.lang.RuntimeException if {@code idx < 0} or {@code idx >= degree *2 -1}
     */
    abstract K getKey(int idx);

    /**
     * <p>delete given key in current node</p>
     *
     * @param key the key to delete
     * @return the key deleted or null if key does not exist
     */
    protected K deleteKey(K key) {
        int index = indexOfKey(key);
        if (index >= 0)
            return this.deleteKey(index);
        return null;
    }

    /**
     * <p>delete key with a given index</>
     * @param index index of key to delete
     * @return key delete or null if index is invalid
     * @throws java.lang.RuntimeException if index is invaild.
     *
     */
     protected K deleteKey(int index){
         if(index < 0 || index >=this.nkey()){
             throw new RuntimeException("Index is invaild");
         }
         K result = this.getKey(index);
         while(index < this.nkey() -1){
             this.setKey(this.getKey(index + 1),index);//从index起直到最后一个元素，依次前移，与线性链表的删除类似
             index ++;
         }
         this.setKey(null,this.nkey() - 1);     //最后不忘把最后一个坑置为空
         this.setKey(this.nkey() - 1);
         return result;
     }

    /**
     * <p> check if current exists given key</>
     * @param key key to check
     * @return true is  given key exists in current node
     */
     boolean existsKey(K key){
        return indexOfKey(key) >= 0;
     }

    /**
     * Replace one key with new Key
     * @param oldkey the key to replace
     * @param newkey the new key to insert in
     */
    protected void replaceKey(K oldkey,K newkey){
        int index = indexOfKey(oldkey);
        if(index >= 0) {
            setKey(newkey, index);
        }
    }
    /**
     * replace given index key with a new key
     * @param newkey the new key to insert in
     * @param oldkeyindex old key`s index
     * @return the key be replaced or null if the index is invaild
     */

    protected abstract K setKey(K newkey,int oldkeyindex);

    /**
     * Set one of current child with given index
     * @param  sub child subtree
     * @param index index of child to set
     */
    protected abstract void setChild(AbstractBTreeNode<K>sub,int index);            //在这个抽象类中，用抽象方法加上注解的方式来确定一个抽象树节点的功能，接下来可以用具体的类来重写抽象方法实现具体类

    /**
     * insert a child at given index
     * the node being inserted is not full yet[simpled condition]
     * @param sub child subtree to insert
     * @param index index of child to insert
     */
    protected void insertChild(AbstractBTreeNode<K>sub,int index){          //
        int i = this.nchild;
        while(i >index){
            this.setChild(this.getChild(i - 1),i);
            i --;
        }
        this.setChild(sub,index);
        this.setNChild(this.nchild() + 1);          //open a gap to insert childsubTree
    }

    /**
     * Get child with given index
     * @param index index of child to get
     * @return return the child being getted.or null if index is invalld;
     */
    abstract AbstractBTreeNode<K>getChild(int index); //getChild can be various method,so using Abstact method

    /**
     * Delete given child in current node
     * @param child child Subtree to delete
     */
    protected void deleteChild(AbstractBTreeNode<K>child){    //protected : available for sons,private for other classes
        int index  = -1;
        for(int i = 0; i < nchild();i++){               //move index to deleting place
            if(this.getChild(i) == child){
                index = i;
                break;                                  //break the for loop if get right place
            }
        }
        if(index > 0){
            deleteChild(index);
        }
    }

    /**
     * delete child with given index
     * @param index index of child to be deleted
     * @return child subtree or null if index is invaild
     */
    protected AbstractBTreeNode<K>deleteChild(int index){
        AbstractBTreeNode<K>result = null;
        if(index >= 0 && index < this.nchild()){
            result = this.getChild(index);
            while(index < this.nchild() -1){
                this.setChild(this.getChild(index + 1),index);
                index ++;
            }
            this.setChild(null.index);
            this.setNchild(this.nchild() - 1);
        }
        return result;
    }

    /**
     * split a full child to two child node
     * @param child child index to split
     * @throw java.lang.RuntimeException is child to split is not full
     */
    protected abstract void splitChild(int child);
    /**
     * split current node to two node
     *
     * @param newNode new node
     * @return middle of current node before split
     * @throws java.lang.RuntimeException if currrent node is not full
     */
    protected abstract void splitSelf(AbstractBTreeNode<K>newNode);

    /**
     * Merge current node with another
     * @param middle middle key of two node
     * @param sibling sibling node to merge
     * @throws java.lang.RuntimeException if keys of either node exceed degree -1
     */
    protected abstract void merge(K middle,AbstractBTreeNode<K>sibling);        //method of merge can be variosu

    /**
     * set key amount of current node
     * @param nkey key amount to set
     * @return old key amount
     */
    protected abstract int setNKey(int nkey);
    /**
     * key amount of current node
     * @return key amount of current node
     */
    abstract int nkey();

    /**
     * Child amount of current node
     * @return ket amount of current node
     */
    abstract int nchild();

    /**
     * set child anmount of current node
     * @param nchild child amount
     * @return old child amount
     */
    protected abstract int setNchild(int nchild);

    /**
     * get index of given key
     * @param key the key to get
     * @return index of key or -1 if key does not exist in current node
     */
    protected int indexOfKey(K key){
        for(int i = 0; i < this.nkey(); i++){
            if(key.equals(this.getKey(i))){
                return i;
            }
        }
        return -1;
    }

    /**
     * check whehter current node is full
     * @return true if current node is full,else false
     */
    protected boolean isFull(){
        return nkey () == degree * 2-1;             //the reasonable key number of Treenode
    }

    /**
     * check current node is not full
     * @throws java.lang.RuntimeException if current is full
     */

    protected final void checkNotFull(){
        if(isFull()){
            throw new RuntimeException(this.toString() + "is full.");
        }
    }

    /**
     * recursively traverse the b TREE ,constitute a String
     *
     * @param  root root of B-Tree
     * @param <K>Type of key of B-TREE
     * @return  String of B-Tree
     */
    static <K extends Comparable<K>>String BTreeToString(AbstractBTreeNode<K>root){
        StringBuffer sb = new StringBuffer();
        AbstractBTreeNode node;
        Queue<AbstractBTreeNode> queue = new LinkedList<>();
        queue.add(root);
        String newLine = System.getProperty("line.separator");
        while (!queue.isEmpty()){
            node = queue.poll();
            sb.append(node).append(newLine);
            int i = 0;
            while (node.getChild(i) != null){
                queue.offer(node.getChild(i));
                i++;
            }
        }
        return sb.toString();
    }
}


