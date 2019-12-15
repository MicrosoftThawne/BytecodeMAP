#pragma once
#include <Windows.h>
#include <string>
using namespace std;

namespace Utilities
{
	void antidump()
	{
		/* snipped, just get it from Synapse X source code */
	}
	void memlock()
	{
		/* snipped, private! */
		/* Will exit if intructions are edited or something */
	}
	void whitelist()
	{
		/* snipped */
		/* simple whitelist (hwid, mac, pcname, pcuser, ip) */
	}

	/* Generate a random character pattern */
	std::string random_character(int length) {
		std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		std::string ppj;
		int pos = 0;
		while (pos != length) {
			int ppk = ((rand() % (str.size() - 1)));
			ppj = ppj + str[ppk];
			pos += 1;
		}
		return ppj.c_str();
	}
}
