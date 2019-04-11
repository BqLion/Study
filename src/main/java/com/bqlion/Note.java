package com.bqlion;

public class Note {
}
/*
1.Parse Tree

2.所有的文件只能有一个class 也就是public class
其他的class都写成内部类

3.lombook

4.ast tree

5.编译原理

6.图相关的算法：两种实现
    1.邻接表
    2.矩阵

7.headfirst 设计模式

8.三元迭代

2019.3.28更新:

1.数据结构的代码要自己写，尝试完全脱离书本。

2.缺少测试用例，多写点测试项。
2.1 两个数据结构压入十万条数据做crud性能比较，早知道性能损耗在哪里如何优化
                               【crud性能比较：写个计时器循环插入数据进去】
3.不贪快要深入。


问题一:Array - Matrix Line 16：
为什么书上的this(n,n)就OK我这里这么写就无法编译？
缺省构造函数中的this(n,n)是否指代的是非缺省函数？
this到底该怎么理解？
this.value到底有无必要？
直接value好像也可以直接通过编译

问题二：Array -Matrix Line 37:
因为get函数需要返回int型不得不设为int型函数
那么如何表示错误？
直接return，return null都不可以；
这里用return 0代替，但是不能分辨是报错还是真的取出的是0元素?

问题三：Array -Matrix Line 58:
add函数功能是两个矩阵相加，C[][] = A[][] + B[][]
A[i][j]、B[i][j] 用 get(i,j)函数来获取，书上直接this.value[i][j] + b.value.[i][j]
value数组为private权限
private权限限定只有本类可见，相同包不同包中的其他类和子类均不可见
在测试函数中：
new Matrix C= new Matirx A.add(new Matrix B)时，A B C 应该是三个不同的类不可直接调用value数组吧

问题四：BinaryTree line27：
递归也有退出条件，i< length,i++
如何去思考去理解递归呢？
       BinaryTree line 112:

       public int height(BinaryTreeNode<E> p) {
        if (p != null) {
            int ld = height(p.left);
            int rd = height(p.right);
            return (ld >= rd) ? ld + 1 : rd + 1;
        }
        return 0;
    }

问题五：
ThreadBinaryTree.java
line 17 -- 28

关于递归：

for(i = 0 ;i < length; i++)     /写在函数外边的i = 0是否是否规范？递归的一般性写法和思考方式是什么？
{.left = preorder
 .right = preorder
}

问题六：
ThreadBinaryTree。java
line 37 -- 46如何理解递归？遇见类似的树类定义又该如何去组织思维？

*/