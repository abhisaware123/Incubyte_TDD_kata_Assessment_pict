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
                if(FirstPart.size())
                    Numbers.push_back(stoi(FirstPart));
                FirstPart="";

            }
            else if (givenString[index] >= 'a' and givenString[index]<='z')
            {
                Numbers.push_back((givenString[index] - 'a')+1);
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
        // else if(Numbers.size()==1)  // if only one element is there in the String the directly returning it
        // {
        //     return Numbers[0];
        // }
        //case 3 solving
        // else if(Numbers.size()==2)                       // Adding the 2 Numbers in the string
        // {
        //     return Numbers[0]+Numbers[1];
        // }
        //case 4 and 5
        else{
            int sum=0;
            for(int num:Numbers) //looping to all the element i.e. unknown amount of elements 
            {
                try
                {
                    /* code */
                    if(num<0)
                    {
                        throw num;
                    }
                    sum += num;
                }
                catch(int num)
                {
                    cout <<"Negatives not allowed ";
                    return num; 
                }
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

    // Testing the code for sample tests
    //cases 1
    cout << Calculator.CalculateString("") << endl;
    // cases 2
    cout << Calculator.CalculateString("123") << endl;
    // cases 3
    cout << Calculator.CalculateString("123,23") << endl;

    // Adding Test Cases for Case 4
    string Str = "123,23,23,43,54,232";
    cout << Calculator.CalculateString(Str) << endl;

    // Adding Test Cases for Case 5
    string Str1 = "123,a,b";
    cout << Calculator.CalculateString(Str1) << endl;

    // Adding Test Cases for Case 6 for a negative number
    string Str2 = "123,-2";
    cout << Calculator.CalculateString(Str2) << endl;

    return 0;
}

//testcases to be handeled