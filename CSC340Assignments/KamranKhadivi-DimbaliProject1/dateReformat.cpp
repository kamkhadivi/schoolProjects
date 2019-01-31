//
//
//  CSC340Project#1
//  Promblem #1
//  Created by Kamran Khadivi-Dimbali on 6/20/17.
//
//


#include <iostream>
#include <string>
using namespace std;

struct  date //creates a date structure
{
    int day;
    int pos;
    string dateString;
    int nextPos;
    string month;
    string temp;
    int year;
};

string reformatDate(int day, int pos, string dateString, int nextPos, string month, string temp, int year) //reformats the input date
{


    string currMonth = month;
    string newDay;
    int currDay= day;
    int currYear = year;
    
    if(currMonth.compare("Jan") == 0)
        currMonth = "01";
    else if(currMonth.compare("Feb") == 0)
        currMonth = "02";
    else if(currMonth.compare("Mar") == 0)
        currMonth = "03";
    else if(currMonth.compare("Apr") == 0)
        currMonth = "04";
    else if(currMonth.compare("May") == 0)
        currMonth= "05";
    else if(currMonth.compare("Jun") == 0)
        currMonth = "06";
    else if(currMonth.compare("Jul") == 0)
        currMonth = "07";
    else if(currMonth.compare("Aug") == 0)
        currMonth = "08";
    else if(currMonth.compare("Sep") == 0)
        currMonth = "09";
    else if(currMonth.compare("Oct") == 0)
        currMonth = "10";
    else if(currMonth.compare("Nov") == 0)
        currMonth = "11";
    else if(currMonth.compare("Dec") == 0)
        currMonth = "12";
    if(currDay == 1)
        newDay = "01";
    else if(currDay == 2)
        newDay = "02";
    else if(currDay == 3)
        newDay = "03";
    else if(currDay == 4)
        newDay = "04";
    else if(currDay == 5)
        newDay = "05";
    else if(currDay == 6)
        newDay = "06";
    else if(currDay == 7)
        newDay = "07";
    else if(currDay == 8)
        newDay = "08";
    else if(currDay == 9)
        newDay = "09";
    else
        newDay = to_string(currDay);
    
    string output = to_string(currYear) + " - " + currMonth + " - " + newDay;
    return output;
}
int main()
{
    string inputDate;
    cout << "Enter the date in the following format: 1st Mar 1984 ==> ";
    getline(cin, inputDate);
    
    int currDay = stoi (inputDate, nullptr, 10);
    int shift1 = inputDate.find(" ");
    string newDay;
    inputDate = inputDate.substr(shift1+1);
    int shift2 = inputDate.find(" ");
    string currMonth = inputDate.substr(0, shift2);
    string currTemp = inputDate.substr(shift2+1);
    int currYear = stoi(currTemp, nullptr, 10);
    
    date olderDate; //creates olderDate struct
    olderDate.day = currDay;
    olderDate.pos = shift1;
    olderDate.dateString = inputDate;
    olderDate.nextPos = shift2;
    olderDate.month = currMonth;
    olderDate.temp = currTemp;
    olderDate.year = currYear;
    
    cout << "The date reformatted is ==> " << reformatDate(olderDate.day,  olderDate.pos, olderDate.dateString, olderDate.nextPos, olderDate.month, olderDate.temp, olderDate.year) << endl;
   
}





