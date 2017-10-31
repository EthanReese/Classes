#include <iostream>
#include "Media.h"

using namespace std;

//Return what type of media it is
int Media::getType(){
	return 0;
}
int Media::getYear(){
     return year;
}
char* Media::getTitle(){
     return title;
}
void Media::printStuff(){
     cout << "Why is this running?";
}
Media::~Media(){

}
