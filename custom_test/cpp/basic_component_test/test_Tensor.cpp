#include <arm_compute/runtime/Tensor.h>

using namespace arm_compute;

int main(int argc, char **argvs){
    Tensor src{};
    src.allocator()->init(TensorInfo(TensorShape(3, 224, 224), 1, DataType::F32));
    src.info();
    printf("test acl tensor");
    return 0;
}