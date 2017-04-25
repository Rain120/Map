#ifndef LISTHEADER_H
#define LISTHEADER_H
#include "Macro.h"


/* *********************************************************
 *                      Basic Function
 * *********************************************************/
int sizeList(Link_t p);

void PrintList(Link_t p);

Link_t createList(void);


/* *********************************************************
 *                      Sorting Function
 * *********************************************************/
Link_t bubbleSort(Link_t p);

Link_t selectSort( Link_t L );

Link_t insertSort( Link_t L );

Link_t quickSort( Link_t head, Link_t tail );

/* *********************************************************
 *                      Searching Function
 * *********************************************************/
Link_t listSearchLinkID(Link_t head, unsigned long lLinkId);

Link_t listSearchBrunch(Link_t head, int lBrunch);

Link_t listSearchRoadName(Link_t head, char *lRoadName);

/* *********************************************************
 *                      Inserting Function
 * *********************************************************/
Link_t listOrderInsert(Link_t L, Link_t node) ;

Link_t listPositionInsert(Link_t L,int pos,Link_t node) ;

/* *********************************************************
 *                      Deleting Function
 * *********************************************************/
Link_t listDelete(Link_t L, int LinkID);

#endif // LISTHEADER_H
