#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include "readcmd.h"


void trace_cmd(struct cmdline *l) {

		int i, j;

		/* Display each command of the pipe */
		printf("trace_cmd\n");
		for (i=0; l->seq[i]!=0; i++) {
			char **cmd = l->seq[i];
			printf("seq[%d]: ", i);
			for (j=0; cmd[j]!=0; j++) {
				printf("(%s) ", cmd[j]);
			}
			printf("\n");
		}
}


void change_dir(char *param) {
        char *curr_dir;
        char buf[1024];
        char *path;
        if ((curr_dir=getcwd(NULL, 0)) == NULL) {
                perror("cd failed (getcwd)");
                return;
        }
        if (!param) path = getenv("HOME");
        else
                if (strncmp(param,"/",1)) {
                        if ((strlen(curr_dir)+strlen(param)+2)>1024) {
                                perror("cd failed (path too large)");
                                free(curr_dir);
                                return;
                        }
                        path = strcpy(buf,curr_dir);
                        path = strcat(path, "/");
                        path = strcat(path, param);
                } else path = param;
                //printf("%s\n",path);
                if (chdir(path)) {
                        perror ("cd failed (chdir)");
                        chdir(curr_dir);
                }
                free(curr_dir);
}


int main()
{
	pid_t spid;
	int status ;
	struct cmdline *l;
	int fd[2],fd2[2];
	char ***seq;
	int debut;
	
	while(1) {
		printf("shell> ");

		l = readcmd();
		trace_cmd(l);
		seq = l->seq;

		if (! *seq) continue;

		if(!strcasecmp(**seq, "exit")) {
			return 0;
		}

                if(!strcasecmp(**seq, "cd")) {
                        change_dir((*seq)[1]);
                        continue;
                }

		debut = 1;
		
		//if (seq[0]==0) continue;

		while (*seq!=0) {

			char **cmd = *seq;
			seq++;
			
			if(*seq){
				pipe(fd);
			}

			if ((spid=fork()) == 0) {
				if (*seq) {
					close(fd[0]);
					dup2(fd[1], STDOUT_FILENO);
					close(fd[1]);
				}
				if (!debut) {
					close(fd2[1]);
					dup2(fd2[0], STDIN_FILENO);
					close(fd2[0]);
				}			
				if (execvp(*cmd,cmd)==-1) {
					perror ("execvp failed");
					exit(1);
				}		 
			} else {
				if(!debut){
					close(fd2[1]);
					close(fd2[0]);
				}	
				fd2[0]=fd[0];fd2[1]=fd[1];
			}
			debut = 0;
		}
		if (waitpid(spid,&status,0)==-1) {
			perror ("waitpid failed");
			exit(1);
		}
		
	}
	return 0;
}
