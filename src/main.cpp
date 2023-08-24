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

    int val = mat[1][7];

    std::cout << val << '\n';

    val = 35;

    std::cout << (mat[1][7] = mat[5][5] = 5) << '\n';

    std::cout << mat[1][7] << '\n';

    mat.set_default_value(100);

    std::cout << mat[5][5] << '\n';

    std::cout << mat[1][1] << '\n';

    mat[5][5] = -1;
    
    std::cout << mat[5] << '\n';

    //std::cout << mat.at(7, 5) << '\n';
    //std::cout << mat.at(1, 2) << '\n';
    //std::cout << mat.at(0, 7) << '\n';

    std::array<int, 3> arr = {-7}; 
    auto k = std::ranges::empty(arr);
    std::cout << k;
	
    return 0;
}
