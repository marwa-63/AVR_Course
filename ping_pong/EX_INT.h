/*
 * EX_INT.h
 *
 *  Created on: Feb 2, 2024
 *      Author: HP
 */

#ifndef EX_INT_H_
#define EX_INT_H_

#include "stdTypes.h"
#include "priv.h"
#include "config.h"

 void EXINT_Init(void);
 void EXINT_Enable(u8 EXINT_ID);
 void EXINT_Disable(u8 EXINT_ID);
 void EXINTGLOBAL_Enable(void);
 void EXINTGLOBAL_Disable(void);
 void EXINT_Callback(void (*Func_ptr) (void) );
 void Vector(void);

#endif /* EX_INT_H_ */
