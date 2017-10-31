#include <iostream>
#include "Media.h"

using namespace std;

class Music: public Media{
public:
	int getType();
	void printStuff();
	Music(char*, char*, char*, int, int);
	int getYear();
	char* getTitle();
     ~Music();
private:
	char* title;
	int year;
	int duration;
	char* publisher;
	char* artist;
};
