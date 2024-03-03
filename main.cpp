#include <iostream>
#include <vector>
#include <type_traits>

template<typename T>
T average(const std::vector<T> &vec){
    if(vec.empty()) return T();

    static_assert( std::is_same<T, int>::value || std::is_same<T, float>::value || std::is_same<T, double>::value, "False type" );

    T avg = 0;
    if(vec.size())
    {
        for(auto it : vec)
            avg += it;
        avg /=vec.size();
    }

    return avg;
}

template<typename T>
void input(std::vector<T> &vec){

    static_assert( std::is_same<T, int>::value || std::is_same<T, float>::value || std::is_same<T, double>::value, "False type" );

    std::cout << "Fill the vector<" << typeid(T).name()  << "> with values:" << std::endl;

    T tmp;
    for(int i = 0; i < vec.size(); ++i)
    {
        std::cout << "[" << i << "]: ";
        std::cin >> tmp;
        vec[i] = tmp;
    }
}


int main(int, char**){
    std::cout << "Hello, from 33_4_array_avg!\n";

    std::vector<int> int_vec(8);
    std::vector<double> double_vec(8);
    std::vector<float> float_vec(8);

    input(int_vec);
    std::cout << "Average: " << average(int_vec) << std::endl;

    input(double_vec);
    std::cout << "Average: " << average(double_vec) << std::endl;

    input(float_vec);
    std::cout<< "Average: " << average(float_vec) << std::endl;

    return 0;
}
