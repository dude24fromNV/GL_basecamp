#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "listLib.h"


int main(int argc, char *argv[])
{
        char b='b';
        int it = 888;
        int a= -84;
        short c = -10;
        long l = 435;
        float f = 435.453;
        double d = -123456789.98765;
        char st[]="hell0 tgrtgrthrthrthrthrt";
        printf("init list with 1 data\n");
        struct item *start=NULL;
        init(&start, &it, sizeof(it), Tint);

        printf("Tailadd 7\n");
        tailadd(&start, &a, sizeof(a), Tint);
        tailadd(&start, &b, sizeof(b), Tchar);
        tailadd(&start, &c, sizeof(c), Tshort);
        tailadd(&start, &l, sizeof(l), Tlong);
        tailadd(&start, &f, sizeof(f), Tfloat);
        tailadd(&start, &d, sizeof(d), Tdouble);
        tailadd(&start, &st[0], sizeof(st), Tchar);

        printf("List element\n");
        printList(start);
        int c_item = count(start);
        printf("count = %d \n", c_item);
        printf("===========================\n");
        printf("Remove from list\n");
        removeFromList(&start,4);
        printList(start);
        c_item = count(start);
        printf("count = %d \n", c_item);
        printf("===========================\n");
        printf("Insert in list\n");
        inserInList(&start, 0, &c, sizeof(c), Tshort);
        printList(start);
        c_item = count(start);
        printf("count = %d \n", c_item);
        printf("===========================\n");
        printf("Revers list\n");
        reverseList(&start);
        printList(start);
        printf("===========================\n");
        printf("Clear list\n");
        clearList(start);
        c_item = count(start);
        printf("count = %d \n", c_item);
        printList(start);
        return 0;
}




