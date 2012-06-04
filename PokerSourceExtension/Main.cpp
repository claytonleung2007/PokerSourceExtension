#include <windows.h>

HINSTANCE ghInstance;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID)
{
 switch ( dwReason )
 {
  case DLL_PROCESS_ATTACH:

       ghInstance = hInstance;
       break;

  case DLL_PROCESS_DETACH:

       break;

  case DLL_THREAD_ATTACH:

       break;

  case DLL_THREAD_DETACH:

       break;
 }

 return TRUE;
}