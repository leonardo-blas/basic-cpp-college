//Assignment 10 by Leonardo Blas
//General comment: There is array decay! See sorting by points

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Student
{
private:
   //members
   string lastName;
   string firstName;
   int totalPoints;
   static int sortKey;

   //functions
   static bool validString(string testStr);
   static bool validPoints(int testPoints);
   //helper function designed by the client
   static bool validSortKey(int key);

public:
   //members
   static const int SORT_BY_FIRST = 88;
   static const int SORT_BY_LAST = 98;
   static const int SORT_BY_POINTS = 108;
   static const string DEFAULT_NAME;
   static const int DEFAULT_POINTS = 0;
   static const int MAX_POINTS = 1000;
   static const int DEFAULT_KEY = SORT_BY_LAST;

   //constructor
   Student(string lst = DEFAULT_NAME, string fst = DEFAULT_NAME,
      int pts = DEFAULT_POINTS);

   //accessors
   string getLastName() { return lastName; }
   string getFirstName() { return firstName; }
   int getTotalPoints() { return totalPoints; }
   static int getSortKey() { return sortKey; }

   //mutators
   bool setLastName(string last);
   bool setFirstName(string first);
   bool setPoints(int pts);
   static bool setSortKey(int key);

   static int compareTwoStudents(Student firstStud, Student secondStud);
   string toString();
};

class StudentArrayUtilities
{
public:
   //members
   static const int MAX_STUDENTS = 20;

   Student theArray[MAX_STUDENTS];

   //functions
   bool addStudent(Student stud);
   Student removeStudent();
   string toString(string title);
   void arraySort();
   double getMedianDestructive();
   
private:
   //members
   int numStudents = 0;

   //functions
   bool floatLargestToTop(int top);
   void mySwap(Student &a, Student &b);
};

//static initializations
const string Student::DEFAULT_NAME = "zz-error";
int Student::sortKey = DEFAULT_KEY;

//only global constant, indentation
const string INDENT = "   ";

int main()
{
   Student myClass[]
   {
      Student("Pikachu", "Trump", 1), Student("Snorlax", "Trump", 2),
      Student("Troll", "Mate", 3), Student("Spongebob", "Trump", 4),
      Student("Burro", "Peanuts", 5), Student("Gary", "Trump", 6),
      Student("Shrek", "Trump", 7), Student("Squidward", "Trump", 8),
      Student("Farquad", "Trump", 9), Student("Mr.Krabs", "Trump", 10),
      Student("Patrick", "Trump", 11), Student("Plankton", "Trump", 12)
   };
   
   int k;
   int arraySize = sizeof(myClass) / sizeof(myClass[0]);
   Student student;
   StudentArrayUtilities myStuds;
   
   myStuds.addStudent(Student("Eric", "Cartman", 13));
   myStuds.addStudent(Student("Homer", "Simpsons", 14));
   myStuds.addStudent(Student("Scooby", "Doo", 15));

   for (k = 0; k < arraySize; k++)
      myStuds.addStudent(myClass[k]);

   cout << myStuds.toString("Before:");
   
   cout << "***Sorting by default***\n\n";
   
   myStuds.arraySort();
   cout << myStuds.toString("After:");
   
   cout << "***Sorting by first name***\n\n";

   Student::setSortKey(Student::SORT_BY_FIRST);
   myStuds.arraySort();
   cout << myStuds.toString("After:");

   cout << "***Sorting by points***\n\n";

   Student::setSortKey(Student::SORT_BY_POINTS);
   myStuds.arraySort();
   cout << myStuds.toString("After:");

   cout << INDENT + "Median of myClass: ";
   
   cout << myStuds.getMedianDestructive();
   
   cout << "\n\n";

   // various tests of removing and adding too many students
   cout << "Removal test:\n";

   for (k = 0; k < 100; k++)
   {
      student = myStuds.removeStudent();
      if (Student::compareTwoStudents(student, Student()))
         cout << INDENT + "Removed " << student.toString();
      else
      {
         cout << "\n" + INDENT + "Empty after " << k << " removes.\n";
         cout << INDENT + "The array now has 0 elements.\n\n";
         break;
      }
   }

   cout << "Adding elements test:\n";

   //k = 1 and not 0 because the last iteration won't accumulate
   for (k = 1; k < 100; k++)
   {
      if (myStuds.addStudent(Student("TEST", "TEST", 99)))
      {
         cout << INDENT + "Full after " << k << " adds.\n";
         cout << myStuds.toString("Test array:");
         break;
      }
   }
   return 0;
}

//Student functions
Student::Student(string last, string first, int points)
{
   if (!setLastName(last))
      lastName = DEFAULT_NAME;
   if (!setFirstName(first))
      firstName = DEFAULT_NAME;
   if (!setPoints(points))
      totalPoints = DEFAULT_POINTS;
}

bool Student::setLastName(string last)
{
   if (!validString(last))
      return false;
   lastName = last;
   return true;
}

bool Student::setFirstName(string first)
{
   if (!validString(first))
      return false;
   firstName = first;
   return true;
}

bool Student::setPoints(int pts)
{
   if (!validPoints(pts))
      return false;
   totalPoints = pts;
   return true;
}

bool Student::setSortKey(int key)
{
   if (!validSortKey(key))
      return false;
   sortKey = key;
   return true;
}

// could be an instance method and, if so, would take one parameter
int Student::compareTwoStudents(Student firstStud, Student secondStud)
{
   int result;

   switch (sortKey)
   {
   case SORT_BY_FIRST:
      result = firstStud.firstName.compare(secondStud.firstName);
      break;
   case SORT_BY_LAST:
      result = firstStud.lastName.compare(secondStud.lastName);
      break;
   case SORT_BY_POINTS:
      result = firstStud.totalPoints - secondStud.totalPoints;
   }

   return result;
}

string Student::toString()
{
   string resultString;
   ostringstream cnvrtFirst, cnvrtLast, cnvrtPoints;

   cnvrtFirst << firstName;
   cnvrtLast << lastName;
   cnvrtPoints << totalPoints;

   resultString = " " + cnvrtLast.str()
      + ", " + cnvrtFirst.str()
      + " points: " + cnvrtPoints.str()
      + "\n";
   return resultString;
}

bool Student::validString(string testStr)
{
   if (testStr.length() > 0 && isalpha(testStr[0]))
      return true;
   return false;
}

bool Student::validPoints(int testPoints)
{
   if (testPoints >= 0 && testPoints <= MAX_POINTS)
      return true;
   return false;
}

//helper function designed by the client
bool Student::validSortKey(int key)
{
   if (key == SORT_BY_FIRST || key == SORT_BY_LAST || key == SORT_BY_POINTS)
      return true;
   return false;
}

//StudentArrayUtilities functions
bool StudentArrayUtilities::addStudent(Student stud)
{
   theArray[numStudents] = stud;
   numStudents++;

   if (numStudents >= MAX_STUDENTS)
   {
      return true;
   }
   else
   return false;
}

Student StudentArrayUtilities::removeStudent()
{
   Student selectedForDeletion;   
   Student blankStudent = Student();

   if ((numStudents > 0)) 
   {
      selectedForDeletion = theArray[numStudents];
      theArray[numStudents] = blankStudent;
      numStudents--;
   }
   else 
   {
      selectedForDeletion = Student();
   }

   return selectedForDeletion;
}

string StudentArrayUtilities::toString(string title)
{
   string output = "";
   string returnString;

   // build the output string from the individual Students:
   for (int k = 0; k < numStudents; k++)
      output += " " + theArray[k].Student::toString();
   returnString = title + "\n" + output + "\n";
   return returnString;
}

//getMedianDestructive function
double StudentArrayUtilities::getMedianDestructive()
{
   double returnDouble = 0;
   int evenRemainder = numStudents % 2;
   int oddRemainder = numStudents % 3;
   const int EVEN_ARRAY_MIN_SIZE = 2;
   const int ODD_ARRAY_MIN_SIZE = 3;
   const int ONE_ELEMENT_ARRAY_SIZE = 1;
   int originalKey = Student::getSortKey();

   Student::setSortKey(Student::SORT_BY_POINTS);
   arraySort();

   if (numStudents == ONE_ELEMENT_ARRAY_SIZE)
      returnDouble = theArray[0].getTotalPoints();

   if (evenRemainder == 0 && numStudents >= EVEN_ARRAY_MIN_SIZE)
   {
      //consider the trailing caused by division
      int lowerMiddleIndex = (numStudents / 2);
      int upperMiddleIndex = ((numStudents / 2) + 1);
      returnDouble = (double)(theArray[lowerMiddleIndex].getTotalPoints()
         + theArray[upperMiddleIndex].getTotalPoints()) / 2;
   }

   if (oddRemainder == 0 && numStudents >= ODD_ARRAY_MIN_SIZE)
   {
      //consider the trailing caused by division
      int middleIndex = ((numStudents / 2) + 1);
      returnDouble = theArray[middleIndex].getTotalPoints();
   }

   Student::setSortKey(originalKey);

   return returnDouble;
}

void StudentArrayUtilities::arraySort()
{
   for (int k = 0; k < numStudents; k++)
      if (!floatLargestToTop(numStudents))
         return;
}

bool StudentArrayUtilities::floatLargestToTop(int top)
{
   bool changed = false;

   for (int k = 0; k < top; k++)
      if (Student::compareTwoStudents(theArray[k], theArray[k + 1]) > 0)
      {
         mySwap(theArray[k], theArray[k + 1]);
         changed = true;
      }
   return changed;
}

void StudentArrayUtilities::mySwap(Student &a, Student &b)
{
   Student temp("", "", 0);

   temp = a;
   a = b;
   b = temp;
}

/* ------------------------------ run ----------------------------
Before:
  Eric, Cartman points: 13
  Homer, Simpsons points: 14
  Scooby, Doo points: 15
  Pikachu, Trump points: 1
  Snorlax, Trump points: 2
  Troll, Mate points: 3
  Spongebob, Trump points: 4
  Burro, Peanuts points: 5
  Gary, Trump points: 6
  Shrek, Trump points: 7
  Squidward, Trump points: 8
  Farquad, Trump points: 9
  Mr.Krabs, Trump points: 10
  Patrick, Trump points: 11
  Plankton, Trump points: 12

***Sorting by default***

After:
  Burro, Peanuts points: 5
  Eric, Cartman points: 13
  Farquad, Trump points: 9
  Gary, Trump points: 6
  Homer, Simpsons points: 14
  Mr.Krabs, Trump points: 10
  Patrick, Trump points: 11
  Pikachu, Trump points: 1
  Plankton, Trump points: 12
  Scooby, Doo points: 15
  Shrek, Trump points: 7
  Snorlax, Trump points: 2
  Spongebob, Trump points: 4
  Squidward, Trump points: 8
  Troll, Mate points: 3

***Sorting by first name***

After:
  Eric, Cartman points: 13
  Scooby, Doo points: 15
  Troll, Mate points: 3
  Burro, Peanuts points: 5
  Homer, Simpsons points: 14
  Farquad, Trump points: 9
  Gary, Trump points: 6
  Mr.Krabs, Trump points: 10
  Patrick, Trump points: 11
  Pikachu, Trump points: 1
  Plankton, Trump points: 12
  Shrek, Trump points: 7
  Snorlax, Trump points: 2
  Spongebob, Trump points: 4
  Squidward, Trump points: 8

***Sorting by points***

After:
  zz-error, zz-error points: 0
  Pikachu, Trump points: 1
  Snorlax, Trump points: 2
  Troll, Mate points: 3
  Spongebob, Trump points: 4
  Burro, Peanuts points: 5
  Gary, Trump points: 6
  Shrek, Trump points: 7
  Squidward, Trump points: 8
  Farquad, Trump points: 9
  Mr.Krabs, Trump points: 10
  Patrick, Trump points: 11
  Plankton, Trump points: 12
  Eric, Cartman points: 13
  Homer, Simpsons points: 14

   Median of myClass: 8

Removal test:
   Removed  Scooby, Doo points: 15
   Removed  Homer, Simpsons points: 14
   Removed  Eric, Cartman points: 13
   Removed  Plankton, Trump points: 12
   Removed  Patrick, Trump points: 11
   Removed  Mr.Krabs, Trump points: 10
   Removed  Farquad, Trump points: 9
   Removed  Squidward, Trump points: 8
   Removed  Shrek, Trump points: 7
   Removed  Gary, Trump points: 6
   Removed  Burro, Peanuts points: 5
   Removed  Spongebob, Trump points: 4
   Removed  Troll, Mate points: 3
   Removed  Snorlax, Trump points: 2
   Removed  Pikachu, Trump points: 1

   Empty after 15 removes.
   The array now has 0 elements.

Adding elements test:
   Full after 20 adds.
Test array:
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
  TEST, TEST points: 99
---------------------------------------------------------------- */