/*
 * ADC_int.h
 *
 *  Created on: Feb 8, 2024
 *      Author: HP
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

ES_t ADC_Init(void);

ES_t ADC_Conversion(void);

ES_t ADC_enuPollingSystem(void);

ES_t ADC_enuReadHighValue(u8 * Copy_pu8Value);

ES_t ADC_enuRead(u16 * Copy_pu16Value);

ES_t ADC_enuCallBack(void(*Copy_pfunAppFun)(void*) , void * Copy_pvidAppParameter);

ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID);

ES_t ADC_enuEnableTriggeringMode(u8 Copy_u8TriggeringSource);

ES_t ADC_enuDisableTriggeringMode(void);

ES_t ADC_enuEnableInterruptMode(void);


#define ADC_FREE_RUNNING  10
#define ADC_EXTI0_TRIG    14


/***ADC Channel:-***/
/*
 *  ---->single channel ID:
 *  ADC_PIN0 0
 *  ADC_PIN1 1
 *  ADC_PIN2 2
 *  ADC_PIN3 .....
 *
 *  ---->Differential channel ID:
 * /// positiveEdgePin_NegatibeEdgePin_Gain
 *    ADC0_ADC0_10X 8
 *    ADC1_ADC0_10X 9
 *    ADC0_ADC0_200X 10
 *    ADC1_ADC0_200X 11
 *    ADC2_ADC2_10X  12
 *    ADC3_ADC2_10X  13
 *    ADC2_ADC2_200X 14
 *    ADC3_ADC2_200X 15
 *    ADC0_ADC1_1X   16
 *    ADC1_ADC1_1X   17
 *    ADC2_ADC1_1X
 *    ADC3_ADC1_1X
 *    ADC4_ADC1_1X
 *    ADC5_ADC1_1X
 *    ADC6_ADC1_1X
 *    ADC7_ADC1_1X
 *    ADC0_ADC2_1X
 *    ADC1_ADC2_1X
 *    ADC2_ADC2_1X
 *    ADC3_ADC2_1X
 *    ADC4_ADC2_1X
 *    ADC5_ADC2_1X  29
 *
 */


#endif /* ADC_INT_H_ */
