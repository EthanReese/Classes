#include <cstdlib>
#include <iostream>
#include "Music.h"
#include <cstring>


using namespace std;

//Return that it is music
int Music::getType(){
	return 2;
}

//Print out all the relevant information about the song
void Music::printStuff(){
	cout << "Song: " << title;
	cout << endl << "Year: " << year;
	cout << endl << "Artist: " << artist;
	cout << endl << "Length: " << duration;
	cout << endl << "Published by: " << publisher;
}
//Constructor
Music::Music(char*  newtitle, char* newArtist, char* newPublisher, int newDuration, int newYear){
	title = new char[80];
     strcpy(title, newtitle);
     artist = new char[80];
	strcpy(artist, newArtist);
     publisher = new char[80];
	strcpy(publisher, newPublisher);
	year = newYear;
	duration = newDuration; 
}
//Get the title of the song
char* Music::getTitle(){
	return title;
}
//Get the year of the song
int Music::getYear(){
	return year;
}
//Deconstructor
Music::~Music(){
     delete title;
     delete artist;
     delete publisher;
}
