#include "arm_compute/core/TensorShape.h"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace arm_compute;

template <typename T>
string print_Dimensions(Dimensions<T>& test){
    std::ostringstream  out;
    auto max_dim = test.num_dimensions();
    for(auto i=0; i< max_dim; i++){
        out << test[i];
        out << ", ";
    }
    return out.str();
}



void test_func(string &func_name, TensorShape& tensor_shape){
    if (func_name == "set") {
       
        TensorShape tensor_shape_copy(tensor_shape);
        // set dim 1 to zero 
        std::cout << "----------tensor_shape_copy.set(1, 0)-------------" << std::endl;
        tensor_shape_copy.set(1, 0);
        std::cout << "The number of dimension: " << tensor_shape_copy.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_copy) << std::endl;
        
        TensorShape tensor_shape_copy2(tensor_shape);
        std::cout << "----------tensor_shape_copy2.set(1, 32)-------------" << std::endl;
        tensor_shape_copy2.set(1, 32);
        std::cout << "The number of dimension: " << tensor_shape_copy2.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_copy2) << std::endl;

        // TensorShape tensor_shape_copy(tensor_shape);
        std::cout << "----------tensor_shape_copy2.set(4, 32)-------------" << std::endl;
        tensor_shape_copy2.set(4, 32);
        std::cout << "The number of dimension: " << tensor_shape_copy2.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_copy2) << std::endl;
       
        // TensorShape tensor_shape_copy(tensor_shape);
        std::cout << "----------tensor_shape_copy2.set(5, 1, increase_dim_unit=false)-------------" << std::endl;
        tensor_shape_copy2.set(5, 1, true, false);
        std::cout << "The number of dimension: " << tensor_shape_copy2.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_copy2) << std::endl;

        std::cout << "----------tensor_shape_copy2.set(5, 1, true, true)-------------" << std::endl;
        tensor_shape_copy2.set(5, 1, true, true);
        std::cout << "The number of dimension: " << tensor_shape_copy2.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_copy2) << std::endl;

        std::cout << "----------tensor_shape_copy2.set(5, 1, false, true)-------------" << std::endl;
        tensor_shape_copy2.set(5, 1, false, true);
        std::cout << "The number of dimension: " << tensor_shape_copy2.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_copy2) << std::endl;
    }else if(func_name=="remove_dimension"){
        // 赋值运算符
        TensorShape tensor_shape_copy = tensor_shape;
        tensor_shape_copy.set(2, 1);
        std::cout << "The number of dimension: " << tensor_shape_copy.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_copy) << std::endl;
        tensor_shape_copy.remove_dimension(3);
        std::cout << "The number of dimension: " << tensor_shape_copy.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_copy) << std::endl;
    }else if(func_name == "collapse"){
        TensorShape tensor_shape_copy(std::move(tensor_shape));
        
        tensor_shape_copy.collapse(2, 2);
        std::cout << "The number of dimension: " << tensor_shape_copy.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_copy) << std::endl;
    }else if(func_name == "collapsed_from"){
        TensorShape tensor_shape_out = tensor_shape.collapsed_from(2);
        std::cout << "The number of dimension: " << tensor_shape_out.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_out) << std::endl;
    }else if(func_name == "shift_right"){
        TensorShape tensor_shape_copy = std::move(tensor_shape);
        tensor_shape_copy.shift_right(2);
        std::cout << "The number of dimension: " << tensor_shape_copy.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape_copy) << std::endl;
    }else if(func_name=="broadcast_shape"){
        TensorShape bc_shape;
        std::cout << "The number of dimension: " << bc_shape.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(bc_shape) << std::endl;
        
        bc_shape = TensorShape::broadcast_shape(bc_shape, tensor_shape);
        std::cout << "The number of dimension: " << bc_shape.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(bc_shape) << std::endl;

        std::cout << "----------------------test2 ----------------------------" << std::endl;
        TensorShape bc_shape2(1, 3);
        std::cout << "The number of dimension: " << bc_shape2.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(bc_shape2) << std::endl;
        bc_shape2 = TensorShape::broadcast_shape(bc_shape2, tensor_shape);
        
        std::cout << "The number of dimension tensor_shape: " << tensor_shape.num_dimensions() << std::endl;
        std::cout << "The values of each dimension tensor_shape:" << print_Dimensions(tensor_shape) << std::endl;
        std::cout << "The number of dimension: " << bc_shape2.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(bc_shape2) << std::endl;
        
    }
    
}

int main(int argc, char **argv){
    
    if (argc < 2){
        std::cout << "Please confirm if the input parameters are correct" << std::endl;
        std::cout << "Example: ./test_dimensions  member_func_name" << std::endl;
    }
    else {
        // init TensorShape
        TensorShape tensor_shape(1, 3, 224, 224);
        std::cout << "----------tensor_shape info-------------" << std::endl;
        std::cout << "The number of dimension: " << tensor_shape.num_dimensions() << std::endl;
        std::cout << "The values of each dimension:" << print_Dimensions(tensor_shape) << std::endl;
        string func_name = argv[1];
        TensorShape *tensor_shape_test; 
        test_func(func_name, tensor_shape);
    }
    return 0;
}