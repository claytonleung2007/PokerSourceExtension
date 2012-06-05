#include <Windows.h>
#include <iostream>

__declspec(dllimport) const char* Export_Echo(const char*);
__declspec(dllimport) int __stdcall Export_CompareTexasHand(const char*, const char*, const char*);

// prototypes
void testPlayerOneWins();
void testPlayerTwoWins();
void testDraw();
void testEcho();

int main()
{
	printf("Begin Tests");

	testEcho();

	testPlayerOneWins();
	testPlayerTwoWins();
	testDraw();
   
	std::cin.get();

	return 0;
}

void testPlayerOneWins()
{
	printf("\nTest player 1 wins ... ");

	const char* hand1 = "As";
	const char* hand2 = "TdTh";
	const char* board = "AdTcAc";
		
	int winner;
	winner = Export_CompareTexasHand(hand1, hand2, board);

	if (winner == 1)
		printf("passed");
	else
		printf("failed");

	
}

void testPlayerTwoWins()
{
	printf("\nTest player 2 wins ... ");

	const char* hand1 = "As9s";
	const char* hand2 = "TdTh";
	const char* board = "AdTc5c4h9h";
		
	int winner;
	winner = Export_CompareTexasHand(hand1, hand2, board);

	if (winner == 2)
		printf("passed");
	else
		printf("failed");
}

void testDraw()
{
	printf("\nTest Draw ... ");

	const char* hand1 = "As9s";
	const char* hand2 = "Ah9d";
	const char* board = "AdTc5c4h9h";
		
	int winner;
	winner = Export_CompareTexasHand(hand1, hand2, board);

	if (winner == 0)
		printf("passed");
	else
		printf("failed");
}

void testEcho()
{
	printf("\nTest Echo ... ");
	
	const char* echo;
	echo = Export_Echo("echo this");

	if (echo == "echo this")
		printf("passed");
	else
		printf("failed");
}