#include <iostream>
#include "Media.h"
using namespace std;

//Class that stores the data about a game
class Game: public Media{
public:
	int getType();
	void printStuff();
	char* getTitle();
	int getYear();
	Game(char*, char*, int, int);
     ~Game();
private:
	char* title;
	char* publisher;
	int year;
	int rating;
};
