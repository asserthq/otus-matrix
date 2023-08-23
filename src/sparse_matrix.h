#include <array>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

namespace my {

    template<class T>
    class sparse_matrix
    {
    // public:
    //     struct proxy_element
    //     {
    //         sparse_matrix<T>* _matrix;
    //         T _value;

    //         proxy_element(sparse_matrix<T>* matrix, const T& value)
    //             : _matrix(matrix), _value(value)
    //         {}

    //         T& operator=(const T& other)
    //         {
                
    //         }
            
    //     };

    public:
        using index_type = std::array<std::size_t, 2>;
        using stored_type = T;
        using value_type = std::pair<const index_type, stored_type>;

    public:
        sparse_matrix(const T& defValue = T())
            : m_defValue(defValue)
        {
            m_elements.emplace_back(index_type{7, 5}, 55);
            m_elements.emplace_back(index_type{1, 2}, 99);
        }
        
        stored_type at(std::size_t row, std::size_t column) const
        {
            auto it = std::ranges::find(m_elements, index_type{row, column}, &value_type::first);
            if(it != m_elements.cend())
            {
                return it->second;
            }
            else
            {
                return m_defValue;
            }
        }

    private:
        T m_defValue;
        std::vector<value_type> m_elements;
    };

}
