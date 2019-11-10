//
// Created by xoryo on 11/9/19.
//

#ifndef CGRAPH_LIBRARY_QUEUE_H
#define CGRAPH_LIBRARY_QUEUE_H

/* function return codes. */
#define QUEUE_SUCCESS 0
#define QUEUE_ERR_CAPACITY_REACHED 1
#define QUEUE_EMPTY 2
#define QUEUE_NOT_EMPTY 3

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Queue {
    unsigned int pointer; // Next to dequeue.
    unsigned int position; // Next position to add element.
    unsigned int capacity; // Capacity of the queue.
    int *elements; // Element of the queue.
    int size; // Size of the current queue.
} Queue;


/**
 * Initializes the queue.
 * @param capacity The capacity of the queue.
 * @return A new initialized queue.
 */
Queue *init_queue(unsigned int capacity);

/**
 * Checks if the queue is empty.
 * @param queue The queue to check.
 * @return  QUEUE_EMPTY if queue is not empty
 *          QUEUE_NOT_EMPTY if queue is empty.
 */
int queue_empty(Queue *queue);

/**
 * Pushes an element onto the queue.
 * @param queue The queue to use.
 * @param element The element to push onto the queue.
 * @return  QUEUE_SUCCESS if element is added
 *          QUEUE_ERR_CAPACITY_REACHED if capacity is reached.
 */
int queue_push(Queue *queue, int element);

/**
 * Pops an element from the queue.
 * @param queue The queue to use.
 * @param result The resulting element.
 * @return  QUEUE_SUCCESS if successfully popped
 *          QUEUE_EMPTY if queue is empty, and nothing could be popped.
 */
int queue_pop(Queue *queue, int *result);

/**
 * Destroys the queue and frees the memory.
 * @param queue The queue to be destroyed.
 */
void destroy_queue(Queue *queue);

#ifdef __cplusplus
}
#endif

#endif //CGRAPH_LIBRARY_QUEUE_H
