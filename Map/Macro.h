#ifndef MACRO_H
#define MACRO_H

/* *******************************
 * Define Or Global Paraments
 * *******************************/
typedef int   U8;
typedef char   INT;
typedef unsigned char UCHAR; //1
typedef unsigned short UINT; //2
typedef unsigned long ULONG; //4

#define MAXLENGTH 30
#define FILEMAXLENGTH 50
#define TABLELENGTH 63555

#define MC_GET_CHAR(__data__)  (*((char *)(__data__)))
#define MC_GET_SHORT(__data__)  ((UINT)(( ((UINT)(*((char *)(__data__))))<<8 )|( ((UINT)(*((char *)(__data__)+1)))&0x00ff )))
#define MC_GET_LONG(__data__)  ( ( ((ULONG)MC_GET_SHORT((__data__)))<<16 )|( ((ULONG)MC_GET_SHORT((char *)(__data__)+2))&0x0000ffff ) )
#define MC_GET_3BN(__data__)  ( ( ((ULONG)MC_GET_CHAR((__data__)))<<16 )|( ((ULONG)MC_GET_SHORT((char *)(__data__)+1))&0x0000ffff ) )

/*********************************
       Link情报Record
无符号2byte	这个记录的Size
无符号４byte	LinkID
无符号2byte	道路名称的Size
无符号４byte	始点Node的情报
            31-8	Reserved
            7	路线名称有无Flag
            6-4	岔路数
            3-0	交叉Link列表示Class番号
字符型	长度不定		道路名称字符串
************************************/
struct RoadRecord{
    unsigned short recordSize;  //记录的Size
    unsigned long roadInfo;    //始点Node的情报
    unsigned short roadNameSize;    //道路名称的Size

    unsigned long linkID;     //LinkID
    int DispClass;
    int Brunch;
    int RoadNameFlag;
    char roadName[MAXLENGTH];//道路名称
};

typedef struct link{
    struct RoadRecord road;
    struct link *next;
}*Link_t,link_t;

typedef struct table{
    struct RoadRecord road_t;
}table_t;

/* *******************************
 * Sequence table Function Define
 * *******************************/

void tableReadFile( table_t *p );
void tableSaveFile( table_t *p );
void tableUpdateInfo( table_t *p );

/* *******************************
 * List Function Define
 * *******************************/
Link_t listReadFile(Link_t p);  /*readFile*/
Link_t listSaveFile(Link_t p);  /*saveFile*/
Link_t listUpdateInfo(Link_t p);/*updateFile*/
void menu(void);

#endif // MACRO_H
