//
//  main.cpp
//  CSC340#1Pt2
//  Problem #2
//  Created by Kamran Khadivi-Dimbali on 6/22/17.
//
//

#include <iostream>
#include <vector>
using namespace std;

struct TokenFreq{
    string token;
    int freq;
};


//Defines the function getLeastFreqLetter()
void getLeastFreqLetter(string s)
{
    //Array for characters frequency
    int freqArray[27] = {0};
 
    for(int i = 0; i < s.size(); ++i)
    {
        //check for upper case values
        if(s[i] >= 65 && s[i] <= 90)
        {

            s[i] += s[i] + 32;
        }
        //assigns to array
        if(s[i] >= 97 && s[i] <= 122)
        {
           
            freqArray[s[i] - 97]++;
        }
    }

    int lowNum = 0;
    //for loop to find least frequent
    for(int count = 1; count < 26; ++count)
    {
        if(freqArray[lowNum] > freqArray[count]){
            lowNum = count; //lowNum contains asquii number - 97 for the least frequent letter and can access frequency by freqArray
        }
    }
    
}

vector<TokenFreq> getTokenFreq(string& s){
    
    
        int tokenNum=0;
        vector<TokenFreq> TFreq;
        string token="";
    
        TFreq.push_back(TokenFreq());
        int num=0; //num used for frequency
    
        //loop to find special characters
        for(int count=0;count<s.length();count++)
        {
    
            if(s[count]==' ' || s[count]==',' || s[count]=='.' ||s[count]==';' || s[count]==':')
            {
                num=0;
                //goes through loop get frequency and sets token to "" to get rid of special char
                for(int i = 0; i<TFreq.size(); i++)
                {
                    if(TFreq[i].token==token)
                    {
                        TFreq[i].freq++;
                        num=1;
                        token="";
                    }
                }
            
                if(num==0) //sets vector token/frequency
                {
                    TFreq[tokenNum].token=token;
                    TFreq[tokenNum].freq=1;
                    tokenNum++;
                    TFreq.push_back(TokenFreq());
                    token="";
                }
            }
            else //if not a special char, puts back into the string
            {
                token=token+s[count];
            }
        }
    
        num=0;
        //loop for non-special characters to create vector, "deletes" vector by setting to ""
        for(int it = 0; it<TFreq.size(); it++)
        {
          
            if(TFreq[it].token==token)
            {
                TFreq[it].freq++;
                num=1;
                token="";
            }
            
        }

        //print results
        for(int i = 0; i < TFreq.size()-1; i++)
        {
            if(i == 0)
                cout << "{ ";
            cout<< "'" << TFreq[i].token<< "': "<< TFreq[i].freq;
            if(i != TFreq.size()-2)
                cout << ", ";
            if(i == TFreq.size()-2)
                cout << " }";
        }
 
    
    return TFreq;
    
}



int main(){

    string s;
    vector<TokenFreq> freak1;

    //get user input
    cout<<"Enter the paragraph:"<<endl;
    getline(cin,s);
    
    
    freak1=getTokenFreq(s);

    getLeastFreqLetter(s);

    return 0;

}
