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
	
	//const char* myecho = pokerstory::Echo("echo echo");
	//return alloc_string(PokerUtils::Echo(text));	

	return alloc_string(pokerstory::Echo(text));
}
DEFINE_PRIM (pse_echo, 1);

extern "C" void test_main () {
	
	// Here you could do some initialization, if needed
	
}
DEFINE_ENTRY_POINT (test_main);

extern "C" int test_register_prims () { return 0; }