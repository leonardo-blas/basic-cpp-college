//Assignment 9, by Leonardo Blas
//General comment: I created a helper functions to help modularize the 
//program, validSortKey.

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

// class Student prototype -----------------------
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
	//memnbers
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
};  // end of class Student prototype --------------

// class StudentArrayUtilities prototype -----------------------
class StudentArrayUtilities
{
public:
	static string toString(string title, Student data[], int arraySize);
	static void arraySort(Student array[], int arraySize);
	//getMedianDestructive function
	static double getMedianDestructive(Student array[], int arraySize);

private:
	static bool floatLargestToTop(Student data[], int top);
	static void mySwap(Student &a, Student &b);
};

// static initializations that can't be done in-line
const string Student::DEFAULT_NAME = "zz-error";
int Student::sortKey = DEFAULT_KEY;

//only global constant, indentation
const string INDENT = "   ";

int main()
{
	Student oddClass[] =
	{
	   Student("Pikachu", "Trump", 10), Student("Snorlax", "Trump", 11),
	   Student("Togepi", "Trump", 16), Student("Brock", "Trump", 13),
	   Student("Asuna", "Trump", 17), Student("Ash", "Trump", 15),
	   Student("Troll", "Trump", 18), Student("Spongebob", "Trump", 17),
	   Student("Burro", "Trump", 19), Student("Gary", "Trump", 19),
	   Student("Shrek", "Trump", 20), Student("Squidward", "Trump", 21),
	   Student("Farquad", "Trump", 22), Student("Mr.Krabs", "Trump", 23),
	   Student("Patrick", "Trump", 24)
	};

	Student evenClass[] =
	{
	   Student("Pikachu", "Trump", 10), Student("Snorlax", "Trump", 11),
	   Student("Togepi", "Trump", 16), Student("Brock", "Trump", 13),
	   Student("Asuna", "Trump", 17), Student("Ash", "Trump", 15),
	   Student("Troll", "Trump", 18), Student("Spongebob", "Trump", 17),
	   Student("Burro", "Trump", 19), Student("Gary", "Trump", 19),
	   Student("Shrek", "Trump", 20), Student("Squidward", "Trump", 21),
	   Student("Farquad", "Trump", 22), Student("Mr.Krabs", "Trump", 23),
	   Student("Patrick", "Trump", 24), Student("Plankton", "Trump", 25)
	};

	Student singleClass[] =
	{
	   Student("Mermaid", "Man", 26)
	};

	Student noClass[1] = 
	{
	};

	int oddArraySize = sizeof(oddClass) / sizeof(oddClass[0]);
	int evenArraySize = sizeof(evenClass) / sizeof(evenClass[0]);
	int singleArraySize = sizeof(singleClass) / sizeof(singleClass[0]);
	int noArraySize = sizeof(noClass) / sizeof(noClass[0]);

	cout << StudentArrayUtilities::toString("Before: ", evenClass,
		evenArraySize);

	cout << "***Sorting by default***\n\n";
	StudentArrayUtilities::arraySort(evenClass, evenArraySize);
	cout << StudentArrayUtilities::toString("After: ",
		evenClass, evenArraySize);

	cout << "***Sorting by first name***\n\n";
	Student::setSortKey(Student::SORT_BY_FIRST);
	StudentArrayUtilities::arraySort(evenClass, evenArraySize);
	cout << StudentArrayUtilities::toString("After: ",
		evenClass, evenArraySize);

	cout << "***Sorting by total points***\n\n";
	Student::setSortKey(Student::SORT_BY_POINTS);
	StudentArrayUtilities::arraySort(evenClass, evenArraySize);
	cout << StudentArrayUtilities::toString("After: ",
		evenClass, evenArraySize);

	Student::setSortKey(Student::SORT_BY_FIRST);
	cout << INDENT + "Median of evenClass: "
		<< StudentArrayUtilities::
		getMedianDestructive(evenClass, evenArraySize)
		<< "\n";

	cout << INDENT + "Median of oddClass: "
		<< StudentArrayUtilities::
		getMedianDestructive(oddClass, oddArraySize)
		<< "\n";

	cout << INDENT + "Median of smallClass: "
		<< StudentArrayUtilities::
		getMedianDestructive(singleClass, singleArraySize)
		<< "\n";

	cout << INDENT + "Median of noClass: "
		<< StudentArrayUtilities::
		getMedianDestructive(noClass, noArraySize)
		<< "\n\n";

	if (Student::getSortKey() == Student::SORT_BY_FIRST)
		cout << INDENT + "The client's sortKey was preserved." << endl;
}

// beginning of Student method definitions -------------

// constructor requires parameters - no default supplied
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

// end of Student method definitions  --------------

// beginning of StudentArrayUtilities method definitions -------------

// print the array with string as a title for the message box
// this is somewhat controversial - we may or may not want an I/O
// methods in this class.  we'll accept it today

string StudentArrayUtilities::toString(
	string title, 
	Student data[], 
	int arraySize)
{
	string output = "";
	string returnString;

	// build the output string from the individual Students:
	for (int k = 0; k < arraySize; k++)
		output += " " + data[k].toString();

	returnString = title + "\n" + output + "\n";

	return returnString;
}

void StudentArrayUtilities::arraySort(Student array[], int arraySize)
{
	for (int k = 0; k < arraySize; k++)
		// compare with method def to see where inner loop stops
		if (!floatLargestToTop(array, arraySize - 1 - k))
			return;
}

//getMedianDestructive function
double StudentArrayUtilities::getMedianDestructive(
	Student array[], 
	int arraySize)
{
	double returnDouble = 0;
	int evenRemainder = arraySize % 2;
	int oddRemainder = arraySize % 3;
	const int EVEN_ARRAY_MIN_SIZE = 2;
	const int ODD_ARRAY_MIN_SIZE = 3;
	const int ONE_ELEMENT_ARRAY_SIZE = 1;
	int originalKey = Student::getSortKey();

	Student::setSortKey(Student::SORT_BY_POINTS);
	arraySort(array, arraySize);

	if (arraySize == ONE_ELEMENT_ARRAY_SIZE)
		returnDouble = array[0].getTotalPoints();

	if (evenRemainder == 0 && arraySize >= EVEN_ARRAY_MIN_SIZE)
	{
		//consider the trailing caused by division
		int lowerMiddleIndex = (arraySize / 2);
		int upperMiddleIndex = ((arraySize / 2) + 1);
		returnDouble = (double)(array[lowerMiddleIndex].getTotalPoints()
			           + array[upperMiddleIndex].getTotalPoints()) / 2;
	}

	if (oddRemainder == 0 && arraySize >= ODD_ARRAY_MIN_SIZE)
	{
		//consider the trailing caused by division
		int middleIndex = ((arraySize / 2) + 1);
		returnDouble = array[middleIndex].getTotalPoints();
	}

	Student::setSortKey(originalKey);

	return returnDouble;
}

// returns true if a modification was made to the array
bool StudentArrayUtilities::floatLargestToTop(Student data[], int top)
{
	bool changed = false;

	// compare with client call to see where the loop stops
	for (int k = 0; k < top; k++)
		if (Student::compareTwoStudents(data[k], data[k + 1]) > 0)
		{
			mySwap(data[k], data[k + 1]);
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

// end of StudentArrayUtilities method definitions  --------------

/* ------------------------------ run ----------------------------
Before:
  Pikachu, Trump points: 10
  Snorlax, Trump points: 11
  Togepi, Trump points: 16
  Brock, Trump points: 13
  Asuna, Trump points: 17
  Ash, Trump points: 15
  Troll, Trump points: 18
  Spongebob, Trump points: 17
  Burro, Trump points: 19
  Gary, Trump points: 19
  Shrek, Trump points: 20
  Squidward, Trump points: 21
  Farquad, Trump points: 22
  Mr.Krabs, Trump points: 23
  Patrick, Trump points: 24
  Plankton, Trump points: 25

***Sorting by default***

After:
  Ash, Trump points: 15
  Asuna, Trump points: 17
  Brock, Trump points: 13
  Burro, Trump points: 19
  Farquad, Trump points: 22
  Gary, Trump points: 19
  Mr.Krabs, Trump points: 23
  Patrick, Trump points: 24
  Pikachu, Trump points: 10
  Plankton, Trump points: 25
  Shrek, Trump points: 20
  Snorlax, Trump points: 11
  Spongebob, Trump points: 17
  Squidward, Trump points: 21
  Togepi, Trump points: 16
  Troll, Trump points: 18

***Sorting by first name***

After:
  Ash, Trump points: 15
  Asuna, Trump points: 17
  Brock, Trump points: 13
  Burro, Trump points: 19
  Farquad, Trump points: 22
  Gary, Trump points: 19
  Mr.Krabs, Trump points: 23
  Patrick, Trump points: 24
  Pikachu, Trump points: 10
  Plankton, Trump points: 25
  Shrek, Trump points: 20
  Snorlax, Trump points: 11
  Spongebob, Trump points: 17
  Squidward, Trump points: 21
  Togepi, Trump points: 16
  Troll, Trump points: 18

***Sorting by total points***

After:
  Pikachu, Trump points: 10
  Snorlax, Trump points: 11
  Brock, Trump points: 13
  Ash, Trump points: 15
  Togepi, Trump points: 16
  Asuna, Trump points: 17
  Spongebob, Trump points: 17
  Troll, Trump points: 18
  Burro, Trump points: 19
  Gary, Trump points: 19
  Shrek, Trump points: 20
  Squidward, Trump points: 21
  Farquad, Trump points: 22
  Mr.Krabs, Trump points: 23
  Patrick, Trump points: 24
  Plankton, Trump points: 25

   Median of evenClass: 19
   Median of oddClass: 19
   Median of smallClass: 26
   Median of noClass: 0

   The client's sortKey was preserved.
---------------------------------------------------------------- */