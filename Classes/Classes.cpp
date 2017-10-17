/*
 * c++ program that uses classes to manage media items
 * Created by: Ethan Reese
 * October 11, 2017
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include "Media.h"
#include "Movie.h"
#include "Game.h"
#include "Music.h"

//Define the constants for the type of media
#define UNDEFINED 0
#define MOVIE 1
#define MUSIC 2
#define GAME 3

using namespace std;

int addMedia(vector<Media*> &media);
void toLowerCase(char (&arr)[7]);
void searchMeia(vector<Media*> &media);
void deleteMedia(vector<Media*> &media);


int main(){
	//Create the master vector of media pointers
	vector<Media*> &media;
	//Make character arrays that define the command words
	char add[7] = "add";
	char search[7] = "search";
	char del[7] = "delete";
	char quit[7] = "quit";
	//Loop through infinitely until the user decides it is time to quit
	while(true){
		//Prompt the user to put in a command
		cout << "Please enter one of the command words: Add, Print, Delete, or Quit: ";
		char input[7];
		cin >> input;
		toLowerCase(input);
		//If the input is add then it needs to run that function
		if (strcmp(input, add) == 0){
			addMedia(media) == 1;
		}
		else if(strcmp(input, del) == 0){
			deleteMedia(media);
		}
		else if(strcmp(input, search) == 0){
			searchMedia(media);
		}
		else if(strcmp(input, quit) == 0){
			return 0;
		}
		else{
			cout << "Invalid input, please pick one of the command words";
		}
	}

}

//Function to make char arrays to lower case
void toLowerCase(char (&arr)[7]){
	//Loop through the character array and make every item lowercase
	for(int i = 0; i < 7; i++){
		arr[i] = tolower(arr[i]);
	}

}
//Make new media
int addMedia(vector<Media*> &media){
	//Check with the user about what kind of media they want to add
	cout << "What kind of media would you like to add (movie, music or game)?" << endl;
	char input[7];
	cin >> input;
	//Take the input for all of the fields
	if(strcmp(input, "movie") == 0){
		//TODO: Maybe think about adding some try catches for the input
		cout << "Title: ";
		cin >> char* title;
		cout << endl << "Year: ";
		int year;
		cin >> year;
		cout << endl << "Rating: ";
		int rating;
		cin >> rating;
		cout << endl << "Duration: ";
		int duration;
		cin >> duration;
		cout << endl << "Director: ";
		char* director;
		cin >> director;
		Movie *movie = new Movie(title, director, year, rating, duration);
		media->push_back(movie);
		cout << endl << "Movie Created.";
		return 0;
	}
	//Take the input for all of the fields
	else if(strcmp(input, "game") == 0){
		//TODO: Maybe think about adding some try catches for the input
		cout << "Title: ";
		cin >> char* title;
		cout << endl << "Year: ";
		int year;
		cin >> year;
		cout << endl << "Rating: ";
		int rating;
		cin >> rating;
		cout << endl << "Publisher: ";
		char* publisher;
		cin >> publisher;
		Game *game = new Game(title, publisher, year, rating);
		media->push_back(game);
		cout << endl << "Game Created.";
		return 0;
	}
	//Take the input for all of the fields
	else if(strcmp(input, "music") == 0){
		//TODO: Maybe think about adding some try catches for the input
		cout << "Title: ";
		cin >> char* title;
		cout << "Artist: ";
		char* artist;
		cin >> artist;
		cout << endl << "Year: ";
		int year;
		cin >> year;
		cout << endl << "Duration: ";
		int duration;
		cin >> duration;
		cout << endl << "Publisher: ";
		char* publisher;
		cin >> publisher;
		Music *music = new Music(title, artist, publisher, duaration, year);
		media->push_back(music);
		cout << endl << "Music Created.";
		return 0;
	}

}
