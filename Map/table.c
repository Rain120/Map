#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableHeader.h"
#include "Macro.h"

/*************************************************************************
*    Func:      printTable(Table)
*    Para:      table_t *p, int n
*    retrurn:   void
**************************************************************************/
void printTable( table_t *p,int n )
{
    int i = 0;
    while(i < n)
    {
        printf("LinkID=%ld  ",p[i].road_t.linkID);
        printf("RoadNameFlag=%d  ",p[i].road_t.RoadNameFlag);
        printf("Brunch=%d  ",p[i].road_t.Brunch);
        printf("DispClass=%d  ",p[i].road_t.DispClass);
        printf("RoadName=%s\n",p[i].road_t.roadName);
        i++;
    }
}
/*************************************************************************
 *                      Searching Function
 * ***********************************************************************/

/*************************************************************************
*    Func:      Bublesort(Table)
*    Para:      table_t *p, int n
*    retrurn:   void
**************************************************************************/
void Bublesort( table_t *p,int n )
{
    puts("\t\t\tBublesort Begining");
    int i,j,k;
    for( j = 0;j < n;j++ )   /* 气泡法要排序n次*/
    {
        for( i = 0;i < n - j;i++ )  /* 值比较大的元素沉下去后，只把剩下的元素中的最大值再沉下去就可以啦 */
        {
             if( p[i].road_t.linkID > p[i + 1].road_t.linkID )  /* 把值比较大的元素沉到底 */
             {
                 /*p[i].road_t.linkID = p[i].road_t.linkID ^ p[i + 1].road_t.linkID;
                 p[i + 1].road_t.linkID = p[i].road_t.linkID ^ p[i + 1].road_t.linkID;
                 p[i].road_t.linkID = p[i].road_t.linkID ^ p[i + 1].road_t.linkID;*/

                 k = p[i].road_t.linkID;
                 p[i].road_t.linkID = p[i + 1].road_t.linkID;
                 p[i + 1].road_t.linkID = k;
             }
        }
    }
    puts("\t\t\tBublesort Finished");
}

/*************************************************************************
*    Func:      SelectSort(Table)
*    Para:      table_t *p, int n
*    retrurn:   void(Error)
**************************************************************************/
void SelectSort(table_t *p,int n)
{
    puts("\t\t\tSelectSort Begining");
    int i = 0;
    int j = 0;
    int min_index;
    //进行N-1轮选择
    for(i = 0; i < n - 1; i++)
    {
        min_index = i;
        //找出第i小的数所在的位置
        for(j = i + 1; j < n; j++)
        {
            if(p[j].road_t.linkID < p[min_index].road_t.linkID)
            {
                min_index = j;
            }
        }

        //将第i小的数，放在第i个位置；如果刚好，就不用交换
        if( i != min_index)
        {
            p[i].road_t.linkID = p[i].road_t.linkID ^ p[min_index].road_t.linkID;
            p[min_index].road_t.linkID = p[i].road_t.linkID ^ p[min_index].road_t.linkID;;
            p[i].road_t.linkID = p[i].road_t.linkID ^ p[min_index].road_t.linkID;
        }
    }
    puts("\t\t\tSelectSort Finished");
}
/*************************************************************************
*    Func:      InsertSort(Table)
*    Para:      table_t *p, int n
*    retrurn:   void(Error)
**************************************************************************/
void InsertSort(table_t *p, int n)
{
    puts("\t\t\tInsertSort Begining");
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < n ; i++)
    {
        temp = p[i].road_t.linkID;
        j = i - 1;
        while (j >= 0 && p[j].road_t.linkID > temp)
        {
            p[j + 1].road_t.linkID = p[j].road_t.linkID;
            j--;
        }
        p[j + 1].road_t.linkID = temp;
    }
    puts("\t\t\tInsertSort Finished");
}
/*************************************************************************
*    Func:      partition(Table)
*    Para:      table_t *p,int low,int high
*    retrurn:   int
**************************************************************************/
int Partition(table_t *p,int low,int high)
{
    int key = 0;
    key = p[low].road_t.linkID;
    while(low < high)
    {
        while(low < high && p[high].road_t.linkID >= key)
        {
            high--;
        }
        if(low < high)
        {
            p[low++].road_t.linkID = p[high].road_t.linkID;
        }
        while(low < high && p[low].road_t.linkID <= key)
        {
            low++;
        }
        if(low < high)
        {
            p[high--].road_t.linkID = p[low].road_t.linkID;
        }
    }
    p[low].road_t.linkID = key;
    return low;
}

/*************************************************************************
*    Func:      QuickSort(Table)
*    Para:      table_t *p,int low,int high
*    retrurn:   int
**************************************************************************/
void QuickSort(table_t *p,int low,int high)
{
    int pivotloc = 0;
    if(low < high)
    {
        pivotloc = Partition(p,low,high);
        QuickSort(p,low,pivotloc - 1);
        QuickSort(p,pivotloc + 1,high);
    }
}
/*************************************************************************
*    Func:      MergeSort(Table)
*    Para:      table_t *p, int low, int mid, int high
*    retrurn:   void
**************************************************************************/
void Merge(table_t *p, int low, int mid, int high)
{
    int i, k;
    table_t *tmp = (table_t *)malloc( (high - low + 1) * sizeof(table_t) );
    //申请空间，使其大小为两个
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;

    for(k = 0; left_low <= left_high && right_low <= right_high; k++)
    {  // 比较两个指针所指向的元素
        if(p[left_low].road_t.linkID <= p[right_low].road_t.linkID)
        {
            tmp[k].road_t.linkID = p[left_low++].road_t.linkID;
        }
        else
        {
            tmp[k].road_t.linkID = p[right_low++].road_t.linkID;
        }
    }

    if(left_low <= left_high)
    {  //若第一个序列有剩余，直接复制出来粘到合并序列尾
        for(i = left_low;i <= left_high;i++)
        {
            tmp[k++].road_t.linkID = p[i].road_t.linkID;
        }
    }

    if(right_low <= right_high)
    {//若第二个序列有剩余，直接复制出来粘到合并序列尾
        for(i = right_low; i <= right_high; i++)
        {
            tmp[k++].road_t.linkID = p[i].road_t.linkID;
        }
    }

    for(i = 0; i < high - low + 1; i++)
        p[low + i].road_t.linkID = tmp[i].road_t.linkID;
    free(tmp);
    return;
}
/*************************************************************************
*    Func:      MergeSort(Table)
*    Para:      table_t *p, unsigned int first, unsigned int last
*    retrurn:   void
**************************************************************************/
void MergeSort(table_t *p, int first, int last)
{
    int mid = 0;
    if(first < last)
    {
        mid = ( first + last ) / 2; /* 注意防止溢出 */
        MergeSort( p, first, mid );
        MergeSort( p, mid+1,last );
        Merge( p,first,mid,last );
    }
    return;
}
/*************************************************************************
*    Func:      ShellSort(Table)
*    Para:      table_t *p, int n
*    retrurn:   void
**************************************************************************/
void ShellSort(table_t *p, int n)
{
    puts("\t\t\tShellSort Begining");
     int d, i, j, temp;
     for(d = n / 2;d >= 1;d = d / 2)
     {
        for(i = d; i < n;i++)
        {
            temp = p[i].road_t.linkID;
            for(j = i - d;(j >= 0) && ( p[j].road_t.linkID > temp );j = j - d)
            {
                p[j + d].road_t.linkID = p[j].road_t.linkID;
            }
            p[j + d].road_t.linkID = temp;
       }
    }

     puts("\t\t\tShellSort Finished");
}

/*************************************************************************
*    Construct: heap
*    Func:      heapAdjust(Table)
*    Para:      table_t *p, int i,int n
*    retrurn:   void
**************************************************************************/
void HeapAdjust(table_t *p, int i, int n)
{
    int child, temp;

    for (temp = p[i].road_t.linkID; 2 * i + 1 < n; i = child)
    {
        child = 2 * i + 1;
        //取得較大子結點索引
        if (child < n -1 && p[child].road_t.linkID < p[child + 1].road_t.linkID)
        {
            child++;
        }
        //保證父結點大於等於子結點
        if ( temp < p[child].road_t.linkID )
        {
            p[i].road_t.linkID = p[i].road_t.linkID ^ p[child].road_t.linkID;
            p[child].road_t.linkID = p[i].road_t.linkID ^ p[child].road_t.linkID;
            p[i].road_t.linkID = p[i].road_t.linkID ^ p[child].road_t.linkID;
        }
        else
        {
            break;
        }
    }
}
/*************************************************************************
*    Func:      heapAdjust(Table)
*    Para:      table_t *p,int n
*    retrurn:   void
**************************************************************************/
void HeapSort(table_t *p,int n)
{
    int i = 0;
    int j = 0;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        HeapAdjust(p, i, n);
    }
    for (i = n - 1; i > 0; i--)
    {
        p[i].road_t.linkID = p[i].road_t.linkID ^ p[0].road_t.linkID;
        p[0].road_t.linkID = p[i].road_t.linkID ^ p[0].road_t.linkID;
        p[i].road_t.linkID = p[i].road_t.linkID ^ p[0].road_t.linkID;
        HeapAdjust(p, 0, i);
    }
}

/*************************************************************************
 *                      Searching Function
 * ***********************************************************************/

/*************************************************************************
*    Func:      tableSearchLinkID(Table)
*    Para:      table_t *p,int len
*    retrurn:   void
**************************************************************************/
void tableSearchLinkID( table_t *p,int len )
{
    unsigned long tLinkID = 0;
    int i = 0;
    int j = 0;
    int searchTime_t = 0;
    table_t *q = (table_t *)malloc( TABLELENGTH * sizeof(table_t) );
    printf("Please input the LinkID you want to search:");
    scanf("%ld",&tLinkID);
    puts("\t\t\tSearching Begining!!!");
    while( i < len )
    {
        if ( p[i].road_t.linkID == tLinkID )
        {
            q[j].road_t.linkID = p[i].road_t.linkID;
            q[j].road_t.Brunch = p[i].road_t.Brunch;
            q[j].road_t.RoadNameFlag = p[i].road_t.RoadNameFlag;
            q[j].road_t.DispClass = p[i].road_t.DispClass;
            strcpy(q[j].road_t.roadName,p[i].road_t.roadName);
            j++;
            searchTime_t++;
        }
        i++;
    }
    if ( 0 == searchTime_t  )
    {
        puts("The data has 0 in the file!!!");
    }
    else if  ( searchTime_t < 5 )
    {
        puts("The data has saved in the file!!!");
        printTable( q,searchTime_t );
    }
    else
    {
        puts("Search data more than 5,it has saved in the file!!!");
        tableSaveFile(q, searchTime_t);
    }
    puts("\t\t\tSearching Finishing!!!");
    printf("Searching times:%d\n",searchTime_t);
    searchTime_t = 0;
}

/*************************************************************************
*    Func:      tableSearchBrunch(Table)
*    Para:      table_t *p,int len
*    retrurn:   void
**************************************************************************/
void tableSearchBrunch( table_t *p,int len )
{
    int tBrunch = 0;
    int i = 0;
    int j = 0;
    int searchTime_t = 0;
    table_t *q = (table_t *)malloc( TABLELENGTH * sizeof(table_t) );
    printf("Please input the Brunch you want to search:");
    scanf("%d",&tBrunch);
    puts("\t\t\tSearching Begining!!!");
    while( i < len )
    {
        if ( p[i].road_t.Brunch == tBrunch )
        {
            q[j].road_t.linkID = p[i].road_t.linkID;
            q[j].road_t.Brunch = p[i].road_t.Brunch;
            q[j].road_t.RoadNameFlag = p[i].road_t.RoadNameFlag;
            q[j].road_t.DispClass = p[i].road_t.DispClass;
            strcpy(q[j].road_t.roadName,p[i].road_t.roadName);
            j++;
            searchTime_t++;
        }
        i++;
    }
    if ( 0 == searchTime_t  )
    {
        puts("The data has 0 in the file!!!");
    }
    else if  ( searchTime_t < 5 )
    {
        printTable( q, searchTime_t );
    }
    else
    {
        puts("Search data more than 5,it has saved in the file!!!");
        tableSaveFile(q, searchTime_t);
    }
    puts("\t\t\tSearching Finishing!!!");
    printf("Searching times:%d\n",searchTime_t);
    searchTime_t = 0;
}

/*************************************************************************
*    Func:      tableSearchRoadName(Table)
*    Para:      table_t *p,int len
*    retrurn:   void
**************************************************************************/
void tableSearchRoadName( table_t *p,int len )
{
    char tRoadName[MAXLENGTH];;
    int i = 0;
    int j = 0;
    int searchTime_t = 0;
    table_t *q = (table_t *)malloc( TABLELENGTH * sizeof(table_t) );
    printf("Please input the RoadName you want to search:");
    scanf("%s",tRoadName);
    puts("\t\t\tSearching Begining!!!");
    while( i < len )
    {
        if ( !strcmp(p[i].road_t.roadName,tRoadName) )
        {
            q[j].road_t.linkID = p[i].road_t.linkID;
            q[j].road_t.Brunch = p[i].road_t.Brunch;
            q[j].road_t.RoadNameFlag = p[i].road_t.RoadNameFlag;
            q[j].road_t.DispClass = p[i].road_t.DispClass;
            strcpy(q[j].road_t.roadName,p[i].road_t.roadName);
            j++;
            searchTime_t++;
        }
        i++;
    }
    if ( 0 == searchTime_t  )
    {
        puts("The data has 0 in the file!!!");
    }
    else if  ( searchTime_t < 5 )
    {
        printTable( q,searchTime_t );
    }
    else
    {
        puts("Search data more than 5,it has saved in the file!!!");
        tableSaveFile(q, searchTime_t);
    }
    puts("\t\t\tSearching Finishing!!!");
    printf("Searching times:%d\n",searchTime_t);
    searchTime_t = 0;
}
/*************************************************************************
 *                      Inserting Function
 * ***********************************************************************/

/*************************************************************************
*    Func:      JungleSameLinkID(Table)
*    Para:      table_t *p,unsigned long tLinkID,int len
*    retrurn:   int
**************************************************************************/
int JungleSameLinkID(table_t *p,unsigned long tLinkID,int len)
{
    int i = 0;
    while(i < len)
    {
        if (tLinkID == p[i].road_t.linkID)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/*************************************************************************
*    Func:      tableInsertOrder(Table)
*    Para:      table_t *p, table_t *q
*    retrurn:   int
**************************************************************************/
int tableOrderInsert( table_t *p,int len )
{
    unsigned long tLinkID = 0;
    int i = len;
    int j = 0;
    table_t *q = (table_t *)malloc( TABLELENGTH * sizeof(table_t) );

    printf("Please input the data you want to insert!!!\n");
    printf("LinkID:");
    scanf("%ld",&tLinkID);
    if( !JungleSameLinkID( p,tLinkID,len ) )
    {
        puts("The LinkID had in the data,Please input again:");
        printf("linkID: ");
        scanf("%ld",&tLinkID);
    }

    q[0].road_t.linkID = tLinkID;
    printf("Brunch:");
    scanf("%d",&q[0].road_t.Brunch);
    printf("DispClass:");
    scanf("%d",&q[0].road_t.DispClass);
    printf("RoadNameFlag:");
    scanf("%d",&q[0].road_t.RoadNameFlag);
    printf("roadName:");
    scanf("%s",q[0].road_t.roadName);

    if ( p[i].road_t.linkID > q[0].road_t.linkID )
    {
        p[i + 1].road_t.linkID = p[i].road_t.linkID;
        p[i + 1].road_t.Brunch = p[i].road_t.Brunch;
        p[i + 1].road_t.DispClass = p[i].road_t.DispClass;
        p[i + 1].road_t.RoadNameFlag = p[i].road_t.RoadNameFlag;
        strcpy( p[i + 1].road_t.roadName,p[i].road_t.roadName );

        i--;
    }

    p[i].road_t.linkID = q[0].road_t.linkID;
    p[i].road_t.Brunch = q[0].road_t.Brunch;
    p[i].road_t.DispClass = q[0].road_t.DispClass;
    p[i].road_t.RoadNameFlag = q[0].road_t.RoadNameFlag;
    strcpy(p[i].road_t.roadName,q[0].road_t.roadName);

    len++;
    return len;
}
/*************************************************************************
*    Func:      tablePositionInsert(Table)
*    Para:      table_t *p, int len
*    retrurn:   int
**************************************************************************/
int tablePositionInsert( table_t *p,int len )
{
    unsigned long tLinkID = 0;
    int pos = 0;
    int i = len;
    //char tRoadName[MAXLENGTH];
    table_t *q = (table_t *)malloc( TABLELENGTH * sizeof(table_t) );

    printf("Please input the data you want to insert!!!\n");
    printf("LinkID:");
    scanf("%ld",&tLinkID);
    if( !JungleSameLinkID( p,tLinkID,len ) )
    {
        puts("The LinkID had in the data,Please input again:");
        printf("linkID: ");
        scanf("%ld",&tLinkID);
    }

    q[0].road_t.linkID = tLinkID;
    printf("Brunch:");
    scanf("%d",&q[0].road_t.Brunch);
    printf("DispClass:");
    scanf("%d",&q[0].road_t.DispClass);
    printf("RoadNameFlag:");
    scanf("%d",&q[0].road_t.RoadNameFlag);
    printf("roadName:");
    scanf("%s",q[0].road_t.roadName);

    printf("Please input the position you want to insert:");
    scanf("%d",&pos);
    if( pos < 1 || pos > len + 1 )
    {
        puts("Error insert position!!!");
    }
    while ( i > pos )
    {
        p[i].road_t.linkID = p[i - 1].road_t.linkID;
        p[i].road_t.Brunch = p[i - 1].road_t.Brunch;
        p[i].road_t.DispClass = p[i - 1].road_t.DispClass;
        p[i].road_t.RoadNameFlag = p[i - 1].road_t.RoadNameFlag;
        strcpy( p[i].road_t.roadName,p[i - 1].road_t.roadName );

        i--;
    }

    p[i - 1].road_t.linkID = q[0].road_t.linkID;
    p[i - 1].road_t.Brunch = q[0].road_t.Brunch;
    p[i - 1].road_t.DispClass = q[0].road_t.DispClass;
    p[i - 1].road_t.RoadNameFlag = q[0].road_t.RoadNameFlag;
    strcpy(p[i - 1].road_t.roadName,q[0].road_t.roadName);

    len++;
    return len;
}
/*************************************************************************
 *                      Deleting Function
 * ***********************************************************************/

/*************************************************************************
*    Func:      tableDelete(Table)
*    Para:      table_t *p,int len
*    retrurn:   int
**************************************************************************/
int tableDelete( table_t *p,int len )
{
    int i = 0;
    int j = 0;
    unsigned long tLinkID = 0;
    printf("Please input the LinkID of data you want to delete:");
    scanf("%ld",&tLinkID);
    for( i = 0; i < len; i++ )
    {
        if( p[i].road_t.linkID == tLinkID )
        {
            for ( j = i;j < len;j++ )
            {
                p[j].road_t.linkID = p[j + 1].road_t.linkID;
                p[j].road_t.Brunch = p[j + 1].road_t.Brunch;
                p[j].road_t.DispClass = p[j + 1].road_t.DispClass;
                p[j].road_t.RoadNameFlag = p[j + 1].road_t.RoadNameFlag;
                strcpy( p[j].road_t.roadName,p[j + 1].road_t.roadName );
            }
        }
    }
    len--;
    return len;
}
