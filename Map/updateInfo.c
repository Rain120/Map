#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include "menu.h"
#include "Macro.h"
#include "tableHeader.h"
#include "listHeader.h"

void tableUpdateInfo(table_t *p,int len)
{
    table_t *node;
    node = p;
    char fileName[FILEMAXLENGTH];
    char fileNameHeader[FILEMAXLENGTH] = "../Data/";
    char fileNameFeet[FILEMAXLENGTH];
    int count = 0;
    unsigned short recordSizeBuf;
    unsigned long linkIDBuf;
    unsigned short roadSizeBuf;
    unsigned long roadInfoBuf;
    char roadNameBuf[MAXLENGTH] = "";

    strcpy(fileName,fileNameHeader);
    printf("Please input the update file saving path(etc:GTBL_New.dat):");
    scanf("%s",fileNameFeet);
    strcat(fileName,fileNameFeet);
    FILE *pFileIn = fopen(fileName,"wb");    //写入刚才读取的文件
    //FILE *pFileIn = fopen("../Data/GTBL_New_t.dat","wb");    //写入刚才读取的文件
    if(pFileIn == NULL)
    {
        printf("can not open the newgtal.txt file or there is no the file!\n");
        exit(0);
    }
    else
    {
        printf("Update Save Opening!\n");
    }
    printf("\n\t\t\tUpdate File Saving....\n");
    while(count < len)
    {

        if (node[count].road_t.recordSize - 12 != 0)
        {
            strcpy(roadNameBuf,"１＝");
        }
        recordSizeBuf = MC_GET_SHORT(&node[count].road_t.recordSize);
        linkIDBuf = MC_GET_LONG(&node[count].road_t.linkID);
        roadSizeBuf = MC_GET_SHORT(&node[count].road_t.roadNameSize);
        roadInfoBuf = MC_GET_LONG(&node[count].road_t.roadInfo);
        strcat(&roadNameBuf,&node[count].road_t.roadName);

        fwrite(&recordSizeBuf,sizeof(unsigned short),1,pFileIn);
        fwrite(&linkIDBuf,sizeof(unsigned long),1,pFileIn);
        fwrite(&roadSizeBuf,sizeof(unsigned short),1,pFileIn);
        fwrite(&roadInfoBuf,sizeof(unsigned long),1,pFileIn);
        fwrite(&roadNameBuf,node[count].road_t.recordSize - 12,1,pFileIn);

        memset( roadNameBuf,0,sizeof(recordSizeBuf) );

        //printf("%d:%hd\t%ld\t%hd\t%ld\n",count,recordSizeBuf,node->road.linkID,roadSizeBuf,roadInfoBuf);
        /*printf("%d:#linkID=%ld;Brunch=%d;DispClass=%d;RoadNameFlag=%d;roadName=%s;#\n\n", count,
                       node->road.linkID,node->road.Brunch,node->road.DispClass,
                       node->road.RoadNameFlag,node->road.roadName);*/
        count++;
    }
    printf("Update File Saving Count = %d\n",count);
    fclose(pFileIn);
    printf("\t\t\tUpdate File Saving Successful!!!\n");
}

Link_t listUpdateInfo(Link_t p)
{
    Link_t node = createList();
    char fileName[FILEMAXLENGTH];
    char fileNameHeader[FILEMAXLENGTH] = "../Data/";
    char fileNameFeet[FILEMAXLENGTH];
    int count = 0;
    unsigned short recordSizeBuf;
    unsigned long linkIDBuf;
    unsigned short roadSizeBuf;
    unsigned long roadInfoBuf;
    char roadNameBuf[MAXLENGTH] = "";

    strcpy(fileName,fileNameHeader);
    printf("Please input the update file saving path(etc:GTBL_New.dat):");
    scanf("%s",fileNameFeet);
    strcat(fileName,fileNameFeet);
    FILE *pFileIn = fopen(fileName,"wb");    //写入刚才读取的文件
    //FILE *pFileIn = fopen("../Data/GTBL_New.dat","wb");    //写入刚才读取的文件
    if(pFileIn == NULL)
    {
        printf("can not open the newgtal.txt file or there is no the file!\n");
        exit(0);
    }
    else
    {
        printf("Update Save Opening!\n");
    }
    printf("\n\t\t\tUpdate File Saving....\n");
    node = p->next;
    while(NULL != node)
    {

        if (node->road.recordSize - 12 != 0)
        {
            strcpy(roadNameBuf,"１＝");
        }
        recordSizeBuf = MC_GET_SHORT(&node->road.recordSize);
        linkIDBuf = MC_GET_LONG(&node->road.linkID);
        roadSizeBuf = MC_GET_SHORT(&node->road.roadNameSize);
        roadInfoBuf = MC_GET_LONG(&node->road.roadInfo);
        strcat(&roadNameBuf,&node->road.roadName);

        fwrite(&recordSizeBuf,sizeof(unsigned short),1,pFileIn);
        fwrite(&linkIDBuf,sizeof(unsigned long),1,pFileIn);
        fwrite(&roadSizeBuf,sizeof(unsigned short),1,pFileIn);
        fwrite(&roadInfoBuf,sizeof(unsigned long),1,pFileIn);
        fwrite(&roadNameBuf,node->road.recordSize - 12,1,pFileIn);

        memset( roadNameBuf,0,sizeof(recordSizeBuf) );

        //printf("%d:%hd\t%ld\t%hd\t%ld\n",count,recordSizeBuf,node->road.linkID,roadSizeBuf,roadInfoBuf);
        /*printf("%d:#linkID=%ld;Brunch=%d;DispClass=%d;RoadNameFlag=%d;roadName=%s;#\n\n", count,
                       node->road.linkID,node->road.Brunch,node->road.DispClass,
                       node->road.RoadNameFlag,node->road.roadName);*/

        node = node->next;
        count++;
    }
    printf("Update File Saving Count = %d\n",count);
    fclose(pFileIn);
    printf("\t\t\tUpdate File Saving Successful!!!\n");
    return node;
}
