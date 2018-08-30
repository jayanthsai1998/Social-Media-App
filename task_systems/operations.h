
void post()
{
	printf("Enter user : ");
	char user_name[20];
	scanf("%s", user_name);
	printf("Enter post name : ");
	char post_name[20];
	scanf("%s", post_name);
	printf("Enter post link : ");
	char post_link[20];
	scanf("%s", post_link);
	int i;
	for (i = 0; i < (no_of_users); i++)
	{
		if (strcmp(entry[i].user_name, user_name) == 0)
			break;
	}


	entry[i].no_of_posts += 1;
	int p = entry[i].no_of_posts - 1;
	
	//entry[i].next = (posts *)realloc(entry[i].next,(p+1) * sizeof(posts));
	
	strcpy(entry[i].next[p].post_name, post_name);
	strcpy(entry[i].next[p].post_link, post_link);

	FILE * v = fopen(post_link, "rb");
	int f = 0; char c;
	while (fread(&c, 1, 1, v))
	{
		entry[i].next[p].post_content[f++] = c;
	}
	entry[i].next[p].post_content[f] = '\0';
	fclose(v);

	entry[i].next[p].no_of_comments = 0;
	entry[i].next[p].no_of_likes = 0;
}

void comment_on_post()
{
	printf("Enter user : ");
	char user_name[20];
	scanf("%s", user_name);
	printf("Enter post name : ");
	char post_name[20];
	scanf("%s", post_name);
	printf("Add Comment : ");
	char comment[20];
	scanf("%s", comment);
	int i, j;
	for (i = 0; i < (no_of_users); i++)
	{
		if (strcmp(entry[i].user_name, user_name) == 0)
			break;
	}
	for (j = 0; j < (entry[i].no_of_posts); j++)
	{
		if (strcmp(entry[i].next[j].post_name, post_name) == 0)
			break;
	}

	entry[i].next[j].no_of_comments += 1;
	int p = entry[i].next[j].no_of_comments - 1;

	//entry[i].next[j].go = (comments *)realloc(entry[i].next[j].go , (p + 1)*sizeof(comments));
	strcpy(entry[i].next[j].go[p].content , comment);
}

void like_post()
{
	printf("Enter user : ");
	char user_name[20];
	scanf("%s", user_name);
	printf("Enter post name : ");
	char post_name[20];
	scanf("%s", post_name);
	int i, j;
	for (i = 0; i < (no_of_users); i++)
	{
		if (strcmp(entry[i].user_name, user_name) == 0)
			break;
	}
	for (j = 0; j < (entry[i].no_of_posts); j++)
	{
		if (strcmp(entry[i].next[j].post_name, post_name) == 0)
			break;
	}
	entry[i].next[j].no_of_likes += 1;
}

void remove_post()
{
	printf("Enter user : ");
	char user_name[20];
	scanf("%s", user_name);
	printf("Enter post name : ");
	char post_name[20];
	scanf("%s", post_name);
	int i, j, k;
	for (i = 0; i < (no_of_users); i++)
	{
		if (strcmp(entry[i].user_name, user_name) == 0)
			break;
	}
	for (j = 0; j < (entry[i].no_of_posts); j++)
	{
		if (strcmp(entry[i].next[j].post_name, post_name) == 0)
			break;
	}
	for (k = j; k < (entry[i].no_of_posts - 1); k++)
	{
		entry[i].next[k] = entry[i].next[k + 1];
	}
	entry[i].no_of_posts--;

	//entry[i].next = (posts *)realloc(entry[i].next, (entry[i].no_of_posts) * sizeof(posts));
}

void update_post()
{
	printf("Enter user : ");
	char user_name[20];
	scanf("%s", user_name);
	printf("Enter post name : ");
	char post_name[20];
	scanf("%s", post_name);
	printf("Enter new post link : ");
	char new_post_link[20];
	scanf("%s", new_post_link);
	int i, j;
	for (i = 0; i < (no_of_users); i++)
	{
		if (strcmp(entry[i].user_name, user_name) == 0)
			break;
	}
	for (j = 0; j < (entry[i].no_of_posts); j++)
	{
		if (strcmp(entry[i].next[j].post_name, post_name) == 0)
			break;
	}
	strcpy(entry[i].next[j].post_link , new_post_link);

	FILE * v = fopen(new_post_link, "rb");
	int f = 0; char c;
	while (fread(&c, 1, 1, v))
	{
		entry[i].next[j].post_content[f++] = c;
	}
	entry[i].next[j].post_content[f] = '\0';
	fclose(v);
}

void save_post()
{
	printf("Enter user : ");
	char user_name[20];
	scanf("%s", user_name);
	printf("Enter post name : ");
	char post_name[20];
	scanf("%s", post_name);
	int i, j;
	for (i = 0; i < (no_of_users); i++)
	{
		if (strcmp(entry[i].user_name, user_name) == 0)
			break;
	}
	for (j = 0; j < (entry[i].no_of_posts); j++)
	{
		if (strcmp(entry[i].next[j].post_name, post_name) == 0)
			break;
	}

	FILE *w = fopen("checking_image.png", "wb");
	fwrite(&(entry[i].next[j].post_content), 524288, 1, w);
	fclose(w);
}

void message_user()
{

}

void get_all_messages()
{

}

void operations(char * file_name)
{
	printf("1 -	POST	2 - COMMENT ON POST   3 - LIKE POST   4 - REMOVE POST    5 - UPDATE POST    6 - SAVE POST    7 - MESSAGE USER    8 - GET ALL MSGS\n");
	printf("Enter option : ");
	int option;
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		post();
		break;
	case 2:
		comment_on_post();
		break;
	case 3:
		like_post();
		break;
	case 4:
		remove_post();
		break;
	case 5:
		update_post();
		break;
	case 6:
		save_post();
		break;
	case 7:
		message_user();
		break;
	case 8:
		get_all_messages();
		break;
	}
}