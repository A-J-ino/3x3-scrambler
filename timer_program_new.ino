 #include <TM1637.h> //library for timer display
//pin location and variables for display
int a,b,c,d;
int clk = 2;
int dio = 3;
TM1637 tm(clk,dio);

//storing each display number
int disp0;
int disp1;
int disp2;
int disp3;
//variables and pin locations for sensor
const int out= 9;
//for flag value to execute each paticular stage
int stage;

void setup() {
  // put your setup code here, to run once:
  pinMode(out,INPUT);
  //pinMode(echo,INPUT);
  Serial.begin(9600);
  tm.init();
  tm.set(4);
}

void loop() {
  // put your main code here, to run repeatedly:
while(digitalRead(9)==0)
 {
  if(stage==7){
    //making the completed time displayed to go back to zero
    tm.display(0,disp0);
    tm.display(1,disp1);
    tm.display(2,disp2);
    tm.display(3,disp3);
    digitalRead(9);
  }
  else
  {
  stage = 1;
  tm.point(1);
  tm.display(0,0);
  tm.display(1,0);
  tm.display(2,0);
  tm.display(3,0);
  digitalRead(9);
  }
 }
stage =2;
while(digitalRead(9)==1)
{
 tm.display(0,0);
 tm.display(1,0);
 tm.display(2,0);
 tm.display(3,0);
 for(a=0;a<2;a++)
 {tm.display(0,a);
   for(b=0;b<10;b++)
   { tm.display(1,b);
     for(c=0;c<10;c++)
     {tm.display(2,c);
       for(d=0;d<10;d++)
       {
         tm.display(3,d);
         //storing of numbers
         delay(10);
         //to stop timer
         //the sensor says that the cubes back 
         Serial.println(digitalRead(9));
         if((digitalRead(9)==0)&&(stage==2)){
            
            break;
         }
       }
     if((digitalRead(9)==0)&&(stage==2)){
            break;
      }
    }
   if((digitalRead(9)==0)&&(stage==2)){
            break;
     }
    
    }
    
  if((digitalRead(9)==0)&&(stage==2)){
            stage = 3;
            break;
  }
 }
 }
while((digitalRead(9)==0)&& (stage==3))
 {
  tm.display(0,0);
  tm.display(1,0);
  tm.display(2,0);
  tm.display(3,0);
  digitalRead(9);
 }
stage = 4;
while(digitalRead(9)== 1)
{
 for(a=0;a<2;a++)
 {tm.display(0,a);
   for(b=0;b<10;b++)
   { tm.display(1,b);
     for(c=0;c<10;c++)
     {tm.display(2,c);
       for(d=0;d<10;d++)
       {
         tm.display(3,d);
         //storing of numbers
         delay(10);
         //to stop timer
         //the sensor says that the cubes back 
         if((digitalRead(9)==0)&&(stage==4)){
            break;
         }
       }
     if((digitalRead(9)==0)&&(stage==4)){
            break;
      }
    }
   if((digitalRead(9)==0)&&(stage==4)){
            break;
     }
    
    }
    
  if((digitalRead(9)==0)&&(stage==4)){
            stage = 5;
            break;
  }
 }
 }
//checking to assign stage 1: object near sensor
while(digitalRead(9)==0)
 {//checking if the function is repeated
  digitalRead(9);
  //displays start state
  tm.point(1);
  tm.display(0,0);
  tm.display(1,0);
  tm.display(2,0);
  tm.display(3,0);
 }
stage = 6;
//when its away its stage 2: the timer begins its display
while(digitalRead(9)==1)
 {
 
 //display loop
 //the tm.display command is used for displaying the number in the given position 
 //left hand parameter before the , is the position : it is in this order |0|1|2|3| 
  
 for(a=0;a<6;a++)
 {tm.display(0,a);
   for(b=0;b<10;b++)
   { tm.display(1,b);
     for(c=0;c<10;c++)
     {tm.display(2,c);
       for(d=0;d<10;d++)
       {
         tm.display(3,d);
         //storing of numbers
         disp0 = a;
         disp1 = b;
         disp2 = c;
         disp3 = d;
         delay(10);
         //to stop timer
         //the sensor says that the cubes back 
         if((digitalRead(9)==0)&&(stage==6)){
            
            break;
         }
       }
     if((digitalRead(9)==0)&&(stage==6)){
            break;
      }
    }
   if((digitalRead(9)==0)&&(stage==6)){
            break;
     }
    
    }
    
  if((digitalRead(9)==0)&&(stage==6)){
            stage = 7;
            break;
  }
 }
 } 
tm.display(0,disp0);
tm.display(1,disp1);
tm.display(2,disp2);
tm.display(3,disp3); 
}
   
