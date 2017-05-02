#include <iostream>
template<int N>
struct meta_print {
	static void out(std::ostream& os)
	{
		meta_print<N - 1>::out(os);
		os << N << std::endl;
	}
};
template<>
struct meta_print<1> {
	static void out(std::ostream& os)
	{
		os << 1 << std::endl;
	}
};
int main() {
	meta_print<100>::out(std::cout);
}
