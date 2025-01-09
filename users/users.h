#ifndef USERS_H
#define USERS_H



struct user{
	char *username;
	int id;
	char *name;
	char *surname;
	char *password;
	void *dataArr;
};

void createUser(struct user * local);


#endif
