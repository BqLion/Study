package com.bqlion.After.DataStruct.Tree;

public class trieTree {

/********************field**********************************/

    private int SIZE = 26;
    private TrieNode root;

/********************field**********************************/


/********************Constructor****************************/
    trieTree(){
        this.root = new TrieNode();
    }
/********************Constructor****************************/


/********************Method*********************************/

    public void insert(String str) {
        if (str == null || str.length() == 0) {
            return;
        }
        TrieNode node = root;
        char[]letters = str.toCharArray();
        for(int i = 0,len = str.length();i < len;i++)
        {
            int pos = letters[i] - 'a';
            if(node.son[pos]==null)
            {
                node.haveSon = true;
                node.son[pos] = new TrieNode();
                node.son[pos].val  = letters[i];
            }
            else
            {
                node.son[pos].num++;
            }
            node = node.son[pos];
        }
        node.isEnd = true;
    }
/********************Method*********************************/
}
