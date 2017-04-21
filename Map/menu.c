#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listHeader.h"
#include "Macro.h"
#include "menu.h"

static int rFlag = 0;

void versionMenu(void)
{
    printf("\t/****************************************\n");
    printf("\t*                                      *\n");
    printf("\t*Electronic map information management *\n");
    printf("\t*                                      *\n");
    printf("\t*                    Designer ZC-Rainy *\n");
    printf("\t*                    2017-04-17        *\n");
    printf("\t****************************************/\n");
}
void insertMenu(void)
{
    printf("***********************insertMenu***********************\n");
    printf("\t\t1->Order Insert Data\n\n");
    printf("\t\t2->position Insert Data\n\n");
    printf("\t\t0->Back\n\n");
}
void insertMenuChoose(Link_t p)
{
    char ch[MAXLENGTH];
    Link_t *q = createList();
    q = p;
    int pos = 0;
    int choose;
    Link_t node;
    node = createList();
    insertMenu();
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
        insertMenu();
    }
}
void deleteMenu(void)
{
    printf("***********************deleteMenu***********************\n");
    printf("\t\t1->Delete Data\n\n");
    printf("\t\t0->Back\n\n");
}
void deleteMenuChoose(Link_t p)
{
    Link_t *q = createList();
    q = p;
    unsigned long rLinkID = 0;
    int choose;
    deleteMenu();
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
                break;
           case 0:
               listMenuChoose(q);
               break;
           default:
             printf("Error choose!!!\n");
       }
       listSaveFile(q);
       deleteMenu();
    }
}
void searchMenu(void)
{
    printf("***********************searchMenu***********************\n");
    printf("\t\t1->Search LinkID\n\n");
    printf("\t\t2->Search Brunch\n\n");
    printf("\t\t3->Search RoadName\n\n");
    printf("\t\t0->Back\n");
}
void searchMenuChoose(Link_t p)
{
    Link_t *q = createList();
    q = p;
    unsigned long rLinkID = 0;
    int rBrunch = 0;
    char ch[MAXLENGTH];
    int choose;
    searchMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                printf("Please Input the LinkID you want to search:");
                scanf("%ld",&rLinkID);
                listSearchLinkID(q,rLinkID);
                break;
            case 2:
                printf("Please Input the Brunch you want to search:");
                scanf("%d",&rBrunch);
                listSearchBrunch(q,rBrunch);
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
       searchMenu();
    }
}
void sortMenu(void)
{
    printf("***********************sortMenu***********************\n");
    printf("\t\t1->Bubble Sort\n\n");
    printf("\t\t2->Select Sort\n\n");
    printf("\t\t3->Insert Sort\n\n");
    printf("\t\t4->Quick Sort\n\n");
    printf("\t\t0->Back\n\n");
}

void sortMenuChoose(Link_t p)
{
    Link_t *q = createList();
    q = p;
    clock_t start, finish;
    double  duration = 0.0;
    int choose;
    sortMenu();
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
       sortMenu();
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
                    insertMenuChoose(q);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 3:
                if (rFlag == 1)
                {
                    deleteMenuChoose(q);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 4:
                if (rFlag == 1)
                {
                    searchMenuChoose(q);
                }
                else
                {
                    printf("Please perform readFile first\n");
                }
                break;
            case 5:
                if (rFlag == 1)
                {
                    sortMenuChoose(q);
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
void mainMenu(void)
{
    versionMenu();
    printf("***********************mainMenu***********************\n");
    printf("\t\t1->Sequence table(R & D)\n\n");
    printf("\t\t2->linked list\n\n");
    printf("\t\t3->Search tree(R & D)\n\n");
    printf("\t\t0->Exit\n\n");
}

void mainMenuChoose(Link_t p)
{
    int choose;
    mainMenu();
    while(1)
    {
        printf("Please choose:");
        scanf("%d",&choose);
        if(choose == 0)
        {
            puts("Program Closing!!");
            break;
        }
        switch(choose)
        {
           case 1:
              //tableMenu();
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

