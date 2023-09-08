//Assignment 6, by Leonardo Blas

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


// ------------------ the main method ---------------------------------
int  main()
{
   //instantiating TripleString objects
   TripleString object1, object2, object3, object4;

   //assigning values to objects
   object1.setString1("I");
   object1.setString2("like");
   object1.setString3("doggies");

   object2.setString1("and I");
   object2.setString2("like");
   object2.setString3("cooking, horses, coding, and hanging out with friends" 
                      " too");

   object3.setString1("");
   object3.setString2("");
   object3.setString3("");

   object4.setString1("");
   object4.setString2("");
   object4.setString3("");

   
   //displaying (first time)
   cout << "\n";
   cout << INDENTATION + "Displaying objects' members (first time):\n\n";
   cout << INDENTATION + "Object 1:\n";
   cout << INDENTATION + object1.toString() + "\n\n";
   cout << INDENTATION + "Object 2:\n";
   cout << INDENTATION + object2.toString() + "\n\n";
   cout << INDENTATION + "Object 3:\n";
   cout << INDENTATION + object3.toString() + "\n\n";
   cout << INDENTATION + "Object 4:\n";
   cout << INDENTATION + object4.toString() + "\n\n\n";

   //mutating
   object1.setString2("love");
   object2.setString3("horses");
   object3.setString1("hot tea");
   object4.setString1("nope");

   //displaying (second time)
   cout << INDENTATION + "Displaying objects' members (second time):\n\n";
   cout << INDENTATION + "Object 1:\n";
   cout << INDENTATION + object1.toString() + "\n\n";
   cout << INDENTATION + "Object 2:\n";
   cout << INDENTATION + object2.toString() + "\n\n";
   cout << INDENTATION + "Object 3:\n";
   cout << INDENTATION + object3.toString() + "\n\n";
   cout << INDENTATION + "Object 4:\n";
   cout << INDENTATION + object4.toString() + "\n\n\n";

   //mutators test 1
   string testString1 = "puppers";
   object1.setString3(testString1);

   cout << INDENTATION + "Mutators test 1:\n";
   
   if (object1.getString3() == testString1)
      cout << INDENTATION + "The mutators made a change!\n\n\n";
   else
      cout << INDENTATION + "The mutators didn't make any change!\n\n\n";

   //mutators test 2
   string testString2 = "";
   object2.setString2(testString2);

   cout << INDENTATION + "Mutators test 2:\n";

   if (object2.getString2() == testString2)
      cout << INDENTATION + "The mutators made a change!\n\n\n";
   else
      cout << INDENTATION + "The mutators didn't make any change!\n\n\n";

   //accessors call test 1
   object1.setString3("pupperinos");

   cout << INDENTATION + "Accessor call test 1:\n";
   cout << INDENTATION + object1.getString3() + "\n\n\n";

   //accessors call test 2
   object3.setString2("Mountain View");

   cout << INDENTATION + "Accessor call test 1:\n";
   cout << INDENTATION + object3.getString2();

   return 0;
}
//------------------------------------------------------------------------------

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
   string reportMembers = "String 1, 2, and 3: " + getString1() + ", " + getString2() +
                          ", " + getString3() + ".";
   return reportMembers;
}

/*---------------------- TEST RUN --------------------------------


   Displaying objects' members (first time):

   Object 1:
   String 1, 2, and 3: I, like, doggies.

   Object 2:
   String 1, 2, and 3: and I, like,  (undefined) .

   Object 3:
   String 1, 2, and 3:  (undefined) ,  (undefined) ,  (undefined) .

   Object 4:
   String 1, 2, and 3:  (undefined) ,  (undefined) ,  (undefined) .


   Displaying objects' members (second time):

   Object 1:
   String 1, 2, and 3: I, love, doggies.

   Object 2:
   String 1, 2, and 3: and I, like, horses.

   Object 3:
   String 1, 2, and 3: hot tea,  (undefined) ,  (undefined) .

   Object 4:
   String 1, 2, and 3: nope,  (undefined) ,  (undefined) .


   Mutators test 1:
   The mutators made a change!


   Mutators test 2:
   The mutators didn't make any change!


   Accessor call test 1:
   pupperinos


   Accessor call test 1:
   Mountain View

---------------------- TEST RUN --------------------------------*/