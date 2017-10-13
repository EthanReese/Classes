#include <iostream>
#include "Movie.h"


using namespace std;

//Return that it is a movie
int Movie::getType(){

	return 1;
}

//Print out all the relevant information about the movie
void Movie::printStuff(){
	cout << "Movie: " << title;
	cout << endl << "Year: " << year;
	cout << endl << "Rating: " << rating;
	cout << endl << "Running Time: " << duration;
	cout << endl << "Directed by: " << director;
}
//Constructor
Movie::Movie(char[20]*  newtitle, char[20]* newdirector, int newyear, int newrating, int newduration){
	title = newtitle;
	director = newdirector;
	year = newyear;
	rating = newrating;
	duration = newduration; 
}
//Get the title of the movie
char[20]* Movie::getTitle(){
	return title;
}
int Movie::getYear(){
	return year;
}
