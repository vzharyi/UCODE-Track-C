#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *end = mx_create_node(data);
    t_list *tmp = *list;

    if (*list == NULL)
        *list = end;
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = end;
    }
}
