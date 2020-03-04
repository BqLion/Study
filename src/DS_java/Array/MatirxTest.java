package com.bqlion.Before.DataStructure.Array;

/* *
 * Created by BqLion on 2019/3/31
 */
public class MatirxTest {
    public static void main(String[] args) {
        Matrix A = new Matrix(10,9);
        System.out.println("A null Matrix of 10*9 is as follow: ");
        A.display();

        Matrix B = new Matrix(10,9);
        int q = 0;
        for(int i = 0; i < B.getwide(); i++)
            for(int j = 0; j < B.getlength(); j++) {
                B.set(i, j, q);
                q++;
            }
        System.out.println("Matrix B is as follow: ");
        B.display();


        for(int k = 0; k < A.getwide(); k++)
            for(int m = 0; m < A.getlength(); m++)
                    A.set(k,m,1);
        System.out.println("all A element was set to be 1");
        A.display();

        Matrix C = B.add(A);
        System.out.println("C = A + B ");
        C.display();
    }
}
