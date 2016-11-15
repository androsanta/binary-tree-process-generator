#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {FALSE, TRUE} boolean;

int main(int argc, char **argv)
{
int n, t, i, j;
pid_t pid;
boolean figlio;

if(argc!=3){
	printf("Errore parametri\n");
	exit(EXIT_FAILURE);
}

n=atoi(argv[1]);
t=atoi(argv[2]);

printf("%d\n", getpid());
for(j=0, figlio=TRUE; j<n && figlio; j++){
	for(i=0, figlio=FALSE; i<2 && !figlio; i++){
		pid=fork();
		if(pid>0){ //padre
			printf("%d\t%d\t%d\n", getppid(), getpid(), pid);
		}
		else{ //figlio
			figlio=TRUE;
			if(j==(n-1)){
				sleep(t);
				printf("foglia albero\tPID: %d\n", getpid());
			}
		}
	}
}
sleep(5);
return 0;
}
