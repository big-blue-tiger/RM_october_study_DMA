//
// Created by 28672 on 24-10-14.
//
#include "main.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"
extern uint8_t Recieve_data[128];
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    HAL_UART_Transmit_DMA(&huart6, Recieve_data, 8);

    HAL_UARTEx_ReceiveToIdle_DMA(&huart6,Recieve_data,sizeof(Recieve_data));
}
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    HAL_UART_Transmit_DMA(&huart6, Recieve_data, Size);
    HAL_UARTEx_ReceiveToIdle_DMA(&huart6,Recieve_data,sizeof(Recieve_data));
}