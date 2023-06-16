#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *subject_search(char subject[], char *commands)
{
	char *str = strtok(subject, ";");
	//char *s = strtok(subject, ":");
	char command[800];
	while((str = strtok(NULL, ";")) != NULL)
	{
		printf("str %s\n", str);
		sprintf(command, "dir /s %s/%s", str, commands);
		printf("command: %s\n", command);
		system(command);
	}
	return subject;
}


int main(int args, char *argv[])
{
	char *command = argv[1];
	char commands[300];
	system("z:\\root\\mingw-setup.bat");
	system("echo %path% > path.txt");
	sprintf(commands , "dir 3/s c:/*%s*", command);
	printf("%s\n" , commands);
	FILE *fp = fopen("path.txt" , "r");
	
	char subject[500];
	while(fgets(subject, sizeof(subject), fp) != NULL)
	{
		subject_search(subject, command);
		printf("file subject. : \n %s\n",
 subject);
		
		
	}
	
	//system(commands);

	fclose(fp);	
	return 0;
}
