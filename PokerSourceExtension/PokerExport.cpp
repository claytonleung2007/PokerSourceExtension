#include <Windows.h>
#include "PokerUtils.h"

__declspec(dllexport) const char* Export_Echo(const char* text)
{
	return pokerstory::Echo(text);	
}

__declspec(dllexport) int __stdcall Export_CompareTexasHand(const char* hand1, const char* hand2, const char* board)
{
	return pokerstory::CompareTexasHand(hand1, hand2, board);
}

