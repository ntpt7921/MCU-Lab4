/*
 * pending_task.h
 *
 *  Created on: Nov 13, 2022
 *      Author: ntpt
 */

#ifndef INC_CUSTOM_PENDING_TASK_H_
#define INC_CUSTOM_PENDING_TASK_H_

#include "main.h"
#include "Custom/scheduler_task.h"

/*
 * NOTE:
 * When a task has been determined to reach its timeout and are decided to be run
 * (with respect to its priority), the task can be put into a pending queue (normal
 * queue). At this point it is not necessary to store everything about the task
 * any more.
 *
 * A new struct is created to represent a pending task waiting to be run in the
 * pending queue, with fewer data item compare to SchedTask_t
 *
 * A function to convert from a SchedTask_t pointer to a PendingTask_t is provided
 */
typedef struct
{
    SchedTask_Func_t pTask;  // function pointer
    void *pTaskArg;          // argument for task
    uint8_t taskID;          // used to identify task
} PendingTask_t;

PendingTask_t Custom_PendTask_FromSchedTask(SchedTask_t *stask);

#endif /* INC_CUSTOM_PENDING_TASK_H_ */
