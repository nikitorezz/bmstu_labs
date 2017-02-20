#include "TVector.h";

int main() {
	TVector vec1;
	std::cout << "vec1 " << vec1 << std::endl;
	double arr[3] = { 1.0, 1.5, 2.4 };
	TVector vec2(arr, 3);
	std::cout << "vec2 " << vec2 << std::endl;
	vec1 = vec2;
	std::cout << "vec1 " << vec1 << std::endl;
	std::cout << "vec1[1] " << vec1[1] << std::endl;
	vec1[0] = vec2[2];
	std::cout << "vec1 " << vec1 << std::endl;
	std::cout << "vec1*vec2 " << vec1*vec2 << std::endl;
}
