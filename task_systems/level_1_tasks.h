
void upload_file()
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

	printf("Enter file to be inserted from disk to fs : ");
	char disk_file[20];
	scanf("%s", disk_file);
	FILE * v = fopen(disk_file, "rb");
	int f = 0; char c;
	while (fread(&c, 1, 1, v))
	{
		entry[i].next[j].post_content[f++] = c;
	}
	entry[i].next[j].post_content[f] = '\0';
	fclose(v);

}

void view_file()
{
	printf("File names are : \n");
	int i, j;
	for (i = 0; i < no_of_users; i++)
	{
		//printf("\tUser Name : %s\n", entry[i].user_name);
		for (j = 0; j < (entry[i].no_of_posts); j++)
		{
			printf("\t\t%s\n", entry[i].next[j].post_link);
		}
	}
}

void download_file()
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

void delete_file()
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
}

void add_comment()
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

	/*if (entry[i].next[j].no_of_comments == 0)
	{
		entry[i].next[j].go = (comments *)calloc(0, sizeof(comments));
	}*/

	entry[i].next[j].no_of_comments += 1;
	int p = entry[i].next[j].no_of_comments - 1;

	//entry[i].next[j].go = (comments *)realloc(entry[i].next[j].go, (p + 1)*sizeof(comments));
	strcpy(entry[i].next[j].go[p].content, comment);
}

void view_comments()
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

void delete_comment()
{
	printf("Enter user : ");
	char user_name[20];
	scanf("%s", user_name);
	printf("Enter post name : ");
	char post_name[20];
	scanf("%s", post_name);
	printf("Comment to be deleted : ");
	char comment[20];
	scanf("%s", comment);
	int i, j, k, g;
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

	for (k = 0; k < (entry[i].next[j].no_of_comments); j++)
	{
		if (strcmp(entry[i].next[j].go[k].content, comment) == 0)
			break;
	}

	for (g = k; g < (entry[i].next[j].no_of_comments- 1); g++)
	{
		entry[i].next[j].go[g] = entry[i].next[j].go[g + 1];
	}
	entry[i].next[j].no_of_comments--;

	//entry[i].next[j].go = (comments *)realloc(entry[i].next[j].go, (entry[i].next[j].no_of_comments)*sizeof(comments));
}

void level1_tasks()
{
	printf("1 - UPLOAD FILE  2 - VIEW FILE  3 - VIEW FILE  4 - DOWNLOAD FILE  5 - DELETE FILE  6 - ADD COMMENT FOR FILE  7 - VIEW COMMENTS  8 - DELETE COMMENT\n");
	printf("Enter option : ");
	int option;
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		upload_file();
		break;
	case 2:
		view_file();
		break;
	case 3:
		download_file();
		break;
	case 4:
		delete_file();
		break;
	case 5:
		add_comment();
		break;
	case 6:
		view_comments();
		break;
	case 7:
		delete_comment();
		break;
	default:
		break;
	}
}