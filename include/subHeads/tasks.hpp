#include "main.h"

/**
 * Task function to get controller inputs
 * \param param (void*) put a NULL pointer here or smth idk
 * \note Run in task using pros::Task
 * \returns None
*/
extern void inputs_task_fn(void* param);

/**
 * Task function to control the chassis
 * \param param (void*) put a NULL pointer here or smth idk
 * \note Run in task using pros::Task
 * \returns None
*/
extern void chassis_task_fn(void* param);