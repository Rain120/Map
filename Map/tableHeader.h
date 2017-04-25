#ifndef TABLEHEADER_H
#define TABLEHEADER_H
#include "Macro.h"

void printTable( table_t *p,int n );
/* *********************************************************
 *                      Sorting Function
 * *********************************************************/
void Bublesort( table_t *p,int n );

void SelectSort(table_t *p,int n);

void InsertSort(table_t *p, int n);

int Partition(table_t *p,int low,int high);
void QuickSort(table_t *p,int low,int high);

void Merge(table_t *p, int low, int mid, int high);
void MergeSort(table_t *p, int first, int last);

void ShellSort(table_t *p, int n);

void heapAdjust(table_t *p, int i, int n);
void HeapSort(table_t *p,int n);
/* *********************************************************
 *                      Searching Function
 * *********************************************************/
void tableSearchLinkID( table_t *p,int len );

void tableSearchBrunch( table_t *p,int len );

void tableSearchRoadName( table_t *p,int len );

/* *********************************************************
 *                      Inserting Function
 * *********************************************************/
int tableOrderInsert( table_t *p,int len ) ;

int tablePositionInsert( table_t *p,int len ) ;

/* *********************************************************
 *                      Deleting Function
 * *********************************************************/
int tableDelete( table_t *p,int len );

#endif // TABLEHEADER_H
