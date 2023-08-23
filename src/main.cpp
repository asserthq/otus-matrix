#include "sparse_matrix.h"
#include <iostream>
#include <type_traits>

int fact(int n)
{
    if(n < 2) return 1;
    return n * fact(n-1);
}

int main()
{
    auto a = fact(5);
	std::cout << a << '\n';

    my::sparse_matrix<int> mat(-1);
    std::cout << mat.at(7, 5) << '\n';
    std::cout << mat.at(1, 2) << '\n';
    std::cout << mat.at(0, 7) << '\n';
	
    return 0;
}
