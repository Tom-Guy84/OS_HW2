#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/module.h>
#include <linux/sched.h>
#include "linux/global_var.h"

asmlinkage long sys_hello(void) {
	 printk("Hello, World!\n");
	 return 0;
}

asmlinkage long  sys_set_status(int status){
	if(status < 0 || status > 1)
		return -EINVAL;
	current->fac = status;
 	return 0;
}

asmlinkage int sys_get_status(void){
	return  current->fac;
}

asmlinkage int sys_register_process(void){
	add_our(current->tgid);
	return 0;	
}

asmlinkage long sys_get_all_cs(void){
    return sum_cs_our();
}

