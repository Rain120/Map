#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listHeader.h"
#include "Macro.h"

/*****************************
 *  Paraments
 *****************************/
extern int searchTime = 0;

/************************************************************************
 *  创建链表
*************************************************************************/
Link_t createList(void)
{
    Link_t p = (Link_t)malloc(sizeof(link_t));
    if (NULL == p)
    {
        printf("Malloc Fail!\n");
    }
    p->next = NULL;
    return p;
}
/************************************************************************
*                    打印带头结点的单链表
*************************************************************************/
void PrintList(Link_t p)
{
    /**
     *  注意这里，如果单链表为空（只有一个头结点），我也让它打印（打印成功）。只是里面没有元素，打出来是空的而已,所以在控制台上就是一行空的；
     */
    int i = 0;
    if (NULL == p)
    {
        puts("The list is NULL!\n");
    }
    Link_t q;
    q = p->next;
    while (q != NULL)
    {
        printf("linkID = %ld\t",q->road.linkID);
        printf("Brunch: %d\t", q->road.Brunch);
        printf("roadName: %s\n", q->road.roadName);
        q = q->next;
    }
}
/************************************************************************
*                   返回带头结点的单链表的长度
*************************************************************************/
int sizeList(Link_t p)
{
    /**
     *  当只有一个头结点的时候，size = 0；头节点不计算到链表长度中。
     */
    int len = 0;
    Link_t q;
    q = p->next;
    while (q != NULL) {
        len++;
        q = q->next;
    }
    return len;
}
/************************************************************************
*                             冒泡排序
*      比较相邻节点，选出未排序元素中的最大数，
*      需要用一个尾指针由后向前遍历链表。这里不改变链表结构，而是交换节点存储的数据。
*************************************************************************/
Link_t bubbleSort(Link_t head)       //冒泡排序
{
    printf("\t\t\tBubble Sorting Begining!!!\n");
    Link_t endpt;    //控制循环比较
    Link_t p;        //临时指针变量
    Link_t p1,p2;

    p1 = createList();
    p1->next = head->next;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
    head->next = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

    for (endpt = NULL; endpt != head->next; endpt = p)
    {
        for (p = p1 = head->next; p1->next->next != endpt; p1 = p1->next)
        {
            if (p1->next->road.linkID > p1->next->next->road.linkID)  //如果前面的节点键值比后面节点的键值大，则交换
            {
                p2 = p1->next->next;
                p1->next->next = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p = p1->next->next;
            }
        }
    }

    p1 = head->next;              //把p1的信息去掉
    head->next = head->next->next;       //让head指向排序后的第一个节点
    free(p1);          //释放p1
    p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

    printf("\t\t\tBubble Sorting Finished!!!\n");
    return head;
}
/************************************************************************
 * Bubble Value Error
 ***********************************************************************/
Link_t bubbleSort1(Link_t p)
{
    //unsigned long  temp;
    int count = sizeList(p);//用来控制次数

    Link_t q;
    q = p->next;
    while (count > 1) {
        while (q->next != NULL) {
            if (q->road.linkID > q->next->road.linkID) {

                q->road.linkID = (q->road.linkID) ^ (q->next->road.linkID);
                q->next->road.linkID = (q->road.linkID) ^ (q->next->road.linkID);
                q->road.linkID = (q->road.linkID) ^ (q->next->road.linkID);

                /*temp = q->road.linkID;
                q->road.linkID = q->next->road.linkID;
                q->next->road.linkID = temp;*/
            }
            q = q->next;
        }
        count--;
        q = p->next;
    }
    //PrintList(p);
    return p;
}
/************************************************************************
*                            选择排序
*       遍历链表，每次找出一个最小的节点，
*       将其值与未排序节点的首个节点交换，这里需要一个指针标记值最小的节点。
*************************************************************************/
Link_t selectSort(Link_t Lhead)          //选择排序
{
    printf("\t\t\tSelect Sorting Begining!!!\n");
    Link_t pfirst;
    Link_t ptail;
    Link_t pminBefore;
    Link_t pmin;
    Link_t p;

    pfirst = NULL;
    while (Lhead->next != NULL)
    {
        for (p = Lhead->next , pmin = Lhead->next; p->next != NULL; p = p->next)
        {
            if (((p->next)->road).linkID < ((pmin->next)->road).linkID)
            {
                pminBefore = p;
                pmin = p->next;
            }
        }

        if (pfirst == NULL)
        {
            pfirst = pmin;
            ptail  = pmin;
        }
        else
        {
            ptail->next = pmin;
            ptail = pmin;
        }
        if (pmin == Lhead->next)
        {
            Lhead->next = Lhead->next->next;
        }
        else
        {
            pminBefore->next = pmin->next;
        }
    }

    if (pfirst != NULL)
    {
        ptail->next = NULL;
    }
    Lhead->next = pfirst;
    printf("\t\t\tSelect Sorting Finished!!!\n");
    return Lhead;
}
Link_t selectSort1(Link_t L)
{
    printf("\t\t\tSelect Sorting Begining!!!\n");
    Link_t first;     /*排列后有序链的表头指针*/
    Link_t tail;      /*排列后有序链的表尾指针*/
    Link_t p_min;     /*保留键值更小的节点的前驱节点的指针*/
    Link_t min;       /*存储最小节点*/
    Link_t p;         /*当前比较的节点*/

    first = NULL;
    while (L->next != NULL) /*在链表中找键值最小的节点。*/
    {
        /*注意：这里for语句就是体现选择排序思想的地方*/
        for (p  = L->next,min = L->next; p->next != NULL; p = p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/
        {
            if (p->next->road.linkID < min->road.linkID) /*找到一个比当前min小的节点。*/
            {
                p_min = p; /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/
                min = p->next; /*保存键值更小的节点。*/
            }
        }

        /*上面for语句结束后，就要做两件事；
            一是把它放入有序链表中；
            二是根据相应的条件判断，安排它离开原来的链表。*/

        /*第一件事*/
        if (first == NULL) /*如果有序链表目前还是一个空链表*/
        {
            first = min; /*第一次找到键值最小的节点。*/
            tail = min; /*注意：尾指针让它指向最后的一个节点。*/
        }
        else /*有序链表中已经有节点*/
        {
            tail->next = min; /*把刚找到的最小节点放到最后，即让尾指针的next指向它。*/
            tail = min; /*尾指针也要指向它。*/
        }
        /*第二件事*/
        if (min == L) /*如果找到的最小节点就是第一个节点*/
        {
            //printf("表头%d已经是最小，当前结点后移。\n", min->data);
            L->next = L->next->next; /*显然让head指向原head->next,即第二个节点，就OK*/
        }
        else /*如果不是第一个节点*/
        {
            p_min->next = min->next; /*前次最小节点的next指向当前min的next,这样就让min离开了原链表。*/
        }
    }
    if (first != NULL) /*循环结束得到有序链表first*/
    {
        tail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL*/
    }
    L->next = first;
    printf("\t\t\tSelect Sorting Finished!!!\n");
    return L;
}
/************************************************************************
 * Select Value Error
 ***********************************************************************/
Link_t selectSort2( Link_t L )
{
    Link_t p, q, small;

    unsigned long  temp;

    for( p = L->next; p->next != NULL; p = p->next )    /*每次循环都找出一个最小值，将最小值交换到第一位，然后将指针向后移动一位*/
    {
        small = p;
        for( q = p->next; q; q = q->next )    /*由前向后遍历，找出最小的节点*/
        {
            if( q->road.linkID < small->road.linkID )
            small = q;
        }
        if( small != p )
        {
            temp = p->road.linkID;
            p->road.linkID = small->road.linkID;
            small->road.linkID = temp;
        }
    }
    //PrintList(L);
    return L;
}
/************************************************************************
*                             插入排序
*  需要用两个指针对链表进行遍历，一个指针用于标记待插入的节点（外循环），
*  另一个指针用于寻找插入位置（内循环）。
*  因为需要进行节点的删除与插入，因此对用于遍历的两个指针，还需要再添加两个前驱指针。
*************************************************************************/
Link_t insertSort(Link_t Lhead)
{
    printf("\t\t\tInsert Sorting Begining!!!\n");
    Link_t first;
    Link_t t;
    Link_t p;
    Link_t q;

    first = Lhead->next->next;
    Lhead->next->next = NULL;

    while (first != NULL)
    {

        for (t = first, q = Lhead->next; ((q != NULL) && ((q->road).linkID < (t->road).linkID)); p = q, q = q->next);

        first = first->next;

        if (q == Lhead->next)
        {
            Lhead->next = t;
        }
        else
        {
            p->next = t;
        }
        t->next = q;
    }
    printf("\t\t\tInsert Sorting Finished!!!\n");
    return Lhead;
}
/************************************************************************
 * Insert Value Error
 ***********************************************************************/
Link_t insertSort1(Link_t head)
{
    printf("\t\t\tInsert Sorting Begining!!!\n");
    Link_t first; /*为原链表剩下用于直接插入排序的节点头指针*/
    Link_t t; /*临时指针变量：插入节点*/
    Link_t p; /*临时指针变量*/
    Link_t q; /*临时指针变量*/

    first = head->next->next; /*原链表剩下用于直接插入排序的节点链表*/
    head->next->next = NULL; /*只含有一个节点的链表的有序链表*/

    while (first != NULL) /*遍历剩下无序的链表*/
    {   /*无序节点在有序链表中找插入的位置*/
        for (t = first, q = head->next; ((q != NULL) && (q->road.linkID < t->road.linkID)); p = q, q = q->next);
        first = first->next; /*无序链表中的节点离开，以便它插入到有序链表中。*/
        if (q == head) /*插在第一个节点之前*/
        {
            head = t;
        }
        else /*p是q的前驱*/
        {
            p->next = t;
        }
        t->next = q; /*完成插入动作*/
        //first = first->next;
    }
    printf("\t\t\tInsert Sorting Finished!!!\n");
    return head;
}
Link_t insertSort2( Link_t L )
{
    Link_t p1, p2, temp, prep1, prep2;
    if( L->next->next == NULL )
    {
        return L;
    }
    for( p1 = L->next->next, prep1 = L->next; p1 != NULL; p1 = p1->next, prep1 = prep1->next )
    {
        temp = p1;    /*保存待插入节点*/
        for( p2 = L->next, prep2 = L; p2 != p1; p2 = p2->next, prep2 = prep2->next )
        {
            if( p2->road.linkID > p1->road.linkID )
            {
                p1 = p1->next;
                prep1->next = temp->next;    /*删除待插入节点*/
                prep2->next = temp;              /*将其插入对应位置*/
                temp->next = p2;
                break;
            }
        }
    }
    //PrintList(L);
    return L;
}
/*************************************************************************
 *      快速排序(Rubbish Data)
 *************************************************************************/
Link_t quickSort( Link_t head, Link_t tail )
{
    if ( head->next == tail || head->next->next == tail )
        return NULL;

    Link_t mid = head->next;
    Link_t p = head;
    Link_t q = mid;
    int pivot = mid->road.linkID;
    Link_t t = mid->next;

    while ( t != tail )
    {
        if ( t->road.linkID < pivot )
            p = p->next = t;
        else
            q = q->next = t;
        t = t->next;
    }
    p->next = mid;
    q->next = tail;

    quickSort( head, mid );
    quickSort( mid, tail );

    return head;
}

/***********************************************************************
 *
 * Link_t p = NULL;
    Link_t pPrior = NULL;
    Link_t mid = head->next;
    Link_t midPrior = head;

    if(NULL != mid)
    {
    for(p = mid->next,pPrior = mid; NULL != p && p != tail ; p = p->next)
    {
          if(p->road.linkID < mid->road.linkID)
          {
          //将p结点插入base结点之前
               pPrior->next = p->next;
               p->next = midPrior->next;
               midPrior->next = p;

               p = pPrior;
           }
           else
           {
                pPrior = pPrior->next;
           }
       }
       if(NULL != head->next && head->next != tail)
       {
            quickSort(head,mid);
            quickSort(mid,tail);
       }
    }
 *************************************************************************/

/*************************************************************************
 *  LinkID查询
 *************************************************************************/
Link_t listSearchLinkID(Link_t head, unsigned long rLinkId)
{
    Link_t p,pointer = createList();
    Link_t q  = NULL;
    Link_t pTail = NULL;
    pTail = pointer;
    pointer->next = NULL;

    p = head;
    while(p != NULL)
    {
        if(p->road.linkID == rLinkId)
        {
            searchTime++;
            /*printf("listSearchLinkID->");
            printf("LinkId: %ld\t", p->road.linkID);
            printf("Brunch: %d\t", p->road.Brunch);
            printf("roadName: %s\n", p->road.roadName);*/
            q = createList();

            q->road.linkID = p->road.linkID;
            q->road.Brunch = p->road.Brunch;
            q->road.RoadNameFlag = p->road.RoadNameFlag;
            q->road.DispClass = p->road.DispClass;
            strcpy(q->road.roadName,p->road.roadName);

            q->next = pTail->next;
            pTail->next = q;
            pTail = q;
        }
        p = p->next;
    }
    free(q);
    printf("searchTime=%d\n",searchTime);
    if(searchTime < 5)
    {
        PrintList(pointer);
    }
    else
    {
        puts("Search data more than 5");
        listSaveFile(pointer);
    }
    searchTime = 0;
    return head;
}
/*************************************************************************
 *  Brunch查询
 *************************************************************************/
Link_t listSearchBrunch(Link_t head, int rBrunch)
{
    Link_t p,pointer = createList();
    Link_t q  = NULL;
    Link_t pTail = NULL;
    pTail = pointer;
    pointer->next = NULL;

    p = head;
    while(p != NULL)
    {
        if(p->road.Brunch == rBrunch)
        {
            searchTime++;
            /*printf("listSearchBrunch->");
            printf("LinkId: %ld\t", p->road.linkID);
            printf("Brunch: %d\t", p->road.Brunch);
            printf("roadName: %s\n", p->road.roadName);*/

            q = createList();

            q->road.linkID = p->road.linkID;
            q->road.Brunch = p->road.Brunch;
            q->road.RoadNameFlag = p->road.RoadNameFlag;
            q->road.DispClass = p->road.DispClass;
            strcpy(q->road.roadName,p->road.roadName);

            q->next = pTail->next;
            pTail->next = q;
            pTail = q;

            //q->next = createList();
            //q = q->next;
        }
        p = p->next;
    }
    printf("searchTime=%d\n",searchTime);
    if(searchTime < 5)
    {
        PrintList(pointer);
    }
    else
    {
        puts("Search data more than 5");
        listSaveFile(pointer);
    }
    searchTime = 0;
    return pointer;
}
/*************************************************************************
 *  RoadName查询
 *************************************************************************/

Link_t listSearchRoadName(Link_t head, char *rRoadName)
{
    Link_t p,pointer = createList();
    Link_t q  = NULL;
    Link_t pTail = NULL;
    pTail = pointer;
    pointer->next = NULL;

    p = head;
    while(p != NULL)
    {
        if( !strcmp(p->road.roadName,rRoadName) )
        {
            searchTime++;
            /*printf("listSearchRoadName->");
            printf("LinkId: %hd\t", p->road.linkID);
            printf("Brunch: %d\t", p->road.Brunch);
            printf("roadName: %s\n", p->road.roadName);*/

            q = createList();

            q->road.linkID = p->road.linkID;
            q->road.Brunch = p->road.Brunch;
            q->road.RoadNameFlag = p->road.RoadNameFlag;
            q->road.DispClass = p->road.DispClass;
            strcpy(q->road.roadName,p->road.roadName);

            q->next = pTail->next;
            pTail->next = q;
            pTail = q;
        }
        p = p->next;
    }
    printf("searchTime=%d\n",searchTime);
    if(searchTime < 5)
    {
        PrintList(pointer);
    }
    else
    {
        puts("Search data more than 5");
        listSaveFile(pointer);
    }
    searchTime = 0;
    return head;
}
/*************************************************************************
*    链表按顺序插入
**************************************************************************/

Link_t listOrderInsert(Link_t L, Link_t node)
{
    Link_t p, q;
    p = L;
    while (p -> next != NULL && p->next->road.linkID < node->road.linkID)
    {
        p = p->next;
    }

    q = createList();
    q->road.linkID = node->road.linkID;
    q->road.DispClass = node->road.DispClass;
    q->road.Brunch = node->road.Brunch;
    q->road.RoadNameFlag = node->road.RoadNameFlag;
    strcpy(q->road.roadName,node->road.roadName);

    /*printf("#linkID=%ld;Brunch=%d;DispClass=%d;RoadNameFlag=%d;roadName=%s;#\n\n",
                   q->road.linkID,q->road.Brunch,q->road.DispClass,
                   q->road.RoadNameFlag,q->road.roadName);*/

    q->next = p->next;
    p->next = q;
    free(q);
    puts("Insert Data Successful!!");
    return L;
}

/*************************************************************************
*    链表插入,在链表的第pos个位置插入元素
**************************************************************************/
Link_t listPositionInsert(Link_t L,int pos,Link_t node)
{
    Link_t pre;                      //pre为前驱结点
    Link_t q;                                //插入的结点为q
    pre = L;
    while (pos-- > 1)
    {
        pre = pre->next;                 //查找第i个位置的前驱结点
    }
    q = createList();

    q->road.linkID = node->road.linkID;
    q->road.DispClass = node->road.DispClass;
    q->road.Brunch = node->road.Brunch;
    q->road.RoadNameFlag = node->road.RoadNameFlag;
    strcpy(q->road.roadName,node->road.roadName);

    q->next = pre->next;
    pre->next = q;

    return L;
}
/*************************************************************************
*          链表删除等于特定值的节点
**************************************************************************/
Link_t listDelete(Link_t L, int LinkID)
{
    Link_t p, q;
    if(NULL == L)
    {
        return NULL;
    }
    p = L;
    q = p->next;

    if (p->road.linkID == LinkID)
    {
        L = q;
        free(p);
        return L;
    }

    while (q != NULL)
    {
        if (q->road.linkID == LinkID)
        {
            p->next = q->next;
            free(q);
            q = NULL;
            break;
        }
        p = p->next;
        q = q->next;
    }
    if(NULL == q)
    {
        return L;
    }
    puts("Delete Data Successful!!");
    return L;
}
