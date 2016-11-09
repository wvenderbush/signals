#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

//Winston Venderbush and Sarah Yoon
//11/9/16

void sighand(int signum){
	if (signum == SIGINT){
		printf("Signal %d caught!\n", signum);
		int d = open("log.txt", O_CREAT | O_RDWR, 0644);
		write(d, "Process exited due to SIGINT", 29);
		exit(1);
	}
	if (signum == SIGUSR1)
		printf("Signal %d caught!\n", signum);
}

int main(){
	signal(SIGINT, sighand);
	signal(SIGUSR1, sighand);

   while(1) 
   {
      printf("Running %d...\n", getpid());
      sleep(1); 
   }
   return(0);

}