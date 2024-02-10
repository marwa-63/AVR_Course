/*
 * EXINT_int.h
 *
 *  Created on: Feb 10, 2024
 *      Author: HP
 */

#ifndef EXINT_INT_H_
#define EXINT_INT_H_

ES_t EXINT_Init(void);
ES_t EXINT_Enable(u8 EXINT_ID);
ES_t EXINT_Disable(u8 EXINT_ID);
ES_t EXINTGLOBAL_Enable(void);
ES_t EXINTGLOBAL_Disable(void);
ES_t EXINT_Callback(void (*Func_ptr) (void),u8 EX_INT_ID );

#endif /* EXINT_INT_H_ */
