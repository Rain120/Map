#ifndef MENU_H
#define MENU_H
#include "Macro.h"

/* *******************************
 * Define Or Global Paraments
 * *******************************/
//static int rFlag = 0;

void versionMenu(void);
void tableMenu(void);

void mainMenu(void);
void mainMenuChoose(Link_t p);

void listMenu(void);
void listMenuChoose(Link_t p);

void insertMenu(void);
void insertMenuChoose(Link_t p);

void deleteMenu(void);
void deleteMenuChoose(Link_t p);

void searchMenu(void);
void searchMenuChoose(Link_t p);

void sortMenu(void);
void sortMenuChoose(Link_t p);

void treeMenu(void);

#endif // MENU_H
