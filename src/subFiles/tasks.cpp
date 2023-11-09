#include "main.h"

void my_task_fn(void* param) {
    std::cout << "Hello" << (char*)param;
}