#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

using namespace std;

class Media{
	public:
		virtual int getType();
          virtual void printStuff();
          virtual char* getTitle();
          virtual int getYear();
          virtual ~Media();
	private:	
		int year;
          char* title;
};

#endif
