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
*    Func:      tableReadFile
*    Para:      link  link_t[](typedef struct link link_t[])
*    retrurn:   link_t
**************************************************************************/
void tableReadFile( table_t *p )
{
    table_t *node;
    node = p;

    char fileName[FILEMAXLENGTH];
    int count = 0;
    unsigned short recordSizeBuf;
    unsigned long linkIDBuf;
    unsigned short roadSizeBuf;
    unsigned long roadInfoBuf;
    char roadNameBuf[MAXLENGTH] = "";

    /*printf("Please input the reading file path(etc:../Data/GTBL.dat):");
    scanf("%s",fileName);
    FILE *pFile = fopen(fileName,"rb");  //读*/
    FILE *pFile = fopen("../Data/GTBL.dat","rb");  //读
    if(pFile == NULL)
    {
        printf("can not open the GTBL.dat file or there is no the file!\n");
        exit(0);
    }
    else
    {
        printf("Read Opening!\n");
    }
    printf("\n\t\t\tFile Reading....\n");
    while( !feof(pFile) )
    {
        if(0 == fread(&recordSizeBuf,sizeof(unsigned short),1,pFile))
        {
            break;
        }
        fread(&linkIDBuf,sizeof(unsigned long),1,pFile);
        fread(&roadSizeBuf,sizeof(unsigned short),1,pFile);
        fread(&roadInfoBuf,sizeof(unsigned long),1,pFile);

        recordSizeBuf = MC_GET_SHORT(&recordSizeBuf);
        linkIDBuf = MC_GET_LONG(&linkIDBuf);
        roadSizeBuf = MC_GET_SHORT(&roadSizeBuf);
        roadInfoBuf = MC_GET_LONG(&roadInfoBuf);

        fread(roadNameBuf,recordSizeBuf - 12,1,pFile);
        //printf("1%s\n",roadNameBuf);
        if (recordSizeBuf - 12 != 0)
        {
            strcpy(node[count].road_t.roadName,roadNameBuf + 4);
        }
        else
        {
            strcpy(node[count].road_t.roadName,"NULL");
        }

        node[count].road_t.linkID = linkIDBuf;
        node[count].road_t.recordSize = recordSizeBuf;
        node[count].road_t.roadNameSize = roadSizeBuf;
        node[count].road_t.roadInfo = roadInfoBuf;

        node[count].road_t.Brunch = (roadInfoBuf & (7<<4));
        node[count].road_t.DispClass = (roadInfoBuf & 15);
        node[count].road_t.RoadNameFlag = (roadInfoBuf & (1<<7))>>7;

        memset(roadNameBuf,0,recordSizeBuf - 12);

        tableLength++;
        count++;
    }
    printf("Reading Count = %d\n",count);
    printf("Reading tableLength = %d\n",tableLength);
    fclose(pFile);
    printf("\t\t\tFile Reading Successful!!!\n");
}
/*************************************************************************
*    Func:      listReadFile
*    Para:      Link_t p  (typedef struct link* Link_t)
*    retrurn:   Link_t
**************************************************************************/
Link_t listReadFile(Link_t p)
{
    char fileName[FILEMAXLENGTH];
    Link_t node = createList();
    int count = 0;
    unsigned short recordSizeBuf;
    unsigned long linkIDBuf;
    unsigned short roadSizeBuf;
    unsigned long roadInfoBuf;
    char roadNameBuf[MAXLENGTH] = "";

    printf("Please input the reading file path(etc:../Data/GTBL.dat):");
    scanf("%s",fileName);
    FILE *pFile = fopen(fileName,"rb");  //读
    //FILE *pFile = fopen("../Data/GTBL.dat","rb");  //读
    if(pFile == NULL)
    {
        printf("can not open the GTBL.dat file or there is no the file!\n");
        exit(0);
    }
    else
    {
        printf("Read Opening!\n");
    }
    /*
    FILE *pFileOut = fopen("../Data/sourceLink.txt","w");    //写入刚才读取的文件
    if(pFileOut == NULL)
    {
        printf("can not open the newgtal.txt file or there is no the file!\n");
        exit(0);
    }*/
    printf("\n\t\t\tFile Reading....\n");
    while( !feof(pFile) )
    {
        if(0 == fread(&recordSizeBuf,sizeof(unsigned short),1,pFile))
        {
            break;
        }
        fread(&linkIDBuf,sizeof(unsigned long),1,pFile);
        fread(&roadSizeBuf,sizeof(unsigned short),1,pFile);
        fread(&roadInfoBuf,sizeof(unsigned long),1,pFile);

        recordSizeBuf = MC_GET_SHORT(&recordSizeBuf);
        node->road.linkID = MC_GET_LONG(&linkIDBuf);
        roadSizeBuf = MC_GET_SHORT(&roadSizeBuf);
        roadInfoBuf = MC_GET_LONG(&roadInfoBuf);


        fread(roadNameBuf,recordSizeBuf - 12,1,pFile);
        if (recordSizeBuf - 12 != 0)
        {
            strcpy(node->road.roadName,roadNameBuf + 4);
        }
        else
        {
            strcpy(node->road.roadName,"NULL");
        }

        node->road.recordSize = recordSizeBuf;
        node->road.roadNameSize = roadSizeBuf;
        node->road.roadInfo = roadInfoBuf;

        node->road.Brunch = (roadInfoBuf & (7<<4));
        node->road.DispClass = (roadInfoBuf & 15);
        node->road.RoadNameFlag = (roadInfoBuf & (1<<7))>>7;

        //printf("temp->%d->%ld\t%hd\t%hd\t%ld\n",count,node->road.linkID,recordSizeBuf,roadSizeBuf,roadInfoBuf);
        //printf("node->%d->%ld\t%d\t%d\t%x\n",count,node->road.linkID,node->road.Brunch,node->road.DispClass,node->road.roadInfo);

        /*printf("%d:#linkID=%ld;Brunch=%d;DispClass=%d;RoadNameFlag=%d;roadName=%s;#\n\n", count,
               node->road.linkID,node->road.Brunch,node->road.DispClass,
               node->road.RoadNameFlag,node->road.roadName);*/

      /*fprintf(pFileOut,"#");
        fprintf(pFileOut,"LinkID=");
        fprintf(pFileOut,"%5ld;",node->road.linkID);
        fprintf(pFileOut,"RoadnameFlag=");
        fprintf(pFileOut,"%d;",node->road.RoadNameFlag);
        fprintf(pFileOut,"Brunch=");
        fprintf(pFileOut,"%2d;",node->road.Brunch);
        fprintf(pFileOut,"DispClass=");
        fprintf(pFileOut,"%2d;",node->road.DispClass);
        fprintf(pFileOut,"Roadname=");
        fprintf(pFileOut,"%s;",node->road.roadName);
        fprintf(pFileOut,"#");
        fprintf(pFileOut,"\n");
        */
        memset(roadNameBuf,0,recordSizeBuf - 12);

        node->next = NULL;
        p->next = node;
        p = p->next;
        node = (Link_t)malloc(sizeof(link_t));
        count++;
    }
    printf("Reading Count = %d\n",count);
    fclose(pFile);
    printf("\t\t\tFile Reading Successful!!!\n");
    return p;
}
