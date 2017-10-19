#include <cstdlib>
#include <iostream>
#include "Music.h"


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
Music::Music(char[20]*  newtitle, char[20]* newArtist, char[20]* newPublisher, int newDuration, int newYear){
	title = newtitle;
	artist = newArtist;
	publisher = newPublisher;
	year = newYear;
	duration = newDuration; 
}
//Get the title of the song
char[20]* Music::getTitle(){
	return title;
}
//Get the year of the song
int Music::getYear(){
	return year;
}
