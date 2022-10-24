#include<stdio.h>
#include "conio.h"

int chartoint(char c_c);
int create(void);
int verify(void);
int cpf_exit(void);

int main(void)
{
   char c=0;
   initconio();
   while(c!='3')
   {
      textcolor(WHITE);
      textbackground(BLUE);
      clrscr();
      printw("\n");
      printw(" CPF Creator v1.0 - by JSFelix 2001\n");
      printw(" ==================================\n\n");
      printw(" [1] Criar um número de CPF\n");
      printw(" [2] Verificar um número de CPF\n");
      printw(" [3] Fim do Programa\n\n");
      c=getch();
      switch(c)
      {
         case '1': create(); break;
         case '2': verify(); break;
         case '3': cpf_exit(); break;
      }
   }
   endconio();
   return 0;
}

int create(void)
{
   char cpfnum[9];
   int cpfnum_i[9];
   int x,y;
   int dig_a, dig_b;
   gotoxy(wherex(), 0);
   printw(" Digite os 9 primeiros algarismos do CPF (sem pontos): ");
   textcolor(YELLOW);
   for(x=0; x<9; x++)
   {
      cpfnum[x]=getch();
      cpfnum_i[x]=chartoint(cpfnum[x]);
   }
   x= 10*cpfnum_i[0]+9*cpfnum_i[1]+8*cpfnum_i[2]+
      7*cpfnum_i[3]+6*cpfnum_i[4]+5*cpfnum_i[5]+
      4*cpfnum_i[6]+3*cpfnum_i[7]+2*cpfnum_i[8];
   y= x/11;
   y*=11;
   y=x-y;
   dig_a=11-y;
   if(dig_a>=10)
      dig_a-=10;

   x= 11*cpfnum_i[0]+10*cpfnum_i[1]+9*cpfnum_i[2]+
      8*cpfnum_i[3]+7*cpfnum_i[4]+6*cpfnum_i[5]+
      5*cpfnum_i[6]+4*cpfnum_i[7]+3*cpfnum_i[8]+2*dig_a;
   y= x/11;
   y*=11;
   y=x-y;
   dig_b=11-y;
   if(dig_b>=10)
      dig_b-=10;
   textcolor(WHITE);
   printw("\n\n Número do CPF: ");
   textcolor(YELLOW);
   for(x=0; x<9; x++)
   {
      printw("%d",cpfnum_i[x]);
      if((x==2)||(x==5))
         printw(".");
   }
   printw("-");
   printw("%d%d\n", dig_a, dig_b);

   textcolor(WHITE);
   printw("\n Pressione qualquer tecla para continuar...");
   getch();
   return 0;
}

int verify(void)
{
   char cpfnum[11];
   int cpfnum_i[11];
   int x,y;
   int dig_a, dig_b;
   gotoxy(wherex(), 0);
   printw(" Digite o número do CPF (sem pontos e sem traço): ");
   textcolor(YELLOW);
   for(x=0; x<11; x++)
   {
      cpfnum[x]=getch();
      cpfnum_i[x]=chartoint(cpfnum[x]);
   }
   x= 10*cpfnum_i[0]+9*cpfnum_i[1]+8*cpfnum_i[2]+
      7*cpfnum_i[3]+6*cpfnum_i[4]+5*cpfnum_i[5]+
      4*cpfnum_i[6]+3*cpfnum_i[7]+2*cpfnum_i[8];
   y= x/11;
   y*=11;
   y=x-y;
   dig_a=11-y;
   if(dig_a>=10)
      dig_a-=10;

   x= 11*cpfnum_i[0]+10*cpfnum_i[1]+9*cpfnum_i[2]+
      8*cpfnum_i[3]+7*cpfnum_i[4]+6*cpfnum_i[5]+
      5*cpfnum_i[6]+4*cpfnum_i[7]+3*cpfnum_i[8]+2*dig_a;
   y= x/11;
   y*=11;
   y=x-y;
   dig_b=11-y;
   if(dig_b>=10)
      dig_b-=10;
   textcolor(WHITE);
   printw("\n\n O CPF n\xBA ");
   for(x=0; x<9; x++)
   {
      printw("%d",cpfnum_i[x]);
      if((x==2)||(x==5))
         printw(".");
   }
   printw("-");
   printw("%d%d está ", cpfnum_i[9], cpfnum_i[10]);
   textcolor(YELLOW);
   if((dig_a==cpfnum_i[9])&&(dig_b==cpfnum_i[10]))
      printw("CORRETO.\n");
   else
   {
      printw("INCORRETO.");
      textcolor(WHITE);
      printw("\n Número correto: ");
      textcolor(YELLOW);
      for(x=0; x<9; x++)
      {
         printw("%d",cpfnum_i[x]);
         if((x==2)||(x==5))
            printw(".");
      }
      printw("-");
      printw("%d%d\n", dig_a, dig_b);
   }
   textcolor(WHITE);
   printw("\n Pressione qualquer tecla para continuar...");
   getch();
   return 0;
}

int cpf_exit(void)
{
   textcolor(LIGHTGRAY);
   textbackground(BLACK);
   clrscr();
   printw(" CPF Creator v1.0 by JSFelix\n");
   printw(" (c)2001 Jefferson dos Santos Felix - Todos os direitos reservados.\n");
   getch();
   return 0;
}

int chartoint(char c)
{
   switch(c)
   {
      case '0': return 0;
      case '1': return 1;
      case '2': return 2;
      case '3': return 3;
      case '4': return 4;
      case '5': return 5;
      case '6': return 6;
      case '7': return 7;
      case '8': return 8;
      case '9': return 9;
   }
}
