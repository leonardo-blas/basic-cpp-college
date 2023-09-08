#include <iostream>

using namespace std;

int main()
{
   int myId = 20325202;
   int numLet = 4;
   int intResult1 = myId % 17;
   int intResult2 = (myId + 4) % 9;
   double doubleResult3 = (double) myId / (myId + 500);
   int intResult4 = 1 + 2 + 3 + 4;
   double doubleResult5 = (double) 15000 / (80 + ((myId - 123456) / ((numLet + 20) * (numLet + 20))));
   
   cout << "My family name is Blas.\n"; 
   cout << "My student ID is " << myId << ".\n";
   cout << "The number of characters in my last name is " << numLet << ".\n\n";
   cout << "Expression #1: " << intResult1 << ".\n\n";
   cout << "Expression #2: " << intResult2 << ".\n\n";
   cout << "Expression #3: " << doubleResult3 << ".\n\n";
   cout << "Expression #4: " << intResult4 << ".\n\n";
   cout << "Expression #5: " << doubleResult5 << ".\n";

   return 0;
}   

/*----------------------------SAMPLE RUN---------------------------------------



My family name is Blas.                                                                                              

My student ID is 20325202.                                                                                           

The number of characters in my last name is 4.
                                                                       

Expression #1: 2.
                                                                                                 
Expression #2: 2.                                                                                                 

Expression #3: 0.999975.                                                                                          

Expression #4: 10.                                                                                                

Expression #5: 0.426718.   



----------------------------SAMPLE RUN---------------------------------------*/