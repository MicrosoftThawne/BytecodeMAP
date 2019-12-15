/* Custom Files */
#include "curl/curl.h"
#include "Utilities.h"
#include "ScriptContext/Memory.h"
#include "ConsoleColours.h"
#include "Definitions.h"

/* C++ Library */
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <fstream>
#include <intrin.h>
#include <Tlhelp32.h>
#include <CommCtrl.h>
#include <fstream>
#include <sstream>
#include <Psapi.h>
#include <stdint.h>
#include <memory>
using namespace std;

	  ///////////////////////////////////////////////////////
	 //			 -------------------------------- 	      //
    //				  Roblox Bytecode M.A.P	     	     //
   //	  		  solution is written by Cindyy	        //
  //			-------------------------------- 	   //
 ///////////////////////////////////////////////////////

void Main()
{
	/* Console Bypass made by idk but i stole it lol */
	DWORD old = 0;
	VirtualProtect(&FreeConsole, 1, 0x40, &old);
	*(uint8_t*)(&FreeConsole) = 0xC3;
	VirtualProtect(&FreeConsole, 1, old, &old);

	AllocConsole();
	freopen("conin$", "r", stdin);						// Enable input
	freopen("conout$", "w", stdout);					// Display output
	freopen("conout$", "w", stderr);					// std error handling
	SetConsoleTitleA(Utilities::random_character(10).c_str());		// Random Console Title Generator

	Utilities::antidump();		// AntiDump
	Utilities::memlock();		// AntiMemory and AntiIntruction editing!
	Utilities::whitelist();		// Whitelist for Seven

	std::cout << iblue << "Scanning for ScriptContext.." << endl;

	/* ScriptContext Scanning */
	_ScriptContext = _(0x1A75F84); // ScriptContextVFTable Address
	uintptr_t v2 = Memory::Scan(PAGE_READWRITE, (char*)& _ScriptContext, (char*)"xxxx"); /* Scan for 'ScriptContextVFTable' Value */

	std::cout << igreen << "Scan Output: " << iyellow << v2 << endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << iblue << "Calculating Final Value.." << endl;

	ScriptContext = v2 + 56 * 0 + 172 - *(DWORD*)(v2 + 56 * 0 + 172); /* Calculate the final value */

	std::cout << igreen << "Final Value: " << iyellow << ScriptContext << endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << iblue << "Set RLuaState.." << endl;

	RobloxLuaState = ScriptContext; /* Set the Roblox LuaState to that value */

	std::cout << igreen << "LuaState: " << iyellow << ScriptContext << endl;

	Sleep(1000);		// Delay 1s

	/* Load all Addresses */

	std::cout << iblue << "Loading Addresses.." << endl;

	luaL_loadaddys(100);		// First argument is the delay between every address being loaded (removed delay)

	std::cout << igreen << "All Addresses Loaded!" << endl;

	Sleep(1000);		// Delay 1s

	const char* _Bytecode = "";		// Roblox Bytecode (has to be for Lua U), could be VM or Script. (Seven used Seven X VM wich was LBI modified by Thawne!)

	std::cout << iblue << "Converting from HEX to Ascii.." << endl;		// Not sure tho.

	/* Hex to ASCII i think, from Rerubi source code as i am too stupid to make my own (lol, sorry) */
	int byte_size = lstrlenA(_Bytecode) / 2;
	uint8_t* bytecode = new uint8_t[byte_size];
	for (int i = 0, j = 0; i < lstrlenA(_Bytecode); i += 2) {
		char c[2];
		c[0] = _Bytecode[i + 0];
		c[1] = _Bytecode[i + 1];
		bytecode[j++] = to_hex(c);
	}

	std::cout << iblue << "Converted!" << endl;

	system("cls");		// Clears the Console window text

	std::cout << iblue << "newthread.." << endl;

	RobloxLuaState = r_newthread(RobloxLuaState);

	std::cout << iblue << "NewThread done!" << endl;

	string chunkname;		// Cache chunkname in here!
	chunkname.append("@");		// add '@' to the chunkname
	chunkname.append(Utilities::random_character(19));		// add 19 random characters to the chunkname
	// final chunkname '@random_characters'
	if (r_deserialize(RobloxLuaState, chunkname.c_str(), (const char*)bytecode, byte_size) == 0)		// Deserialize the "converted bytecode"
	{
		std::cout << igreen << "Executed script!" << endl;
		r_spawn(RobloxLuaState);		// Spawn
		Sleep(250);		// 250 ms delay
		L = luaL_newstate();		// new luastate
		luaL_openlibs(L);		// open libs on the new lua state

	}
	else {
		std::cout << ired << "Deserialize error : " << r_tolstring(RobloxLuaState, 1, NULL) << "\n";		// error
		system("PAUSE");		// pause the Console 'press any key to continue' thing
	}
}

BOOL APIENTRY DllMain(HMODULE Module, DWORD Reason, LPVOID) {
	switch (Reason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(Module);
		DWORD OldProtection;
		VirtualProtect(Module, 0x1000, PAGE_READWRITE, &OldProtection);
		ZeroMemory(Module, 0x1000);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Main, NULL, NULL, NULL);
		break;
	}
	return TRUE;
}
