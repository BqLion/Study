package com.bqlion.study;
import net.mindview.util.Print.*;

import static net.mindview.util.Print.print;

public class Calculator {

    public int calc(String input){
        SeqStack StackOpe = new SeqStack(50);  //符号栈
        SeqStack StackNum = new SeqStack(50);  //数字栈
        String e,temp;                        //中转站
        String ope,x;                         //运算符号
        String a,b;                           //输入的数字
        int i = 0;                          //输入的String[]的指针
        String work[] = new String[100];

        for(int j = 0;j <input.length(); j++){
        work[j] = String.valueOf(input.charAt(j));
        }
        StackOpe.push("#");

        temp = work[0];
        while(!temp.equals("#") || !GetTop(StackOpe).equals("#"))
        {
            boolean flag = isOperator(temp);
            if(flag == false){
                StackNum.push(temp);
                temp = work[++i];
            }
            else
            {
                switch(Compare(GetTop(StackOpe),temp))
                {
                    case"<":
                        StackOpe.push(temp);
                        temp = work[++i];
                        break;
                    case"=":
                        x = StackOpe.pop();
                        temp = work[++i];
                        break;
                    case">":
                         ope = StackOpe.pop();
                         b = StackNum.pop();
                         a = StackNum.pop();
                         StackNum.push(Operator(a,ope,b));
                         break;

                }
            }
        }
        return Integer.parseInt(String.valueOf(GetTop(StackNum)));
    }

    public String GetTop(SeqStack a){
        String c = a.peek();
        return c;
    }

    public boolean isOperator(String a) {
        switch(a){
            case"+":
            case"-":
            case"*":
            case"/":
            case"(":
            case")":
            case"#":
                return true;
            default :
                return false;
        }
    }

    public String Compare(String ope1,String ope2) {
        String result = "0";
        switch (ope2) {
            case "+":
            case "-":
                if (ope1.equals("(")  || ope1.equals("#"))
                    result = "<";
                else
                    result = ">";
                break;

            case "*":
            case "/":
                if (ope1.equals("*") || ope1.equals("/") || ope1.equals(")"))
                    result = ">";
                else
                    result = "<";
                break;

            case "(":
                if (ope1.equals(")")) {
                    print("error!");
                    break;
                } else
                    result = "<";
                break;

            case ")":
                switch (ope1) {
                    case "(":
                        result = "=";
                        break;
                    case "#":
                        print("wrong bracket!");
                        break;
                    default:
                        result = ">";
                }
                break;

            case "#":
                switch (ope1) {
                    case "#":
                        result = "=";
                        break;
                    case "(":
                        print("Wrong bracket!");
                        break;
                    default:
                        result = ">";
                }
        }
        return result;
    }

    public String Operator(String a,String ope,String b){
        int x = Integer.parseInt(String.valueOf(a));
        int y = Integer.parseInt(String.valueOf(b));
        int z = 0;

        switch(ope){
            case"+":
                z = x + y;
                break;
            case"-":
                z = x - y;
                break;
            case"*":
                z = x * y;
                break;
            case"/":
                z = x / y;
                break;
        }
        String result = String.valueOf(z);
        return result;
        }
    }

