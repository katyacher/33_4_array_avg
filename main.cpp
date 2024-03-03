#include <iostream>
#include <vector>
#include <type_traits>

template<typename T>
T average(const std::vector<T> &vec){
    if(vec.empty()) return T();

    static_assert( std::is_same<T, int>::value || std::is_same<T, float>::value || std::is_same<T, double>::value, "False type" );

    T avg = 0;
    if(vec.size()){
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
    for(int i = 0; i < vec.size(); ++i){
        std::cout << "[" << i << "]: ";
        std::cin >> tmp;
        if(std::cin.fail()){
            std::cin.clear();
            std::string str;
            std::getline(std::cin, str);
            throw std::invalid_argument("Error: wrong type!");
        }
        vec[i] = tmp;
    }
}


int main(int, char**){
    std::cout << "Hello, from 33_4_array_avg!\n";

    std::vector<int> int_vec(8);
    std::vector<double> double_vec(8);
    std::vector<float> float_vec(8);

    try{
        input(int_vec);
    }catch(std::invalid_argument& x){
        std::cout << x.what() << std::endl;
    }

    std::cout << "Average: " << average(int_vec) << std::endl;
    

    try{
        input(double_vec);
    }catch(std::invalid_argument& x){
        std::cout << x.what() << std::endl;
    }
    std::cout << "Average: " << average(double_vec) << std::endl;


    try{
        input(float_vec);
    }catch(std::invalid_argument& x){
        std::cout << x.what() << std::endl;
    }
    std::cout<< "Average: " << average(float_vec) << std::endl;

    return 0;
}
