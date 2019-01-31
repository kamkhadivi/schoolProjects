/*
*
*	CSC 340
*	Project 2 Q2
*
*	Kamran Khadivi-Dimbali July 2017
*
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void mergeFiles(ifstream& first, ifstream& second, ofstream& newf);

int main()
{
	ifstream firstFile, secondFile;
	ofstream newFile;
	string firstFileName, secondFileName, newFileName;
	
	cout << "Enter the name of the first file: ";
	cin >> firstFileName;
	cout << "Enter the name of the second file: ";
	cin >> secondFileName;
	cout << "Enter the name of the new file: ";
	cin >> newFileName;

	//check to see if files exist
	firstFile.open(firstFileName);
	if(firstFile.fail()){
		cout << firstFileName << " has failed to open" << endl;
		system("pause");
		exit(1);
	}

	secondFile.open(secondFileName);
	if(secondFile.fail()){
		cout << secondFileName << " has failed to open" << endl;
		system("pause");
		exit(1);
	}
	
	newFile.open(newFileName);
	if(newFile.fail()){
		cout << newFileName << " has failed to open" << endl;
		system("pause");
		exit(1);
	}

	//call to functino which will merge the files into a new file
	mergeFiles(firstFile, secondFile, newFile);

	

     return 0;
}

void mergeFiles(ifstream& first, ifstream& second, ofstream& newf)
{	
	int x, y;
	
	first >> x;
	second >> y;

	//loop to test the first number in each file to see which is bigger
	while(!first.eof() && !second.eof())
	{
		if(x <= y){
		  newf << x << endl;
		  first >> x;
		}
		else{
	 	  newf << y << endl;
		  second >> y;
		}		
	}
	
	//determines which int should go next in the new file (we want ascending order)
	if(x <= y){
		while(!second.eof()){
		  newf << y << endl;
		  second >> y;
		}	
	}
	else{
		while(!first.eof()){
		  newf << x << endl;
		  first >> x;
		}
	}
}
