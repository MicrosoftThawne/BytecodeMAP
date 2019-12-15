#pragma once
#include "Addresses.h"
#include "retcheck.h"
extern "C" {
#include "Lua\lua.h"
#include "Lua\ldo.h"
#include "Lua\lapi.h"
#include "Lua\lualib.h"
#include "Lua\lstate.h"
#include "Lua\lauxlib.h"
#include "Lua\luaconf.h"
#include "Lua\llimits.h"
#include "Lua\lapi.h"
#include "Lua\lfunc.h"
#include "Lua/lopcodes.h"
#include "Lua\lobject.h"
}

#include <Windows.h>
using namespace std;
DWORD _ScriptContext;		// Store the ScriptContextVFTable address
DWORD ScriptContext;		// Store the ScriptContext value until passed onto RobloxLuaState
DWORD RobloxLuaState;		// Roblox LuaState
lua_State* L;

#define _(_) (_ - 0x400000 + (DWORD)GetModuleHandle(NULL))		// Grab an offset from current process

const char c_ref1[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
const int c_ref2[16] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15 };

uint8_t to_hex(char* x) {
	if (lstrlenA(x) != 2) return 0;
	uint8_t b = 0;
	for (int i = 0; i < 16; i++) {
		if (x[0] == c_ref1[i]) b += c_ref2[i] * 16;
		if (x[1] == c_ref1[i]) b += i;
	}
	return b;
}

using namespace Addresses;
using namespace retcheck;
namespace Addresses
{
	/* delay was removed cause i was stupid and forgot it would crash :lmfao: */
	void luaL_loadaddys(int delay)		// Inside Joke!
	{
		std::cout << "1" << endl;
		r_getfield = reinterpret_cast<T_r_getfield>(patch(_(_getfield)));
		//////////////////////////////////////////////////////////////////
		//Sleep(delay);
		//////////////////////////////////////////////////////////////////
		std::cout << "2" << endl;
		r_pushlstring = reinterpret_cast<T_r_pushlstring>(patch(_(_pushstring)));
		//////////////////////////////////////////////////////////////////
		//Sleep(delay);
		//////////////////////////////////////////////////////////////////
		std::cout << "3" << endl;
		r_newthread = reinterpret_cast<T_r_newthread>(patch(_(_newthread)));
		//////////////////////////////////////////////////////////////////
		//Sleep(delay);
		//////////////////////////////////////////////////////////////////
		std::cout << "4" << endl;
		r_pcall = reinterpret_cast<T_r_pcall>(patch(_(_pcall)));
		//////////////////////////////////////////////////////////////////
		//Sleep(delay);
		//////////////////////////////////////////////////////////////////
		std::cout << "5" << endl;
		r_spawn = reinterpret_cast<T_r_spawn>(_(_spawn));
		//////////////////////////////////////////////////////////////////
		//Sleep(delay);
		//////////////////////////////////////////////////////////////////
		std::cout << "6" << endl;
		r_deserialize = reinterpret_cast<T_r_deserialize>(_(_deserialize));
		//////////////////////////////////////////////////////////////////
		//Sleep(delay);
		//////////////////////////////////////////////////////////////////
		std::cout << "7" << endl;
		r_tolstring = reinterpret_cast<t_tolstring>(_(_tolstring));
	}
}