#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

void loading();
//add function

void main(){
 int gd = DETECT, gm;
 char ch;
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 label:
 loading();
 fflush(stdin);
 ch = getch();
 switch(ch){
  case '1':
  cleardevice();
   //call function
   break;
  case '2':
   exit(0);
  default:
   setcolor(WHITE);
   outtextxy(245,300,"INVALID");
   delay(800);
   cleardevice();
   goto label;
 }
 getch();
}

void loading(){
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
 setcolor(RED);
 outtextxy(240,130,"MAIN MENU");
 setcolor(WHITE);
 rectangle(240,190,380,210);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 outtextxy(245,197,"1.START GAME");
 rectangle(240,230,380,250);
 outtextxy(245,237,"2.EXIT");
 setcolor(BLUE);
 outtextxy(240,400,"CREDITS:-");
 outtextxy(240,420,"Milan, Benjin, Bishal");
}