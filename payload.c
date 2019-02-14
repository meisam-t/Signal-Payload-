#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	sigval_t value;
	int pid = atoi(argv[1]); // Get pid from user 
	int ret;
	value.sival_int = 200; // set the sival value 
	printf("The process id is :%d %d\n", pid, value.sival_int);
	ret = sigqueue(pid, SIGTERM,value); // send the SIGTERM to the given process
	if (ret == -1)
		perror("SigQueue");
	else 
		perror(" terminated !!!");
	
	return(EXIT_SUCCESS);
}
