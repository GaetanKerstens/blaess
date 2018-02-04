#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/wait.h>

int main(void)
{
 pid_t pid_fils;

 do {
	pid_fils = fork();
 } while ((pid_fils == -1) && (errno == EAGAIN));

 if (pid_fils == -1) {
	fprintf(stderr, "forfk() impossible, errno=%d\n",errno);
	return 1;
 }
 
 if (pid_fils == 0) { /*Processus fils*/
	fprintf(stdout,"Fils : PID=%ld, PPID=%ld\n",(long)getpid(),(long)getppid());
	return 0;
 } else { /*Processus Père*/
	fprintf(stdout,"Père : PID=%ld, PPID=%ld, PID fils=%ld\n",(long)getpid(),(long)getppid(),(long)pid_fils);
	wait(NULL);
	return 0;
   }
}
