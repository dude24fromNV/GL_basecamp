#include "listLib.h"
void init (struct item **list, void *newdata, size_t datasize, data_type T){
    *list =(struct item*)malloc(sizeof(struct item));
    struct item *current = *list;
    current->next= NULL;
    current->data = malloc(datasize);

    for (int i=0; i<datasize; i++)
            *(char *)(current->data+i)=*(char *)(newdata+i);
    current->type=T;
}

void tailadd (struct item **list, void *newdata, size_t datasize, data_type T){


    if(*list == NULL) {printf("Error, list does not exist. Program close");
                        exit(0);};
    struct item *current = *list;
    struct item *newitem = (struct item*)malloc(sizeof(struct item));
    if(newitem == NULL)
    {
        printf("Error creating a newitem.\n");
        exit(0);
    }
    while (current->next != NULL){
        current= current->next;
    }
    current->next= newitem;
    newitem->data = malloc(datasize);
    newitem->next = NULL;
    for (int i=0; i<datasize; i++)
            *(char *)(newitem->data+i)=*(char *)(newdata+i);
    newitem->type=T;
}

int printList(struct item *list){
    if(list== NULL)  {printf("Error, list do not exist\n");
                        return 0;};
    int c=0;
    while (list != NULL)
    {
        printf("%d. ", c);
        switch (list->type){
            case Tshort:
                printf("%hd ", *(short *)list->data);
                break;
            case Tlong:
                printf("%ld ", *(long *)list->data);
                break;
           case Tint:
                printf("%d ", *(int *)list->data);
                break;
            case Tchar:
                printf("%s ", (char *)list->data);
                break;
            case Tfloat:
                printf("%f ", *(float*)list->data);
                break;
            case Tdouble:
                printf("%lf ", *(double*)list->data);
                break;
            case Tptr:
                printf("pointer %p", (void*)list->data);
                break;

            }
    list=list->next;
    c++;

    printf("\n");
    }
return 0;
}

int  clearList (struct item *list){


    if(list== NULL)  {printf("Error, list do not exist\n");
                        return 0;};
    if(list->next == NULL) {printf("can`t clear empty list \n");
                            return 0;}

    struct item *cursor, *tmp;
    if  (list->next!=NULL)
        {
            cursor=list->next;
            list->next=NULL;
            while (cursor != NULL)
            {
                tmp =cursor->next;
                free(cursor);
                cursor =tmp;
            }

        }
        free(list);
return 0;
}

int removeFromList ( struct item **list, int index){

    if(*list== NULL)  {printf("Error, list do not exist\n");
                        return 0;};

    struct item *current = *list;

    if (index==0){
    *list =current->next;
    free(current);
    return 0;
    }

    for ( int i =0; current!=NULL && i<index-1; i++)
        current=current->next;
    if (current ==NULL || current ->next ==NULL){
        printf("\n This position do not exist\n");
        return 0;
        }
    struct item *next = current->next->next;
    free(current->next);
    current->next=next;
    return 0;
}

int inserInList(struct item **list, int index, void *newdata, size_t datasize, data_type T){

    if(*list== NULL)  {printf("Error, list do not exist\n");
                        return 0;};
     if (index==0){
    struct item *newitem = (struct item*)malloc(sizeof(struct item));
    newitem->data = malloc(datasize);
    for (int i=0; i<datasize; i++)
            *(char *)(newitem->data+i)=*(char *)(newdata+i);
    newitem->type=T;

    newitem->next = *list;
    *list=newitem;
    return 0;
    }

    struct item *current = *list;
    for ( int i =0; current!=NULL && i<index-1; i++)
        current=current->next;
    if (current ==NULL || current ->next ==NULL){
        printf("\n Can`t insert. This position do not exist\n");
        return 0;
        }
    struct item *next = current->next;
    struct item *newitem = (struct item*)malloc(sizeof(struct item));
    current->next= newitem;
    newitem->data = malloc(datasize);
    newitem->next = next;
    for (int i=0; i<datasize; i++)
            *(char *)(newitem->data+i)=*(char *)(newdata+i);
    newitem->type=T;
    return 0;
}

int count( struct item *list){
     if(list== NULL)  {printf("Error, list do not exist\n");
                        return 0;};
    struct item *current = list;
    int c=0;
    while (current!=NULL){
    c++;
    current = current->next;
    }
return c;
}

int reverseList (struct item **list){
    struct item *current = *list;
    struct item *prev= NULL, *next =NULL;
    while(current!= NULL)
    {
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
    }
    *list=prev;
return 0;
}
