#include "main.h"

// Random test task function lol
extern void my_task_fn(void* param);

/**
 * Task function to get controller inputs
 * \param param (void*) put a NULL pointer here or smth
 * \note Run in task using pros::Task
 * \returns None
*/
extern void inputs_task_fn(void* param);