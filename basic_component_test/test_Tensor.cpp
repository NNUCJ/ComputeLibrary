/*
 * 2023 by ICLEAGUE Author, All Rights Reserved.
 * @Description: 
 * @Author: Paul Cheng(成杰)
 * @version: V0.1
 * @Date: 2023-08-22 02:37:42
 * @LastEditors: Paul Cheng(成杰)
 * @FilePath: /ComputeLibrary/basic_component_test/test_Tensor.cpp
 */
#include <arm_compute/runtime/Tensor.h>

using namespace arm_compute;

int main(int argc, char **argvs){
    printf("test acl tensor\n");
    Tensor src{};
    src.allocator()->init(TensorInfo(TensorShape(3, 224, 224), 1, DataType::F32));
    // src..allocator().init(TensorInfo(TensorShape(3, 224, 224), 1, DataType::F32));
    src.allocator()->allocate();
    return 0;
}