#include <arm_compute/core/Utils.h>
#include <arm_compute/core/Types.h>

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

using namespace std;
using namespace arm_compute;


void test_utils_func(std::string &func_name){
    if(func_name == "DIV_CEIL"){
        auto out = DIV_CEIL(10, 4);
        std::cout << "The result of DIV_CEIL(): " <<  out << std::endl;
        std::cout << "The type of result is : "<< typeid(out).name() << std::endl;
        std::cout << "--------- size_t ---------" << std::endl;
        size_t val = 224;
        size_t m = 5; 
        auto out2 = DIV_CEIL(val, m);
        std::cout << "The result of DIV_CEIL(): " <<  out2 << std::endl;
        std::cout << "The type of result is : "<< typeid(out2).name() <<  std::endl;
    }else if(func_name == "data_size_from_type"){

        auto num_byte = data_size_from_type(DataType::U8);
        std::cout << "The byte  of DataType::U8  : "<< num_byte << std::endl;
        
        num_byte = data_size_from_type(DataType::U16);
        std::cout << "The byte  of DataType::U16  : "<< num_byte << std::endl;

        num_byte = data_size_from_type(DataType::F32);
        std::cout << "The byte  of DataType::F32  : "<< num_byte << std::endl;
    }else if(func_name == "data_type_from_format"){
        DataType dt = data_type_from_format(Format::RGB888);
        string dt_str = string_from_data_type(dt);
        std::cout << "The data type of Format::RGB888  : " << dt_str << std::endl;

        std::cout << "==========================================" << std::endl;
        dt = data_type_from_format(Format::U16);
        
        
    }

}

int main(int argc, char **argvs){
    
    if (argc < 2){
        std::cout << "Please confirm if the input parameters are correct" << std::endl;
        std::cout << "Example: ./test_utils  DIV_CEIL" << std::endl;
        return 0;
    }else{
        string func_name = argvs[1];
        test_utils_func(func_name);
    }
    return 0;
}