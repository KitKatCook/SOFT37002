#pragma once
class UtilityMethods
{
public:
	static int Max(int a, int b);
};

// A utility function to get maximum
// of two integers
int UtilityMethods::Max(int a, int b)
{
	return a > b ? a : b;;
}

