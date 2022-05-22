#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#include <linux/list.h>
#include <linux/kernel.h>
#include <linux/sched.h>
struct our_list
{
    struct list_head list;
    int pid;
    int* pfac;
};

void add_our(int pid);
void remove_our(int pid);
long sum_cs_our(void);
#endif
