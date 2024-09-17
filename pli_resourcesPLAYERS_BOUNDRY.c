
//----------------- End of User code ------------------//

// Event Handlers
#include "pli_resources.h"

 #define pacmansize 20
#define startpos 120
  #define YOUR_SCORE 10

 unsigned int playerx0, playery0, playerx1, playery1;
  unsigned int playerdir;
  int statePA6;
  int statePB5;
  int statePD4;
  int statePD2;
  int speed_counter;

  void player(){


   //draw initial position
   TFT_Set_Pen(CL_BLACK, 1);
  TFT_SET_Brush(1, CL_YELLOW,0,0,0,0);
  playerx0 = startpos;
  playery0 = startpos;
  playerx1 = startpos+pacmansize;
  playery1 = startpos+pacmansize;

  TFT_Rectangle(playerx0, playery0, playerx1, playery1);

 }



  void TIMER3_ISR()iv IVT_INT_TIM3{
   TIM3_SR.UIF = 0;
   if(YOUR_SCORE == ADC1_DR){
   speed_counter= YOUR_SCORE+10;
   speed_counter=0;
   }
   speed_counter++;
  }

   // ISR for EXTI2 to check PD2 press, bit 8 in NVIC
 void JoyStickleft() iv IVT_INT_EXTI2 {
 int freq[9]={100,250,220,250,500,250,200,250,100};
   int duration[9]={100,200,200,100,200,200,100,200,200};
   int i=0;
   Sound_Init(&GPIOE_ODR,14);
  if(GPIOD_IDR.B2 == 1 & statePD2 == 0);{
  Sound_Play(freq[i],duration[i]);
      i=i+1;
      if(i==9){i=0;}
       EXTI_PR.B2 = 1;
       statePD2 = 1;
       if(statePD2 == 1){
       speed_counter = 10;
       }
       speed_counter++;
       TFT_SET_Brush(1, CL_BLACK,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);

        playerx0 -= pacmansize;
        playerx1 -= pacmansize;

        TFT_SET_Brush(1, CL_yellow,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);
         if((playerx1 <= 10)&&((playery1 <= 140)&&(playery0>=120)) ) {
             TFT_Set_Pen(CL_BLACK, 1);
             TFT_SET_Brush(1, CL_BLACK,0,0,0,0);
             TFT_Rectangle(playerx0, playery0, playerx1, playery1);

             TFT_Set_Pen(CL_BLACK, 1);
             TFT_SET_Brush(1, CL_YELLOW,0,0,0,0);
             playerx0=299;
             playerx1=319;
             playery0= 120;
             playery1= 140;
            TFT_SET_Brush(1, CL_BLACK,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);
        playerx0 -= pacmansize;
        playerx1 -= pacmansize;

        TFT_SET_Brush(1, CL_yellow,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);
         }
         if(playerx0 <= 10 && playery0 <= 115 ){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
         }
         if(playerx0 <= 10 && playery0 >= 160 ){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
         }
         if(playerx0 <= 55 && playery1 >= 150 && playery0 <=160 ){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
         }
         if(playerx1>=135 && playerx0 <= 145  && playery0 <= 230){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
         }


        }
       if(GPIOD_IDR.B2 == 0 & statePD2 == 1);{
          statePD2 = 0;
          }
 }

// ISR for EXTI4 to check PD4 press, bit 10 in NVIC
 void JoyStickUP() iv IVT_INT_EXTI4 {
 int freq[9]={100,250,220,250,500,250,200,250,100};
   int duration[9]={100,200,200,100,200,200,100,200,200};
   int i=0;
   Sound_Init(&GPIOE_ODR,14);
   if(GPIOD_IDR.B4 == 1 & statePD4 == 0);{
   Sound_Play(freq[i],duration[i]);
      i=i+1;
      if(i==9){i=0;}
       EXTI_PR.B4 = 1;
       statePD4 = 1;

       TFT_SET_Brush(1, CL_BLACK,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);

        playery0 -= pacmansize;
        playery1 -= pacmansize;

        TFT_SET_Brush(1, CL_yellow,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);
        }
        if(playery0 <=30){
        //STOP PLAYSCREEN

         SCORE_SCREEN();
         delay_ms(1000);
         starting();
        }
         if(playery0 <= 160&& playery1 >= 150 &&playerx0 <=55){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
        }
         if(playery0 <= 160 && playery1 >= 150 && playerx1 >=115 && playerx0 <=145  ){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
        }
         if(playery0 <= 160&& playery1 >= 150  && playerx1 >=220){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
        }



       if(GPIOD_IDR.B4 == 0 & statePD4 == 1);{
          statePD4 = 0;
          }


 }

// ISR for EXTI9_5 to check PB5 and PA6 press, bit 23 in NVIC
 void JoyRightAndDown() iv IVT_INT_EXTI9_5 {
 int freq[9]={100,250,220,250,500,250,200,250,100};
   int duration[9]={100,200,200,100,200,200,100,200,200};
   int i=0;
   Sound_Init(&GPIOE_ODR,14);

      if ((EXTI_PR & 0X0020) == 0X0020){
      if(GPIOB_IDR.B5 == 1 & statePB5 == 0);{
      Sound_Play(freq[i],duration[i]);
      i=i+1;
      if(i==9){i=0;}

       EXTI_PR.B5 = 1;
       statePB5 = 1;
       TFT_SET_Brush(1, CL_BLACK,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);

        playery0 += pacmansize;
        playery1 += pacmansize;

        TFT_SET_Brush(1, CL_yellow,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);

        if(playery1>= 230){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
        }
        if(playery1 >= 150&& playery0 <=160 && playerx0<=55 ){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
        }
         if(playery1 >= 150&& playery0 <=160 && playerx1>=115 && playerx0<=145 ){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
        }
        if(playery1 >= 150&& playery0 <=160 && playerx1>=220 ){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
        }

     }

       if(GPIOB_IDR.B5 == 0 & statePB5 == 1);{
          statePB5 = 0;
            }
    }

        if((EXTI_PR & 0X0040)== 0X0040){
       if(GPIOA_IDR.B6 == 1 & statePA6 == 0);{
       Sound_Play(freq[i],duration[i]);
      i=i+1;
      if(i==9){i=0;}
       EXTI_PR.B6 = 1;
       statePA6 = 1;
        TFT_SET_Brush(1, CL_BLACK,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);

        playerx0 += pacmansize;
        playerx1 += pacmansize;

        TFT_SET_Brush(1, CL_yellow,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);
         }

            if((playerx1 >= 320)&&((playery1 <= 140)&&(playery0>=120) )) {
             TFT_Set_Pen(CL_BLACK, 1);
             TFT_SET_Brush(1, CL_BLACK,0,0,0,0);
             TFT_Rectangle(playerx0, playery0, playerx1, playery1);

             TFT_Set_Pen(CL_BLACK, 1);
             TFT_SET_Brush(1, CL_YELLOW,0,0,0,0);
             playerx0=0;
             playerx1=20;
             playery0= 120;
             playery1= 140;
            TFT_SET_Brush(1, CL_BLACK,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);

        playerx0 += pacmansize;
        playerx1 += pacmansize;

        TFT_SET_Brush(1, CL_yellow,0,0,0,0);
        TFT_Rectangle(playerx0, playery0, playerx1, playery1);
      }
        if(playerx1 >= 310 && playery0 <= 115 ){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
         }
         if(playerx1 >= 310 && playery0 >= 160 ){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
         }
         if(playerx1 >=220  && playery1 >= 150 && playery0 <=160 ){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
         }
         if(playerx1 >= 115 && playerx0 <= 145  && playery0 <= 160 && playery1>=150){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
         }
         if(playerx1 >= 145 && playerx0 <= 145  && playery0 <= 150){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
         }
          if(playerx1 >= 145 && playerx0 <= 145  && playery0 <= 230){
         SCORE_SCREEN();
         delay_ms(1000);
         starting();
         }
   }

       if(GPIOA_IDR.B6 == 0 & statePA6 == 1);{
          statePA6 = 0;
                }


  }


 void JoyStickClick() iv IVT_INT_EXTI15_10 {
 EXTI_PR.B13 = 1;
 //defult();
 }

 void Joystick_configuration(){
  GPIOA_CRL = 0X4000000; // PA6 input
  RCC_APB2ENR.IOPAEN = 1; // Enable poart A clock

  GPIOB_CRL = 0X400000; //PB5 input
  RCC_APB2ENR.IOPBEN = 1; // Enable poart B clock

  GPIOD_CRL = 0X40400; //PD2, PD4 input
  RCC_APB2ENR.IOPDEN = 1; // Enable poart D clock

  GPIOC_CRH = 0X80000; //PC13input
  RCC_APB2ENR.IOPCEN = 1; // Enable poart C clock

  RCC_APB2ENR.AFIOEN = 1; //Enable Alternate Function clock for Interrupts
  AFIO_EXTICR1 = 0X0300; // Configure PD2 as interrupt
  AFIO_EXTICR2 = 0x0013; // Configure PA6, PB5, PD4 as intterupt
  AFIO_EXTICR4 = 0X0020; // Configure PC13 interrupt
  EXTI_RTSR = 0x2074; // Enable rising edge trigger
  EXTI_FTSR = 0x2074; // Enable rising edge trigger
  EXTI_IMR = 0x2074; // Enable interrupt unmasking
  NVIC_ISER0.B8 = 1;    // ENABLE NVIC interrupt for PD2
  NVIC_ISER0.B10 = 1;  // ENABLE NVIC interrupt for PD4
  NVIC_ISER0.B23 = 1;  // ENABLE NVIC interrupt for PB5, PA6
  NVIC_IntEnable(IVT_INT_EXTI15_10);
}


 void AdcConfiguration(){
 RCC_APB2ENR |= 1 << 4; // Enable PORTC clock
 RCC_APB2ENR |= 1 << 9 ; // Enable ADC1 Clock
 GPIOC_CRL &= ~(0xF << 0); // Configure PC0 as an Analog Input
 ADC1_SQR1 = (0b0000 << 20); // 1 conversion
 ADC1_SQR3 = 10; // Select Channel 10 as only one in conversion sequence
 ADC1_SMPR1 = 0b100; // Set sample time on channel 10
 ADC1_CR2 |= (0b111 << 17); // Set software start as external event for regular group conversion
 ADC1_CR2.ADON = 1; // Enable ADC1
 delay_ms(10);
}

unsigned int getAdcReading(){
 // Bit 20 is set to start conversion of an external channel, bit 22 starts the conversion
 ADC1_CR2 |= (1 << 22) | (1 << 20);
 while(!(ADC1_SR & 0b10)); // Wait until the ADC conversion has ended
 return ADC1_DR; // Read value from data register. This also clears start bit
}
