//Assignment 5, by Leonardo Blas.
//General comment: this program uses exclusively the getline() input mechanism.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//methods' prototypes
string getString();
char getKeyCharacter();
string maskCharacter(string theString, char keyCharacter);
string removeCharacter(string theString, char keyCharacter);
int countKey(string theString, char keyCharacter);

//only global constant, indentation
const string INDENTATION = "   ";

int main()
{
   char characterino;
   int totalCharactersCount;
   string stringerino;
   string asteriskMaskedString;
   string removeMaskedString;
   
   //method calls; assigning return values to variables
   stringerino = getString();
   characterino = getKeyCharacter();
   asteriskMaskedString = maskCharacter(stringerino, characterino);
   removeMaskedString = removeCharacter(stringerino, characterino);
   totalCharactersCount = countKey(stringerino, characterino);

   //menu
   cout << INDENTATION + "String with key character, '" << characterino 
        << "', masked:\n";
   cout << INDENTATION + asteriskMaskedString + "\n\n";
   cout << INDENTATION + "String with key character, '" << characterino 
        << "', removed.\n";
   cout << INDENTATION + removeMaskedString + "\n\n";
   cout << INDENTATION + "Number of occurrences of key character, '"
        << characterino << "':\n";
   cout << INDENTATION << totalCharactersCount;
}

string getString()
{
   string inputString;
   //initialize for loop accumulator
   int x;
   //initialize checking mechanism's range
   const int MIN_CHARACTERS = 6;

   //loop for reprompting until obtaining a valid string input
   while(true)
   {
      //menu
      cout << "\n" + INDENTATION + "Please enter a phrase or sentence of at"
         " least " << MIN_CHARACTERS << " characters:\n";
      cout << INDENTATION;

      //get string from user input
      getline(cin, inputString);

      cout << "\n";

      //count and accumulate characters
      for (x = 0; inputString[x] != '\0'; x++)
      {
      }

      //check accumulator
      if (x >= MIN_CHARACTERS)
      {
         break;
      }
   }
   //string as functional return
   return inputString;
}

char getKeyCharacter()
{
   //Because we used getline() before, we cannot use cin.
   //We will be using getline() and testing for string lenght = 1.

   string inputString;
   //initialize for loop accumulator
   int x;
   //initialize checking mechanism's range
   const int CHARACTER_LENGHT = 1;

   //loop for reprompting until obtaining a valid character input
   while (true)
   {
      //menu
      cout << INDENTATION + "Please enter a single character to act as key:\n";
      cout << INDENTATION;

      //get character from user input
      getline(cin, inputString);

      cout << "\n";

      //count and accumulate characters
      for (x = 0; inputString[x] != '\0'; x++)
      {
      }

      //check accumulator
      if (x == 1)
      {
         break;
      }
   }
   //transforming 1-character long string into a character
   char inputCharacter;
   inputCharacter = inputString[0];

   //character as functional return
   return inputCharacter;
}

string maskCharacter(string theString, char keyCharacter)
{
   //initialize for loop accumulator
   int x;
   //initialize string intermediary
   string stringIntermediary;
   //initialize key's replacement
   const char replacementCharacter = '*';

   //check every character in the string
   for (x = 0; theString[x] != '\0'; x++)
   {
      //glue characters together on the intermediary string
      if (theString[x] == keyCharacter) 
      {
         stringIntermediary += replacementCharacter;
      }
      else if (theString[x] != keyCharacter)
      {
         stringIntermediary += theString[x];
      }
   }
   //string as functional return
   return stringIntermediary;
}

string removeCharacter(string theString, char keyCharacter)
{
   //initialize for loop accumulator
   int x;
   //initialize string intermediary
   string stringIntermediary;

   //check every character in the string
   for (x = 0; theString[x] != '\0'; x++)
   {
      //glue the non-keyCharacter characters; assign value to intermediary
      if (theString[x] != keyCharacter)
      {
         stringIntermediary += theString[x];
      }
   }
   //string as functional return
   return stringIntermediary;
}

int countKey(string theString, char keyCharacter)
{
   //initialize for loop accumulators
   int x;
   int y = 0;

   //count and accumulate characters
   for (x = 0; theString[x] != '\0'; x++)
   {
      //store accumulator information on y
      if (theString[x] == keyCharacter)
      {
         y++;
      }
   }
   //int as functional return
   return y;
}
/*-----------------------------------TEST RUN 1------------------------------------
   
   Please enter a phrase or sentence of at least 6 characters:
   leonardo

   Please enter a single character to act as key:
   o

   String with key character, 'o', masked:
   le*nard*

   String with key character, 'o', removed.
   lenard

   Number of occurrences of key character, 'o':
   2

--------------------------------------TEST RUN 2------------------------------------

   Please enter a phrase or sentence of at least 6 characters:
   no


   Please enter a phrase or sentence of at least 6 characters:
   okey


   Please enter a phrase or sentence of at least 6 characters:
   hello doggerinos!

   Please enter a single character to act as key:
   g

   String with key character, 'g', masked:
   hello do**erinos!

   String with key character, 'g', removed.
   hello doerinos!

   Number of occurrences of key character, 'g':
   2

--------------------------------------TEST RUN 3------------------------------------

   Please enter a phrase or sentence of at least 6 characters:
   $$$$$$$$$$$$$$$$$!^�$%^"$%^

   Please enter a single character to act as key:
   $

   String with key character, '$', masked:
   *****************!^�*%^"*%^

   String with key character, '$', removed.
   !^�%^"%^

   Number of occurrences of key character, '$':
   19

--------------------------------------TEST RUN 4------------------------------------

   Please enter a phrase or sentence of at least 6 characters:
   happy HALLOWeEn!

   Please enter a single character to act as key:
   E

   String with key character, 'E', masked:
   happy HALLOWe*n!

   String with key character, 'E', removed.
   happy HALLOWen!

   Number of occurrences of key character, 'E':
   1

-----------------------------------TEST RUN 4-------------------------------------*/