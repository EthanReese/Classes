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
int searchMedia(vector<Media*> &media);
void deleteMedia(vector<Media*> &media);


int main(){
	//Create the master vector of media pointers
	vector<Media*> media;
	//Make character arrays that define the command words
	char add[7] = "add";
	char search[7] = "search";
	char del[7] = "delete";
	char quit[7] = "quit";
	//Loop through infinitely until the user decides it is time to quit
	while(true){
		//Prompt the user to put in a command
		cout << "Please enter one of the command words: Add, Search, Delete, or Quit: ";
		char input[7];
		cin >> input;
		toLowerCase(input);
		//If the input is add then it needs to run that function
		if (strcmp(input, add) == 0){
               //I could probably make a way with a while loop to make sure that the input is correct
			addMedia(media);
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
     return 1;

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
     //Make the input lowercase
     toLowerCase(input);
	//Take the input for all of the fields
	if(strcmp(input, "movie") == 0){
		//TODO: Maybe think about adding some try catches for the input
          cout << "Title: ";
		char* title = new char[80];
          cin.ignore();
		cin.getline(title, 80);
		cout << "Year: ";
		int year;
		cin >> year;
          cin.ignore();
		cout << "Rating: ";
		int rating;
		cin >> rating;
          cin.ignore();
		cout << "Duration: ";
		int duration;
		cin >> duration;
          cin.ignore();
		cout << "Director: ";
		char* director = new char[80];
		cin.getline(director, 80);
		Movie *movie = new Movie(title, director, year, rating, duration);
		media.push_back(movie);
          delete[] title;
          delete[] director;
		cout << "Movie Created." << endl;
		return 0;
	}
	//Take the input for all of the fields
	else if(strcmp(input, "game") == 0){
		//TODO: Maybe think about adding some try catches for the input
		cout << "Title: ";
		char* title = new char[80];
          cin.ignore();
		cin.getline(title, 80);
		cout << "Year: ";
		int year;
		cin >> year;
          cin.ignore();
		cout << "Rating: ";
		int rating;
		cin >> rating;
          cin.ignore();
		cout << "Publisher: ";
		char* publisher = new char[80];
		cin.getline(publisher, 80);
		Game *game = new Game(title, publisher, year, rating);
		media.push_back(game);
          delete[] publisher;
          delete[] title;
		cout << "Game Created." << endl;
		return 0;
	}
	//Take the input for all of the fields
	else if(strcmp(input, "music") == 0){
		//TODO: Maybe think about adding some try catches for the input
		cout << "Title: ";
		char* title = new char[80];
          cin.ignore();
		cin.getline(title, 80);
		cout << "Artist: ";
		char* artist = new char[80];
		cin.getline(artist, 80); 
		cout << "Year: ";
		int year;
		cin >> year;
          cin.ignore();
		cout << "Duration: ";
		int duration;
		cin >> duration;
          cin.ignore();
		cout << "Publisher: ";
		char* publisher = new char[80];
		cin.getline(publisher, 80);
		Music *music = new Music(title, artist, publisher, duration, year);
		media.push_back(music);
		cout << "Music Created." << endl;
          delete[] publisher;
          delete[] artist;
          delete[] title;
		return 0;
	}
     cout << "That's not a type of input";
     return 1;

}
int searchMedia(vector<Media*> &media){
     //Get input on whether they want to search by the year or by the title of the media     
     cout << "Would you like to search by the year or the title? ";
     char input[7];
     cin >> input;
     cin.ignore(1000, '\n');
     toLowerCase(input);
     int test = 0;
     //Year sequence
     if(strcmp(input, "year") == 0){
          cout << "What year do you want to search for?";
          int year;
          cin >> year;
          //Loop over all the items in the media vector and check their year to see if they should be printed out
          for(int i = 0; i < media.size(); i++){
               //If the media is the right year then it needs to print out the media that it found there
               if(media.at(i)->getYear() == year){
                    media.at(i)->printStuff();
                    cout << endl;
                    test = 1;
               }
          }
          //If there still aren't any results then it needs to communicate that
          if(test == 0){
               cout << "No results found" << endl;
          }
          return 0;
     }
     //Title Sequence
     else if(strcmp(input, "title") == 0){
          cout << "What title do you want to search for? "<< endl;
          char* titleIn = new char[80];
          cin.getline(titleIn, 80); 
          //Loop over all the items in the media vector and check their title to see if they should be printed out
          for(vector<Media*>::iterator it = media.begin(); it != media.end(); ++it){
               //If the media has the right title then it needs to be printed out
               if(strcmp(titleIn, (*it)->getTitle()) == 0){ 
                         (*it)->printStuff();
                         cout << endl;
                         test = 1;
               }
          }
          //If there still aren't any results then it needs to communicate that
          if(test == 0){
               cout << "No results found" << endl;
          }
          delete[] titleIn;
          return 0;
     }
     cout << "Please enter either title or year";
     return 1;
}
//Function to delete a media item from the library
void deleteMedia(vector<Media*> &media){ 
     //Get input on whether they want to search by the year or by the title of the media     
     cout << "Would you like to find titles to delete by the year or the title? ";
     char input[7];
     cin >> input;
     cin.ignore(1000, '\n');
     toLowerCase(input);
     int test = 0;
     int counter = 0;
     //Year sequence
     if(strcmp(input, "year") == 0){
          cout << "What year do you want to delete by?";
          int year;
          cin >> year;
          //Loop over all the items in the media vector and check their year to see if they should be printed out
          for(int i = 0; i < media.size(); i++){
               //If the media is the right year then it needs to print out the media that it found there
               if(media.at(i)->getYear() == year){
                    media.at(i)->printStuff();
                    //Confirm that the user would actually like to delete the media.
                    cout << "Would you like to delete this item(y/n)?";
                    char checker;
                    cin >> checker;
                    if(tolower(checker)== 'y'){
                         cout << "Working";
                         //Delete the object and release the memory.
                         delete media.at(i);
                         media.erase(media.begin() +i);
                    }
                    cout << endl;
                    test = 1;
               }
          }
          //If there still aren't any results then it needs to communicate that
          if(test == 0){
               cout << "No results found" << endl;
               return;
          }
          return;
     }
     //Title Sequence
     else if(strcmp(input, "title") == 0){
          cout << "What title do you want to search for? "<< endl;
          char* titleIn = new char[80];
          cin.getline(titleIn, 80); 
          //Loop over all the items in the media vector and check their title to see if they should be printed out 
          for(int i = 0; i < media.size(); i++){
               //If the media is the right year then it needs to print out the media that it found there
               if(strcmp(media.at(i)->getTitle(), titleIn) == 0){
                    media.at(i)->printStuff();
                    //Confirm that the user would actually like to delete the media.
                    cout << endl << "Would you like to delete this item(y/n)?";
                    char checker;
                    cin >> checker;
                    if(tolower(checker)== 'y'){
                         //Delete the object and release the memory.
                         delete media.at(i);
                         media.erase(media.begin() +i);
                    }
                    cout << endl;
                    test = 1;
               }
          }
          //If there still aren't any results then it needs to communicate that
          if(test == 0){
               cout << "No results found" << endl;
          }
          delete[] titleIn;
          return;
     }
     cout << "Please enter either title or year";
     return;



}
