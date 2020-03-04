/*2.34 ���ָ������
˼·��ÿ��LNode������һ��Singleָ��ָ������data������data��ָ��������ǰ��ڵ��singleָ��������򵥶���һ���������߽���������ǰ���ߺ�û��singleָ��������NULL��
*/
//��ʼʱ�䣺14:27 ����ʱ�䣺20:31
#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//���ݽṹ����

typedef char XElemType;             //����������char��
typedef struct XorNode              //����ڵ�����ݽṹ����data��ָ��LRPtr���
{
    XElemType data;
    struct XorNode *LRPtr;
}XorNode;

typedef XorNode* XorPointer;   //ָ��ڵ��ָ��
typedef struct                              //������������ݽṹ������������ָ��ڵ��ָ�빹��
{
    XorPointer Left;
    XorPointer Right;
}XorLinkedList;

typedef XorLinkedList* Xor;     //Xor��ָ�������ָ��

//���ֺ��������Ͷ���

Status Algo_2_34_1(Xor L,int mark);
Status Algo_2_34_2(Xor L,int mark);
Status Algo_2_35(Xor L,int i,XElemType e);
Stauts Algo_2_36(Xor L,int i,char *e);
XorPointer XorP_XorL(XorPointer p,XorPointer q);
Status Init_XorL(Xor *L);
Stauts Create_XorL(Xor L,int n,XElemType Data[]);
XorPointer Prior_Next_Ptr_XorL(Xor L,XorPointer cur,int mark);
int Length_XorL(Xor L);
XorPointer GetElemPtr_XorL(Xor L,int i);

int main(int argc,char **argv)
{
    Xor L;                                                          //������һ����һ���������ͣ�һ��n
    XElemType e;
    int n = 9;
    XElemType *data = "123456789";      //�ڵ�Ԫ���ε�ָ���ֵ����ֵΪ���

    Init_XorL(&L);                                      //��ʼ����������˳����������������
    Craete_XorL(L,n,data);
    printf(" 2.34��֤...\n");
    printf("˳�����L...");
    Algo_2_34_1(L,0);
    printf("\n");
    printf("�������...\n");
    Algo_2_34_1(L,1);
    printf("\n\n");

    printf("��2.35��֤...\n");         //����������ɾ�������
    Algo_2_35(L,5,'*');
    printf("���롮*��ΪL�ĵ�����ڵ��˳�����...\n");
    Algo_2_34_2(L,0);
    printf("\n\n");

    printf("��2.36��֤...\n");
    Algo_2_36(L,5,&e);
    printf("ɾ��L �ĵ�����ڵ㡮%c����������� ...\n",e);
    Algo_2_34_2(L,1);
    printf("\n\n");

    return 0;
}

//��ʼ�����ָ������L

Stauts Init_XorL(Xor *L)
{
    *L = (Xor)malloc(sizeof(XorLinkedList));
    if(!(*L))
        exit(OVERFLOW);

    (*L)->Left = NULL;                  //���ָ���ı���ṹ�Ƚϼ򵥣�һ����ָ��һ����ָ�룬һ����ͷ������ͷ����ռ䣬����ָ���ÿռ�����ɳ�ʼ��
    (*L)->Right = NULL;

    return OK;

}

//�������ָ������L

Status Create_XorL(Xor L ,int n,XElemType Data[])
{
    int i;
    XorPointer pre_l,pre_m,pre_r;

    pre_l = pre_m = NULL;           //ǰ�к�����ָ�룬ǰ���ÿգ���ָ�����Ŀռ�

    for(i=1;i<=n;i++)
    {
        pre_r = (XorPointer)malloc (sizeof(XorNode));
        if(!pre_r)
            exit(OVERFLOW);

        pre_r->data = Data[i-1];            //��ָ���data���������ȡԪ��
        if(i==1)
            L->Left = pre_r;               //�״�ִ�У���L->Left ��ָ��ָ��pre_r���Ԫ����

        //�������б�����ǰ�߽綯��
        //pre_r ��������������Ȼ���pre_r���Ž����У��������ڶ���β����m��ָ����Ҫ����Ӧ��������r��ָ��Ԫ����������������֮�󣬶���Rightָ��Ҫ�仯��ָ���µĶ���β��Ȼ���µĶ���β��ָ����ҲҪ����Ӧ������Ȼ��l m r����ָ�밴˳�򲽽�����ʼ��һ��ѭ��

        if(pre_m)
            pre_m->LRPtr = XorP_XorL(pre_l,pre_r);  //pre_m������һ��ѭ���󲽽�1��Ϊ���ˣ�Ҳ���Ǵӵڶ���ѭ����ʱ��ʼ����Ϊ��Ҫ����ָ���pre_m�����У���ָ��Ԫ�ص�ָ������Ա���ֵΪpre_l ��pre_r�����
        L->Right =pre_r;
        pre_r->LRPtr = XorP_XorL(pre_m,NULL);
        pre_l = pre_m;
        pre_m = pre_r;
    }

    return  OK;
}

//��ȡ��ǰ�ڵ�cur��ǰ��mark=0����mark=1

XorPointer Prior_Next_Ptr_XorL(Xor L,XorPointer cur,int mark)
{
    XorPointer p_l,p_m,p_r;

    if(mark!=1 && mark!=0)
        return NULL;

    if(mark == 1)
    {
        p_l = NULL;//       -1
        p_m = L->left;//            0

        while(p_m!=cur)
        {
        p_r = XorP_XorL(p_l,p_m->LRPtr);    //1            //���ָ�������б�ʾp_m��next�ķ�������A,B���������B����A+C������������C,Ҳ����nextԪ��
        p_l = p_m;
        p_m = p_r;              //����ָ�벻�ϲ���,ֱ��p_m����curԪ�أ���ʱ����cur����һ��Ԫ�ؾ�OK��Ҳ���ǡ����p_l��p_m��PTR����
        }

        p_r = XorP_XorL(p_l,p_m->LRPtr);

        return p_r;
    }

    if(mark==0)         //����������ǰ����˼·��ͬ��ģ���p_r �� p_m��PTR�������
    {
    p_m = L->Right;         //�߽�����
    p_r = NULL;
    while(p_m!=cur)
    {
        p_l = XorP_XorL(p_r,p_m->LRPtr);
        p_r = p_m;
        p_m = p_l;
    }

    p_l = XorP_XorL(p_m->LRPtr,p_r);

    return p_l;
    }
}

//(05)��ȡL�ĳ���

int Length_XorL(Xor L)
{
    int count;
    XorPointer p,pre,psuc;

    if(!L)
        exit(OVERFLOW);

    count = 0;
    pre = NULL;
    p = L->Left;

    while(p)
    {
        count++;
        psuc = XorP_XorL(pre,p->LRPtr);
        pre = p;
        p = psuc;               //��������������β����count����++��󷵻�count�� ���ı߽������ǣ������ڶ��������һ�����ҵ�������һ����˵������NULL�����������NULL��p����NULL��ѭ����ֹ�˳���
    }
    return count;
}

//������ָ���i���ڵ��ָ�룩

XorPointer GetElemPtr_XorL(Xor L,int i)
{
    int count;
    XorPointer p,pre,psuc;          //����������ָ��

    if(!L || !L->Left)
        return ERROR;

    if(i<1)
        return ERROR;

    count =1;                   //��������1��ʼ�㣬���ÿգ���Ϊ1����Ϊ1��next��������������е����� �������򣬽�����ҡ������ַ�ʽ�����β������õ���ָ��Ԫ�ء�
    pre = NULL;
    p =  L->Left;

    while (count<i && p)
    {
        psuc = XorP_XorL(pre,p->LRPtr);
        pre = p;
        p = psuc;
        count++;
    }
    return p;
}

//���L��mark��ʾ�������
Status Algo_2_34_1(Xor L,int mark)
{
    XorPointer cur;

    if(mark!=1 && mark !=0)
        return ERROR;

    if(!L || !->Left)
        return ERROR;

    if(mark==0)
    {
        cur = L->Left;
        do
        {
            printf("%c ",cur->data);
            cur = Prior_Next_Ptr_XorL(L,cur,!mark);
        }while(cur);
    }

    if(mark==0)
    {
        cur = L->Left;
        do
        {
        printf("%c ",cur->data);
        cur = Prior_Next_Ptr_XorL(L,cur,!mark);
        }while(cur);
    }
    return OK;
}

//���L��mark��ʾ�������
//������ǰ����̺�����������
Status Algo_2_34_2(Xor L,int mark)
{
    XorPointer p_l,p_m,p_r;

    if(mark!=1 && mark!=0)
        return ERROR;

    if(!L && ��L->Left)
        return ERROR;           //���L����L��ͷԪ��ΪNULL �򷵻ش���

    if(mark == 0)
    {
        p_l =NULL;
        p_m = L->Left;

        while(p_m)
        {
            printf("%c ",p_m->data);
            p_r = XorP_XorL(p_l,p_m->LRPtr);
            p_l = p_m;
            p_m = p_r;
        }
    }

    if(mark == 1)
    {
    p_m = L->Right;
    p_r = NULL;

    while(p_m)
    {
        printf("%c ",p_m->data);
        p_l = XorP_XorL(p_m->LRPtr,p_r);
        p_r = p_m;
        p_m = p_l;
    }
    }
    return OK;
}

//��Ԫ��e���뵽��i���ڵ�֮ǰ

Status Algo_2_35(Xor L,int i,XElemType e)
{
        XorPointer s,i_pre_pre,i_pre,i_suc;

        if(!L)
        return ERROR;

        if(i<1 || i>Length_XorL(L)+1)
            return ERROR;

        s = (XorPointer)malloc(sizeof(XorNode));
        if(!s)
            return OVERFLOW;
        s->data = e;

        i_cur = GetElemPtr_XorL(L,i);
        i_pre = GetElemPtr_XorL(L,i-1);
        i_pre_pre = GetElemPtr_XorL(L,i-2);         //��������ָ��ָ���У�ǰһ��ǰ����

        if(!i_cur)          //���Ҫ�����λ�������ǿգ�������֤ǰһ��λ���Ƿ�Ϊ�գ����ǰ��һ��λ���ǿգ���˵������Ϊ�գ�����Ϊ�׽ڵ㣬���ǰһ��λ����ڣ���֤��i-1�����һ��Ԫ�أ�i�պó��磬������β�巨
        {
            if(!i_pre)          //���ǰһ��λ��Ϊ�գ����ǿձ�ͷ��
            {
                s->LRPtr = NULL;
                L->Left = s;
            }
            else                //���ǰһ��λ��Ϊ�գ���i�պ�����ڶ���β��β�巨����
            {
                s->LRPtr = i_pre;//s��ָ����Ӧ����i_pre��NULL�����Ӧ��Ҳ����i_pre,���Ƕ���β��Ԫ�ص�����
                i_pre->LRPtr = XorP_XorL(i_pre_pre,s);//�͸�����һ������һ�����������ڶ���������
            }

        L->Right = s;
        }
        else
        {
        i_suc = XorP_XorL(i_pre,i_cur->LRPtr);//nextָ�븳ֵΪiλ�����һ����������������next��NULL���������cur��nextԪ�أ�Ҳ�Ƕ���βԪ��

        s->LRPtr = XorP_XorL(i_pre,i_cur);//s��ָ���򱻸�ֵΪpre��cur֮����Ǹ�Ԫ�أ�������Ԫ���Ѿ���ָ������������cur����һ����ԭpreԪ��ָ����ĵ���

        if(!i_pre)
            L->Left = s;
        else
            i_pre ->LRPtr = XorP_XorL(i_pre_pre,s);
        }
    return OK;
}

//ɾ����i���ڵ㣬����e���ܽڵ���Ԫ��ֵ
Status Algo_2_36(Xor L,int i,char *e)
{
    XorPointer i_pre_pre,i_pre,i_cur,i_suc,i_suc_suc;

    if(i<1 || i<L.length_XorL(L))
        return ERROR;

    if(!L ||!L->Left)
        return ERROR;

    i_cur = GetElemPtr_XorL(L,i);
    *e = i_cur->data;

    i_pre = GetElemPtr_XorL(L,i-1);
    i_suc = GetElemPtr_XorL(L,i+1);

    if(!i_suc)
    {
        L->Right = i_pre;

        if(!i_pre)
            L->Left = NULL;
        else
            i_pre->LRPtr = Xor}P_XorL(i_pre->LRPtr,i_cur);
    }
    else
    {
        if(!i_pre)
        {
            L->Left = i_suc;
            i_suc->LRPtr = XorP_XorL(i_cur,i_suc->LRPtr);
        }
    else
    {
    i_pre_pre = XorP_XorL(i_pre->LRPtr,i_cur);
    i_suc_suc = XorP_XorL(i_cur,i_suc->LRPtr);
    i_pre->LRPtr = XorP_XorL(i_pre_pre,i_suc);
    i_suc->LRPtr = XorP_XorL(i_pre,i_suc_suc);
    }
    }
    free(i_cur);
    i_cur = NULL;
    return OK;
}






