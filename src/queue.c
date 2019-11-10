#include "queue.h"
#include <stdlib.h>

Queue *init_queue(unsigned int capacity) {
	Queue *queue = malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->pointer = 0;
	queue->position = 0;
	queue->size = 0;
	queue->elements = malloc(sizeof(int) * capacity);

	return queue;
}

int queue_empty(Queue *queue) {
	if (queue->size == 0) return QUEUE_EMPTY;
	return QUEUE_NOT_EMPTY;
}

int queue_push(Queue *queue, int element) {
	if (queue->size == queue->capacity) return QUEUE_ERR_CAPACITY_REACHED;

	queue->elements[queue->position] = element;
	queue->position = (queue->position + 1) % queue->capacity;
	++queue->size;

	return QUEUE_SUCCESS;
}

int queue_pop(Queue *queue, int *result) {
	if (queue_empty(queue) == QUEUE_EMPTY) return QUEUE_EMPTY;

	int element = queue->elements[queue->pointer];
	*result = element;

	queue->elements[queue->pointer] = 0;
	--queue->size;
	queue->pointer = (queue->pointer + 1) % queue->capacity;

	return QUEUE_SUCCESS;
}