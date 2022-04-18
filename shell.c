#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
int main(int argc, char* argv[])
{
	//printf("no of args:%d,%s,%s",argc,argv[0],argv[1]);
	fclose(fopen("uab_sh.log", "w"));
	char quit[] = "quit";
	char help[] = "help";
	while(1)

	{

	        char line[256] = {0};
		int k;
		int a,pid,state;
		printf("\nuab_sh>");
		scanf(" %[^\n]",line);
		printf("\n line entered is:%s",line);
		//append line to log file
		FILE *fp;
		fp = fopen("uab_sh.log", "a");
		fprintf(fp, line);
		fprintf(fp, "\n");
    fclose(fp);

		char cmd[100]={};
		cmd[0]='.';
		cmd[1]='/';
		strcat(cmd,line);
		printf("\n command is:%s",cmd);
		if(strcmp(line, quit) == 0){
			printf("%s\n", "Quitting the shell program");
			break;
		} else if(strcmp(line, help) == 0){
			printf("\n%s\n", "list – list all the files in the current directory.");
			printf("%s\n", "cd <directory> – change the current directory to the <directory>");
		}
		pid = fork();
		//printf("\n pid %d\n", pid);
		if(pid==0)
		{
			execvp(cmd,NULL);
			exit(0);
		}
		else
		{
			if(waitpid(pid,&state,0)>0)
			{
				if(WIFEXITED(state)&&!WEXITSTATUS(state))
					printf("\nchild successful");
				else
					printf("\nchild problem");
			}
			else
				printf("\nwait pid failed");
		}
	}
	return 0;
}
