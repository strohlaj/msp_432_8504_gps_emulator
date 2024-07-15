
#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include "stdint.h"
#include "string.h"
#include "stdbool.h"

typedef enum {
    LOW,
    MEDIUM,
    HIGH
} EVENT_PRIORITY;

typedef enum {
    STATUS_REPORT,
    KEEP_ALIVE_LED,
    BUTTON_PRESSED,
    TIME_MARKED_PULSE_COMPLETE,
} EVENT_ID;

typedef struct _queue_item {
    EVENT_ID eventId;
// todo: consider data to be passed into the queue
//    uint8_t* data;
//    uint8_t size;
} queue_item;

void init_queue(void);
bool priority_enqueue(EVENT_PRIORITY priority, queue_item item);
// Defaults to low priority
void enqueue(queue_item item);
bool dequeue(queue_item* item);

#endif /* PRIORITY_QUEUE_H_ */
