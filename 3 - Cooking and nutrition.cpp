#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
   //ingredients nutrients' per 1 gram (converted from research)
   //ingredient 1 constants
   const string INGREDIENT_1_NAME = "Raw salmon";
   const double INGREDIENT_1_CALORIES_P1G = 1.42;
   const double INGREDIENT_1_FAT_P1G = 0.063;
   const double INGREDIENT_1_CARBS_P1G = 0;
   const double INGREDIENT_1_PROTEIN_P1G = 0.198;
   const double INGREDIENT_1_OMEGA3_P1G = 20.18;
   const double INGREDIENT_1_IRON_P1G = 0.008;

   //ingredient 2 constants
   const string INGREDIENT_2_NAME = "Raw shrimp";
   const double INGREDIENT_2_CALORIES_P1G = 1.06;
   const double INGREDIENT_2_FAT_P1G = 0.017;
   const double INGREDIENT_2_CARBS_P1G = 0.009;
   const double INGREDIENT_2_PROTEIN_P1G = 0.203;
   const double INGREDIENT_2_OMEGA3_P1G = 5.40;
   const double INGREDIENT_2_IRON_P1G = 0.024;

   //ingredient 3 constants
   const string INGREDIENT_3_NAME = "Raw tomato";
   const double INGREDIENT_3_CALORIES_P1G = 0.18;
   const double INGREDIENT_3_FAT_P1G = 0.002;
   const double INGREDIENT_3_CARBS_P1G = 0.039;
   const double INGREDIENT_3_PROTEIN_P1G = 0.009;
   const double INGREDIENT_3_OMEGA3_P1G = 0.03;
   const double INGREDIENT_3_IRON_P1G = 0.003;

   //ingredient 4 constants
   const string INGREDIENT_4_NAME = "Raw garlic";
   const double INGREDIENT_4_CALORIES_P1G = 1.49;
   const double INGREDIENT_4_FAT_P1G = 0.005;
   const double INGREDIENT_4_CARBS_P1G = 0.331;
   const double INGREDIENT_4_PROTEIN_P1G = 0.064;
   const double INGREDIENT_4_OMEGA3_P1G = 0.20;
   const double INGREDIENT_4_IRON_P1G = 0.017;

   //ingredient 5 constants
   const string INGREDIENT_5_NAME = "Raw white rice";
   const double INGREDIENT_5_CALORIES_P1G = 3.70;
   const double INGREDIENT_5_FAT_P1G = 0.005;
   const double INGREDIENT_5_CARBS_P1G = 0.817;
   const double INGREDIENT_5_PROTEIN_P1G = 0.068;
   const double INGREDIENT_5_OMEGA3_P1G = 0.08;
   const double INGREDIENT_5_IRON_P1G = 0.016;

   //ingredient 6 constants
   const string INGREDIENT_6_NAME = "Raw onions";
   const double INGREDIENT_6_CALORIES_P1G = 0.40;
   const double INGREDIENT_6_FAT_P1G = 0.001;
   const double INGREDIENT_6_CARBS_P1G = 0.093;
   const double INGREDIENT_6_PROTEIN_P1G = 0.011;
   const double INGREDIENT_6_OMEGA3_P1G = 0.04;
   const double INGREDIENT_6_IRON_P1G = 0.002;

   const string INDENT = "   ";

   string recipeName, userInputStr;
   int userInputGrams, userInputServings;
   double totalCalories, totalFat, totalCarbs, totalProtein, totalOmega3, totalIron;

   //initialize accumulator variables
   totalCalories = 0;
   totalFat = 0;
   totalCarbs = 0;
   totalProtein = 0;
   totalOmega3 = 0;
   totalIron = 0;

   //error testing constants
   const int MAX_SERVINGS = 15;
   const int MIN_SERVINGS = 1;
   const int MAX_GRAMS = 1500;
   const int MIN_GRAMS = 0;

   //print menu
   cout << "List of possible ingredients:\n\n";
   cout << INDENT << "Ingredient #1: " << INGREDIENT_1_NAME << ".\n";
   cout << INDENT << "Ingredient #2: " << INGREDIENT_2_NAME << ".\n";
   cout << INDENT << "Ingredient #3: " << INGREDIENT_3_NAME << ".\n";
   cout << INDENT << "Ingredient #4: " << INGREDIENT_4_NAME << ".\n";
   cout << INDENT << "Ingredient #5: " << INGREDIENT_5_NAME << ".\n";
   cout << INDENT << "Ingredient #6: " << INGREDIENT_6_NAME << ".\n\n";
   
   //user input for name of recipe
   cout << "What are you calling this recipe?\n";
   getline(cin, recipeName);
   cout << "\n";
      
   //user input for number of servings
   cout << "How many servings will you produce?\n";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputServings;
   cout << "\n";

   //error testing for number of servings input
   if (userInputServings < MIN_SERVINGS)
   {
      cout << "Error: the program cannot compute serving values lower than " << MIN_SERVINGS << ".\n";
      return 1;
   }
   if (userInputServings > MAX_SERVINGS)
   {
      cout << "Error: the program cannot compute serving values higher than " << MAX_SERVINGS << ".\n";
      return 1;
   }

   //user input for ingredient 1
   cout << "How many grams of " << INGREDIENT_1_NAME << " are you using?\n";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputGrams;

   //error testing for ingredient 1 grams input
   if (userInputGrams < MIN_GRAMS)
   {
      cout << "Error: the program cannot compute masses lower than " << MIN_GRAMS << ".\n";
      return 1;
   }
   if (userInputGrams > MAX_GRAMS)
   {
      cout << "Error: the program cannot compute masses higher than " << MAX_GRAMS << ".\n";
      return 1;
   }

   //update accumulators for ingredient 1
   totalCalories += (userInputGrams * INGREDIENT_1_CALORIES_P1G) / userInputServings;
   totalFat += (userInputGrams * INGREDIENT_1_FAT_P1G) / userInputServings;
   totalCarbs += (userInputGrams * INGREDIENT_1_CARBS_P1G) / userInputServings;
   totalProtein += (userInputGrams * INGREDIENT_1_PROTEIN_P1G) / userInputServings;
   totalOmega3 += (userInputGrams * INGREDIENT_1_OMEGA3_P1G) / userInputServings;
   totalIron += (userInputGrams * INGREDIENT_1_IRON_P1G) / userInputServings;

   //user input for ingredient 2
   cout << "How many grams of " << INGREDIENT_2_NAME << " are you using?\n";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputGrams;

   //error testing for ingredient 2 grams input
   if (userInputGrams < MIN_GRAMS)
   {
      cout << "Error: the program cannot compute masses lower than " << MIN_GRAMS << ".\n";
      return 1;
   }
   if (userInputGrams > MAX_GRAMS)
   {
      cout << "Error: the program cannot compute masses higher than " << MAX_GRAMS << ".\n";
      return 1;
   }

   //update accumulators for ingredient 2
   totalCalories += (userInputGrams * INGREDIENT_2_CALORIES_P1G) / userInputServings;
   totalFat += (userInputGrams * INGREDIENT_2_FAT_P1G) / userInputServings;
   totalCarbs += (userInputGrams * INGREDIENT_2_CARBS_P1G) / userInputServings;
   totalProtein += (userInputGrams * INGREDIENT_2_PROTEIN_P1G) / userInputServings;
   totalOmega3 += (userInputGrams * INGREDIENT_2_OMEGA3_P1G) / userInputServings;
   totalIron += (userInputGrams * INGREDIENT_2_IRON_P1G) / userInputServings;

   //user input for ingredient 3
   cout << "How many grams of " << INGREDIENT_3_NAME << " are you using?\n";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputGrams;

   //error testing for ingredient 3 grams input
   if (userInputGrams < MIN_GRAMS)
   {
      cout << "Error: the program cannot compute masses lower than " << MIN_GRAMS << ".\n";
      return 1;
   }
   if (userInputGrams > MAX_GRAMS)
   {
      cout << "Error: the program cannot compute masses higher than " << MAX_GRAMS << ".\n";
      return 1;
   }

   //update accumulators for ingredient 3
   totalCalories += (userInputGrams * INGREDIENT_3_CALORIES_P1G) / userInputServings;
   totalFat += (userInputGrams * INGREDIENT_3_FAT_P1G) / userInputServings;
   totalCarbs += (userInputGrams * INGREDIENT_3_CARBS_P1G) / userInputServings;
   totalProtein += (userInputGrams * INGREDIENT_3_PROTEIN_P1G) / userInputServings;
   totalOmega3 += (userInputGrams * INGREDIENT_3_PROTEIN_P1G) / userInputServings;
   totalIron += (userInputGrams * INGREDIENT_3_IRON_P1G) / userInputServings;

   //user input for ingredient 4
   cout << "How many grams of " << INGREDIENT_4_NAME << " are you using?\n";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputGrams;

   //error testing for ingredient 4 grams input
   if (userInputGrams < MIN_GRAMS)
   {
      cout << "Error: the program cannot compute masses lower than " << MIN_GRAMS << ".\n";
      return 1;
   }
   if (userInputGrams > MAX_GRAMS)
   {
      cout << "Error: the program cannot compute masses higher than " << MAX_GRAMS << ".\n";
      return 1;
   }

   //update accumulators for ingredient 4
   totalCalories += (userInputGrams * INGREDIENT_4_CALORIES_P1G) / userInputServings;
   totalFat += (userInputGrams * INGREDIENT_4_FAT_P1G) / userInputServings;
   totalCarbs += (userInputGrams * INGREDIENT_4_CARBS_P1G) / userInputServings;
   totalProtein += (userInputGrams * INGREDIENT_4_PROTEIN_P1G) / userInputServings;
   totalOmega3 += (userInputGrams * INGREDIENT_4_OMEGA3_P1G) / userInputServings;
   totalIron += (userInputGrams * INGREDIENT_4_IRON_P1G) / userInputServings;

   //user input for ingredient 5
   cout << "How many grams of " << INGREDIENT_5_NAME << " are you using?\n";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputGrams;

   //error testing for ingredient 5 grams input
   if (userInputGrams < MIN_GRAMS)
   {
      cout << "Error: the program cannot compute masses lower than " << MIN_GRAMS << ".\n";
      return 1;
   }
   if (userInputGrams > MAX_GRAMS)
   {
      cout << "Error: the program cannot compute masses higher than " << MAX_GRAMS << ".\n";
      return 1;
   }

   //update accumulators for ingredient 5
   totalCalories += (userInputGrams * INGREDIENT_5_CALORIES_P1G) / userInputServings;
   totalFat += (userInputGrams * INGREDIENT_5_FAT_P1G) / userInputServings;
   totalCarbs += (userInputGrams * INGREDIENT_5_CARBS_P1G) / userInputServings;
   totalProtein += (userInputGrams * INGREDIENT_5_PROTEIN_P1G) / userInputServings;
   totalOmega3 += (userInputGrams * INGREDIENT_5_OMEGA3_P1G) / userInputServings;
   totalIron += (userInputGrams * INGREDIENT_5_IRON_P1G) / userInputServings;

   //user input for ingredient 6
   cout << "How many grams of " << INGREDIENT_6_NAME << " are you using?\n";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputGrams;
   cout << "\n";

   //error testing for ingredient 6 grams input
   if (userInputGrams < MIN_GRAMS)
   {
      cout << "Error: the program cannot compute masses lower than " << MIN_GRAMS << ".\n";
      return 1;
   }
   if (userInputGrams > MAX_GRAMS)
   {
      cout << "Error: the program cannot compute masses higher than " << MAX_GRAMS << ".\n";
      return 1;
   }
   
   //update accumulators for ingredient 6
   totalCalories += (userInputGrams * INGREDIENT_6_CALORIES_P1G) / userInputServings;
   totalFat += (userInputGrams * INGREDIENT_6_FAT_P1G) / userInputServings;
   totalCarbs += (userInputGrams * INGREDIENT_6_CARBS_P1G) / userInputServings;
   totalProtein += (userInputGrams * INGREDIENT_6_PROTEIN_P1G) / userInputServings;
   totalOmega3 += (userInputGrams * INGREDIENT_6_OMEGA3_P1G) / userInputServings;
   totalIron += (userInputGrams * INGREDIENT_6_IRON_P1G) / userInputServings;

   //report results
   cout << "Nutritional facts of one serving of " << recipeName << ":\n\n";
   cout << INDENT << "Calories: " << totalCalories << " kilocalories.\n";
   cout << INDENT << "Fat: " << totalFat << " grams.\n";
   cout << INDENT << "Carbohydrates: " << totalCarbs << " grams.\n";
   cout << INDENT << "Protein: " << totalProtein << " grams.\n";
   cout << INDENT << "Omega3: " << totalOmega3 << " miligrams.\n";
   cout << INDENT << "Iron: " << totalIron << " miligrams.\n";
   
   return 0;
}

/*---------------------------------TEST RUNS--------------------------------
TEST RUN 1:

List of possible ingredients:

   Ingredient #1: Raw salmon.
   Ingredient #2: Raw shrimp.
   Ingredient #3: Raw tomato.
   Ingredient #4: Raw garlic.
   Ingredient #5: Raw white rice.
   Ingredient #6: Raw onions.

What are you calling this recipe?
Parihuela

How many servings will you produce?
4

How many grams of Raw salmon are you using?
300
How many grams of Raw shrimp are you using?
300
How many grams of Raw tomato are you using?
150
How many grams of Raw garlic are you using?
75
How many grams of Raw white rice are you using?
400
How many grams of Raw onions are you using?
500

Nutritional facts of one serving of Parihuela:

   Calories: 640.688 kilocalories.
   Fat: 6.79375 grams.
   Carbohydrates: 101.669 grams.
   Protein: 39.7875 grams.
   Omega3: 1935.59 miligrams.
   Iron: 4.68125 miligrams.

--------------------------------------------------------------------------
TEST RUN 2:

List of possible ingredients:

   Ingredient #1: Raw salmon.
   Ingredient #2: Raw shrimp.
   Ingredient #3: Raw tomato.
   Ingredient #4: Raw garlic.
   Ingredient #5: Raw white rice.
   Ingredient #6: Raw onions.

What are you calling this recipe?
Paella

How many servings will you produce?
2

How many grams of Raw salmon are you using?
150
How many grams of Raw shrimp are you using?
150
How many grams of Raw tomato are you using?
100
How many grams of Raw garlic are you using?
50
How many grams of Raw white rice are you using?
450
How many grams of Raw onions are you using?
100

Nutritional facts of one serving of Paella:

   Calories: 1084.75 kilocalories.
   Fat: 7.4 grams.
   Carbohydrates: 199.375 grams.
   Protein: 47.975 grams.
   Omega3: 1943.95 miligrams.
   Iron: 6.675 miligrams.

--------------------------------------------------------------------------
TEST RUN 3:

List of possible ingredients:

   Ingredient #1: Raw salmon.
   Ingredient #2: Raw shrimp.
   Ingredient #3: Raw tomato.
   Ingredient #4: Raw garlic.
   Ingredient #5: Raw white rice.
   Ingredient #6: Raw onions.

What are you calling this recipe?
Pan sealed shrimp and garlic

How many servings will you produce?
15

How many grams of Raw salmon are you using?
0
How many grams of Raw shrimp are you using?
1500
How many grams of Raw tomato are you using?
0
How many grams of Raw garlic are you using?
450
How many grams of Raw white rice are you using?
0
How many grams of Raw onions are you using?
0

Nutritional facts of one serving of Sealed shrimp and garlic:

   Calories: 150.7 kilocalories.
   Fat: 1.85 grams.
   Carbohydrates: 10.83 grams.
   Protein: 22.22 grams.
   Omega3: 546 miligrams.
   Iron: 2.91 miligrams.

--------------------------------------------------------------------------
TEST RUN 4:

List of possible ingredients:

   Ingredient #1: Raw salmon.
   Ingredient #2: Raw shrimp.
   Ingredient #3: Raw tomato.
   Ingredient #4: Raw garlic.
   Ingredient #5: Raw white rice.
   Ingredient #6: Raw onions.

What are you calling this recipe?
Shrimp risotto

How many servings will you produce?
3

How many grams of Raw salmon are you using?
0
How many grams of Raw shrimp are you using?
500
How many grams of Raw tomato are you using?
200
How many grams of Raw garlic are you using?
100
How many grams of Raw white rice are you using?
500
How many grams of Raw onions are you using?
300

Nutritional facts of one serving of Shrimp risotto:

   Calories: 895 kilocalories.
   Fat: 4.06667 grams.
   Carbohydrates: 160.6 grams.
   Protein: 49 grams.
   Omega3: 924.6 miligrams.
   Iron: 7.63333 miligrams.

--------------------------------------------------------------------------
TEST RUN 5:

List of possible ingredients:

   Ingredient #1: Raw salmon.
   Ingredient #2: Raw shrimp.
   Ingredient #3: Raw tomato.
   Ingredient #4: Raw garlic.
   Ingredient #5: Raw white rice.
   Ingredient #6: Raw onions.

What are you calling this recipe?
Happi House teriyaki shrimp (error run)

How many servings will you produce?
Their shrimp is baddddd

Error: the program cannot compute serving values lower than 1.

---------------------------------TEST RUNS--------------------------------*/
