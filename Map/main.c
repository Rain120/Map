#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "menu.h"
#include "Macro.h"
#include "tableHeader.h"
#include "listHeader.h"

extern int tableLength = 0;

int main(void)
{
    clock_t start, finish;
    double  duration = 0.0;
    /*Link_t p;
    p = createList();
    mainMenuChoose(p);*/

    table_t *array = (table_t *)malloc( TABLELENGTH * sizeof(table_t) );
    tableReadFile( array );

    start = clock();
    //tableSaveFile( array );
    //Bublesort( array,tableLength - 1 );
    //SelectSort( array,tableLength );
    //InsertSort( array, tableLength );
    //QuickSort(array,0,tableLength);
    //MergeSort(array,0,tableLength);
    //ShellSort( array, tableLength );
    HeapSort( array, tableLength );
    tableSaveFile( array );
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Execute times:%.8f seconds\n", duration);

    /*clock_t start, finish;
    double  duration = 0.0;
    Link_t p,*q,*r;
    p = createList();
    q = p;
    start = clock();
    *q = readFile(p);
    *r = listSearchBrunch(q,64);
    //saveFile(r);
    //q = bubbleSort(q);
    //q = selectSort(q);
    //q = insertSort(q);
    //q = quickSort(q,NULL);
    //saveFile(q);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Execute times:%.8f seconds\n", duration);*/
    //listSearchLinkID(q,10);
    //listSearchBrunch(q,64);
    //saveFile(q);
    //listSearchRoadName(q,ch);
    /*p->road.linkID = 65555;
    p->road.DispClass = 22;
    p->road.Brunch = 66;
    p->road.RoadNameFlag = 111;
    strcpy(p->road.roadName,"K1");
    r = listPositionInsert(q,1,p);
    //r = listOrderInsert(q,p);
    printf("Insert:\n");
    saveFile(r);
    PrintList(r);
    r = listDelete(q,65555);
    printf("Delete:\n");
    PrintList(r);*/
    /*saveFile(q);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Execute times:%.8f seconds\n", duration);*/

    return 0;
}

