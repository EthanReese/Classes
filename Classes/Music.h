#include <iostream>

using namespace std;

class Music: public Media{
public:
	int getType();
	void printStuff();
	Music(char[20]*, char[20]*, char[20], int, int);
	int getYear();
	char[20]* getTitle();
private:
	char[20]* title;
	int year;
	int duration;
	char[20]* publisher;
	char[20]* artist;
}
