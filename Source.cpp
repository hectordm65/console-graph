/*Name: Hector Dominguez-Maceda
Date: 4/12/2016
Class: CSC 2430
Assignment: Lab #2 - Array Quiz Data Bar Chart Analysis
Description: Asks user for quiz scores and varience of each quiz score.
Outputs a graph vertically and horizontally.
*/
#include <iostream>		//Libraries needed for programs
#include <iomanip>

using namespace std;

const int SCORES_POSSIBLE = 51;		//the scores possible, 0 to 50, 51 values

void ScoreKeeper(int, int[]);			//all
int LowestScore(int[]);					//of
int HighestScore(int[]);				//my
int CalculateRange(int, int);			//function
void VerticalGraph(int, int, int[]);	//prototypes
void HorizontalGraph(int, int, int, int, int[]);


int main()
{
	system("cls");		//clears screen

	//Helpful prompts for user
	cout << "Welcome to the Quiz Score Frequency Analyzer, by Hector Dominguez-Maceda" << endl;

	cout << "\nEnter a list of pairs of values: \"QuizScoreValue ScoreCount\"." << endl;

	cout << "  Example: 4 48 indicates 4 more students received a score of 48." << endl;

	cout << "Enter \"-1 0\" when finished: " << endl;

	/*all values used in this program.
	They're all ints because we are only using whole numbers
	in this assignment*/
	int QuizScoreFreq[SCORES_POSSIBLE] = { 0 };	//array that hold amount of times each score occurs
	int Score = 0;
	int SmallestScoreVal = 0;
	int LargestScoreVal = 0;
	int MaxFreq = 0;
	int range = 0;

	ScoreKeeper(Score, QuizScoreFreq);		//calling the function

	cout << "\n";		//needed to keep program clean and put a new line in

	SmallestScoreVal = LowestScore(QuizScoreFreq);		//calling the function

	LargestScoreVal = HighestScore(QuizScoreFreq);		//calling the function

	//calculates maximum frequency
	for (int c = 0; c < SCORES_POSSIBLE; c++)
	{
		if (QuizScoreFreq[c] > MaxFreq)
		{
			MaxFreq = QuizScoreFreq[c];
		}
	}

	//calculates range
	range = CalculateRange(LargestScoreVal, SmallestScoreVal);

	//Outputs smallest score, largest score, and the most frequent score
	cout << "---Input Data----" << endl;

	cout << "Score: Frequency:" << endl;

	for (int i = SmallestScoreVal; i <= LargestScoreVal; i++)
	{
		cout << setw(5) << i << ":";			//setw helps makes it align accordingly
		cout << setw(11) << QuizScoreFreq[i] << endl;
	}

	cout << "\nThe smallest score value is " << SmallestScoreVal << endl;
	cout << "The largest score value is " << LargestScoreVal << endl;
	cout << "The largest frequency count is " << MaxFreq << endl;

	VerticalGraph(LargestScoreVal, SmallestScoreVal, QuizScoreFreq);	//calling the function

	HorizontalGraph(LargestScoreVal, SmallestScoreVal, MaxFreq, range, QuizScoreFreq);	//calling the function

	return (0);
}

//used a void because function doesn't return anything exceot array and array is passed by reference always
void ScoreKeeper(int Score, int QuizScoreFreq[])
{
	int NumOfScore = 0;
	while (Score > -1, NumOfScore > -1)
	{
		cin >> NumOfScore >> Score;
		QuizScoreFreq[Score] += NumOfScore;
	}
}

//returns the lowest score
int LowestScore(int QuizScoreFreq[])
{
	int SmallestScore;
	for (int a = SCORES_POSSIBLE; a > 0; a--)
	{
		if (QuizScoreFreq[a] >= 1)
		{
			SmallestScore = a;
		}
	}
	return SmallestScore;
}

//returns the highest score
int HighestScore(int QuizScoreFreq[])
{
	int LargestScore;
	for (int b = 0; b < SCORES_POSSIBLE; b++)
	{
		if (QuizScoreFreq[b] >= 1)
		{
			LargestScore = b;
		}
	}
	return LargestScore;
}

//returns the range
int CalculateRange(int LargestScoreVal, int SmallestScoreVal)
{
	int range = LargestScoreVal - SmallestScoreVal;
	return range;
}

//outputs a vertical graph and returns nothing
void VerticalGraph(int LargestScoreVal, int SmallestScoreVal, int QuizScoreFreq[])
{
	cout << "\nVertical Bar Chart" << endl;
	cout << "Score: Frequency:" << endl;
	for (int i = SmallestScoreVal; i <= LargestScoreVal; i++)
	{
		cout << setw(5) << i << ": ";
		for (int m = 0; m < QuizScoreFreq[i]; m++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}

//outputs a horizontal graph and returns nothing
void HorizontalGraph(int LargestScoreVal, int SmallestScoreVal, int MaxFreq, int range, int QuizScoreFreq[])
{
	cout << "\nHorizontal Bar Chart" << endl;
	cout << "Frequency:\n" << endl;
	for (int i = MaxFreq; i > 0; i--)
	{
		cout << setw(6) << "^" << setw(3) << i << ": ";
		for (int j = SmallestScoreVal; j <= LargestScoreVal; j++)
		{
			if (QuizScoreFreq[j] >= i)
			{
				cout << setw(3) << "*";
			}
			else
			{
				cout << setw(3) << " ";
			}
		}
		cout << "\n";
	}
	cout << setw(11) << setfill('-') << ": ";
	for (int m = range; m >= 0; m--)
	{
		cout << "--^";
	}
	cout << "\n";

	cout << setw(13) << setfill(' ') << "Score:   ";
	for (int k = SmallestScoreVal; k <= LargestScoreVal; k++)
	{
		cout << k << setw(3);
	}
	cout << "\n";
}