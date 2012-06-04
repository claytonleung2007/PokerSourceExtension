#include <Windows.h>
#include <iostream>

__declspec(dllimport) const char* Export_Echo(const char*);
__declspec(dllimport) void Export_CompareTexasHand(const char*, const char*, const char*, int*);

int main()
{
	const char* result = Export_Echo("Hello World");

	const char* test1 = "hello";

	std::string testme = test1;

	printf(testme.c_str());


	const char* hand1 = "As";
	const char* hand2 = "";
	const char* board = "Ad";

	
	int a = -1;
    int* p;

	p = &a;

	Export_CompareTexasHand(hand1, hand2, board, &a);

	std::cout << "winner = " << a;

	//std::cout << "start: " << result << " :finished";



	std::cin.get();

	return 0;
}