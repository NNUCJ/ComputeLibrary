#include "arm_compute/core/Types.h"


using namespace arm_compute;


void test_ValidRegion(){
    // ValidRegion valid_region;
    
    // 测试 ValidRegion 赋值构造函数
    TensorShape shape({1, 3, 256, 256});
    Coordinates anchor({1, 2, 3});
    printf("before.....\n");
    ValidRegion valid_region_ii = ValidRegion(anchor, shape); 

    ValidRegion region_copy(valid_region_ii);
    std::cout  << "region_copy shape :["<<region_copy.shape[0] <<' ' << region_copy.shape[1] \
                << ' ' << region_copy.shape[2] << ' ' << region_copy.shape[3] << ']'<< std::endl;
}


int main(int argc, char **argv){
    if(argc < 2){
        std::cout << "Please mask sure the params" << std::endl;
        return 0;   
    }
    std::string flag = argv[1];
    if(flag == "test_validregion"){
        test_ValidRegion();
    }
} 