//3.20Ⱦɫ���⣬��ά�����У���0��k��ʾ��ɫ���û��㣨i,j���Լ�����ͬɫ�����ڵ����ɫ��

//���㷨�������Թ�Ѱ·�㷨

//������һ��int�ζ�ά���飬����Ϊ��ͼֽ��������ɫ���ɡ�
//������һ��stack��װ����elemType�������꣬�����꣬��һ����λ��Ҳ��Ϊ�ж��Ƿ񱻷��ʹ������ݡ��������stack��ʵ��"��ͼֽ�Ĳ����ֲ�"��һ����ָʾ�������ͼֽ��Ѱ·�������ϰ�������˻�



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//�궨��

#define SleepTime 2
#define Row 10
#define Col 17

//���Ͷ���
typedef enum{east,south,west,north}Direction;       //���巽��ļ���
typedef enum{color_1,color_2,color_3,color_4}Color;     //������ɫ�ļ���

typedef struct
{
    int x;
    int y;
    int di;
}SElemType;                                            //ջ�����Ԫ������

//����ԭ��

void Coloring_3_20(int g[][17],SElemType start);    //Ⱦɫ
void InitGrap(int g[][17],SElemType *start);//��ʼ��ͼ�����򣬺�Ⱦɫ�����
void PaintGrap(int g[][17]);
void ShowGrap(int g[][17]);//�ϱߵ�PaintGrap�ǰ��������ͣ�ת��Ϊ��Ļ�ϵ�ͼ�񡣱�����Show�ǰ��Ϻ�����ͼ��̶�����Ļ�ϣ�system"pause"
Status Pass(SElemType e,int g[][17]);           //��������������������ʱ���ж��Ƿ���ҪȾɫ
void Mark(SElemType *e,int g[][17]);                //���������жϳ�����������ҪȾɫ������Mark����Ⱦ֮��
Status NextPos(SElemType *e);                          //��ȡ��һ����Ⱦɫ�ķ�λ��
Status IsCross(SElemType e);//�ж��Ƿ�Խ��

int main(int argc,char **argv)
{
    int g[Row][Col];
    SElemType start;            //����һ�����ص�λ��Ϊstart��

    InitGrap(g,start);
    PaintGrap(g);
    Coloring_3_20(g,start);

    return 0;
}

//Ⱦɫ������

void Coloring_3_20(int g[][Col],SElemType start)
{
    SElemType e;
    SElemType stack[10000];//�������������˴���㿪ʼ�������ͼֽ���ߵ�·��������������ϰ�����λ��˵��ֲᡣ����������ջ�ֲᣬ������ͼֽ��ִ�С�
    int top = -1;

    e = start;
    do
    {
        if(Pass(e,g))               //�ж�ͼֽ���Ƿ���1������ǣ�˵����ҪȾɫ��
        {
        Mark(&e,g);         //Ⱦɫ���������ͼֽ����ɫ��1����Ϊ��2���������ֲ��ϣ����������ġ���һ����λ����null��Ϊeast��
        ShowGrap(g);
        stack[++top] = e;       //��Ⱦ��ɫ��Ԫ�ص���Ӧ��Ϣ�������ֲ��ջ
        NextPos(&e);            //����һ��Ҫ���ʵķ�λ��������ֲ��temp����
        }
    else
    {
        if(top!=-1)
        {
            e = stack[top--];       //���e�����������λ�ò���ҪȾɫ������Ҫ���ˡ�

            while(e.di ==North && top !=-1)     //������һ������Ȼû��λ�ÿɷ��ʵ�ʱ�򣬼���ѭ������
                e = stack[top--];

            if(e.di<North)              //��������ҵ����ܷ��ʵĵص㣬��ʱ�����stack�е�e�ķ�λֵ��1���ڰ�next��������һ�£���������
            {
            e.di++;
            stack[++top]   = e;
            NextPos(&e);
            }
        }
    }
    }while(top!=-1);
}


//��ʼ��























