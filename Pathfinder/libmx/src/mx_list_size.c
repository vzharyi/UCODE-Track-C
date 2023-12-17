#include "libmx.h"

int mx_list_size(t_list *list) {
    int counter = 0;
    t_list *temp = list;
    while(temp != NULL){
        temp = temp->next;
        counter++;
    }
    return counter;
}
