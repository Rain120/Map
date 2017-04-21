#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableHeader.h"
#include "Macro.h"

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
        mid = (first+last) / 2; /* 注意防止溢出 */
        MergeSort(p, first, mid);
        MergeSort(p, mid+1,last);
        Merge(p,first,mid,last);
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

