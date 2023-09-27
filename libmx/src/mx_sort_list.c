#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool(*cmp)(void *, void *)) {
    if (lst == NULL || cmp == NULL)
        return lst;
    int size = mx_list_size(lst);
    t_list *list = lst;
    bool swapped = false;
    while (!swapped) {
        swapped = true;
        t_list *curr = list;
        for (int i = 0; i < size - 1; i++) {
            if (cmp(curr->data, curr->next->data)) {
                void *temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = false;
            }
            curr = curr->next;
        }
    }
    return list;
}
