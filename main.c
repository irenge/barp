#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>

#define NUM 600

static void loop_through(struct task_struct *ptask);

static void loop_through(struct task_struct *ptask) {
	for_each_process(ptask) {
		if(ptask->pid < NUM) 
			continue;
		pr_info("%d\t%s\t%d\t%d\n", ptask->pid, ptask->comm, ptask->prio, ptask->exit_code);
	}

}
static int __init barp_init(void){

	struct task_struct *task = NULL;

	pr_info("\nModule initialized\n");

	loop_through(task);

	return 0;
}


static void __exit barp_exit(void) {

	pr_info("\nModule removed\n");

}

module_init(barp_init);
module_exit(barp_exit);

MODULE_AUTHOR("Jules Bashizi");
MODULE_DESCRIPTION("Barman: Process performance");
MODULE_LICENSE("GPL v2");

