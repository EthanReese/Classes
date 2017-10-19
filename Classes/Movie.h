#include <iostream>
#include "media.h"

using namespace std;

//Class that stores the data about a movie
class Movie: public Media{
public:
	int getType();
	void printStuff();
	Movie(char*, char*,  int, int, int);
	int getYear();
	char* getTitle();
private:
	char* title;
	int year;
	int rating;
	int duration;
	char* director;
};
