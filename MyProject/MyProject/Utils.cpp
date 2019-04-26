#include "Utils.h"
#include <algorithm>
#include <string>

template <typename T> int partition(vector<T> &v, int start, int end) {
	int i = start + 1;
	T pivot = v[start];

	for (int j = start + 1; j <= end; j++) {
		if (v[j] < pivot) {
			iter_swap(v.begin() + i, v.begin() + j);
			i++;
		}
	}

	iter_swap(v.begin() + start, v.begin() + i - 1);
	return i - 1;
}

template <typename T> void utils::quickSort(vector<T> &v, int start, int end) {
	if (start < end) {
		int pivotPos = partition(v, start, end);
		quickSort(v, start, pivotPos - 1);
		quickSort(v, pivotPos + 1, end);
	}
}

// Explicit instantiation
template void utils::quickSort<int>(vector<int> &v, int start, int end);
template void utils::quickSort<long>(vector<long> &v, int start, int end);
template void utils::quickSort<float>(vector<float> &v, int start, int end);
template void utils::quickSort<double>(vector<double> &v, int start, int end);
template void utils::quickSort<string>(vector<string> &v, int start, int end);