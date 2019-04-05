#include "pch.h"
#include "gameFunction.h"

Row stringToRow(std::string s)
{
	if (s == "a") return a;
	if (s == "b") return b;
	if (s == "c") return c;
	if (s == "d") return d;
	if (s == "e") return e;
	if (s == "f") return f;
	if (s == "g") return g;
	if (s == "h") return h;
	std::cout << "bad input, assuming row a\n";
	return a;

}
