/*
*	CSC 340
*
*	Project 2 Q3
*
*	Kamran Khadivi-Dimbali July 2017
*
*
*/


#include <iostream>
#include <fstream>

using namespace std;

int main(){

	int myArray[10000];;
	int numPlacementPosition = (5*6000);
	fstream file("file1.txt");
	int count = 0;

	if(!file.is_open()){
	  cout << "File failed to open" << endl;
	  exit(1);
	}

	int currentPosition = file.tellg();
	
	file >> myArray[count];
	
	while(!file.fail()){
		count++;
		file >> myArray[count];
	}

	file.clear();
	file.seekp(numPlacementPosition);

	for(int i = 7777; i < 7782; i++){
		file << i << endl;
	}

	for(int i = 0; i < count; i++){
		file << myArray[i] << endl;
	}

	file.close();
	return 0;

}
