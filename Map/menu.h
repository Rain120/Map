#ifndef MENU_H
#define MENU_H
#include "Macro.h"

/* *********************************************************
 *              Define Or Global Paraments
 * *********************************************************/
//static int rFlag = 0;

void versionMenu(void);
void mainMenu(void);
void mainMenuChoose();
/* *********************************************************
 *                      TableMenu
 * *********************************************************/
void tableMenu(void);
void tableMenuChoose(table_t *p);

void tableInsertMenu(void);
void tableInsertMenuChoose(table_t *p);

void tableDeleteMenu(void);
void tableDeleteMenuChoose(table_t *p);

void tableSearchMenu(void);
void tableSearchMenuChoose(table_t *p);

void tableSortMenu(void);
void tableSortMenuChoose(table_t *p);

/* *********************************************************
 *                      ListMenu
 * *********************************************************/
void listMenu(void);
void listMenuChoose(Link_t p);

void listInsertMenu(void);
void listInsertMenuChoose(Link_t p);

void listDeleteMenu(void);
void listDeleteMenuChoose(Link_t p);

void listSearchMenu(void);
void listSearchMenuChoose(Link_t p);

void listSortMenu(void);
void listSortMenuChoose(Link_t p);

/* *********************************************************
 *                      TreeMenu
 * *********************************************************/
void treeMenu(void);

#endif // MENU_H
