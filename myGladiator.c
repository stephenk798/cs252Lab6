//made by Stephen Kramer, Spring 2015, CS252
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <proc/readproc.h>
#include <string.h>

int main(int argc, char *argv[]){
	PROCTAB* theProc = openproc(PROC_FILLSTATUS);
	pid_t p;
	while (1) {
		proc_t* curP; 
		while(curP = readproc(theProc, NULL)){
			char* test = strstr(curP->cmd, "myGladiator");
			if(test == NULL){
				kill(curP->tid, SIGKILL);
			}
			p = fork();
		}
		p = fork();
		waitpid(-1, NULL,WNOHANG);
	}

}
