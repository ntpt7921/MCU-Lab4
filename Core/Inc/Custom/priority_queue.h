/*
 * priority_queue.h
 *
 *  Created on: Nov 10, 2022
 *      Author: ntpt
 */

#ifndef INC_CUSTOM_PRIORITY_QUEUE_H_
#define INC_CUSTOM_PRIORITY_QUEUE_H_

#include "main.h"

// this function return true if the first arg is <= the second arg
typedef uint8_t (*Compare_function_t)(void*, void*);

/*
 * NOTE:
 * This module define function that work on a statically allocated priority
 * queue (binary heap). Whether it is max-heap or min-heap is not important,
 * since we will provide the comparison function between element.
 *
 * It is assumed that the array containing the heap already exists, and 
 * we can access the top element of the heap at array[0]
 *
 * The operation defined for the heap are:
 * - heap_create: make heap from random array
 * - heap_insert: insert a element into the heap
 * - heap_pop: remove the top element of the heap
 *
 * This module is written with reuse in mind, so it is necessarily general
 * and unoptimized. Each function takes a slew of argument:
 * - the pointer to array containing the heap
 * - the array max size (in element count)
 * - the element size
 * - the current element count within array
 * - the compare function
 * - pointer to the element to add (heap_create)
 */

void Custom_PQueue_Create(void *arr, size_t asize, size_t esize, size_t elemc,
        Compare_function_t cmp);
void Custom_PQueue_Insert(void *arr, size_t asize, size_t esize, size_t elemc, void *elem,
        Compare_function_t cmp);
void Custom_PQueue_Pop(void *arr, size_t asize, size_t esize, size_t elemc,
        Compare_function_t cmp);

#endif /* INC_CUSTOM_PRIORITY_QUEUE_H_ */
