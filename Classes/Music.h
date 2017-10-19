#include <iostream>
#include "media.h"

using namespace std;

class Music: public Media{
public:
	int getType();
	void printStuff();
	Music(char[20]*, char[20]*, char*[20], int, int);
	int getYear();
	char[20]* getTitle();
private:
	char* title[20];
	int year;
	int duration;
	char* publisher[20];
	char* artist[20];
};
