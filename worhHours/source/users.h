#ifndef USERS_H
#define USERS_H



struct user{
	int id;
	char *username[20];
	char *password[20];
	char *name[15];
	char *surname[20];
	 void *dataArr[0];
};

void createUser(struct user * local);


#endif
