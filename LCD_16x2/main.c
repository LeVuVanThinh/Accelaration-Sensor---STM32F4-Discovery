#include "stm32f4xx.h"
#include "lcd.h"
#include <stdio.h>

void Delay(__IO uint32_t nCount);

/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

int main(void)
{
  int i;
  lcd_Init();		
  lcd_Clear();
  lcd_Goto(0,0);
  printf("Welcome to :");
  lcd_Goto(1,0);
  printf("... ICViet.vn");
  Delay(50000000);
  while (1)
  {
    for(i=0;i<1000;i++)
    {
      lcd_Goto(0,0);
      printf("Counting :     ");
      lcd_Goto(1,0);
      printf("%d             ",i);
      Delay(1000000);
    }
  }
}

void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}

PUTCHAR_PROTOTYPE
{
  lcd_Data_Write((u8)ch);
  return ch;
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

