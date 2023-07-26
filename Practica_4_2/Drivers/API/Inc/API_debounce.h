/*
 * API_debounce.h
 *
 *  Created on: Jul 26, 2023
 *      Author: Carlos Mendoza
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

#include "stdint.h"
#include "stdbool.h"
#include "main.h"

typedef bool bool_t;

void debounceFSM_init(void);
void debounceFSM_update(void);
bool_t readKey();

#endif /* API_INC_API_DEBOUNCE_H_ */
