#include <iostream>
#include <sstream>
#include <cstdlib>

#include "arm_compute/core/Dimensions.h"
#include "arm_compute/core/TensorShape.h"

using namespace arm_compute;
using namespace std;

// void test_constructed(){
//     printf("Testing for constructed\n");
//     Dimensions<int> test(1, 2, 3, 4);
//     // test copy constructed
//     std::cout << "test copy constructed (Dimensions(const Dimensions &) = default)" << std::endl;
//     Dimensions<int> test2(test);
//     std::cout << "test class to be copied:\nDimensions &operator=(const Dimensions &) = default" << std::endl;
//     Dimensions<int> test3 = test2;
//      std::cout << "compare test & test2: " << (test3!=test2) << std::endl;
//     // 验证移动构造函数与移动赋值运算
//     std::cout << "[Dimensions(Dimensions &&) = default] api test" << std::endl;
//     Dimensions<int> test4(std::move(test3));
//     std::cout << "compare test4 & test3: " << (test3==test4) << std::endl;
//     std::cout << "[Dimensions &operator=(Dimensions &&) = default] api test" << std::endl;
//     Dimensions<int> test5 = std::move(test4);
//     std::cout << "compare test4 & test5: " << (test5==test4) << std::endl;
// }

// template <typename T>
// string print_Dimensions(Dimensions<T>& test){
//     std::ostringstream  out;
//     auto max_dim = test._num_dimensions;
//     for(auto i=0; i< max_dim; i++){
//         out << test[i];
//         out << ", ";
//     }
//     return out.str();
// }

// void test_func(string& func_name){
//     printf("Testing for member func\n");
//     Dimensions<int> test(1, 1, 224, 224);
//     std::cout << "The values of each dimension:" << print_Dimensions(test) << std::endl;
//     if (func_name == "set"){
//         test.set(1, 3);
//         std::cout << "The values of each dimension after using set() member func:" << print_Dimensions(test) << std::endl;
//         std::cout << " ----------- test set() func dimension > _num_dimensions ----------" << std::endl;
//         test.set(4, 8);
//         std::cout << "The values of each dimension after using set() member func:" << print_Dimensions(test) << std::endl;
//     }else if(func_name == "increment"){
//         test.increment(2, 32);
//         test.increment(3, 32);
//         std::cout << "The values of each dimension after using increment() member func:" << print_Dimensions(test) << std::endl;
//     }else if(func_name == "set_num_dimensions"){
//         test.set_num_dimensions(5);
//         std::cout << "The number of dimension: " << test.num_dimensions() << std::endl;
//         std::cout << "The values of each dimension:" << print_Dimensions(test) << std::endl;

//     }else if(func_name == "collapse"){
//         test.collapse(2, 1);
//         std::cout << "The number of dimension: " << test.num_dimensions() << std::endl;
//         std::cout << "The values of each dimension:" << print_Dimensions(test) << std::endl;
//     }else if(func_name == "remove"){
//         test.remove(1);
//         std::cout << "The number of dimension: " << test.num_dimensions() << std::endl;
//         std::cout << "The values of each dimension:" << print_Dimensions(test) << std::endl;
//     }
    
// }

int main(int argc, char **argv){
    std::cout << "Please make sure 'protected' -> 'Public' in Dimensions.h" << std::endl; 
    // if (argc < 2){
    //    std::cout << "Please confirm if the input parameters are correct" << std::endl;
    //    std::cout << "Example: ./test_dimensions  1" << std::endl;
    // }
    // else{
    //     string func_name;
    //     int flag = atoi(argv[1]);
    //     if (argc == 3)  func_name = (argv[2]);
    //     switch (flag)
    //     {
    //     case 1:
    //         test_constructed();
    //         break;
    //     case 2:
    //         test_func(func_name);
    //         break;
    //     default:
    //         test_constructed();
    //     }
    
    // }
   
    return 0;
}