#include <stdio.h>
#include <stdlib.h>


typedef enum {
    Tshort = 1,
    Tlong = 2,
    Tint,
    Tfloat,
    Tdouble,
    Tchar,
    Tptr
    } data_type;

/**
*struct item - Element of list.
*@data: for save data.
*@type: for save data type.
*@next: pointer to next element of list.
*/
struct item{
    void *data;
    data_type type;
    struct item *next;
};
/**
*init() - Initialization of list and add 1st element.
*@arg1: pointer on list = NULL.
*@arg2: data what save in node.
*@arg3: size of data what save. 
*@arg4: type of data what save.
*
*Context:
*Return: function doesn`t return value.
*/
void init (struct item **, void *, size_t , data_type);

/**
*tailadd() - adding element to end of list.
*@arg1: pointer on list = NULL.
*@arg2: data what save in node.
*@arg3: size of data what save. 
*@arg4: type of data what save.
*
*Context:
*Return: function doesn`t return value.
*/
void tailadd (struct item **, void *, size_t , data_type);

/**
*printList() - print all element. 
*@arg1: a list what will be printed.
*
*Context: if list not initializing will be error
*Return: must return 0 after correct work.
*/
int printList(struct item *);

/**
*clearList() - delete all element in list.
*@arg1: a list what will be cleared.
*
*Context: if list not initializing will be error,
*         if pointer next == null will be printed error because list clear already
*Return: must return 0 after correct work.
*/
int  clearList (struct item *);

/**
*removeFromList() - delete one element in needed position.
*@arg1: pointer on a list where delete element.
*@arg2: position of element what will be delete.
*
*Context: if list not initializing will be error,
*         if posiotion doesn`t correct will be print error
*Return: must return 0 after correct work.
*/
int removeFromList ( struct item **, int );

/**
*inserInList() - adding element to end of list.
*@arg1: pointer on list.
*@arg2: position.
*@arg3: data what save in node.
*@arg4: size of data what save. 
*@arg5: type of data what save.
*
*Context:if list not initializing will be error,
*         if posiotion doesn`t correct will be print error
*Return: must return 0 after correct work.
*/
int inserInList(struct item **, int , void *, size_t , data_type);

/**
*count() - counting the number of list items.
*@arg1: list.
*
*Context:if list not initializing will be error,
*
*Return: must return number of elemnts .
*/
int count( struct item *);

/**
*reverseList() - reversing a list.
*@arg1: pointer on list.
*
*Context:
*
*Return: must return 0 after correct work.
*/
int reverseList (struct item **);
