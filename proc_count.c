#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

// global var to store directory
static struct proc_dir_entry *pc;

static int get_proc_count(void) {
  int counter = 0;
  struct task_struct *t;
  
  // loop through processes and increment counter
  for_each_process(t) {
    counter++;
  }
  return counter;
}

// write # of processes count to "count" file
static int counting_show(struct seq_file *s, void *v) {
  seq_printf(s, "%d\n", get_proc_count());
  return 0;
}

static int __init proc_count_init(void)
{
	pr_info("proc_count: init\n");
	// create proc entry that "shows" the processes count
	pc = proc_create_single("count", 0, NULL, counting_show);
	return 0;
}

static void __exit proc_count_exit(void)
{        
	pr_info("proc_count: exit\n");
	// clean up the directory
	proc_remove(pc);
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Samprikta Basu");
MODULE_DESCRIPTION("Creates /proc/count file displaying count of currently running processes.");
MODULE_LICENSE("GPL");
