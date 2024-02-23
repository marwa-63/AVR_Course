/*
 * TIMER_int.h
 *
 *  Created on: Feb 23, 2024
 *      Author: HP
 */

#ifndef MCAL_TIMER_TIMER_INT_H_
#define MCAL_TIMER_TIMER_INT_H_

ES_t TIMER_enuInit(void);
/***OVF MODE****/
ES_t TIMER_enuSetPreload(u8 Copy_u8Preload);

ES_t TIMER_enuSetAsychDelay(u32 Copy_u8Time , void(*Copy_pfunApp)(void*) , void * parameter);

ES_t TIMER_enuSetSychDelay(u32 Copy_u8Time);

/***CTC MODE****/

ES_t TIMERCTC_enuSetAsychDelay(u32 Copy_u8Time , void(*Copy_pfunApp)(void*) , void * parameter);

ES_t TIMERCTC_enuSetSychDelay(u32 Copy_u8Time);

/**PWM**/
ES_t TIMERCTC_enuSetVoltage(f32 Copy_u8Voltage);



#endif /* MCAL_TIMER_TIMER_INT_H_ */
