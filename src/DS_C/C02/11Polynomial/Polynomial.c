/***************************************

�ļ��У�02���Ա�/11 Polynomial

�ļ�����Polynomial.c

�㷨��2.22��2.23

**************************************/

#ifndef POLYNOMIAL_C
#define POLYNOMIAL_C

#include "Polynomial.h"

//�㷨2.22

void CreatePolyn_P(FILE *fp,Polynomial *P,int m)
{
    PositionPtr h;
    ElemType_P e;
    int i;
    Link p;

    InitList_E(P);      //��ʼ��һ����չ�ĵ������Ŷ���ʽ
    h = GetHead_E(*P);   //��ȡ����ʽͷָ��

    e.coef = 0.0;               //e���Ԫ�أ�ϵ������0��ָ������-1
    e.expn = -1;
    SetCurElem_E(h,e);     //����ͷ��������Ԫ�أ�ָ��hָ���Լ�����ֵ����e��
    h->next = NULL;        //h��ָ�������һ��Ԫ�ص�nextָ����NULL����ɳ�ʼ��

    for(i=1;i<=m;i++)       //����¼��n��������
    {
                Scanf(fp,"%f%d",&(e.coef),&(e.expn));
                MakeNode_E(&p,e);           //����һ���ڵ�e����ַ��p
                p->next = NULL;
                InsFirst_E(P,h,p);                  //��p��ָ������½ڵ�����б�ǰ��
                h = h->next;                   //hָ�벽��
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

    //�㷨2.23
    void AddPolyn_P(Polynomial *Pa,Polynomial *Pb)
    {
        PositionPtr ha,hb;
        PositionPtr qa,qb;
        ElemType_P a,b;
        float sum;

        ha = GetHead_E(*Pa);                //ha hb�ֱ�ָ���������е�ͷ���
        hb = GetHead_E(*Pb);
        qa = NextPos_E(ha);                 //qa  qb�ֱ�ָ���������еĵ�ǰ�ڵ�
        qb = NextPos_E(hb);

        while(qa && qb)         //qa qb��ָ�ľ��ǿ�
        {
        a = GetCurElem_E(qa);           //a b�ֱ��ǵ�ǰ�Ƚϵ�Ԫ��
        b = GetCurElem_E(qb);

        switch(Cmp_exp(a,b))
        {
            case -1:                    //����ʽPa�е�ǰ�ڵ��ָ��ֵ��С       ��Ϊ�ǰ�pb��ֵժ������pa�в��룬�����������ֱ��pass����ָ��ֱ𲽽�
                ha = qa;                //ָ��ͷ����ha����1��ָ������p����Ϊp�����ˣ�p���µ�ͷ��㣩
                qa = NextPos_E(ha);//ָ��ǰ�ڵ��qaָ������ָ�����ha��next
                break;
            case 0:                         //���������е�Ԫ�صĴ�����ͬ��Ҫ���
                sum = a.coef  + b.coef;     //���
                if (sum != 0.0)                 //����Ӻ���ֵ������0
                {
                    qa->data.coef = sum;        //qa��ָ��Ԫ�ص��������ֵ��ʽ����˵��sum
                    SetCurElem_E(qa,qa->data);//    SetCurElem_E�����о��ڴ˶��һ�� ��ԭ�������£�void SetCurElem_E(Link p, LElemType_E e){	p->data = e;}���ǰѺ�߲�����ָ����ֵ��ֵ��ǰ���Ǹ��������о�����һ����һ����
                    ha = qa;            //ͷָ��ָ�������µ�ͷ���Ҳ����qa
                }
                else                    //��ϵ����ӵ���0
                {
                    DelFirst_E(Pa,ha,&qa);  //��pa�еĶ�Ӧ�ڵ�ɾ����Ȼ����һ���ͷ����Ŀռ�
                    FreeNode_E(&qa);
                }
                //�������ϱߵ����ֲ�������ʱ��QB�����е�Ԫ�ض��Ѿ��������ˣ���һ����Ҫɾ��
                DelFirst_E(Pb,hb,&qb);
                FreeNode_E(&qb);
                qb = NextPos_E(hb);     //����ָ��ֱ����
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
            Append_E(Pa,qb);                    //��Pb��δɨ���꣬��ʣ�������ӵ�Pa���±�����ɨ�����ˣ�ɾ��hb����ز���

        FreeNode_E(&hb);                        //�ͷ�Pbͷ���
        (*Pb).head  = (*Pb).tail = NULL;//����PbΪ����״̬
        (*Pb).len = 0;
}

void SubtractPolyn_P(Polynomial *Pa,Polynomial *Pb)
{
    PositionPtr ha,hb;
    PositionPtr qa,qb;
    PositionPtr r;
    ElemType_P a,b;
    float sum;

    ha = GetHead_E(*Pa);        //ha hbָ��ֱ��ͷ��㣬qa qb�ֱ�ָ��ǰ�Ľ��
    hb = GetHead_E(*Pb);
    qa = NextPos_E(ha);
    qb = NextPos_E(hb);

    while(qa && qb)     //qa qb��ָ����ǿ�
    {
    a = GetCurElem_E(qa);//a��bΪ�����е�ǰ�Ƚ�Ԫ��
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
            r->data.coef =-r->data.coef;            //�ı�ʣ�������
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
            s = (Link)malloc(sizeof(ELNode));       //  ����ռ�
            if(!s)
                exit(OVERFLOW);

            s->data.coef = qa->data.coef * qb->data.coef;       //ϵ�����
            s->data.expn = qa->data.expn + qb->data.expn;   //ָ�����
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




























