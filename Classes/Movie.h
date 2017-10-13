#include <iostream>

using namespace std;

//Class that stores the data about a movie
class Movie: public Media{
public:
	int getType();
	void printStuff();
	Movie(char[20]*, char[20]*,  int, int, int);
	int getYear();
	char[20]* getTitle();
private:
	char[20]* title;
	int year;
	int rating;
	int duration;
	char[20]* director;
};
