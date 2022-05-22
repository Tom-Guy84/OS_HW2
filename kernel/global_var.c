#include "linux/global_var.h"

LIST_HEAD(list_global);

void add_our(int pid)
{
    struct list_head* ptr;
    struct our_list* entry;
    struct our_list* our_add = vmalloc(sizeof(*our_add));

    for (ptr = list_global.next; ptr != &list_global; ptr = ptr->next) {
        entry = list_entry(ptr, struct our_list, list);
        if (entry->pid == pid) {
            return;
        }
    }

    our_add->pid = pid;
    INIT_LIST_HEAD(&our_add->list); // now the list is initialized
    our_add->pfac = &current->fac;
    list_add_tail(&our_add->list, &list_global);
}

void remove_our(int pid)
{
    struct list_head* ptr;
    struct our_list* entry;


    for (ptr = list_global.next; ptr != &list_global; ptr = ptr->next) {
        entry = list_entry(ptr, struct our_list, list);
        if (entry->pid == pid) {
            list_del(ptr);
            return;
        }
    }
}

long sum_cs_our(void)
{
    struct list_head* ptr;
    struct our_list* entry;
    long sum = 0;
    int any_proc = 0;
    for (ptr = list_global.next; ptr != &list_global; ptr = ptr->next) {
        entry = list_entry(ptr, struct our_list, list);
        if(*entry->pfac == 1)
        {
            sum += entry->pid;
        }
	any_proc++;
    }
    if(any_proc == 0)
    {
        return -ENODATA;
    }
    return sum;
}

