#define _CRT_SECURE_NO_WARNINGS
#define USER_TYPE 1
#define POST_TYPE 2
#define COMMENT_TYPE 3


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "operations.h"
#include "commands.h"
#include "level_1_tasks.h"

void check()
{
	int i, j, k;
	for (i = 0; i < no_of_users; i++)
	{
		printf("User Name : %s\n", entry[i].user_name);
		for (j = 0; j < (entry[i].no_of_posts); j++)
		{
			printf("\tPost Name : %s\n", entry[i].next[j].post_name);
			printf("\tPost link : %s\n", entry[i].next[j].post_link);
			printf("\tNo.of likes : %d\n", entry[i].next[j].no_of_likes);
			printf("\tNo.of comments : %d\n", entry[i].next[j].no_of_comments);
			printf("\tComments : \n");
			for (k = 0; k < (entry[i].next[j].no_of_comments); k++)
			{
				printf("\t\t%d . %s\n", k + 1, entry[i].next[j].go[k].content);
			}
		}
	}
}

void choice(char * file_name)
{
	while (1)
	{
		printf("1 COMMANDS ON USER DATA    2 - USER OPERATIONS	  3 - CHECK	  4 - LEVEL-1 TASKS	5 - EXIT\n");
		printf("Enter option : ");
		int option;
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			commands(file_name);
			break;
		case 2:
			operations(file_name);
			break;
		case 3:
			check();
			break;
		case 4:
			level1_tasks();
			break;
		case 5:
			int i;
			FILE *fw = fopen(file_name, "wb");
			fwrite(&no_of_users, sizeof(no_of_users), 1, fw);
			for (i = 0; i < (no_of_users); i++)
			{
				fwrite(&(entry[i]), sizeof(entry[i]), 1, fw);
			}
			fclose(fw);
			exit(0);
		}
	}
}

void writing_to_mem(char * file_name)
{
	FILE * fw = fopen(file_name, "rb");
	fread(&no_of_users, sizeof(no_of_users), 1, fw);
	entry = (users *)realloc(entry, no_of_users * sizeof(users));
	int i;
	for (i = 0; i < no_of_users; i++)
	{
		fread(&entry[i], 5248384, 1, fw);
	}
	fclose(fw);
}

int main(int argc, char * argv[])
{
	char * file_name = "file_system.bin";
	writing_to_mem(file_name);
	//printf("size : %d\n", sizeof(struct users));
	choice(file_name);
	system("pause");
	return 0;
}