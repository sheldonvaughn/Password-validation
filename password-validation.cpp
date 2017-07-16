// This program tests a password for the American Equities
// web page to see if the format is correct

// Sheldon Vaughn

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std; 

//function prototypes 

bool testPassWord(char[]);  
int countLetters(char*);
int countDigits(char*);

int main()
{
	char passWord[20];  
	
	cout << "Enter a password consisting of exactly 5 "
		 << "letters and 3 digits:" << endl;
	cin.getline(passWord,20);

	if (testPassWord(passWord))
		cout << "Please wait - your password is being verified" << endl;
	else
	{
		cout << "Invalid password. Please enter a password "
		     << "with exactly 5 letters and 3 digits" << endl;
	    cout << "For example, my37RuN9 is valid" << endl;
	}


		int numLetters = countLetters(passWord);
		int numDigits = countDigits(passWord);

		cout << "There are " << numLetters <<" letters in the password" << endl;
		cout << "There are " << numDigits <<" digits in the password" << endl;

        bool valid = testPassWord(passWord);

        if (valid != 0)
        {
            cout << "Password Accepted" << endl;
            cout << "Your password is now: " << passWord << endl;
        }

        else
        {
            cout << passWord << " is an invalid password" << endl;
        }

	return 0;
}


//**************************************************************
//                       testPassWord
//
// task:			determines if the word contained in the
//				    character array passed to it, contains
//					exactly 5 letters and 3 digits.
// data in:			a word contained in a character array
// data returned:   true if the word contains 5 letters & 3
//					digits, false otherwise
//
//**************************************************************
bool testPassWord(char custPass[])
{
	int numLetters, numDigits, length;

	length = strlen(custPass);
    numLetters = countLetters(custPass);
	numDigits = countDigits(custPass);
	if (numLetters == 5 && numDigits == 3 && length == 8 )
		return true;
	else
		return false;
}


// the next 2 functions are from Sample Program 10.5
//**************************************************************
//                       countLetters
//
// task:			counts the number of letters (both
//                  capital and lower case in the string
// data in:			a string 
// data returned:   the number of letters in the string
//
//**************************************************************
int countLetters(char *strPtr) 
{
	int occurs = 0;

	while(*strPtr != '\0')       

	{
		if (isalpha(*strPtr))  
			occurs++;
		strPtr++;
	}

	return occurs;
}

//**************************************************************
//                       countDigits
//
// task:			counts the number of digitts in the string
// data in:			a string 
// data returned:   the number of digits in the string
//
//**************************************************************
int countDigits(char *strPtr)  // this function counts the
                               // number of digits
{  
	int occurs = 0;

	while(*strPtr != '\0')
	{
		if (isdigit(*strPtr))  // isdigit determines if
			                   // the character is a digit
			occurs++;
		strPtr++;
	}

	return occurs;
}