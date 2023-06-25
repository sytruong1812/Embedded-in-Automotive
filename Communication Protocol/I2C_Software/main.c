/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdint.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//isMaster: 1 = master, 2 = slave
static uint8_t isMaster = 1;
//isMaster: 1 = SDA_OUT, 2 = SDA_IN
static uint8_t modeSDA = 1;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

void I2C_Init(void);                			 
void I2C_Start(void);				
void I2C_Stop(void);	  			
void I2C_Send_Byte(uint8_t txd);		
uint8_t I2C_Read_Byte(unsigned char ack);
uint8_t I2C_Wait_Ack(void); 				
void I2C_Ack(void);					
void I2C_NAck(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void I2C_Init(void){
	isMaster = 1;			//Master
	modeSDA = 1;			//SDA = OUTPUT
	MX_GPIO_Init();
}

void I2C_Start(void){
	modeSDA = 1;			//SDA = OUTPUT
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_SET);			// I2C_SCL = 1;
	HAL_GPIO_WritePin(GPIOA, SDA_Pin, GPIO_PIN_SET);      // I2C_SDA = 1;
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
}

void I2C_Stop(void){
	modeSDA = 1;			//SDA = OUTPUT	
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
	HAL_GPIO_WritePin(GPIOA, SDA_Pin, GPIO_PIN_RESET);      // I2C_SDA = 0;
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_SET);			// I2C_SCL = 1;
	HAL_GPIO_WritePin(GPIOA, SDA_Pin, GPIO_PIN_SET);      // I2C_SDA = 1;
	HAL_Delay(100);	
}

void I2C_Send_Byte(uint8_t txd){    //11111111 & 10000000
	int i = 0;
	modeSDA = 1;			//SDA = OUTPUT
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
	for(i = 0; i < 8; i++){
		HAL_GPIO_WritePin(GPIOA, SDA_Pin, (txd & 0x80) >> 7);      // I2C_SDA = 1;
		txd <<= 1;
		HAL_Delay(50);
		HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_SET);			// I2C_SCL = 1;
		HAL_Delay(50);
		HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
	}
}

void I2C_Ack(void){
	modeSDA = 1;			//SDA = OUTPUT
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
	HAL_GPIO_WritePin(GPIOA, SDA_Pin, GPIO_PIN_RESET);      // I2C_SDA = 0;
	HAL_Delay(50);
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_SET);			// I2C_SCL = 1;
	HAL_Delay(50);
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
}

void I2C_NAck(void){
	modeSDA = 1;			//SDA = OUTPUT
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
	HAL_GPIO_WritePin(GPIOA, SDA_Pin, GPIO_PIN_SET);      // I2C_SDA = 1;
	HAL_Delay(50);
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_SET);			// I2C_SCL = 1;
	HAL_Delay(50);
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
}	

uint8_t I2C_Read_Byte(unsigned char ack){
	int i = 0;
	uint8_t rec = 0;
	modeSDA = 0;			 //SDA = INPUT
	for(i=0;i<8;i++){			//11111111
		HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
		HAL_Delay(50);
		HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_SET);			// I2C_SCL = 1;
		HAL_Delay(50);
		rec <<= 1;
		if(HAL_GPIO_ReadPin(GPIOA, SDA_Pin)) rec++;
	}
	if(!ack){
		I2C_Ack();
	}
	else{
	I2C_NAck();	
	}
}

uint8_t I2C_Wait_Ack(void){
	uint8_t time=0;
	modeSDA = 0;			//SDA = INPUT
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
	HAL_Delay(25);
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_SET);			// I2C_SCL = 1;
	HAL_Delay(25);
	while(HAL_GPIO_ReadPin(GPIOA, SDA_Pin)){
		time++;
		if(time>250){
			I2C_Stop(); 
			return 1;
		}
	}
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET);			// I2C_SCL = 0;
	return 0; 
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

	if(isMaster){
		/*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_SET);
		/*Configure GPIO pin */
		GPIO_InitStruct.Pin = SCL_Pin|SDA_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		if(modeSDA){
			/*Configure GPIO pin Output Level */
			HAL_GPIO_WritePin(GPIOA, SDA_Pin, GPIO_PIN_SET);
			/*Configure GPIO pin */
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		}
		else{
			/*Configure GPIO pin */
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		}
	}
	else{
		/*Configure GPIO pin */
		GPIO_InitStruct.Pin = SCL_Pin|SDA_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		if(modeSDA){
			/*Configure GPIO pin Output Level */
			HAL_GPIO_WritePin(GPIOA, SDA_Pin, GPIO_PIN_SET);
			/*Configure GPIO pin */
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		}
		else{
			/*Configure GPIO pin */
			GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		}
	}
}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
