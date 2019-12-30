#include "pines.h"
#include "display.h"

//char num[4];
void setup() {
  // put your setup code here, to run once:
  configuration();
  digitalWrite(D2P, 1);
  digitalWrite(PNT, 1);
  digitalWrite(DP, 1);
  //Serial.begin(9600);
  //Serial.print("Empecemos");
}



void loop() {
  /*for(int h=0; h<10000;h++){
    display(h);
    }*/

  display(-753);


}
