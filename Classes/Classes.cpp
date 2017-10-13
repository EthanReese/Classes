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

}

//Function to make char arrays to lower case
void toLowerCase(char (&arr)[7]){
	//Loop through the character array and make every item lowercase
	for(int i = 0; i < 7; i++){
		arr[i] = tolower(arr[i]);
	}

}

