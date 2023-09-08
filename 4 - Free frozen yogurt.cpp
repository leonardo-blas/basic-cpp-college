/*Free Frozen Yogurt, by Leonardo Blas

Comment: I'm using individual lines of code for outputting blank lines 
("\n";) because it conveys a better sense of structure and navigation 
within the menu's source code. Additionally, the vast number of 
string constants instead of string literals have a purpose, a future
peace of mind when editing.*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
   //initialize constants and variables
   int inputRequestedYogurt;
   int stampPricePerYogurt = 9;
   string inputStringPorS, inputStringYorN;
   const char PURCHASE_CHARACTER = 'P';
   const char SHUT_DOWN_CHARACTER = 'S';
   const char AFFIRMATION_CHARACTER = 'Y';
   const char REJECTION_CHARACTER = 'N';
   const string INDENTATION = "   ";
   const string MENU_TITLE = "Menu";
   const string PURCHASE_PROMPT = "process purchase";
   const string SHUT_DOWN_PROMPT = "shut down";
   const string SHUTTING_DOWN_PROMPT = "Shutting Down.";
   const string CHOICE_PROMPT = "Your choice?";
   const string YOGURT_PROMPT = "How many yogurts would you like to buy?";
   const string YOGURT_ERROR = "Invalid number of yogurts.";
   const string ERROR_DECORATION = "***";
   const string FREE_YOGURT_PROMPT = "You qualify for a free yogurt.";
   const string GOODBYE_PROMPT = "Enjoy your free yogurt!";
   const string ASK_USE_STAMPS = "Would you like to use your stamps?";
   const string EARNED_PROMPT = "You have just earned";
   const string USED_PROMPT = "You have just used";

   //initialize accumulators
   int accumulatedStamps = 0;

   //while loop for repeating until shut down order
   while (true)
   {
      //print menu
      cout << "\n";
      cout << INDENTATION + MENU_TITLE + ":";
      cout << "\n\n";
      cout << INDENTATION << PURCHASE_CHARACTER << " (" + PURCHASE_PROMPT + ")";
      cout << "\n";
      cout << INDENTATION << SHUT_DOWN_CHARACTER << " (" + SHUT_DOWN_PROMPT +
         ")";
      cout << "\n\n";
      cout << INDENTATION + CHOICE_PROMPT + ": ";
      cin >> inputStringPorS;

      //check if the input starts with p or P
      if(inputStringPorS[0] == 'p' || inputStringPorS[0] == 'P')
      {
         cout << "\n";
         cout << INDENTATION + YOGURT_PROMPT + ": ";
         cin >> inputRequestedYogurt;
         cout << "\n";

         //creating an output variable for inputRequestedYogurt
         int outputRequestedYogurt = inputRequestedYogurt;

         //check if invalid request of yogurt
         if (inputRequestedYogurt <= 0)
         {
            cout << INDENTATION << ERROR_DECORATION + YOGURT_ERROR + 
                    ERROR_DECORATION;
            cout << "\n\n";
         }
         
         //check if valid request of yogurt
         else if (inputRequestedYogurt > 0)
         {
            //udpate accumulators
            accumulatedStamps += inputRequestedYogurt;

            //check if user has more than the required stamps for the award
            if (accumulatedStamps >= 9)
            {
               cout << INDENTATION + EARNED_PROMPT + " " << outputRequestedYogurt
                  << " stamps and have " << accumulatedStamps << " stamps.";
               cout << "\n";

               //while loop such that the program reprompts if it doesn't get Y or N 
               while (true) 
               {
                  cout << INDENTATION + ASK_USE_STAMPS + " (" << AFFIRMATION_CHARACTER
                     << " or " << REJECTION_CHARACTER << "): "; 
                  cin >> inputStringYorN;

                  //checking if user wants to use stamps
                  if (inputStringYorN[0] == 'y' || inputStringYorN[0] == 'Y')
                  {
                     accumulatedStamps -= stampPricePerYogurt;
                     cout << "\n";
                     cout << INDENTATION + USED_PROMPT + " " << stampPricePerYogurt
                          << " stamps and have " << accumulatedStamps << " stamps.";
                     cout << "\n";
                     cout << INDENTATION + GOODBYE_PROMPT;
                     cout << "\n\n";
                     break;
                  }

                  //check if user doesn't want to use stamps
                  else if (inputStringYorN[0] == 'n' || inputStringYorN[0] == 'N')
                  {
                     cout << "\n";
                     break;
                  }

                  //if neither Y or N loop
                  else
                  {
                     cout << "\n";
                     cout << INDENTATION + ERROR_DECORATION + " Use "
                          << AFFIRMATION_CHARACTER << " or " << REJECTION_CHARACTER
                          << ERROR_DECORATION;
                     cout << "\n\n";
                  }
               }
            }

            //if not enough stamps for reward, show accumulated stamps
            else
            {
               cout << INDENTATION + EARNED_PROMPT + " " << outputRequestedYogurt 
                    << " and have " << accumulatedStamps << " to spend.";
               cout << "\n\n";
            }
         }
      }
      //check if the input starts with s or S
      else if(inputStringPorS[0] == 's' || inputStringPorS[0] == 'S')
      {
         cout << "\n";
         cout << INDENTATION + SHUTTING_DOWN_PROMPT;
         cout << "\n";
         return 0;
      }

      //repeat while loop if neither s or p starting characters
      else
      {
         cout << "\n";
         cout << INDENTATION + ERROR_DECORATION + " Use " << PURCHASE_CHARACTER 
              << " or " << SHUT_DOWN_CHARACTER << ERROR_DECORATION;
         cout << "\n\n";
      }
   }
   return 0;
}
/*---------------------------------TRIAL ONE -----------------------------------

   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: DOGGERINO

   *** Use P or S***


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: PuertoRico

   How many yogurts would you like to buy?: 0

   ***Invalid number of yogurts.***


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: p

   How many yogurts would you like to buy?: -8

   ***Invalid number of yogurts.***


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: PICASSO

   How many yogurts would you like to buy?: 8

   You have just earned 8 and have 8 to spend.


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: poboysandwich

   How many yogurts would you like to buy?: 67

   You have just earned 67 stamps and have 75 stamps.
   Would you like to use your stamps? (Y or N): U

   *** Use Y or N***

   Would you like to use your stamps? (Y or N): Y

   You have just used 9 stamps and have 66 stamps.
   Enjoy your free yogurt!


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: p

   How many yogurts would you like to buy?: 1

   You have just earned 1 stamps and have 67 stamps.
   Would you like to use your stamps? (Y or N): yessir

   You have just used 9 stamps and have 58 stamps.
   Enjoy your free yogurt!


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: no

   *** Use P or S***


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: p

   How many yogurts would you like to buy?: 78

   You have just earned 78 stamps and have 136 stamps.
   Would you like to use your stamps? (Y or N): no


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: stormtrooper

   Shutting Down.

---------------------------------TRIAL TWO -----------------------------------

   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: lolllll

   *** Use P or S***


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: plox

   How many yogurts would you like to buy?: 45

   You have just earned 45 stamps and have 45 stamps.
   Would you like to use your stamps? (Y or N): y

   You have just used 9 stamps and have 36 stamps.
   Enjoy your free yogurt!


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: portobelloburger

   How many yogurts would you like to buy?: 8

   You have just earned 8 stamps and have 44 stamps.
   Would you like to use your stamps? (Y or N): y

   You have just used 9 stamps and have 35 stamps.
   Enjoy your free yogurt!


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: i

   *** Use P or S***


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: pototo

   How many yogurts would you like to buy?: 4

   You have just earned 4 stamps and have 39 stamps.
   Would you like to use your stamps? (Y or N): n


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: psiloveu

   How many yogurts would you like to buy?: 65

   You have just earned 65 stamps and have 104 stamps.
   Would you like to use your stamps? (Y or N): y

   You have just used 9 stamps and have 95 stamps.
   Enjoy your free yogurt!


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: P

   How many yogurts would you like to buy?: 45

   You have just earned 45 stamps and have 140 stamps.
   Would you like to use your stamps? (Y or N): YESSERINO

   You have just used 9 stamps and have 131 stamps.
   Enjoy your free yogurt!


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: TROLL

   *** Use P or S***


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?: postoffice

   How many yogurts would you like to buy?: 5

   You have just earned 5 stamps and have 136 stamps.
   Would you like to use your stamps? (Y or N): n


   Menu:

   P (process purchase)
   S (shut down)

   Your choice?:

*/