#include "pli_objects.h"
#include "pli_resources.h"

//--------------------- User code ---------------------//
void starting(){
int freq[50]={264,297,264,352,330,264,264,297,264,396,352,264,264,264,440,352,352,330,297,466,466,440,352,396,352};
int duration[50]={250,250,250,250,500,500,250,250,250,250,500,500,250,250,250,250,250,250,500,500,250,250,250,250,250};
int i=0;
  Sound_Init(&GPIOE_ODR,14);
  TFT_Set_Pen(CL_SILVER, 1);
  TFT_Set_Brush(1, CL_SILVER,0,0,0,0);
  TFT_RECTANGLE(0,0,320,240);
  TFT_Set_Pen(CL_BLACK, 1);
  TFT_Set_Brush(1, CL_BLACK,0,0,0,0);
  TFT_RECTANGLE(20,20,300,220);   
  TFT_Set_Font(TFT_defaultfont, CL_BLUE, FO_HORIZONTAL);
  TFT_Write_Text("RICHA", 135, 220);
  delay_ms(50);
  TFT_Set_Pen(CL_RED, 1);
  TFT_Set_Brush(1, CL_RED,0,0,0,0);
  TFT_Circle(112, 54, 1.5);
  TFT_Circle(112, 24, 1.5);
  TFT_Circle(72, 24, 1.5);
  TFT_Circle(72, 54, 1.5);
  TFT_Circle(32, 24, 1.5);
  TFT_Circle(32, 54, 1.5);
  TFT_Circle(152, 54, 1.5);
  TFT_Circle(152, 24, 1.5);
  TFT_Circle(198, 24, 1.5);
  TFT_Circle(198, 54, 1.5);
  TFT_Circle(242, 24, 1.5);
  TFT_Circle(242, 54, 1.5);
  TFT_Circle(285, 24, 1.5);
  TFT_Circle(285, 54, 1.5);
  TFT_Circle(112, 84, 1.5);
  TFT_Circle(72, 84, 1.5);
  TFT_Circle(72, 114, 1.5);
  TFT_Circle(32, 84, 1.5);
  TFT_Circle(32, 114, 1.5);
  TFT_Circle(152, 84, 1.5);
  TFT_Circle(198, 84, 1.5);
  TFT_Circle(242, 84, 1.5);
  TFT_Circle(242, 114, 1.5);
  TFT_Circle(285, 84, 1.5);
  TFT_Circle(285, 114, 1.5);
  TFT_Circle(112, 174, 1.5);
  TFT_Circle(112, 144, 1.5);
  TFT_Circle(72, 174, 1.5);
  TFT_Circle(72, 144, 1.5);
  TFT_Circle(32, 174, 1.5);
  TFT_Circle(32, 144, 1.5);
  TFT_Circle(152, 174, 1.5);
  TFT_Circle(152, 144, 1.5);
  TFT_Circle(198, 204, 1.5);
  TFT_Circle(198, 144, 1.5);
  TFT_Circle(242, 174, 1.5);
  TFT_Circle(242, 144, 1.5);
  TFT_Circle(285, 174, 1.5);
  TFT_Circle(285, 144, 1.5);
  TFT_Circle(112, 204, 1.5);
  TFT_Circle(72, 204, 1.5);
  TFT_Circle(32, 204, 1.5);
  TFT_Circle(152, 204, 1.5);
  TFT_Circle(242, 204, 1.5);
  TFT_Circle(285, 204, 1.5);
  delay_ms(200);
  TFT_Set_Pen(CL_WHITE, 1);
  TFT_Set_Brush(1, CL_YELLOW,0,0,0,0);
  TFT_Circle(120, 64, 10);
  TFT_Set_Pen(CL_BLACK, 1);
  TFT_Set_Brush(1, CL_BLACK,0,0,0,0);
  TFT_RECTANGLE(100,40,120,64);
  TFT_Set_Pen(CL_WHITE, 1);
  TFT_Set_Brush(1, CL_YELLOW,0,0,0,0);
  TFT_Circle(194, 170, 10);
  TFT_Set_Pen(CL_BLACK, 1);
  TFT_Set_Brush(1, CL_BLACK,0,0,0,0);
  TFT_RECTANGLE(194,170,220,180);
  TFT_Set_Pen(CL_RED, 1);
  TFT_Set_Brush(1, CL_RED,0,0,0,0);
  TFT_Circle(198, 174, 1.5);
  delay_ms(100);
  TFT_Set_Pen(CL_WHITE, 1);
  TFT_Set_Brush(1, CL_WHITE,0,0,0,0);
  TFT_Set_Font(TFT_defaultfont, CL_WHITE, FO_HORIZONTAL);
  TFT_Write_Text("||*PACMAN @ 2023*||", 87, 110);
  while(GPIOC_IDR.B13!=0){
  Sound_Play(freq[i],duration[i]);
  i=i+1;
  if(i==50){i=0;}}
  ClearScreen();

}


void ClearScreen(){
   int freq[9]={100,250,220,250,500,250,200,250,100};
   int duration[9]={100,200,200,100,200,200,100,200,200};
   int i=0;
   Sound_Init(&GPIOE_ODR,14);
   TFT_Set_Pen(CL_SILVER, 1);
   TFT_Set_Brush(1, CL_SILVER,0,0,0,0);
   TFT_RECTANGLE(0,0,320,240);
   TFT_Set_Pen(CL_LIME, 1);
   TFT_Set_Brush(1, CL_LIME,0,0,0,0);
   TFT_RECTANGLE(20,20,300,220);
   TFT_Set_Font(TFT_defaultfont, CL_BLUE, FO_HORIZONTAL);
   TFT_Write_Text("RICHA", 135, 220);
   TFT_Set_Pen(CL_WHITE, 1);
   TFT_Set_Brush(1, CL_BLACK,0,0,0,0);
   TFT_Set_Font(TFT_defaultfont, CL_BLACK, FO_HORIZONTAL);
   TFT_Write_Text("WELCOME!", 125, 110);
   while(GPIOC_IDR.B13 != 0){
      Sound_Play(freq[i],duration[i]);
      i=i+1;
      if(i==9){i=0;}
      } Play_screen();
  }
  
void Play_screen(){
  TFT_Set_Pen(CL_BLACK, 1);
  TFT_Set_Brush(1, CL_BLACK,0,0,0,0);
  TFT_RECTANGLE(0,0,320,240);
  TFT_Set_Pen(CL_WHITE, 1);
  TFT_Set_Brush(1, CL_WHITE,0,0,0,0);
  TFT_Set_Font(TFT_defaultfont, CL_WHITE, FO_HORIZONTAL);
  TFT_Write_Text("YOUR_SCORE", 3, 3);
  TFT_Write_Text("HIGH_SCORE", 200, 3);
  
  TFT_Set_Pen(CL_RED, 1);
  TFT_Set_Brush(1, CL_RED,0,0,0,0);
  TFT_RECTANGLE(0,20,319,30);
  TFT_RECTANGLE(0,230,319,240);
  TFT_RECTANGLE(0,30,10,115);
  TFT_RECTANGLE(309,30,319,115);
  TFT_RECTANGLE(0,150,10,230);
  TFT_RECTANGLE(309,150,319,230);
  TFT_RECTANGLE(145,30,155,230);
  TFT_RECTANGLE(115,150,145,160);
  TFT_RECTANGLE(10,150,55,160);
  TFT_RECTANGLE(220,150,310,160);
  player();

}

void SCORE_SCREEN(){
TFT_Set_Pen(CL_white, 1);
  TFT_Set_Brush(1, CL_white,0,0,0,0);
  TFT_RECTANGLE(0,0,320,240);
  TFT_Set_Pen(CL_BLACK, 1);
  TFT_Set_Brush(1, CL_white,0,0,0,0);
   TFT_Set_Font(TFT_defaultfont, CL_BLUE, FO_HORIZONTAL);
   TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
  TFT_Write_Text("YOUR_SCORE", 120, 100);
  TFT_Write_Text("HIGH_SCORE", 120, 150);
}

 
 


//----------------- End of User code ------------------//

// Event Handlers