/*
 * gps_structures.h
 *
 *  Created on: Jul 13, 2024
 *      Author: AaronStrohl
 */

#ifndef GPS_STRUCTURES_H_
#define GPS_STRUCTURES_H_
#include "stdint.h"


typedef enum Gender {
    MALE = 1,
    FEMALE= 2
} Gender;

typedef struct Person {
    uint8_t age;
    Gender gender;
} Person_t;


#endif /* GPS_STRUCTURES_H_ */
