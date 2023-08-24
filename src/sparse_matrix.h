#include <array>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <iostream>
#include <algorithm>

namespace my {

    template<class T>
    class sparse_matrix
    {
    public:
        using KeyType = std::array<std::size_t, 2>;
        using ValueType = T;
        using MapType = std::map<KeyType, ValueType>;

        struct value_proxy
        {
            sparse_matrix<T>* _mat;
            KeyType _key;
            std::size_t _index;

            value_proxy(const KeyType& key, sparse_matrix<T>* mat)
                : _mat(mat), _key(key), _index(2)
            {}

            value_proxy(const std::size_t i, sparse_matrix<T>* mat)
                : _mat(mat), _key({i}), _index(1)
            {}

            auto& operator[](const std::size_t i)
            {
                _key[_index] = i;
                ++_index;
                return *this;
            }

            ValueType operator=(const ValueType& other)
            {
                return _mat->set(_key, other);
            }

            operator ValueType() const
            {
                return _mat->get(_key);
            }
        };

    public:
        sparse_matrix(const ValueType& defValue = ValueType())
            : m_defValue(defValue)
        {}
        
        value_proxy at(std::size_t row, std::size_t column)
        {
            return value_proxy(KeyType{ row, column }, this);
        }

        value_proxy operator[](const std::size_t i)
        {
            return value_proxy(i, this);
        }

        void set_default_value(const ValueType& value)
        {
            m_defValue = value;
        }

    private:
        const ValueType& get(const KeyType& key) const
        {
            auto it = m_map.find(key);
            if(it != m_map.cend())
            {
                return it->second;
            }
            return m_defValue;
        }

        ValueType set(const KeyType& key, const ValueType& value)
        {
            if(value == m_defValue)
            {
                m_map.erase(key);
                return value;
            }

            auto [it, inserted] = m_map.insert_or_assign(key, value);
            return it->second;
        }

    private:
        ValueType m_defValue;
        MapType m_map;
    };

}
