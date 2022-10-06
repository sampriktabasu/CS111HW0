# A Kernel Seedling

Kernel module that displays the count or # of currently running processes.

## Building

Run the following commands:
make
sudo insmod proc_count.ko

## Running

Run the kernel module with the following command: cat /proc/count
Expect an integer output that represents the # of running processes.

## Cleaning Up

Remove the kernel module with the following command: sudo rmmod proc_count.ko

Inside the code, clean up is performed using the function proc_remove() in the kernel module's exit function to clean up the directory that was created by proc_create_single upon init. 

## Testing

Kernel Release Version: 5.14.8-arch1-1
