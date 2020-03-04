package com.bqlion.After.DataStruct.Tree;

public class HuffmanTreeNode extends BinaryTreeNode{

/********************field**********************************/
    private int weight;
    private String code = "";
/********************field**********************************/



/********************Constructor****************************/
    public HuffmanTreeNode(int weight){this(weight,null);}

    public HuffmanTreeNode(int weight,Object e){
        super(e);
        this.weight = weight;
    }
/********************Constructor****************************/



/********************Method*********************************/
public HuffmanTreeNode getParent(){
    return(HuffmanTreeNode)super.getParent(); }


    public HuffmanTreeNode getLchild(){
        return (HuffmanTreeNode)super.getlChild();
    }

    public HuffmanTreeNode getRchild(){
        return (HuffmanTreeNode)super.getrChild();
    }

    public HuffmanTreeNode setLChild(HuffmanTreeNode htn){return null;}
    public HuffmanTreeNode setRChild(HuffmanTreeNode htn){return null;}
    public boolean isLChild(){return true;}
    public int getWeight(){return weight;}

    public String getCode(){return code;}

    public void setCode(String code){this.code = code;}
/********************Method*********************************/
}
