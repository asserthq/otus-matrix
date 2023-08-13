#include "sparse_matrix.h"
#include <iostream>

int fact(int n)
{
    if(n < 2) return 1;
    return n * fact(n-1);
}

int main()
{
    auto a = fact(5);
	std::cout << a << '\n';
	
    return 0;
}
