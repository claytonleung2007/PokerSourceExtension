#include "PokerUtils.h"
#include <Windows.h>
#include <sstream>
#include <string>
#include <iostream>

extern "C"
{
	#include "..\XPokerEval.Pokersource\include\inlines\eval.h"
	#include "..\XPokerEval.Pokersource\include\inlines\eval_type.h"
	#include "..\XPokerEval.Pokersource\include\enumerate.h"
}

namespace pokerstory{

	const char* Echo(const char* text)
	{
		return text;
	}

	// Helper:
	// Given a string such as "AcKcQcJcTc" representing a poker hand,
	// return an StdDeck_CardMask representing that hand.	
	extern "C" StdDeck_CardMask TextToPokerEval(const char* strHand)
	{
	   StdDeck_CardMask theHand, theCard;
	   StdDeck_CardMask_RESET(theHand);

	   if (strHand && strlen(strHand))
	   {
		  int cardIndex = -1;
		  char* curCard = const_cast<char*>(strHand);

		  while (*curCard)
		  {
			 // Take the card text and convert it to an index (0..51)
			 StdDeck_stringToCard(curCard, &cardIndex); 
			 // Convert the card index to a mask
			 theCard = StdDeck_MASK(cardIndex);
			 // Add the card (mask) to the hand
			 StdDeck_CardMask_OR(theHand, theHand, theCard);
			 // Advance to the next card (if any)
			 curCard += 2;
		  }
	   }

	   return theHand;
	}
	
	/*
		pocket1 and pocket2 are 2 cards represented as strings e.g "AcKc"
		board is made up of 5 cards represented as strings e.g "AcKcQcJcTc"
	*/
	void CompareTexasHand(const char* hand1, const char* hand2, const char* board, int* result)
	{
		// Say we start with something like this...
		StdDeck_CardMask player1 = TextToPokerEval(hand1);
		StdDeck_CardMask player2 = TextToPokerEval(hand2);
		StdDeck_CardMask theBoard = TextToPokerEval(board);

		// Get each player's full 7-card hand into his mask
		StdDeck_CardMask_OR(player1, player1, theBoard);
		StdDeck_CardMask_OR(player2, player2, theBoard);

		// Evaluate each player's hand
		int player1Val = StdDeck_StdRules_EVAL_N(player1, 7);
		int player2Val = StdDeck_StdRules_EVAL_N(player2, 7);
		
		int winner;

		if (player1Val > player2Val)
		   winner = 1;
		else if (player1Val < player2Val)
		   winner = 2;
		else
		   winner = 0;

		result = &winner;
	}

}
