//Assignment 7, by Leonardo Blas
/* General comment: I am insecure about initializing variables inside an else
statement (see main function), but I believe it's a good decision */

#include <iostream>
#include <string>

using namespace std;

//class prototyping
class TripleString
{
private:
   //private members
   string string1;
   string string2;
   string string3;

   //private helper method
   bool validString(string str);

public:
   //public static constants
   static const int MAX_LEN;
   static const int MIN_LEN;
   static const string DEFAULT_STRING;

   //default constructor
   TripleString();

   //3-parameter constructor
   TripleString(string str1, string str2, string str3);

   //mutators
   bool setString1(string str1);
   bool setString2(string str2);
   bool setString3(string str3);

   //accessors
   string getString1();
   string getString2();
   string getString3();

   //return three strings of TripleString objects method
   string toString();
};

//initializing static class constants
const int TripleString::MAX_LEN = 50;
const int TripleString::MIN_LEN = 1;
const string TripleString::DEFAULT_STRING = " (undefined) ";

//only global constant, indentation
const string INDENTATION = "   ";

//global methods' prototypes
int getBet();
string randString();
TripleString pull();
int getPayMultiplier(TripleString thePull);
void display(TripleString thePull, int winnings);

//main method
int main()
{
   //loop for reprompting users
   while (true)
   {
      int bet;

      bet = getBet();

      if (bet == 0)
         break;

      else
      {
         TripleString thePull;
         int winnings;
         int multiplier;

         thePull = pull();
         multiplier = getPayMultiplier(thePull);

         winnings = bet * multiplier;

         display(thePull, winnings);
      }
   }
   return 0;
}

//global methods' definitions

//get a legal bet from user input 
int getBet()
{
   int bet;

   while (true)
   {
      cout << "\n";
      cout << INDENTATION + "Insert bet. The amount should be an integer"
         " between 1 and 50. Press 0 to exit.\n";
      cout << INDENTATION + "$";
      cin >> bet;

      if (0 <= bet && bet <= 50)
         break;
      else
         continue;
   }
   return bet;
}

//create random strings
string randString()
{
   int randomInteger;
   const int MAX_RANDOM = 1000;
   const int MIN_RANDOM = 1;
   const string SPACE = "Space";
   const string SEVEN = "7";
   const string BAR = "BAR";
   const string CHERRIES = "Cherries";
   
   //random ranges' calculations

   //Space
   const int MAX_SPACE = (0.07 * MAX_RANDOM);
   //7
   const int MAX_SEVEN = (0.15 * MAX_RANDOM) + MAX_SPACE;
   //BAR
   const int MAX_BAR = (0.38 * MAX_RANDOM) + MAX_SEVEN;
   //Cherries
   const int MAX_CHERRIES = (0.4 * MAX_RANDOM) + MAX_BAR;

   //generate random string based on rand() function
   randomInteger = rand() % MAX_RANDOM + MIN_RANDOM;
   
   if (MIN_RANDOM <= randomInteger && randomInteger <= MAX_SPACE)
      return SPACE;
   else if (MAX_SPACE < randomInteger && randomInteger <= MAX_SEVEN)
      return SEVEN;
   else if (MAX_SEVEN < randomInteger && randomInteger <= MAX_BAR)
      return BAR;
   else if (MAX_BAR < randomInteger && randomInteger <= MAX_RANDOM)
      return CHERRIES;
}

//store the random strings
TripleString pull()
{
   TripleString thePull;

   //binding 3 randString() calls to 3 string objects
   string randomString1 = randString();
   string randomString2 = randString();
   string randomString3 = randString();

   //assigning 3 strings to TripleString object's members
   thePull.setString1(randomString1);
   thePull.setString2(randomString2);
   thePull.setString3(randomString3);

   return thePull;
}

//reward certain combinations
int getPayMultiplier(TripleString thePull)
{
   //creating local variables to plug in if statements
   string str1 = thePull.getString1();
   string str2 = thePull.getString2();
   string str3 = thePull.getString3();

   //creating the same local variables as in randString()
   const string SPACE = "Space";
   const string SEVEN = "7";
   const string BAR = "BAR";
   const string CHERRIES = "Cherries";

   //case1: cherries - not cherries - any
   if (str1 == CHERRIES && str2 != CHERRIES)
      return 5;

   //case2: cherries - cherries - not cherries
   if (str1 == CHERRIES && str2 == CHERRIES && str3 != CHERRIES)
      return 15;

   //case3: cherries - cherries - cherries
   if (str1 == CHERRIES && str2 == CHERRIES && str3 == CHERRIES)
      return 30;

   //case4: bar - bar - bar
   if (str1 == BAR && str2 == BAR && str3 == BAR)
      return 50;

   //case5: 7 - 7 - 7
   if (str1 == SEVEN && str2 == SEVEN && str3 == SEVEN)
      return 100;

   //case6: else
   else
      return 0;
}

//display earnings or you lost message
void display(TripleString thePull, int winnings)
{
   cout << "\n";
   cout << INDENTATION + thePull.toString();
   
   //testing and reporting if user won or lost
   if (0 < winnings)
   {
      cout << INDENTATION + "Congratulations! You earned $";
      cout << winnings;
      cout << "\n\n";
   }
   else
   {
      cout << INDENTATION + "You lost. \n\n";
   }
}

//default constructor
TripleString::TripleString()
{
   string1 = DEFAULT_STRING;
   string2 = DEFAULT_STRING;
   string3 = DEFAULT_STRING;
}

//3-parameter constructor
TripleString::TripleString(string str1, string str2, string str3)
{
   if (!setString1(str1))
      string1 = DEFAULT_STRING;

   if (!setString2(str2))
      string2 = DEFAULT_STRING;

   if (!setString3(str3))
      string3 = DEFAULT_STRING;
}

//mutators
bool TripleString::setString1(string str1)
{
   if (validString(str1))
      string1 = str1;
   else
      return false;
}

bool TripleString::setString2(string str2)
{
   if (validString(str2))
      string2 = str2;
   else
      return false;
}

bool TripleString::setString3(string str3)
{
   if (validString(str3))
      string3 = str3;
   else
      return false;
}

//accessors
string TripleString::getString1()
{
   return string1;
}

string TripleString::getString2()
{
   return string2;
}

string TripleString::getString3()
{
   return string3;
}

//helper method
bool TripleString::validString(string str)
{
   if (str.length() <= MAX_LEN && str.length() >= MIN_LEN)
      return true;

   else
      return false;
}

//return three strings of TripleString objects method
string TripleString::toString()
{
   string reportMembers = "Your pull is: \n" + INDENTATION + getString1() + 
                          " - " + getString2() + " - " + getString3() + "\n\n";
   return reportMembers;
}

// *** I got a pull of all BARS in pulls 10 and 33 ***
// *** I got a pull of all Cherries in pulls 11, 15, 19, 30, and 36 ***
/*---------------------- TEST RUN --------------------------------

   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $-123

   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $1

   Your pull is:
   Space - BAR - BAR

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $2

   Your pull is:
   BAR - 7 - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $3

   Your pull is:
   BAR - BAR - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $4

   Your pull is:
   BAR - Cherries - 7

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $5

   Your pull is:
   BAR - Cherries - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $6

   Your pull is:
   BAR - Cherries - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $7

   Your pull is:
   Cherries - BAR - BAR

   Congratulations! You earned $35


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $8

   Your pull is:
   Cherries - Cherries - 7

   Congratulations! You earned $120


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $9

   Your pull is:
   BAR - BAR - BAR

   Congratulations! You earned $450


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $10

   Your pull is:
   Cherries - Cherries - Cherries

   Congratulations! You earned $300


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $11

   Your pull is:
   BAR - Cherries - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $12

   Your pull is:
   BAR - Cherries - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $13

   Your pull is:
   Cherries - BAR - Space

   Congratulations! You earned $65


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $14

   Your pull is:
   Cherries - Cherries - Cherries

   Congratulations! You earned $420


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $15

   Your pull is:
   BAR - BAR - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $16

   Your pull is:
   Cherries - 7 - Cherries

   Congratulations! You earned $80


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $17

   Your pull is:
   BAR - Cherries - BAR

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $18

   Your pull is:
   Cherries - Cherries - Cherries

   Congratulations! You earned $540


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $19

   Your pull is:
   Space - Cherries - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $20

   Your pull is:
   Cherries - BAR - Cherries

   Congratulations! You earned $100


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $21

   Your pull is:
   BAR - Space - 7

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $22

   Your pull is:
   Cherries - BAR - 7

   Congratulations! You earned $110


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $23

   Your pull is:
   Space - Cherries - BAR

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $24

   Your pull is:
   Cherries - BAR - Cherries

   Congratulations! You earned $120


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $25

   Your pull is:
   Cherries - Cherries - BAR

   Congratulations! You earned $375


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $26

   Your pull is:
   BAR - Space - 7

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $27

   Your pull is:
   BAR - BAR - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $28

   Your pull is:
   Cherries - 7 - Cherries

   Congratulations! You earned $140


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $29

   Your pull is:
   Cherries - Cherries - Cherries

   Congratulations! You earned $870


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $30

   Your pull is:
   BAR - Cherries - BAR

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $31

   Your pull is:
   Cherries - BAR - Cherries

   Congratulations! You earned $155


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $32

   Your pull is:
   BAR - BAR - BAR

   Congratulations! You earned $1600


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $33

   Your pull is:
   7 - 7 - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $34

   Your pull is:
   BAR - Cherries - 7

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $35

   Your pull is:
   Cherries - Cherries - Cherries

   Congratulations! You earned $1050


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $36

   Your pull is:
   Cherries - Cherries - BAR

   Congratulations! You earned $540


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $37

   Your pull is:
   Cherries - BAR - Space

   Congratulations! You earned $185


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $38

   Your pull is:
   Cherries - Cherries - 7

   Congratulations! You earned $570


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $39

   Your pull is:
   BAR - Cherries - Cherries

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $40

   Your pull is:
   BAR - 7 - BAR

   You lost.


   Insert bet. The amount should be an integer between 1 and 50. Press 0 to exit.
   $0
---------------------- TEST RUN --------------------------------*/