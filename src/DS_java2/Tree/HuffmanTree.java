package com.bqlion.After.DataStruct.Tree;

import com.bqlion.After.DataStruct.List.ArrayList;
import com.bqlion.After.DataStruct.List.List;

public class HuffmanTree {

/********************field**********************************/

/********************field**********************************/


/********************Constructor****************************/
    private static HuffmanTreeNode buildHuffmanTree(HuffmanTreeNode[] materials){
        int materialsLength =  materials.length;
        if(materialsLength < 2)return materials[0];

        ArrayList huffmanTreeBuilder = new ArrayList();

        for(int i  = 0;i < materialsLength;i++)
            insertToListByOrder(huffmanTreeBuilder,materials[i]);

        for(int i  = 1;i < materialsLength; i++) {
            HuffmanTreeNode min1 = (HuffmanTreeNode) huffmanTreeBuilder.remove(huffmanTreeBuilder.getSize() - 1);
            HuffmanTreeNode min2 = (HuffmanTreeNode) huffmanTreeBuilder.remove(huffmanTreeBuilder.getSize() - 1);
            HuffmanTreeNode newRoot = new HuffmanTreeNode(min1.getWeight() + min2.getWeight());
            newRoot.setLChild(min1);
            newRoot.setRChild(min2);
            insertToListByOrder(huffmanTreeBuilder, newRoot);
        }
            return (HuffmanTreeNode)huffmanTreeBuilder.get(0);
    }
/********************Constructor****************************/


/********************Method*********************************/
    private static void insertToListByOrder(ArrayList l,HuffmanTreeNode node){
        for(int j = 0;j < l.getSize();j++)
            if(node.getWeight() > ((HuffmanTreeNode)l.get(j)).getWeight()){
                l.insert(j,node);
                return;
            }
        l.insert(l.getSize(),node);
    }

    private static void generateHuffmanCode(HuffmanTreeNode root){
        if(root == null)return;

        if(root.hasParent()){
            if(root.isLChild())
                root.setCode(root.getParent().getCode() + "0");
            else
                root.setCode(root.getParent().getCode() + "1");
        }
        generateHuffmanCode(root.getLchild());
        generateHuffmanCode(root.getRchild());

    }


/********************Method*********************************/
}
