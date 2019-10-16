package com.bqlion.DataStructure.Tree;

import com.sun.org.apache.xml.internal.security.Init;
import javafx.beans.binding.ObjectExpression;

/* *
 * Created by BqLion on 2019/4/4
 */
public class BinaryTreeTest {
    public static void main(String[] args) {
        Object[] InitArray = {'a','b',null,null,'c','d',null,null,null};
        BinaryTree<Object> bs = new BinaryTree<Object>(InitArray);
        System.out.println(bs.isEmpty());
        bs.display();
        System.out.println(bs.display());
        bs.PrintTree(bs.display());
    }
}
