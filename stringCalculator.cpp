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
            if(givenString[index]==',')
            {
                Numbers.push_back(stoi(FirstPart));
                cout<<FirstPart<<" -> ";
                FirstPart="";

            }
            else {
                FirstPart+=givenString[index];
            }
        }
        if(FirstPart.size())
                Numbers.push_back(stoi(FirstPart));
        return Numbers.size();

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

    return 0;
}

//testcases to be handeled