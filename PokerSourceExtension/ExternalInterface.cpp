#ifndef IPHONE
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif

#include <hx/CFFI.h>
#include <stdio.h>
#include "PokerUtils.h"


static value pse_echo(value message)
{	
	const char* text = val_string(message);
	
	return alloc_string(pokerstory::Echo(text));
}
DEFINE_PRIM (pse_echo, 1);

static value pse_CompareTexasHand(value hand1, value hand2, value board)
{
	return alloc_int(pokerstory::CompareTexasHand(val_string(hand1), val_string(hand2), val_string(board)));
}
DEFINE_PRIM (pse_CompareTexasHand, 3);

extern "C" void test_main () {
	
	// Here you could do some initialization, if needed
	
}
DEFINE_ENTRY_POINT (test_main);

extern "C" int test_register_prims () { return 0; }