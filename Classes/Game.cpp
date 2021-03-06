#include <iostream>
#include "Game.h"
#include <cstdlib>
#include <cstring>

using namespace std;

//Return that the it is a game
int Game::getType(){
	return 3;
}

//Print out all the relevant information about the game
void Game::printStuff(){
	cout << "Game: " << title;
	cout << endl << "Made by: " << publisher;
	cout << endl << "Year: " << year;
	cout << endl << "Rated: " << rating;
}

//Return the title of the game
char* Game::getTitle(){
	return title;
}

//Return the year of the game
int Game::getYear(){
	return year;
}

//Constructor
Game::Game(char* nTitle, char* nPublisher, int nYear, int nRating){
	title = new char[80];
     strcpy(title, nTitle);
     publisher = new char[80];
	strcpy(publisher, nPublisher);
	rating = nRating;
	year = nYear;
}
//Deconstructor
Game::~Game(){
     delete title;
     delete publisher;

}
