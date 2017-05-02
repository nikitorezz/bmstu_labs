#include <iostream>
#include <vector>

template<class IT>
void sort(IT beg, IT end)
{
	for (IT i = beg; i != end; i++){
		IT min = i;
		for (IT j = i; j != end; j++){
			if (*j < *min){
				std::swap(*j, *min);
			}
		}
		if (*min != *i){
			std::swap(*min, *i);
		}
	}
}

int main() {
	int arr[] = { 123, 3, 0, 13212, -100 };
	sort(&arr[0], &arr[3]); // arr: 0, 3, 123, 13212, -100
	sort(&arr[2], &arr[5]); // arr: 0, 3, -100, 123, 13212
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::vector<double> vec = { 123.0, 3.0, 0.0, 13212.0, -100.0 };
	sort(vec.begin(), vec.end()); // vec: -100.0, 0.0, 3.0, 123.0, 13212.0
	for (size_t i = 0; i < 5; i++)
		std::cout << vec.at(i) << " ";
	return 0;
}
