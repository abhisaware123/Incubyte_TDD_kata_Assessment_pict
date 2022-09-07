#include<bits/stdc++.h>
using namespace std;

class stringCalulationClass
{
    private:

    public:

    int CalculateString(string givenString)
    {

        string s1="";
        int sizeOfString=givenString.size();
        vector<int>Numbers;
        // lets divide the string into equal parts possible for calculation
        int index=0;
        string FirstPart="",SecondPart="";

        for(index=0;index<sizeOfString;index++)
        {
            if(givenString[index]==',') {
                
                Numbers.push_back(stoi(FirstPart));
                FirstPart="";

            }
            else if (givenString[index] >= 'a' and givenString[index]<='z')
            {
                if (!isdigit(FirstPart[0]))
                {
                    Numbers.push_back((FirstPart[0] - 'a') + 1);
                }
            }   
            else
            {
                FirstPart += givenString[index];
            }
        }
        if(FirstPart.size()) {
                Numbers.push_back(stoi(FirstPart));
        }

        //Case 1 Solving 
        if(Numbers.size()==0)       //if no number found in the string then return 0
        {
            return 0;
        }
        //case 2 solving
        else if(Numbers.size()==1)  // if only one element is there in the String the directly returning it
        {
            return Numbers[0];
        }
        //case 3 solving
        else if(Numbers.size()==2)                       // Adding the 2 Numbers in the string
        {
            return Numbers[0]+Numbers[1];
        }
        else{
            int sum=0;
            for(int num:Numbers) //looping to all the element i.e. unknown amount of elements 
            {
                sum+=num;
            }
            return sum;  //returning sum of all possible elements

        }

    }
};

int main()
{
    //creating object of class
    stringCalulationClass Calculator;

    //taking the input from the user
    // string InputString;
    // cin>>InputString;

    // Testing the code for sample test cases
    cout << Calculator.CalculateString("") << endl;
    cout << Calculator.CalculateString("123") << endl;
    cout << Calculator.CalculateString("123,23") << endl;

    // Adding Test Cases for Case 4
    string Str = "123,23,23,43,54,232";
    cout << Str << " = " << Calculator.CalculateString(Str) << endl;

    // Adding Test Cases for Case 5
    string Str1 = "123,a,b";
    cout << Str << " = " << Calculator.CalculateString(Str1) << endl;

    return 0;
}

//testcases to be handeled