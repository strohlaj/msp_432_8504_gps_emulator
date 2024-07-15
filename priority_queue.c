#include "priority_queue.h"
#include <string.h>

#define MAX_QUEUE_SIZE 5

static uint8_t hi_head = 0;
static uint8_t hi_tail = 0;

static uint8_t med_head = 0;
static uint8_t med_tail = 0;

static uint8_t low_head = 0;
static uint8_t low_tail = 0;


static queue_item high_priority_queue[MAX_QUEUE_SIZE];
static queue_item medium_priority_queue[MAX_QUEUE_SIZE];
static queue_item low_priority_queue[MAX_QUEUE_SIZE];

static bool hi_priority_queue_is_full();
static bool medium_priority_queue_is_full();
static bool low_priority_queue_is_full();

static bool hi_priority_queue_is_empty();
static bool medium_priority_queue_is_empty();
static bool low_priority_queue_is_empty();

void init_queue(void) {
    // hi_head, hi_tail, med_head, med_tail, low_head, low_tail = 0;
    memset(high_priority_queue, 0, sizeof(queue_item) * MAX_QUEUE_SIZE);
    memset(medium_priority_queue, 0, sizeof(queue_item) * MAX_QUEUE_SIZE);
    memset(low_priority_queue, 0, sizeof(queue_item) * MAX_QUEUE_SIZE);
}

bool priority_enqueue(EVENT_PRIORITY priority, queue_item item) {
    if (priority == HIGH) {
        if (hi_priority_queue_is_full()) return false;
        high_priority_queue[hi_tail] = item;
        hi_tail = (hi_tail + 1) % MAX_QUEUE_SIZE;
    } else if (priority == MEDIUM) {
        if (medium_priority_queue_is_full()) return false;
        medium_priority_queue[med_tail] = item;
        med_tail = (med_tail + 1) % MAX_QUEUE_SIZE;
    } else {
        if (low_priority_queue_is_full()) return false;
        low_priority_queue[low_tail] = item;
        low_tail = (low_tail + 1) % MAX_QUEUE_SIZE;
    }
    return true;
}

void enqueue(queue_item item) {
    priority_enqueue(HIGH, item);
}

bool dequeue(queue_item* item) {
    if (!hi_priority_queue_is_empty()) {
        memcpy(item, &high_priority_queue[hi_head], sizeof(queue_item));
        hi_head = (hi_head + 1) % MAX_QUEUE_SIZE;
        return true;
    } else if (!medium_priority_queue_is_empty()) {
        // todo implement
        return false;
    } else if (!low_priority_queue_is_empty()) {
        // todo implement
        return false;
    } else {
        // todo implement
        return false;
    }
}

bool hi_priority_queue_is_full() {
    return (hi_tail + 1) % MAX_QUEUE_SIZE == hi_head;
}

bool medium_priority_queue_is_full() {
    return (med_tail + 1) % MAX_QUEUE_SIZE == med_head;
}

bool low_priority_queue_is_full() {
    return (low_tail + 1) % MAX_QUEUE_SIZE == low_head;
}

bool hi_priority_queue_is_empty() {
    return hi_tail == hi_head;
}

bool medium_priority_queue_is_empty() {
    return med_tail == med_head;
}

bool low_priority_queue_is_empty() {
    return low_tail == low_head;
}

