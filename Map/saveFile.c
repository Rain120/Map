#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "menu.h"
#include "Macro.h"
#include "tableHeader.h"
#include "listHeader.h"

int tableLength;
/*************************************************************************
*    Func:      tableSaveFile
*    Para:      link  link_t[](typedef struct link link_t[])
*    retrurn:   link
**************************************************************************/
void tableSaveFile( table_t *p )
{
    table_t *node;
    node = p;
    char fileName[FILEMAXLENGTH];
    int count = 0;

    /*printf("Please input the writing file saving path(etc:../Data/sourceLink.txt):");
    scanf("%s",fileName);
    FILE *pFileOut = fopen(fileName,"w");    //写入刚才读取的文件*/
    FILE *pFileOut = fopen("../Data/sourceLink1.txt","w");    //写入刚才读取的文件
    if(pFileOut == NULL)
    {
        printf("can not open the newgtal.txt file or there is no the file!\n");
        exit(0);
    }
    else
    {
        printf("Save Opening!\n");
    }
    printf("\n\t\t\tFile Saving....\n");
    while(count < tableLength)
    {
        fprintf(pFileOut,"%5d",count);
        fprintf(pFileOut,"#");
        fprintf(pFileOut,"LinkID=");
        fprintf(pFileOut,"%5ld;",node[count].road_t.linkID);
        fprintf(pFileOut,"RoadnameFlag=");
        fprintf(pFileOut,"%d;",node[count].road_t.RoadNameFlag);
        fprintf(pFileOut,"Brunch=");
        fprintf(pFileOut,"%3d;",node[count].road_t.Brunch);
        fprintf(pFileOut,"DispClass=");
        fprintf(pFileOut,"%3d;",node[count].road_t.DispClass);
        fprintf(pFileOut,"Roadname=");
        fprintf(pFileOut,"%s;",node[count].road_t.roadName);
        fprintf(pFileOut,"#");
        fprintf(pFileOut,"\n");

        /*printf("%d:#linkID=%ld;Brunch=%d;DispClass=%d;RoadNameFlag=%d;roadName=%s;#\n\n", count,
               node->road.linkID,node->road.Brunch,node->road.DispClass,
               node->road.RoadNameFlag,node->road.roadName);*/
        count++;
    }
    printf("Saving Count = %d\n",count);
    fclose(pFileOut);
    printf("\t\t\tFile Saving Successful!!!\n");
}
/*************************************************************************
*    Func:      listSaveFile
*    Para:      Link_t p  (typedef struct link* Link_t)
*    retrurn:   Link_t
**************************************************************************/
Link_t listSaveFile(Link_t p)
{
    char fileName[FILEMAXLENGTH];
    Link_t node = createList();
    int count = 0;

    printf("Please input the writing file saving path(etc:../Data/sourceLink.txt):");
    scanf("%s",fileName);
    FILE *pFileOut = fopen(fileName,"w");    //写入刚才读取的文件
    //FILE *pFileOut = fopen("../Data/sourceLink.txt","w");    //写入刚才读取的文件
    if(pFileOut == NULL)
    {
        printf("can not open the newgtal.txt file or there is no the file!\n");
        exit(0);
    }
    else
    {
        printf("Save Opening!\n");
    }
    printf("\n\t\t\tFile Saving....\n");
    node = p->next;
    while(NULL != node)
    {
        fprintf(pFileOut,"%5d",count);
        fprintf(pFileOut,"#");
        fprintf(pFileOut,"LinkID=");
        fprintf(pFileOut,"%5ld;",node->road.linkID);
        fprintf(pFileOut,"RoadnameFlag=");
        fprintf(pFileOut,"%d;",node->road.RoadNameFlag);
        fprintf(pFileOut,"Brunch=");
        fprintf(pFileOut,"%3d;",node->road.Brunch);
        fprintf(pFileOut,"DispClass=");
        fprintf(pFileOut,"%3d;",node->road.DispClass);
        fprintf(pFileOut,"Roadname=");
        fprintf(pFileOut,"%s;",node->road.roadName);
        fprintf(pFileOut,"#");
        fprintf(pFileOut,"\n");

        /*printf("%d:#linkID=%ld;Brunch=%d;DispClass=%d;RoadNameFlag=%d;roadName=%s;#\n\n", count,
               node->road.linkID,node->road.Brunch,node->road.DispClass,
               node->road.RoadNameFlag,node->road.roadName);*/

        node = node->next;
        count++;
    }
    printf("Saving Count = %d\n",count);
    fclose(pFileOut);
    printf("\t\t\tFile Saving Successful!!!\n");
    return node;
}
