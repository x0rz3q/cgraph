#include <gtest/gtest.h>
#include <queue.h>

/**
 * Tests queue initialization.
 */
TEST(QueueTest, InitializeQueue) {
    Queue *queue = init_queue(100);
    EXPECT_EQ(queue->capacity, 100);
    EXPECT_EQ(queue->pointer, 0);
    EXPECT_EQ(queue->size, 0);
    EXPECT_EQ(queue->position, 0);
}

/**
 * Tests if queue is empty check.
 */
TEST(QueueTest, QueueEmpty) {
    Queue *queue = init_queue(10);
    EXPECT_EQ(queue_empty(queue), QUEUE_EMPTY);
}

/**
 * Tests queue push.
 */
TEST(QueueTest, QueuePush) {
    Queue *queue = init_queue(100);
    EXPECT_EQ(queue_push(queue, 1), QUEUE_SUCCESS);
    EXPECT_EQ(queue->elements[queue->pointer], 1);
}

/**
 * Tests queue pop.
 */
TEST(QueueTest, QueuePop) {
    Queue *queue = init_queue(100);

    int start_element = 20;
    for (int i = start_element; i < start_element + 10; i++) {
        queue_push(queue, i);
    }

    int result = 0;
    EXPECT_EQ(queue_pop(queue, &result), QUEUE_SUCCESS);
    EXPECT_EQ(result, start_element);
}

/**
 * Tests if queue will be empty after all elements are popped.
 */
TEST(QueueTest, QueuePopEmpty) {
    Queue *queue = init_queue(100);

    for (int i = 0; i < 10; i++) {
        queue_push(queue, i);
    }

    for (int i = 0; i < 10; i++) {
        int result = 0;
        queue_pop(queue, &result);
    }

    EXPECT_EQ(queue_empty(queue), QUEUE_EMPTY);
}

/**
 * Tests destroying the graph.
 */
TEST(QueueTest, QueueDestroy) {
    Queue *queue = init_queue(100);
    destroy_queue(queue);
}