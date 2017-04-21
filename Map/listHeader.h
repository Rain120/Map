#ifndef LISTHEADER_H
#define LISTHEADER_H
#include "Macro.h"

int sizeList(Link_t p);
void PrintList(Link_t p);
Link_t createList(void);

/*****************************
 *  Sort
 *****************************/
Link_t bubbleSort(Link_t p);
Link_t selectSort( Link_t L );
Link_t insertSort( Link_t L );
Link_t quickSort( Link_t head, Link_t tail );
/*****************************
 *  Search
 *****************************/
Link_t listSearchLinkID(Link_t head, unsigned long rLinkId);
Link_t listSearchBrunch(Link_t head, int rBrunch);
Link_t listSearchRoadName(Link_t head, char *rRoadName);
/*****************************
 *  Insert
 *****************************/
Link_t listOrderInsert(Link_t L, Link_t node) ;
Link_t listPositionInsert(Link_t L,int pos,Link_t node) ;

Link_t listDelete(Link_t L, int LinkID);

#endif // LISTHEADER_H
