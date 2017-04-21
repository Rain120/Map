#ifndef TABLEHEADER_H
#define TABLEHEADER_H
#include "Macro.h"

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
#endif // TABLEHEADER_H
