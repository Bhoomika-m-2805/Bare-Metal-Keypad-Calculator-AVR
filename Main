#include "lcd.h";
volatile char data[4][4]={{0x31,0x32,0x33,0x2B},{0x34,0x35,0x36,0x2D},{0x37,0x38,0x39,0x2A},{0x2E,0x30,0x3D,0x2F}};
volatile char data1[4][4]={{'1','2','3','+'},{'4','5','6','-'},{'7','8','9','*'},{'.','0','=','/'}};
char wholeterm[20],firstterm[10],secondterm[10],h=0,g=0,p=0,flag=0,sign,nextcalculation=0;
#define debounce 200000
String answer;
void calculation(void);
void displayresult(void);
void setup()
{
setlcd();
volatile char i,j;
volatile char *dirf,*dirk;
  volatile char *row,*col;
  volatile long k;
  dirf=0x30; dirk=0x107;
  row=0x31;col=0x106;
  *dirf=0x0F;*dirk=0x00;
  while(1)
  {
 
for(i=0;i<4;i++)
{
*row = 1<<i;
if(*col)
{
  if(*col==0x01)
  j=0;
  else if(*col==0x02)
  j=1;
  else if(*col==0x04)
  j=2;
  else
  j=3;
if(nextcalculation==0)
{
  displaylcd(data[i][j]);
  if(data1[i][j]!='=')
  {
    wholeterm[h]=data1[i][j];
    h++;
  }
else
{
calculation();
displayresult();
nextcalculation=1;
}
}

else if(nextcalculation==1)
{
  volatile char i,j,l;
  for(i=0;firstterm[i]!=0;i++)
  {
    firstterm[i]=0;
  }
   for(j=0;secondterm[j]!=0;j++)
  {
    secondterm[j]=0;
  }
  for(l=0;wholeterm[l]!=0;l++)
  {
    wholeterm[l]=0;
  }
  h=0;
  p=0;
  g=0;
  flag=0;
  init_lcd();
  nextcalculation=0;
}

 for(k=0;k<debounce;k++);
}
}
}
}



void calculation()
{
   volatile char i;
  for(i=0;wholeterm[i]!=0;i++)
  {
    if(flag==0)
    {
    if(wholeterm[i]!='+' && wholeterm[i]!='-' && wholeterm[i]!='*' && wholeterm[i]!='/')
    {
    firstterm[g]=wholeterm[i];
    g++;
    }
    else  if(wholeterm[i]=='+' || wholeterm[i]=='-' || wholeterm[i]=='*' || wholeterm[i]=='/')
    {
    sign=wholeterm[i];
    flag=1;
    }
    }

    else if(flag==1)
    {
      secondterm[p]=wholeterm[i];
      p++;
    }
  }
double first,second,result;
char *endptr;
first=strtod(firstterm,&endptr);
second=strtod(secondterm,&endptr);
if(sign=='+')
result=first+second;
else if(sign=='-')
result=first-second;
else if(sign=='*')
result=first*second;
else if(sign=='/')
result=first/second;
answer=(String)result;
}

void displayresult()
{
init_lcd();  
volatile char i,j;
for(g=0;answer[g]!=0;g++)
{
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      if(data1[i][j]==answer[g])
      {
      displaylcd(data[i][j]);
      }
    }
  }
}
}

void loop()
{

}
