//Assignment 8, by Leonardo Blas
//General comment: the style for the 6 parameter methods and all formatting 
//in this program was acquired from Stack Overflow posts.

#include <iostream>
#include <string>

using namespace std;

//class prototyping
class DateProfile
{
private:

   //private members
   char gender;
   char searchGender;
   int romance;
   int finance;
   int distance;
   string name;

   //private member functions

   //return gender fit
   double determineGenderFit(DateProfile partner);

   //return romance fit
   double determineRomanceFit(DateProfile partner);

   //return finance fit
   double determineFinanceFit(DateProfile partner);

   //return distance fit
   double determineDistanceFit(DateProfile partner);

public:

   //public default constants
   static const char DEFAULT_GENDER;
   static const char DEFAULT_SEARCH_GENDER;
   static const int DEFAULT_ROMANCE;
   static const int DEFAULT_FINANCE;
   static const int DEFAULT_DISTANCE;
   static const string DEFAULT_NAME;

   //public constants, for mutator tests
   static const char MALE_GENDER, FEMALE_GENDER;
   static const char MALE_SEARCH, FEMALE_SEARCH;
   static const int MIN_ROMANCE, MAX_ROMANCE;
   static const int MIN_FINANCE, MAX_FINANCE;
   static const int MIN_DISTANCE, MAX_DISTANCE;
   static const int MIN_NAME_LENGHT, MAX_NAME_LENGHT;

   //public member functions

   //default constructor
   DateProfile();

   //parametrized constructor
   DateProfile(
      char pGender,
      char pSearchGender,
      int pRomance,
      int pFinance,
      int pDistance,
      string pName);

   //mutators
   bool setGender(char pGender);
   bool setSearchGender(char pSearchGender);
   bool setRomance(int pRomance);
   bool setFinance(int pFinance);
   bool setDistance(int pDistance);
   bool setName(string pName);

   //accessors
   char getGender();
   char getSearchGender();
   int getRomance();
   int getFinance();
   int getDistance();
   string getName();

   //void six-parameters member function
   void setAll(
      char pGender, 
      char pSearchGender, 
      int pRomance,
      int pFinance, 
      int pDistance, 
      string pName);

   //setting members to default member function
   void setDefaults();

   //return fit member function
   double fitValue(DateProfile partner);

   //display profiles
   static void displayTwoProfiles(DateProfile profile1, DateProfile profile2);
};

//initializing public default constants
const char DateProfile::DEFAULT_GENDER = 'M';
const char DateProfile::DEFAULT_SEARCH_GENDER = 'F';
const int DateProfile::DEFAULT_ROMANCE = 1;
const int DateProfile::DEFAULT_FINANCE = 1;
const int DateProfile::DEFAULT_DISTANCE = 1;
const string DateProfile::DEFAULT_NAME = " (unnamed profile) ";

//initializing public constants, for mutator tests
const char DateProfile::MALE_GENDER = 'M'; 
const char DateProfile::FEMALE_GENDER = 'F';
const char DateProfile::MALE_SEARCH = 'M';
const char DateProfile::FEMALE_SEARCH = 'F';
const int DateProfile::MIN_ROMANCE = 1; 
const int DateProfile::MAX_ROMANCE = 10;
const int DateProfile::MIN_FINANCE = 1;
const int DateProfile::MAX_FINANCE = 10;
const int DateProfile::MIN_DISTANCE = 1;
const int DateProfile::MAX_DISTANCE = 10;
const int DateProfile::MIN_NAME_LENGHT = 3; //arbitrary, not stated in the spec
const int DateProfile::MAX_NAME_LENGHT = 30; //arbitrary, not stated in the spec

//initializing only global constant, indentation
const string INDENTATION = "   ";

int main()
{
   DateProfile applicant1, applicant2, applicant3, applicant4;
   
   applicant1.setAll('M', 'F', 9, 1, 3, "Pikachu");
   applicant2.setAll('F','M', 6, 7, 8, "Psyduck");
   applicant3.setAll('F', 'M', 8, 3, 2, "Lapras");
   applicant4.setAll('M', 'F', 10, 1, 10, "Snorlax");

   DateProfile::displayTwoProfiles(applicant1, applicant1);
   DateProfile::displayTwoProfiles(applicant1, applicant2);
   DateProfile::displayTwoProfiles(applicant1, applicant3);
   DateProfile::displayTwoProfiles(applicant1, applicant4);

   DateProfile::displayTwoProfiles(applicant2, applicant1);
   DateProfile::displayTwoProfiles(applicant2, applicant2);
   DateProfile::displayTwoProfiles(applicant2, applicant3);
   DateProfile::displayTwoProfiles(applicant2, applicant4);

   DateProfile::displayTwoProfiles(applicant3, applicant1);
   DateProfile::displayTwoProfiles(applicant3, applicant2);
   DateProfile::displayTwoProfiles(applicant3, applicant3);
   DateProfile::displayTwoProfiles(applicant3, applicant4);

   DateProfile::displayTwoProfiles(applicant4, applicant1);
   DateProfile::displayTwoProfiles(applicant4, applicant2);
   DateProfile::displayTwoProfiles(applicant4, applicant3);
   DateProfile::displayTwoProfiles(applicant4, applicant4);

   return 0;
}

//defining member functions

//default constructor
DateProfile::DateProfile()
{
   setDefaults();
}

//parametrized constructor
DateProfile::DateProfile(
   char pGender,
   char pSearchGender,
   int pRomance,
   int pFinance,
   int pDistance,
   string pName) 
{
   setAll(
      pGender,
      pSearchGender,
      pRomance,
      pFinance,
      pDistance,
      pName);
}

//mutators
bool DateProfile::setGender(char pGender)
{
   if (pGender == MALE_GENDER || pGender == FEMALE_GENDER)
      return true;
   else
      return false;
}

bool DateProfile::setSearchGender(char pSearchGender)
{
   if (pSearchGender == MALE_SEARCH || pSearchGender == FEMALE_SEARCH)
      return true;
   else
      return false;
}

bool DateProfile::setRomance(int pRomance)
{
   if (pRomance >= MIN_ROMANCE && pRomance <= MAX_ROMANCE)
      return true;
   else
      return false;
}

bool DateProfile::setFinance(int pFinance)
{
   if (pFinance >= MIN_FINANCE && pFinance <= MAX_FINANCE)
      return true;
   else
      return false;
}

bool DateProfile::setDistance(int pDistance)
{
   if (pDistance >= MIN_DISTANCE && pDistance <= MAX_DISTANCE)
      return true;
   else
      return false;
}

bool DateProfile::setName(string pName)
{
   if (pName.length() >= MIN_NAME_LENGHT && pName.length() <= MAX_NAME_LENGHT)
      return true;
   else
      return false;
}

//accessors
char DateProfile::getGender()
{
   return gender;
}

char DateProfile::getSearchGender()
{
   return searchGender;
}

int DateProfile::getRomance()
{
   return romance;
}

int DateProfile::getFinance()
{
   return finance;
}

int DateProfile::getDistance()
{
   return distance;
}

string DateProfile::getName()
{
   return name;
}

//void six-parameters member function
void DateProfile::setAll(
   char pGender,
   char pSearchGender,
   int pRomance,
   int pFinance,
   int pDistance,
   string pName)
{
   if (!setGender(pGender))
      gender = DEFAULT_GENDER;
   else
      gender = pGender;

   if (!setSearchGender(pSearchGender))
      searchGender = DEFAULT_SEARCH_GENDER;
   else
      searchGender = pSearchGender;
   
   if (!setRomance(pRomance))
      romance = DEFAULT_ROMANCE;
   else
      romance = pRomance;
   
   if (!setFinance(pFinance))
      finance = DEFAULT_FINANCE;
   else finance = pFinance;
   
   if (!setDistance(pDistance))
      distance = DEFAULT_DISTANCE;
   else distance = pDistance;
   
   if (!setName(pName))
      name = DEFAULT_NAME;
   else
      name = pName;
}

//setting members to default member function
void DateProfile::setDefaults()
{
   gender = DEFAULT_GENDER;
   searchGender = DEFAULT_SEARCH_GENDER;
   romance = DEFAULT_ROMANCE;
   finance = DEFAULT_FINANCE;
   distance = DEFAULT_DISTANCE;
   name = DEFAULT_NAME;
}

//return gender fit
double DateProfile::determineGenderFit(DateProfile partner)
{
   const int MIN_GENDER_FIT = 0;
   const int MAX_GENDER_FIT = 1;
   double genderFit;

   if (partner.gender == this->searchGender
      && partner.searchGender == this->gender)
      genderFit = MAX_GENDER_FIT;
   else
      genderFit = MIN_GENDER_FIT;

   return genderFit;
}

//return romance fit
double DateProfile::determineRomanceFit(DateProfile partner)
{
   double smallerNumber, largerNumber;
   double romanceFit;

   //not using array sorting because it's too complicated for 2 elements
   if (partner.romance > this->romance)
   {
      smallerNumber = this->romance;
      largerNumber = partner.romance;
   }
   else
   {
      smallerNumber = partner.romance;
      largerNumber = this->romance;
   }

   romanceFit = smallerNumber / largerNumber;

   return romanceFit;
}

//return finance fit
double DateProfile::determineFinanceFit(DateProfile partner)
{
   double smallerNumber, largerNumber;
   double financeFit;

   //not using array sorting because it's too complicated for 2 elements
   if (partner.finance > this->finance)
   {
      smallerNumber = this->finance;
      largerNumber = partner.finance;
   }
   else
   {
      smallerNumber = partner.finance;
      largerNumber = this->finance;
   }

   financeFit = smallerNumber / largerNumber;

   return financeFit;
}

//return distance fit
double DateProfile::determineDistanceFit(DateProfile partner)
{
   double smallerNumber, largerNumber;
   double distanceFit;

   //not using array sorting because it's too complicated for 2 elements
   if (partner.distance > this->distance)
   {
      smallerNumber = this->distance;
      largerNumber = partner.distance;
   }
   else
   {
      smallerNumber = partner.distance;
      largerNumber = this->distance;
   }

   distanceFit = smallerNumber / largerNumber;

   return distanceFit;
}

//return fit member function
double DateProfile::fitValue(DateProfile partner)
{
   double totalFit;

   if (this->determineGenderFit(partner) == 0)
   {
      totalFit = 0;
      return totalFit;
   }

   double romanceFit, financeFit, distanceFit;
   
   romanceFit = this->determineRomanceFit(partner);
   financeFit = this->determineFinanceFit(partner);
   distanceFit = this->determineDistanceFit(partner);

   totalFit = (romanceFit + financeFit + distanceFit) / 3;

   return totalFit;
}

//display profiles
void DateProfile::displayTwoProfiles(DateProfile profile1, DateProfile profile2)
{
   string nameProfile1, nameProfile2;
   double totalFit;

   nameProfile1 = profile1.getName();
   nameProfile2 = profile2.getName();
   totalFit = profile1.fitValue(profile2);

   cout << INDENTATION + "Fit between " + nameProfile1 + " and " + nameProfile2
      + ": " << totalFit << "\n";
}
/*------------------------------TEST RUN------------------------------
   Fit between Pikachu and Pikachu: 0
   Fit between Pikachu and Psyduck: 0.394841
   Fit between Pikachu and Lapras: 0.62963
   Fit between Pikachu and Snorlax: 0
   Fit between Psyduck and Pikachu: 0.394841
   Fit between Psyduck and Psyduck: 0
   Fit between Psyduck and Lapras: 0
   Fit between Psyduck and Snorlax: 0.514286
   Fit between Lapras and Pikachu: 0.62963
   Fit between Lapras and Psyduck: 0
   Fit between Lapras and Lapras: 0
   Fit between Lapras and Snorlax: 0.444444
   Fit between Snorlax and Pikachu: 0
   Fit between Snorlax and Psyduck: 0.514286
   Fit between Snorlax and Lapras: 0.444444
   Fit between Snorlax and Snorlax: 0
--------------------------------TEST RUN----------------------------*/