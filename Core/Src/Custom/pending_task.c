/*
 * pending_task.c
 *
 *  Created on: Nov 13, 2022
 *      Author: ntpt
 */

#include "Custom/pending_task.h"

PendingTask_t Custom_PendTask_FromSchedTask(SchedTask_t *stask)
{
    PendingTask_t ret;
    ret.pTask    = stask->pTask;
    ret.pTaskArg = stask->pTaskArg;
    ret.taskID   = stask->priority;

    return ret;
}
