/***************************************

文件夹：02线性表/11 Polynomial

文件名：Polynomial.c

算法：2.22、2.23

**************************************/

#ifndef POLYNOMIAL_C
#define POLYNOMIAL_C

#include "Polynomial.h"

//算法2.22

void CreatePolyn_P(FILE *fp,Polynomial *P,int m)
{
    PositionPtr h;
    ElemType_P e;
    int i;
    Link p;

    InitList_E(P);      //初始化一个扩展的单链表存放多项式
    h = GetHead_E(*P);   //获取多项式头指针

    e.coef = 0.0;               //e这个元素，系数等于0，指数等于-1
    e.expn = -1;
    SetCurElem_E(h,e);     //设置头结点的数据元素（指针h指向自己，数值等于e）
    h->next = NULL;        //h所指的这个第一个元素的next指针置NULL，完成初始化

    for(i=1;i<=m;i++)       //依次录入n个非零项
    {
                Scanf(fp,"%f%d",&(e.coef),&(e.expn));
                MakeNode_E(&p,e);           //新作一个节点e，地址是p
                p->next = NULL;
                InsFirst_E(P,h,p);                  //把p所指的这个新节点插在列表前方
                h = h->next;                   //h指针步进
    }
    }

    void DestroyPolyn_P(Polynomial *P)
    {
    DestroyList_E(P);
    }

    int PolynLength_P(Polynomial P)
    {
    return ListLength_E(P);
    }

    //算法2.23
    void AddPolyn_P(Polynomial *Pa,Polynomial *Pb)
    {
        PositionPtr ha,hb;
        PositionPtr qa,qb;
        ElemType_P a,b;
        float sum;

        ha = GetHead_E(*Pa);                //ha hb分别指向两个队列的头结点
        hb = GetHead_E(*Pb);
        qa = NextPos_E(ha);                 //qa  qb分别指向两个队列的当前节点
        qb = NextPos_E(hb);

        while(qa && qb)         //qa qb所指的均非空
        {
        a = GetCurElem_E(qa);           //a b分别是当前比较的元素
        b = GetCurElem_E(qb);

        switch(Cmp_exp(a,b))
        {
            case -1:                    //多项式Pa中当前节点的指数值较小       因为是把pb的值摘下来往pa中插入，所以这种情况直接pass，各指针分别步进
                ha = qa;                //指向头结点的ha步进1（指向现在p，因为p过关了，p是新的头结点）
                qa = NextPos_E(ha);//指向当前节点的qa指针现在指向的是ha的next
                break;
            case 0:                         //两个队列中的元素的次数相同，要相加
                sum = a.coef  + b.coef;     //相加
                if (sum != 0.0)                 //若相加后数值不等于0
                {
                    qa->data.coef = sum;        //qa所指的元素的数据项被赋值上式子所说的sum
                    SetCurElem_E(qa,qa->data);//    SetCurElem_E函数感觉在此多此一举 ：原函数如下：void SetCurElem_E(Link p, LElemType_E e){	p->data = e;}就是把后边参数所指的数值赋值给前边那个参数，感觉和上一行是一样的
                    ha = qa;            //头指针指向现在新的头结点也就是qa
                }
                else                    //若系数相加等于0
                {
                    DelFirst_E(Pa,ha,&qa);  //把pa中的对应节点删除了然后下一行释放它的空间
                    FreeNode_E(&qa);
                }
                //不管是上边的哪种操作，这时的QB队列中的元素都已经操作过了，下一步需要删除
                DelFirst_E(Pb,hb,&qb);
                FreeNode_E(&qb);
                qb = NextPos_E(hb);     //两个指针分别后移
                qa = NextPos_E(hb);
                break;
            case 1:
                DelFirst_E(Pb,hb,&qb);
                InsFirst_E(Pa,ha,qb);
                qb = NextPos_E(hb);
                ha = NextPos_E(ha);
                break;
        }//switch
        }//while
        if(qb)
            Append_E(Pa,qb);                    //若Pb还未扫描完，将剩余项连接到Pa，下边是若扫描完了，删除hb的相关操作

        FreeNode_E(&hb);                        //释放Pb头结点
        (*Pb).head  = (*Pb).tail = NULL;//设置Pb为销毁状态
        (*Pb).len = 0;
}

void SubtractPolyn_P(Polynomial *Pa,Polynomial *Pb)
{
    PositionPtr ha,hb;
    PositionPtr qa,qb;
    PositionPtr r;
    ElemType_P a,b;
    float sum;

    ha = GetHead_E(*Pa);        //ha hb指向分别的头结点，qa qb分别指向当前的结点
    hb = GetHead_E(*Pb);
    qa = NextPos_E(ha);
    qb = NextPos_E(hb);

    while(qa && qb)     //qa qb所指有物，非空
    {
    a = GetCurElem_E(qa);//a和b为两表中当前比较元素
    b = GetCurElem_E(qb);

    switch(Cmp_exp(a,b))
    {
        case -1:
                ha = qa;
                qa = NextPos_E(ha);
                break;
        case 0:
            sum = a.coef - b.coef;
            if(sum!=0.0)
            {
                qa->data.coef = sum;
                SetCurElem_E(qa,qa->data);
                ha =qa;
            }
            else
            {
                DelFirst_E(Pa,ha,&qa);
                FreeNode_E(&qa);
            }
            DelFirst_E(Pb,hb,&qb);
            FreeNode_E(&qb);
            qb = NextPos_E(hb);
            qa = NextPos_E(ha);
            break;
        case 1:
            DelFirst_E(Pb,hb,&qb);
            qb->data.coef=-qb->data.coef;
            InsFirst_E(Pa,ha,qb);
            qb = NextPos_E(hb);
            ha = NextPos_E(ha);
            break;
        }//switch
    }//while

    if(qb)
    {
        r = qb;
        while(r)
        {
            r->data.coef =-r->data.coef;            //改变剩余结点符号
            r =r->next;
        }
    Append_E(Pa,qb);
    }

    FreeNode_E(&hb);
    (*Pb).head = (*Pb).tail = NULL;
    (*Pb).len = 0;
}

    void MultiplyPolyn_P(Polynomial *Pa,Polynomial *Pb)
    {
    Polynomial Pc,Ptmp;
    int i,j,la,lb;
    PositionPtr ha;
    PositionPtr qa,qb;
    Link s;

    la = PolynLength_P(*Pa);
    lb = PolynLength_P(*Pb);
    ha = (*Pa).head;

    InitList_E(&Pc);

    for(i=1;i<=la;i++)
    {
        InitList_E(&Ptmp);

        DelFirst_E(Pa,ha,&qa);
        qb = (*Pb).head->next;

        for(j=1;j<lb;j++)
        {
            s = (Link)malloc(sizeof(ELNode));       //  申请空间
            if(!s)
                exit(OVERFLOW);

            s->data.coef = qa->data.coef * qb->data.coef;       //系数相乘
            s->data.expn = qa->data.expn + qb->data.expn;   //指数相加
            s->next = NULL;

            Append_E(&Ptmp,s);

            qb = qb->next;
        }
            AddPolyn_P(&Pc,&Ptmp);
    }

        AddPolyn_P(Pa,&Pc);

        DestroyPolyn_P(Pb);
    }

    int Cmp_exp(ElemType_P c1,ElemType_P c2)
    {
    int i = c1.expn -c2.expn;

    if(i<0)
        return -1;
    else if(i == 0)
        return 0;
    else
        return 1;
    }

    void PrintPolyn_P(Polynomial P)
    {
        int i;
        Link p;

        p = P.head->next;
        for(i=1;i<=P.len;i++)
        {
            if(i == 1)
                printf("%g",p->data.coef);
            else
            {
                if(p->data.coef>0)
                {
                    printf(" + ");
                    printf("%g",p->data.coef);
                }
                else
                {
                printf(" - ");
                printf("%g",-p->data.coef);
                }
            }

        if(p->data.expn)
        {
            printf("x");

            if(p->data.expn!=1)
                printf("%d",p->data.expn);
        }

        p = p->next;
        }
    }

#endif // POLYNOMIAL_C




























