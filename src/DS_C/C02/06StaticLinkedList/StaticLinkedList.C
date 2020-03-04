/********************************************

�ļ��У�C02/06StaticLinkedList.c

�ļ�����StaticLinkedList.c

�㷨��2.13,2.14,2.15,2.16

******************************************/

#ifndef STATICLINKEDLIST_C
#define STATICLINKEDLIST_C

#include"StaticLinkedList.h"                //����ͷ�ļ�

//�㷨2.14

void InitSpace_SL()             //���ȳ�ʼ�����ÿռ�
{
    int i;                                 //i�Ǹ�������

    for(i=0;i<MAXSIZE-1;i++)        //ѭ��999�����²���
        SPACE[i].cur =  i+1;              //�ѽ���Ƥ���ĵڶ��е�Ԫ�ض���ֵΪ������+1��������Ԫ�ص��±����ʼ����Ϊ��һ��Ԫ�ص�λ��

    SPACE[MAXSIZE-1].cur = 0;//���һλԪ�ص��±���Ϊ��
}

//�㷨2.15

int Malloc_SL()         //�ӱ��ÿռ�����ڵ�ռ�  ���� ���ϵĺ����Ѿ������˱��ÿռ�999�������������̬������Ҫʹ�õĻ���Ҫ�������
{
    int i ;

    i = SPACE[0].cur;                                    //i����ֵΪͷ����next������һ��Ԫ��

    if(SPACE[0].cur)                                     //�����һ��space���ÿռ���±겻����0���ռ�δ�������꣩
    {
        SPACE[0].cur = SPACE[i].cur;            //ͷ����next����ֵΪԭ��һ���ڵ��next��ԭ��һ���ڵ㱻ɾȥ�������Ѿ�����ɹ�����Ҫ��ʹ����
        return i;                                             //����i��ֵ��i���ղ������ͷ����nextֵ��������ɹ���ԭ��һ���ڵ��λ��
    }
    else
        return 0;
}
//Malloc_SL���Ǵ��ʼ��ʼ����1000�����ÿռ��а��մ�ͷ��β��˳��ȡ��һ��Ԫ�س�����׼��Ҫʹ����

//�㷨2.16

void Free_SL(int k)             //����K�ڵ�Ŀռ�
{
    SPACE[k].cur = SPACE[0].cur;    //k�ڵ��next����ֵΪͷ����next
    SPACE[0].cur = k;                       //ͷ����next����ֵΪk�����������ڰ�k�ڵ㰴ͷ�巨������SPACE�����У�����ʹ�ÿռ�ص��˱��ÿռ䣬��malloc_SL���෴�Ĳ���
}

Status InitList_SL(SLinkList *H)        //��ʼ����̬�����ĺ�����HΪͷ���ָ�루SLinkList����def�ȼ���int��������൱���Ƕ����� һ��int�ε�ָ�룩
{                                                        //���ܶ������һ��ָ��̬�����Ļ���ָ��ڵ����ָ������ӵĽṹ���ָ�룬ָ��һֱ��һ����λ�ġ����ƺš�����߾ʹ���һ����ַ��Ϣ��ָ�벻��ָ����������Ͳ�ͬ�����ִ�С
    *H = Malloc_SL();                         //ָ�� ��̬����������������int�Σ���ָ��H����ָ���ڴ��ַ�ϴ洢�����ݣ�����ֵΪMALLOC_SL�������صġ����ÿռ�ĵ�һ�����нڵ��λ��

    if(!(*H))                                        //���ָ��ָ��ĵ�ַ�洢��������Ϊ�գ��򱨴������е�malloc�������������һ�仰��
        exit(OVERFLOW);                    //������OVERFLOW��

    SPACE[*H].cur = 0;                    //���ÿռ�ġ���ָ��H��ָ���Ǹ�Ԫ�ء���next���Ϊ0�������뱸�ÿռ�SPACE������

    return OK;
}

Status ClearList_SL(SLinkList H)
{
    int p,q;

    if(!H)          //���H������0�򱨴�
        return ERROR;

        p = SPACE[H].cur;                           //��ϰSPACE���壺SPACE��һ��componet�α�����component��һ��ӵ��1000�� ��̬����Ԫ��struct ��̬�������ÿռ�
                                                                //p�Ǹ����α������ھ�̬�����г䵱��ָ�롱�Ľ�ɫ��p����ֵΪ��H��Ԫ�ص�cur������Ҳ���ǵ�H��Ԫ�ص���һ��Ԫ�ص�λ��˳��Ļ������Ǳ�H��1������

        while(p)                                           //��p������0��ʱ��,��pָ���Ԫ�ز�Ϊ�յ�ʱ��ѭ�������²���
        {
            SPACE[H].cur = SPACE[p].cur;      //��2��Ԫ�ص�next��3����3�� Ԫ�ص�next��4��ֱ�Ӱѵڶ���Ԫ�ص�next��ֵΪ������Ԫ�ص�nextҲ����4���������������൱��ָ���ƿ��м�Ԫ�أ�Ҳ�����ڱ���ɾ�����м�Ԫ��
            Free_SL(p);                                     //�ڶ���Ԫ�ص�next�Ѿ�����ֵΪ4�ˣ�������Ԫ�ؿ��Ա�free����
            p = SPACE[H].cur;                         //H��next�Ѿ������˱仯����2��Ԫ�ص�next�Ѿ���4�ˣ�����p������3��Ϊ����ֵΪ4���Ӷ�ʹѭ�������run����
        }

        return OK;
}

void DestroyLsit_SL(SLinkList *H)
{
    ClearList_SL(*H);           //��վ�̬�������Ԫ��

    Free_SL(*H);            //��ͷ���Ĵ洢�ռ�Ҳ����SPACE

    *H = 0;                //ͷ�����0��
}

Status ListEmpty_SL(SLinkList H)
{
    if(H && !SPACE[H].cur)              //��H������0����H�ڵ��next����0��������£������棬���򷵻ؼ١�������ֻ��ͷ����򷵻�ʱ�յģ����򷵻طǿ�
        return TRUE;
    else
        return FALSE;
}

int ListLength_SL(SLinkList H)
{
    int count;
    int p;
    if(!H)
        exit(OVERFLOW);             //H����0��ʱ�򷵻ش���

    count = 0;
    p = SPACE[H].cur;               //p����ͷ����ĵ�һ���ڵ�

    while(p)                            //��pû��Խ���ʱ��ѭ��������������ͬʱ����1
    {
        count++;
        p = SPACE[p].cur;
    }
    return count;
}

Status GetElem_SL(SLinkList H,int i,LElemType_S *e)
{
    int count,p;

    if(!H || i<1 || i>MAXSIZE-2)
        return ERROR;                   //�쳣������ų���

    count = 0;
    p = SPACE[H].cur;           //���������㣬������ָ�롱ָ���һ��Ԫ��

    while(p)                        //ָ��pû�����������£�������ѭ������1��ֱ������������ҪgetԪ�ص�λ����ʱe����ֵΪԪ�ص�data
    {
    count++;

        if(count ==i)
        {
            *e = SPACE[p].data;
        return OK;
        }

    p = SPACE[p].cur;
    }
}

//�㷨2.13

int LocateElem_SL(SLinkList H,LElemType_S e)
{

    int k,count;

    count = 1;

    if(H && SPACE[H].cur)               //�����������H����ͷ�ͺ��Ԫ�ض�����˵���˱��ǿգ��������²�����
    {
        k = SPACE[H].cur;                   //����k����ֵΪͷ����next����������Ϊָ���׸��ڵ��ָ�룩

        while(k &&SPACE[k].data!=e)     //��ָ��k��Ϊ�㣨δ������� ������ָ��k��ָ��data��ʱ��˵����û�е�λ����ʱ��ָ��Ҫһֱ����
            {
                count ++;
                k = SPACE[k].cur;
            }

            if(k)
                return count;               //����������ѭ�������k������0��˵��û�а�kѭ��������ˣ���return ����������ʾ������
    }
    return 0;
}

Status PriorElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *pre_e)           //ǰ��Ԫ��
{
    int  p,q;

    if(H)
    {
        p = SPACE[H].cur;               //pָ����ڵ�һ��Ԫ�ص��±�

        if(p && SPACE[p].data!=cur_e)   //���ָ��p������0����SPACE��data��û��ָ��cur_e
        {

            q = SPACE[p].cur;            //q����pָ�����һ��Ԫ�ص��±�

            while(q && SPACE[q].data!=cur_e)    //qָ�����pָ�����һ��
            {
                p = q;
                q = SPACE[q].cur;
            }

                if(q)
                {
                *pre_e = SPACE[p].data;
                return OK;
                }
        }
    }
    return ERROR;
}

Status NextElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *next_e)       //ȡcur_e����һ��Ԫ��next_e
{
    int p;

    if(H)
    {
        p = SPACE[H].cur;                               //���������ı�H������0����ָ�롱���±꣩p����ֵΪH��ͷ���

        while(p && SPACE[p].data != cur_e)  //��pû�в������������pָ����ָ��Ԫ�ص�data������cur_e��ʱ��p��������
            p = SPACE[p].cur;

        if(p && SPACE[p].cur)       //�ϱ��Ǹ�ѭ������SPACE[p].data ����cur_e����p=0��ʱ��ֹͣѭ�����������ж�p��p��next�ǲ��ǵ����㣬��������˵����ָ�������һ���ڵ㣬��������ǲ����ں�̽ڵ�ģ���Ҫ����һ��else���������򣬾ͳ�ȥp��ָ��Ԫ�ص���һ��Ԫ�ؾ�OK��
        {
            p = SPACE[p].cur;
            *next_e = SPACE[p].data;
            return OK;
        }
    }
    return ERROR;
}

Status ListInsert_SL(SLinkList H,int i,LElemType_S e)
{
    int count,k,p;

    if(!H)                  //������������ڷ��ش���
        return ERROR;

    if (i>0)
    {
        count = 0;
        k = H;                  //kָ��ͷ���

        while(k && count<i-1)           //��kָ�뻹û���ܳ������count��������ʾ��û�е�λ��ʱ��
        {
            count ++;
            k = SPACE[k].cur;               //������ѭ������1��kָ��ѭ����������Ų
        }

    if(k)               //�ϱ��Ǹ�ѭ�������ˣ����ֽ����1.kָ����ָ��λ�� 2.k��������û�ҵ����ŵĶ�����������Ϊ0�����if����Ϊ���ų�k=0�����
    {
        p = Malloc_SL();    //k�ҵ���ָ��λ���ˣ���̬�����ڴ����
        if(!p)                      //���p����0�򱨴�  ��������ڴ����ʧ�ܣ����ش���
            return ERROR;

        SPACE[p].data =e;                   //p��������Ŀռ䣬��e����ֵ������
        SPACE[p].cur = SPACE[k].cur;        //p��ָ��ָ��Ҫ�����Ԫ�ص�next��˼·����������ʱһ��
        SPACE[k].cur = p;                           //ǰһ��Ԫ�ص�nextָ��p

        return OK;
        }
    }
    return ERROR;
}

Status ListDelete_SL(SLinkList H,int i,LElemType_S *e)
{
    int count,k,p;

    if(!H)
        return  ERROR;              //����������Ҫ����

    if(i>0)
    {
        count = 0;
        k = H;                     //kָ������H��ͷ���

        while(k && count <i-1)      //Ѱ��ɾ��Ԫ�ص�ǰһ��λ��
        {
            count ++;
            k = SPACE[k].cur;               //û�ҵ��Ļ�����������1��ָ��kҲ����ѭ������ǰ��
        }

    if (k && SPACE[k].cur)          //����������ѭ���ҵ��˵�i-1��Ԫ�ص�λ�ã���ʱ�ų���i-1�������һ��λ�ã����û�п�ɾ����
    {
        p = SPACE[k].cur;    //kָ��i-1,pָ��i �����ɾ����Ԫ�ص�λ��
        *e = SPACE[p].data; //��Ҫɾ����p��λ�õ�data��ֵ��e��Ȼ��Ϳ���ִ�н�������ɾ�������ˡ�˼·�͵�������һ����
        SPACE[k].cur = SPACE[p].cur; //ǰһ���ڵ��nextָ��ֱ��ָ�򱾽ڵ��next��ֱ���������ڵ�while����ɾ���˱��ڵ�
        Free_SL(p);             //��p��ָ��Ԫ����ռ�ݵ�SPACE �ռ���ͷ���

        return OK;
    }
    }

    return ERROR;
}

Status ListTraverse_SL(SLinkList H,void(Visit)(LElemType_S))
{
    int p;

    if(!H)
        return ERROR;               //�����������ڻ�Ϊ�շ��ش���

    p = SPACE[H].cur;               //p"ָ��"����ֵΪͷ���

    while (p)                       //p����Ϊ0��û�����ʱ��ѭ�������µĲ���
    {
    Visit(SPACE[p].data);       //����ָ����ָ��Ԫ�ص�����
    p = SPACE[p].cur;           //ָ����ǰ����1

    }
    return OK;
}

#endif // STATICLINKEDLIST_C

















