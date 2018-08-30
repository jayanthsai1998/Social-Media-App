struct comments
{
	char content[50];
};

struct posts
{
	char post_name[20];
	char post_link[20];
	char post_content[524288];
	int no_of_likes;
	int no_of_comments;
	struct comments  go[10];
};

struct users
{
	char user_name[20];	
	int no_of_posts;
	struct posts  next[10];
};
int no_of_users = 0;
users * entry = (users *)calloc(no_of_users, sizeof(users));

int ** post_comm = (int**)calloc(0, sizeof(int*)); 
// for storing the no_of_posts and no_of_comments for each user
