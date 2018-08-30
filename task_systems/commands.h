void create_user(char * user_name, char * file_name)
{
	no_of_users++;
	entry = (users *)realloc(entry, no_of_users * sizeof(users));
	strcpy(entry[no_of_users - 1].user_name , user_name);
	entry[no_of_users-1].no_of_posts = 0;
}

void remove_user(char * user_name, char * file_name)
{
	int i = 0,j;
	for (i = 0; i < no_of_users; i++)
	{
		if (strcmp(entry[i].user_name, user_name) == 0)
		{
			break;
		}
	}
	for (j = i; j < (no_of_users-1); j++)
	{
		entry[j] = entry[j + 1];
	}

	/*for (j = i; j < (no_of_users - 1); j++)
	{
		post_comm[j] = post_comm[j + 1];
	}*/
	no_of_users--;
	entry = (users *)realloc(entry, no_of_users * sizeof(users));
	//post_comm = (int**)realloc(post_comm, no_of_users * sizeof(int));
	
}

void update_user(char * user_name, char * file_name)
{
	int i = 0;
	for (i = 0; i < no_of_users; i++)
	{
		if (strcmp(entry[i].user_name, user_name) == 0)
		{
			break;
		}
	}
	printf("Enter new name : ");
	char new_name[20];
	scanf("%s", new_name);
	strcpy(entry[i].user_name , new_name);
}

void get_user(char * user_name, char * file_name)
{
	int i, j, k;
	for (i = 0; i < no_of_users; i++)
	{
		if (strcmp(entry[i].user_name, user_name) == 0)
		{
			break;
		}
	}
	printf("POSTS:\n");
	for (j = 0; j < (entry[i].no_of_posts); j++)
	{
		printf("\tPost Name : %s\n", entry[i].next[j].post_name);
		printf("\tPost link : %s\n", entry[i].next[j].post_link);
		printf("\tNo.of likes : %d\n", entry[i].next[j].no_of_likes);
		printf("\tNo.of comments : %d\n", entry[i].next[j].no_of_comments);
		printf("\tComments : \n");
		for (k = 0; k < (entry[i].next[j].no_of_comments); k++)
		{
			printf("\t\t%d . %s\n", k+1, entry[i].next[j].go[k].content);
		}
	}
}

void commands(char * file_name)
{
	printf("1 - CREATE USER		2 - REMOVE USER		3 - UPDATE USER		4 - GET USER\n");
	printf("Enter option : ");
	int option;
	scanf("%d", &option);
	printf("Enter user name : ");
	char * user_name = (char*)calloc(20, sizeof(char));
	scanf("%s", user_name);
	switch (option)
	{
		case 1:
			create_user(user_name, file_name);
			break;
		case 2:
			remove_user(user_name, file_name);
			break;
		case 3:
			update_user(user_name, file_name);
			break;
		case 4:
			get_user(user_name, file_name);
			break;
		default:
			break;
	}
}