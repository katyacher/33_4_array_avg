#include <iostream>
#include <vector>
#include <exception>

template<typename T>
T average(const std::vector<T> &vec)
{
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
void input(std::vector<T> &vec)
{
    T tmp;
    for(int i = 0; i < vec.size(); ++i)
    {
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
    std::cout << average(int_vec) << std::endl;

    input(double_vec);
    std::cout << average(double_vec) << std::endl;

    input(float_vec);
    std::cout << average(float_vec) << std::endl;

    return 0;
}
