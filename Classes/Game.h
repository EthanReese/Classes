#include <iostream>
#include "Media.h"
using namespace std;

//Class that stores the data about a game
class Game: public Media{
public:
	int getType();
	void printStuff();
	char[20]* getTitle();
	int getYear();
	Game(*char[20], *char[20], int, int);
private:
	char[20]* title;
	char[20]* publisher;
	int year;
	int rating;
}
