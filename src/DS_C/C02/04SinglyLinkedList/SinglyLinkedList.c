/************************************

�ļ��У�C02/04SinglyLinkedList

�ļ�����SinglyLinkedList.c

�㷨�� 2.8/2.9/2.10/2.11

************************************/

#ifndef SINGLYLINKDELIST_C
#define SINGLYLINKDELIST_c

#include "SinglyLinkedList.h"                   //���Ա�

Status InitList_L(LinkList *L)                  //��ʼ��һ��������������LinkList ָ��LNode�ڵ��ָ���͵�
{
    (*L) = (LinkList)malloc(sizeof(LNode));     //malloc����һ��NULL�ε�ָ�룬ָ��������ڴ��ͷ��㣬����ֵ��*L
    if(!(*L))
        exit(OVERFLOW);                         //���*L����0�������²��������������
    (*L)->next = NULL;                          //������*L��next����NULL

    return OK;
}

Status ClearList_L(LinkList L)                  //���������������ͷ���
{
    LinkList pre,p;

    if(!L)
        return ERROR;                           //���������=0����Ϊ�գ��򷵻�ERROR��

    pre = L ->next;                             //��ֵpre����ͷ����ߵĵ�һ���ڵ��ֵ

    while(pre)                                  //��pre������0��ʱ��������ѭ����
    {                                           //��pre����һ��ֵ��ֵΪp��Ȼ���preɾ�ˣ�Ȼ����˺���
        p = pre->next;
        free(pre);
        pre = p;
    }
    L->next=NULL;                               //ն��ͷ������б����ϵ
    return OK;
}

void DestroyList_L(LinkList *L)                 //�������нڵ�
{
    LinkList p = *L;

    while(p)
    {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
}

Status ListEmpty_L(LinkList L)          //����̽��
{
    if(L!=NULL && L->next==NULL)        //���������ֻ��ͷ��㣨����Ϊ�գ�����һ��ͷ����next��null��
        return TRUE;
    else
        return FALSE;
}

int ListLength_L(LinkList L)     //���������ȵĺ���
{
    LinkList p;
    int i;

    if(L)                             //������Ϊ���������²���
    {
        i=0;
        p = L->next;                   //i�Ǽ�������ָ��ÿ����һ�ξ�����1��
        while(p)                      //p��ʼֵ�ǵ�һ��Ԫ�أ���p��Ϊ�������£���û�ܳ��磩��һֱ����1
        {
            i++;
            p = p->next;
        }
    }
    return i;
}

//�㷨2.8
Status GetElem_L(LinkList L,int i,LElemType_L *e)           //��ȡ�����е�i��Ԫ�ص�ֵ��������e��   ע�������˳��������
{
    int j;
    LinkList p = L->next;          //˳����ε�ָ��p�ĵ�ֵַ���ڵ�������׽ڵ��next������һ���ڵ㣩

    j=1;
    p=L->next;

    while(p && j<i)            //��p��Ϊ�գ�δ������һ�û��i��
    {
        j++;
        p = p->next;            //��������һ��p����һ
    }

    if(!p||j>i)                 // ��p=null���߼Ʋ�����ʾ�Ѿ�����i�˻�û���ҵ�������i��Ԫ�ز�����
        return ERROR;

    *e = p->data;                  // �����������������Ҵ���e�����p��ָ�Ľṹ��������ֵ��e��������

    return OK;
}                                   //�������������Ҫ�������Ʋ��ң�������˳�������ֱ�Ӷ�λ


int LocateElem_L(LinkList L,LElemType_L e,Status(Compare)(LElemType_L,LElemType_L))     //��λԪ�صĺ��������ܣ����ر�L�ĵ�һ������compare��ϵ��Ԫ��λ��
{
    int i;
    LinkList p;

    i= -1;                         //��i������������󷵻ش�ֵ-1.���������߻ᱻ����Ϊ����ֵ

    if(L)                         //�� L������0�����ڣ�������ߵĲ�����i��ʼ��Ϊ0��pָ��L�ĵ�һ���ڵ�
    {
        i = 0;
        p = L->next;

        while(p)        //��ָ��p������NULL��ʱ�򣬼�ָ�뻹δ�����ʱ��ѭ�������¶�����
        {
            i++;

            if(!Compare(e,p->data))         //�����߲�ƥ�䣬��pָ���������
                p = p->next;
            else
                break;
        }
    }

    return i;
}

/*�����Ŷ��㷨�У��˴�������������ֱ��ʹ�ã�ԭ���ǽṹ����ֱ�ӱȽ�*/

#ifndef BANKQUEUING_C

Status PriorELem_L(LinkList L,LElemType_L cur_e,LElemType_L *pre_e)         //��ȡǰ��Ԫ�صĺ�������L����Ԫ��cur_e��ǰ��Ԫ�ظ�ֵ��*pre_e
{
    LinkList p,suc;

    if(L)                   //��L���ڣ�ִ�����²���
    {
        p = L->next;        //ָ��p����ͷ����ߵ�һ��Ԫ�صĵ�ַ

        if(p->data!=cur_e)  //cur_e����ǵ�һ���ڵ�Ļ��򱨴���Ϊ��һ��������ǰ���ڵ�
            {
                while(p->next)  // ���p�ڵ��к�̣���Ϊ�㣩����ѭ�������²���
                {
                    suc = p->next;
                    if(suc->data == cur_e)     //ָ��SUCָ��p�ڵ�ĺ�һ���ڵ㣬����һ���ڵ��ֵ����cur_e
                    {
                        *pre_e = p->data;      //��pָ����ָ��ֵ��ֵ��pre_e
                        return OK;             //������1
                    }
                    p = suc;                   //p������Ų1��ָ��suc��cur_e��ָ��λ��
                }

            }
    }
    return ERROR;                             //��ͷ�Ǽ������������if�����ش���
}

Status NextElem_L(LinkList L,LElemType_L cur_e,LElemType_L *next_e)     //ȡnextԪ�ص�ֵ����ֵ��next_e
{
    LinkList p,suc;                         //�ڵ���ָ��p��suc

    if(L)                                   //��L��Ϊ�յĻ������²���
    {
        p = L->next;                        //pָ��ͷ���

        while(p && p->next)                 //��p��p->next����Ϊ��������ѭ�������²���
        {
            suc = p->next;
            if(suc && p->data == cur_e)    //��suc������null�������������p->data����cur_e�Ļ������ɹ��ҵ��� ��
               {
                *next_e=suc->data;          //��sucָ����ָ��data��ֵ��*next_e
                return OK;
               }
                if(suc)                             //��p��λ��Ų��suc�ϣ���p����1���ص�ѭ������λ��suc����2.if������ʱsuc��=null��Ҳ����һֱҪѭ����ָ���ܳ��б�
                    p = suc;
                else
                    break;
         }
    }

    return ERROR;
}
#endif


/*�㷨2.9*/

Status ListInsert_L(LinkList L,int i ,LElemType_L e)           //���������ѱ�L�ĵ�i��Ԫ��ǰ����Ԫ��e
{                                                              //����Ĳ����˳���򵥣�ֻ�öϿ���������Ӧ��ָ�뼴�ɣ����ð�����Ԫ�صĺ���һ��Ԫ��ȫ����λ
        LinkList p,s;
        int j;

        p=L;
        j=0;

        while(p && j<i-1)                       //Ѱ�ҵ�i-1���ڵ��ѭ����������ͷָ��p������null��δ������Ҽ�����j<i-1;
        {
            p = p->next;                        //p��������
            ++j;                                //j����������1��   i++�������ú�����1��++i��������1�����á�
        }                                       //ѭ��������ʱ��pָ��ָ��i-1�ڵ�

        if(!p || j>i-1)                         //���ָ��p�������j�Ʋ�����ʾ�ܹ��ˣ����ش���
            return ERROR;

        s = (LinkList)malloc(sizeof(LNode));    //ָ��sָ�� ����ΪLinkList�ε� �ڴ�ռ䣬size��һ��Lnode
        if(!s)
            exit(OVERFLOW);                         //�������s=0���򱨴�
        s->data = e;                                 //��������ĺ��Ĳ���
        s->next = p->next;                          //�Ѵ��������ֵ��ֵ���շ���ռ��ָ��s��dataλ��Ȼ���Ƚ�s��nextָ��ָ��p�ĺ�һλ���ٰ�p��ָ��ָ��s���͹��������ӡ�ע��Ҫ���½�ָ�룬�ٶϿ���
        p->next = s;

        return OK;
}


//�㷨2.10 ɾ�������Ԫ��

Status ListDelete_L(LinkList L,int i,LElemType_L *e)           //ɾ��������������ɾ����L�ĵ�i��Ԫ�أ�����ɾ����Ԫ�ط���*e��
{
    LinkList pre,p;
    int j;

    pre = L;     //pre��������L��ͷ���
    j = 1;

    while(pre->next && j<i)             //��pre��next������0����δ������Ҽ�����j��ʾ��δ�ܹ���ʱ��������ѭ��
    {
        pre = pre->next;                //preָ�������������ֱ��preָ���i��Ŀ��Ԫ�ص�ǰһ��Ԫ��
        ++j;                            //j����������1
    }

    if(!pre->next || j>i)       //���������pre������˻��߼�����j��ʾ�Ѿ��ܹ�i�ˣ��򱨴�
        return ERROR;


    //�������ϵ�whileѭ����ָ��pre�Ѿ�ָ���˵�i-1��Ԫ�ص�λ�ã�

    p = pre->next;                  //����ָ��pֱ��ָ��preԪ�صĺ��Ԫ�أ�������

    //����ָ��pָ���˴�ɾ��Ԫ�أ�preָ��ָ���˴�ɾ��Ԫ�ص�ǰһ��Ԫ�أ���ָ����͸�λ

                                    //���������Ǳ��㷨�ĺ��Ĳ���
    pre->next = p->next;            //��ɾ��Ԫ�ص�ǰһ��Ԫ�صĺ�ָ��ֱ��������ɾ��Ԫ�أ�ָ���ɾ��Ԫ�صĺ��Ԫ�ء���һ����ʵ���Ѿ�����������е�ɾ��������������ʱ�򲻻��ٱ�������ɾ��Ԫ����
    *e = p->data;                   //�Ѵ�ɾ���ڵ��Ԫ��ֵ��ֵ������e�����Ϊ����
    free(p);                        //�ͷ�pָ��ָ��Ŀռ�

    return OK;
}


Status ListTraverse_L(LinkList L,void(Visit)(LElemType_L))          //�����������ѱ�L����һ��
{
    LinkList p;

    if(!L)
        return ERROR;           //�������ݽ����ı�L��Ϊ�վͷ���ERROR
    else
        p = L->next;            //���������L��Ϊ�գ�p��ָ��ͷ���


    while (p)                   //��p��ΪNULL����û�����ʱ��,�ظ������²���
    {
        Visit(p->data);         //����visit p������Ԫ��
        p = p->next;            //p����1
    }

    return OK;
}

//�㷨2.11 ͷ�巨��������

Status CreateList_HL(FILE *fp,LinkList *L,int n)
{
    int i;
    LinkList p;
    LElemType_L tmp;

    *L = (LinkList)malloc(sizeof(LNode));   //������L��ͷ���
    if(!(*L))                               //���L=0�򱨴�
        exit(OVERFLOW);
    (*L)->next = NULL;                        //��L��ͷ����next����NULL��������һ���ձ�ֻ��ͷ���

    for(i=1;i<=n;++i)                       //++i��������1��������i������Ҳ����i��һ�����õ�ʱ����Ѿ���2��
    {
        if(Scanf(fp,"%d",&tmp)==1)          //����ܴ�fp��ɨ�赽�����Ļ�
        {
            p = (LinkList)malloc(sizeof(LNode)); //��ָ��p����һ�������ڴ�ռ�
            if(!p)
                exit (OVERFLOW);                //��������ڴ治�ɹ�p=0�򷵻����

            p->data = tmp;                      //ͷ�巨�Ĺؼ����裺��֮ǰscanf��������tmp��ֵ��pָ���data��
            p->next = (*L)->next;               // Ȼ�󽫴�����Ľ��p��nextָ��ָ��ͷ����next
            (*L)->next = p;                     //Ȼ��ͷ����nextָ��ָ��p��������ͨ��insert����insertһ������һ��
        }
        else
            return ERROR;
    }
    return OK;
}

Status CreateList_TL(FILE *fp,LinkList *L,int n)    //β�巢����һ������
{
    int i;
    LinkList p,q;
    LElemType_L tmp;

    *L = (LinkList)malloc(sizeof(LNode));          //������������Lָ��*L����һ��sizeof LNode�� �ڴ�ռ�
    if(!(*L))                                      //malloc֮������ı�׼��䣬��ֹ�ڴ����ʧ��
        exit(OVERFLOW);
    (*L)->next = NULL;                             //������*L��ͷ���

    for(i=1,q=*L;i<=n;++i)                        //������i��ʼ��Ϊ1��ָ��qָ��ͷ���*L����Ϊ�ǳ�ʼ�������Բ��ò�ָ��ͷ��㣬���ǳ���������ָ��qָ�����β�ڵ㡿
    {
        if(Scanf(fp,"%d",&tmp)==1)
        {
            p = (LinkList)malloc(sizeof(LNode));  //ָ��pָ��һ���·����LNode��С���ڴ�ռ���ײ�����ָ��q����״����
            if(!p)                                 //malloc֮��ı�׼��䣬���p=NULL�����ڴ����ʧ�ܣ�����OVERFLOW
                exit(OVERFLOW);
            p->data = tmp;                          //����������￨����������tmpֵ��ֵ��p��data�p����ָ����Ǵ�������
            q->next = p;                            //��q���ָ��ָ����Ƕ�βԪ�أ�����q��nextָ��ָ��p
            q = q->next;                            // Ȼ��q����1��ָ���µĶ�βԪ��
        }
        else
            return ERROR;
    }

    q->next = NULL;                                 //���빤����ɺ�q��nextָ��null������β���һ��Ԫ�ص�nextָ���ÿ�

    return OK;

}

#endif // SINGLYLINKDELIST_C






























