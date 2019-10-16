package com.bqlion.DataStructure.Tree;

/* *
 * Created by BqLion on 2019/4/12
 */

/*
构造哈夫曼树的过程就是输入权值节点，然后最小的两个权值两两合并。在合并的过程中写入左右子树和双亲节点的位置值。
 */
public class HuffmanTree {
    private HuffManTreeNode[] HuffmanArray;         //哈夫曼树的主体就是一个储存哈夫曼四项值的数组
    private int leafNum;                           //叶子节点待编码的元素，枝节点反应各元素的关系。

    public HuffmanTree(int[] weight){                  //数组存储的哈夫曼树的构造函数，唯一参数为权重数组
        int WeightArrayLength = weight.length;          //权重数组长度代表待编码元素个数，记录之
        this.leafNum = WeightArrayLength;
        this.HuffmanArray = new HuffManTreeNode[2 * WeightArrayLength - 1]; //n个待编码元素需要2n-1个树节点才存储他们的本体和关系
    for(int i = 0;i < WeightArrayLength; i++){
        this.HuffmanArray[i] = new HuffManTreeNode(weight[i]); //首先把n个待编码元素放进数组的前n个坑里
    }
    for(int i = 0; i < WeightArrayLength - 1; i++){   //此循环用于填后n-1个坑
        int min1,min2,x1,x2;
        min1 = min2 = Integer.MAX_VALUE;
        x1 = x2 = -1;
        for(int j = 0; j < WeightArrayLength + i; j ++){
            if(HuffmanArray[j].weight < min1 && HuffmanArray[j].parent == -1){      //本if和下边的if是寻找最小值和次最小值的例子
                min2 = min1;                                                        //min1是最小的，min2次小，if 小于min1，赋值给min1，min1赋值给min2
                x2 = x1;
                min1 = HuffmanArray[j].weight;
                x1 = j;
            }
            else if(HuffmanArray[j].weight < min2 && HuffmanArray[j].parent == -1){ //值在min1和min2之间，则直接赋值给min2
                min2 = HuffmanArray[j].weight;                                      //每个节点只能有一次双亲赋值的机会
                x2 = j;                                                             //一旦有爹不可有新爹，所以 判断条件是parent != -1
            }
        }
        HuffmanArray[x1].parent = WeightArrayLength + i;        //两个最小值认爹
        HuffmanArray[x2].parent = WeightArrayLength + i;
        this.HuffmanArray[WeightArrayLength + i] = new HuffManTreeNode();//爹初始化，权重等于两儿子相加
        HuffmanArray[WeightArrayLength + i].weight = HuffmanArray[x1].weight + HuffmanArray[x2].weight;
        HuffmanArray[WeightArrayLength + i].left = x1;  //爹指向儿子，建立关系
        HuffmanArray[WeightArrayLength + i].right = x2;
    }
    }
                                                        //哈夫曼树的建立过程就是：
                                                        //建立最小值和次最小值的游标（工作指针），分别对其进行相应操作
    public String[] huffmanCode(){          //建立了哈夫曼树则哈夫曼编码就直接根据树形输出即可
        String[] code = new String[this.leafNum];
        for(int i = 0; i < this.leafNum; i++){
            code[i] = "";
            int child = i;
            int parent= HuffmanArray[child].parent;
            while(parent != -1){
                if(HuffmanArray[parent].left == child)
                    code[i] = "0" + code[i];
                else
                    code[i] = "1" + code[i];
                child = parent;
                parent = HuffmanArray[child].parent;
            }
        }
        return code;
    }
}
