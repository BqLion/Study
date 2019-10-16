package com.bqlion.DataStructure.Array;

/* *
 * Created by BqLion on 2019/3/31
 */
public class Matrix {
    private int[][] value;      //矩阵的本体是一个二维数组

    public Matrix(int n, int m) {        //构造函数
        value = new int[m][n];
        //value = new Array[m][n];      //新申请一个二维数组就是new int[][]就OK，[][]就是数组，不存在new Arrat
    }

    public Matrix(int n) {
        //this(n, n);              //问题一
        value = new int[n][n];
    }

    public Matrix() {
        value = new int[20][20];
    }

    //数组这种数据结构只有get set，数据的坑位是固定的，只可以取出或者放进。不能插队或删除坑位。
    //所以只有set get方法，无add delete方法

    public boolean set(int m,int n,int o){
        if(m >value.length || n > value[0].length)
        return false;
        else {
            this.value[m][n] = o;
            return true;
        }
    }

    public int get(int m,int n){         //get需要返回值所以是int型函数
    if(m > value.length)
        return 0;               //问题二
    else
        return value[m][n];
    }

    public int getwide(){        //下边的矩阵加函数需要先判定两个矩阵是否形状一致是否可加。遂需得知value数组形状，value是private的需要length函数得知
        return value.length;
    }

    public int getlength(){
        return value[0].length;       //求数组宽度，原理同上
    }

    public String getline(int i){
        StringBuilder line  = new StringBuilder();
        for(int j = 0; j< this.getlength(); j++) {
            line.append(this.value[i][j]);
            line.append(" ");
        }
        return line.toString();
    }

    public Matrix add(Matrix b){          //调用的时候是这样的：matrix c = matrix a.add(matrix b),所以加数是参数matrix b被加数是matrix a
        if (b.getlength() != this.getlength() || b.getwide() != this.getwide() || b.getwide() == 0 || b.getlength() == 0)
            return null;
        else{
            int i = 0,j = 0;
            Matrix temp = new Matrix(b.getlength(),b.getwide());
            for(i = 0; i <b.getwide(); i++) {
                for (j = 0; j < b.getlength(); j++){
                    temp.value[i][j] = this.get(i,j) + b.get(i,j);    //问题三
                }
            }
            return temp;
            }
    }
    public void display(){
            for(int j = 0; j <this.getwide(); j++)
                System.out.println(getline(j));
           System.out.println("\n");

    }
}