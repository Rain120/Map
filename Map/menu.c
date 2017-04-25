#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableHeader.h"
#include "listHeader.h"
#include "Macro.h"
#include "menu.h"

/* *******************************
 * Define Or Global Paraments
 * *******************************/
static int rFlag = 0;
extern int tableLength = 0;

void versionMenu(void)
{
    printf("\t\t/****************************************\n");
    printf("\t\t*                                      *\n");
    printf("\t\t*Electronic Map Information Management *\n");
    printf("\t\t*                                      *\n");
    printf("\t\t*                    Designer ZC-Rainy *\n");
    printf("\t\t*                    2017-04-17        *\n");
    printf("\t\t****************************************/\n");
}

void mainMenu(void)
{
    versionMenu();
    printf("***********************mainMenu***********************\n");
    printf("\t\t1->Sequence table\n\n");
    printf("\t\t2->linked list\n\n");
    printf("\t\t3->Search tree(R & D)\n\n");
    printf("\t\t0->Exit\n\n");
}

void mainMenuChoose()
{
    Link_t p;
    p = createList();
    table_t *array = (table_t *)malloc( TABLELENGTH * sizeof(table_t) );
    int choose;
    mainMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        if(choose == 0)
        {
            puts("Program Closing!!");
            exit(0);
            //break;
        }
        switch(choose)
        {
           case 1:
              tableMenuChoose(array);
              break;
           case 2:
              listMenuChoose(p);
              break;
           case 3:
              //treeMenu();
              break;
           default:
             printf("Error choose!!!\n");
       }
    }
}
/* *********************************************************
 *                      TableMenu
 * *********************************************************/
void tableInsertMenu(void)
{
    printf("***********************tableInsertMenu***********************\n");
    printf("\t\t1->Order Insert Data\n\n");
    printf("\t\t2->position Insert Data\n\n");
    printf("\t\t0->Back\n\n");
}
void tableInsertMenuChoose(table_t *p)
{
    int choose = 0;
    tableInsertMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                tableLength = tableOrderInsert( p,tableLength );
                break;
            case 2:
                tableLength = tablePositionInsert( p,tableLength );
                break;
            case 0:
                tableMenuChoose(p);
                break;
           default:
             printf("Error choose!!!\n");
       }
        tableSaveFile( p,tableLength );
        tableInsertMenu();
    }
}
void tableDeleteMenu(void)
{
    printf("***********************listDeleteMenu***********************\n");
    printf("\t\t1->Delete Data\n\n");
    printf("\t\t0->Back\n\n");
}
void tableDeleteMenuChoose(table_t *p)
{
    int choose;
    tableDeleteMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        switch(choose)
        {
           case 1:
                tableLength = tableDelete( p,tableLength );
                tableSaveFile( p,tableLength );
                break;
           case 0:
               tableMenuChoose(p);
               break;
           default:
             printf("Error choose!!!\n");
       }
       tableDeleteMenu();
    }
}
void tableSearchMenu(void)
{
    printf("***********************tableSearchMenu***********************\n");
    printf("\t\t1->Search LinkID\n\n");
    printf("\t\t2->Search Brunch\n\n");
    printf("\t\t3->Search RoadName\n\n");
    printf("\t\t0->Back\n");
}
void tableSearchMenuChoose(table_t *p)
{
    int choose;
    tableSearchMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                tableSearchLinkID( p,tableLength );
                break;
            case 2:
                tableSearchBrunch( p,tableLength );
                break;
            case 3:
                tableSearchRoadName( p,tableLength );
                break;
            case 0:
                tableMenuChoose(p);
                break;
            default:
                printf("Error choose!!!\n");
       }
       tableSearchMenu();
    }
}
void tableSortMenu(void)
{
    printf("***********************tableSortMenu***********************\n");
    printf("\t\t1->Bubble Sort\n\n");
    printf("\t\t2->Select Sort\n\n");
    printf("\t\t3->Insert Sort\n\n");
    printf("\t\t4->Quick Sort\n\n");
    printf("\t\t5->Merge Sort\n\n");
    printf("\t\t6->Shell Sort\n\n");
    printf("\t\t7->Heap Sort\n\n");
    printf("\t\t0->Back\n\n");
}
void tableSortMenuChoose( table_t *p )
{
    //int tableLength;//temp
    clock_t start, finish;
    double  duration = 0.0;
    int choose;
    tableSortMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                start = clock();
                Bublesort( p,tableLength - 1 );
                finish = clock();
                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Execute times:%.8f seconds\n", duration);
                break;
            case 2:
                start = clock();
                SelectSort( p,tableLength - 1 );
                finish = clock();
                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Execute times:%.8f seconds\n", duration);
                break;
            case 3:
                start = clock();
                InsertSort( p,tableLength );
                finish = clock();
                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Execute times:%.8f seconds\n", duration);
                break;
            case 4:
                 printf("\t\t\tQuick Sorting Begining!!!\n");
                 start = clock();
                 QuickSort(p,0,tableLength);
                 finish = clock();
                 duration = (double)(finish - start) / CLOCKS_PER_SEC;
                 printf("\t\t\tQuick Sorting Finished!!!\n");
                 printf("Execute times:%.8f seconds\n", duration);
                 break;
            case 5:
                 printf("\t\t\tMerge Sorting Begining!!!\n");
                 start = clock();
                 MergeSort( p,0,tableLength - 1);
                 finish = clock();
                 duration = (double)(finish - start) / CLOCKS_PER_SEC;
                 printf("\t\t\tMerge Sorting Finished!!!\n");
                 printf("Execute times:%.8f seconds\n", duration);
                 break;
            case 6:
                 start = clock();
                 ShellSort( p, tableLength );
                 finish = clock();
                 duration = (double)(finish - start) / CLOCKS_PER_SEC;
                 printf("Execute times:%.8f seconds\n", duration);
                 break;
            case 7:
                 printf("\t\t\tQuick Sorting Begining!!!\n");
                 start = clock();
                 HeapSort( p, tableLength );
                 finish = clock();
                 duration = (double)(finish - start) / CLOCKS_PER_SEC;
                 printf("\t\t\tQuick Sorting Finished!!!\n");
                 printf("Execute times:%.8f seconds\n", duration);
                 break;
            case 0:
                tableMenuChoose(p);
                break;
           default:
             printf("Error choose!!!\n");
       }
       tableSaveFile(p, tableLength);
       tableSortMenu();
    }
}
void tableMenu(void)
{
    printf("***********************tableMenu***********************\n");
    printf("\t\t1->Read File\n\n");
    printf("\t\t2->Insert\n\n");
    printf("\t\t3->Delete\n\n");
    printf("\t\t4->Search\n\n");
    printf("\t\t5->Sort\n\n");
    printf("\t\t6->Update\n\n");
    printf("\t\t0->Back\n\n");
}
void tableMenuChoose(table_t *p)
{
    //int tableLength; //temp
    int choose;
    tableMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        if(0 == choose)
        {
            mainMenuChoose(p);
            break;
        }
        switch(choose)
        {
            case 1:
                tableReadFile(p);
                tableSaveFile(p, tableLength);
                rFlag = 1;
                break;
            case 2:
                if (rFlag == 1)
                {
                    tableInsertMenuChoose(p);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 3:
                if (rFlag == 1)
                {
                    tableDeleteMenuChoose(p);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 4:
                if (rFlag == 1)
                {
                    tableSearchMenuChoose(p);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 5:
                if (rFlag == 1)
                {
                    tableSortMenuChoose(p);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 6:
                if (rFlag == 1)
                {
                    tableUpdateInfo(p, tableLength);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            default:
                printf("Error choose!!!\n");
                break;
        }
        tableMenu();
    }
}

/* *********************************************************
 *                      ListMenu
 * *********************************************************/
void listInsertMenu(void)
{
    printf("***********************listInsertMenu***********************\n");
    printf("\t\t1->Order Insert Data\n\n");
    printf("\t\t2->position Insert Data\n\n");
    printf("\t\t0->Back\n\n");
}
void listInsertMenuChoose(Link_t p)
{
    char ch[MAXLENGTH];
    Link_t *q = createList();
    q = p;
    int pos = 0;
    int choose;
    Link_t node;
    node = createList();
    listInsertMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                printf("Please Input the data you want to insert:\n");
                printf("linkID: ");
                scanf("%ld",&node->road.linkID);
                printf("\nBrunch: ");
                scanf("%d",&node->road.Brunch);
                printf("\nDispClass: ");
                scanf("%d",&node->road.DispClass);
                printf("\nRoadNameFlag: ");
                scanf("%d",&node->road.RoadNameFlag);
                printf("\nroadName: ");
                scanf("%s",ch);
                strcpy(node->road.roadName,ch);
                q = listOrderInsert(q,node);
                break;
            case 2:
                printf("Please Input the data you want to insert:\n");
                printf("linkID: ");
                scanf("%ld",&node->road.linkID);
                printf("\nBrunch: ");
                scanf("%d",&node->road.Brunch);
                printf("\nDispClass: ");
                scanf("%d",&node->road.DispClass);
                printf("\nRoadNameFlag: ");
                scanf("%d",&node->road.RoadNameFlag);
                printf("\nroadName: ");
                scanf("%s",ch);
                strcpy(node->road.roadName,ch);
                printf("Please Input the position you want to insert:");
                scanf("%d",&pos);
                q = listPositionInsert(q,pos,node);
                break;
            case 0:
                listMenuChoose(q);
                break;
           default:
             printf("Error choose!!!\n");
       }
        listSaveFile(q);
        listInsertMenu();
    }
}
void listDeleteMenu(void)
{
    printf("***********************listDeleteMenu***********************\n");
    printf("\t\t1->Delete Data\n\n");
    printf("\t\t0->Back\n\n");
}
void listDeleteMenuChoose(Link_t p)
{
    Link_t *q = createList();
    q = p;
    unsigned long rLinkID = 0;
    int choose;
    listDeleteMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        switch(choose)
        {
           case 1:
                printf("Please Input the LinkID you want to delete:");
                scanf("%ld",&rLinkID);
                q = listDelete(q,rLinkID);
                listSaveFile(q);
                break;
           case 0:
               listMenuChoose(q);
               break;
           default:
             printf("Error choose!!!\n");
       }
       listDeleteMenu();
    }
}
void listSearchMenu(void)
{
    printf("***********************listSearchMenu***********************\n");
    printf("\t\t1->Search LinkID\n\n");
    printf("\t\t2->Search Brunch\n\n");
    printf("\t\t3->Search RoadName\n\n");
    printf("\t\t0->Back\n");
}
void listSearchMenuChoose(Link_t p)
{
    Link_t *q = createList();
    q = p;
    unsigned long lLinkID = 0;
    int lBrunch = 0;
    char ch[MAXLENGTH];
    int choose;
    listSearchMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                printf("Please Input the LinkID you want to search:");
                scanf("%ld",&lLinkID);
                listSearchLinkID(q,lLinkID);
                break;
            case 2:
                printf("Please Input the Brunch you want to search:");
                scanf("%d",&lBrunch);
                listSearchBrunch(q,lBrunch);
                break;
            case 3:
                printf("Please Input the roadName you want to search:");
                scanf("%s",ch);
                listSearchRoadName(q,ch);
                break;
            case 0:
                listMenuChoose(p);
                break;
            default:
                printf("Error choose!!!\n");
       }
       listSearchMenu();
    }
}
void listSortMenu(void)
{
    printf("***********************listSortMenu***********************\n");
    printf("\t\t1->Bubble Sort\n\n");
    printf("\t\t2->Select Sort\n\n");
    printf("\t\t3->Insert Sort\n\n");
    printf("\t\t4->Quick Sort\n\n");
    printf("\t\t0->Back\n\n");
}
void listSortMenuChoose(Link_t p)
{
    Link_t *q = createList();
    q = p;
    clock_t start, finish;
    double  duration = 0.0;
    int choose;
    listSortMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        switch(choose)
        {
           case 1:
                start = clock();
                q = bubbleSort(q);
                finish = clock();
                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Execute times:%.8f seconds\n", duration);
                break;
           case 2:
                start = clock();
                q = selectSort(q);
                finish = clock();
                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Execute times:%.8f seconds\n", duration);
                break;
           case 3:
                start = clock();
                q = insertSort(q);
                finish = clock();
                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("Execute times:%.8f seconds\n", duration);
                break;
            case 4:
                 printf("\t\t\tQuick Sorting Begining!!!\n");
                 start = clock();
                 quickSort(q,NULL);
                 finish = clock();
                 duration = (double)(finish - start) / CLOCKS_PER_SEC;
                 printf("\t\t\tQuick Sorting Finished!!!\n");
                 printf("Execute times:%.8f seconds\n", duration);
                 break;
            case 0:
                listMenuChoose(q);
                break;
           default:
             printf("Error choose!!!\n");
       }
       listSaveFile(q);
       listSortMenu();
    }
}

void listMenu(void)
{
    printf("***********************listMenu***********************\n");
    printf("\t\t1->Read File\n\n");
    printf("\t\t2->Insert\n\n");
    printf("\t\t3->Delete\n\n");
    printf("\t\t4->Search\n\n");
    printf("\t\t5->Sort\n\n");
    printf("\t\t6->Update\n\n");
    printf("\t\t0->Back\n\n");
}
void listMenuChoose(Link_t p)
{
    Link_t *q;
    q = p;
    int choose;
    listMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        if(0 == choose)
        {
            mainMenuChoose(q);
            break;
        }
        switch(choose)
        {
            case 1:
                *q = listReadFile(p);
                listSaveFile(q);
                rFlag = 1;
                break;
            case 2:
                if (rFlag == 1)
                {
                    listInsertMenuChoose(q);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 3:
                if (rFlag == 1)
                {
                    listDeleteMenuChoose(q);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 4:
                if (rFlag == 1)
                {
                    listSearchMenuChoose(q);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 5:
                if (rFlag == 1)
                {
                    listSortMenuChoose(q);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 6:
                if (rFlag == 1)
                {
                    listUpdateInfo(q);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            default:
                printf("Error choose!!!\n");
                break;
        }
        listMenu();
    }
}

