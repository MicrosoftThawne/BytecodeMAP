#pragma once
#include <Windows.h>
using namespace std;

#define _getfield			0x764d60
#define getfield_			__cdecl 
#define _pushstring			0x766380
#define pushstring_			__fastcall 
#define _newthread			0x765850 
#define newthread_			__cdecl 
#define _pcall				0x765d50 
#define pcall_				__cdecl 
#define _spawn				0x6d6360 
#define spawn_				__cdecl
#define _deserialize		0x840c90   
#define deserialize_		__cdecl  
#define _tolstring	    	0x7675F0  
#define tolstring_   		__fastcall  

namespace Addresses
{
	typedef char(tolstring_* t_tolstring)(DWORD, int, int);
	t_tolstring r_tolstring;

	typedef void(getfield_* T_r_getfield)(int, int, const char*);
	T_r_getfield r_getfield;


	typedef int(newthread_* T_r_newthread)(int);
	T_r_newthread r_newthread;

	typedef void(pushstring_* T_r_pushlstring)(int, const char*, int);
	T_r_pushlstring r_pushlstring;

	typedef void(pcall_* T_r_pcall)(int, int, int, int);
	T_r_pcall r_pcall;

	typedef int(deserialize_* T_r_deserialize)(int, const char*, const char*, size_t);
	T_r_deserialize r_deserialize;

	typedef void(spawn_* T_r_spawn)(int);
	T_r_spawn r_spawn;
}