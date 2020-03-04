/******************************************

文件夹C02/08ExtenLinkedList-main.c

内容：扩展的单链表相关函数测试

*******************************************/

#include<stdio.h>
#include"E:/E/DS/C02/09ExtenLinkedList/ExtenLinkedList.c"

//函数原型

Status CmpGreater(LElemType_E e,LElemType_E data);          //判断data是否大于e，若data>e，返回TRUE
void PrintElem(LElemType_E e);

int main(int argc,char **argv)
{
                                                                                                                                                                                                                                                                ELinkList L;
        Link p,q,s;
        PositionPtr r;
        int i;
        LElemType_E e;

        printf("↓3\n↑函数LnitList_E测试...\n");
        {
            printf("初始化扩展的单链表L...\n");
            InitList_E(&L);
            printf("\n");
            ListTraverse_E(L,PrintElem);//测试
        }
        PressEnter;

        printf("↓14\n↑ 函数ListEmpty_E 测试...\n");
        {
            ListEmpty_E(L) ? printf(" L 为空！！\n"):printf("L 不为空！！\n");
            printf("\n");
            ListTraverse_E(L,PrintElem);//测试
        }
        PressEnter;

        printf("↓23\n↑函数 ListInsert_L_E 测试...\n");
        ListTraverse_E(L,PrintElem);//测试
        {
            for(i=1;i<=6;i++)
            {
                printf("在L第%d个位置插入 \"%d\" ... \n",i,2*i);
                ListInsert_L_E(&L,i,2*i);
            }
             ListTraverse_E(L,PrintElem);//测试
            printf("\n");
        }
        PressEnter;

        printf("↓15\n↑函数 ListLength_E 测试...\n");
        {        ListTraverse_E(L,PrintElem);//测试
            i = ListLength_E(L);
                 ListTraverse_E(L,PrintElem);//测试
            printf("L 的 长度为%d \n",i);
            printf("\n");
        }
        PressEnter;

        printf("↓24\n↑ 函数ListDelete_E 测试...\n");
        {       ListTraverse_E(L,PrintElem);//测试
            ListDelete_L_E(&L,6,&e);
                ListTraverse_E(L,PrintElem);//测试
            printf("删除L 中的第6个元素 \"%d\"...  \n",e);
            printf("L 中的元素为： L=");
            ListTraverse_E(L,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("↓20\n↑函数LocatePos_E 测试...\n");
        {
            LocatePos_E(L,3,&p);
            printf("L中第三个元素\"%d\" 的地址为 0x%x  \n",p->data,p);
            printf("\n");
        }
        PressEnter;

        printf("↓18\n↑函数 PriorPos_E 测试...\n");
        {
            r = PriorPos_E(L,p);
            printf("指针p指向的元素\"%d\"  的前驱元素为 \"%d\"  \n",p->data,r->data);
            printf("\n");
        }
        PressEnter;

        printf("↓19\n↑ 函数 NextPos_E测试... \n");
        {
            r = NextPos_E(p);
            printf("指针p指向的元素\"%d\" 的后继元素为 \"%d\"  \n",p->data,r->data);
            printf("\n");
        }
        PressEnter;

        printf("↓21\n↑函数LocateElem_E 测试...\n");
        {
            r = LocateElem_E(L,7,CmpGreater);
            printf("L中第一个元素值大于7的元素\"%d\"的地址为0x%x \n",r->data,r);
            printf("\n");
        }
        PressEnter;

        printf("↓1\n↑函数 MakeNode_E 测试...\n");
        {
            printf("创建节点p ...\n");
            MakeNode_E(&p,101);
            printf("创建节点q...\n");
            MakeNode_E(&q,202);
            printf("\n");
        }
        PressEnter;

        printf("↓13\n↑函数 GetCurElem_E 测试...\n");
        {
        e = GetCurElem_E(p);
        printf("节点p的值为\"%d\" \n",e);
        e=  GetCurElem_E(q);
        printf("节点q的值为\"%d\" \n",e);
        printf("\n");
        }
        PressEnter;

        printf("↓12\n↑函数 SetCurElem_E 测试...\n");
        {
            printf("用 888 替换p节点中的值...\n");
            SetCurElem_E(p,888);
            printf("节点p的值为\"%d\"  \n",p->data);
            printf("\n");
        }
        PressEnter;

        printf("↓2\n↑函数 FreeNode_E 测试..\n");
        {
            printf("销毁p节点前：");
            p? printf("p存在！!\n"):printf("p 不存在！！\n");
            FreeNode_E(&p);
            printf("销毁节点p后：");
            p?printf("p 存在！\n"):printf("p 不存在！！\n");
            printf("\n");
        }
        PressEnter;

        printf("↓8\n↑函数Append_E 测试...\n");
        {
            printf("将q节点插入L的最后一个节点之后");
            Append_E(&L,q);
            printf("L中的元素为：L = ");
            ListTraverse_E(L,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("↓\n↑9\n函数 Remove_E 测试...\n");
        {
        printf("删除L中最后一个节点，用p接受删除的结点...\n");
        Remove_E(&L,&p);
        printf("L中的元素为：L=  ");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
        }
        PressEnter;

        printf("↓6\n↑ 函数 InsFirst_E 测试...\n");
        {
            printf("创建值为 303 的结点 p ...\n");
            MakeNode_E(&p,303);
            printf("令q指向L中第4个 元素...\n");
            LocatePos_E(L,4,&q);
            printf("将p节点插入到与以q作为头结点的链表的第一个节点之前...\n");
            InsFirst_E(&L,q,p);
            printf("L中的元素为:L=");
            ListTraverse_E(L,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("↓ 16\n ↑ 函数 GetHead_E 测试...\n");
        {
            p = GetHead_E(L);
            printf("L 头指针为p = L.head = 0x%x  \n",p);
            printf("\n");
        }
        PressEnter;

        printf("↓17\n↑ 函数GetLast_E 测试...\n");
        {
            q = GetLast_E(L);
            printf("L 的尾指针为q = L.tail = 0x%x \n",q);
            printf("\n");
        }
        PressEnter;

        printf("↓10\n↑函数 InsBefore_E 测试...\n");
        {
            printf("创建值为404的结点 s...\n");
            MakeNode_E(&s,404);
            printf("将节点s插入到尾节点q之前...\n");
            InsBefore_E(&L,&q,s);
            printf("当前L的值为：L = ");
            ListTraverse_E(L,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("↓11\n↑ 函数 InsAfter_E 测试...\n");
        {
            printf("创建值为505的结点s...\n");
            MakeNode_E(&s,505);
            printf("将s插入到头结点p之后...\n");
            InsAfter_E(&L,&p,s);
            printf("L中的元素为：L= ");
            ListTraverse_E(L,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("↓4\n↑函数 ClearList_Ec测试...\n");
        {
            printf("清空L前：");
            ListEmpty_E(L)?printf("L为空！！！\n"):printf("L不为空！！！！\n");
            ClearList_E(&L);
            printf("清空L后 ：");
            ListEmpty_E(L)?printf("L为空！！！\n"):printf("L不为空！！！！\n");
            printf("\n");
        }
        PressEnter;

        printf("↓5\n↑ 函数 DestroyList_E 测试...\n");
        {
            printf("销毁L前：");
            L.head != NULL && L.tail!=NULL ?  printf("L 存在！！！\n"):printf("L不存在！！！\n");
            DestroyList_E(&L);
            printf("销毁L后：");
            L.head!=NULL &&L.tail!=NULL ? printf("L 存在！！\n"):printf("L不存在！！！\n");
            printf("\n");
        }
        PressEnter;

        return 0;
}

Status CmpGreater(LElemType_E e,LElemType_E data)
{
    return data>e ? TRUE:FALSE;
}

void PrintElem(LElemType_E e)
{
    printf("%d,e");
}
