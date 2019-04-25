#pragma once
#include <vector>

using namespace std;

class Utils {
public:
	template <typename T> static void quickSort(vector<T> &v, int start, int end);
};