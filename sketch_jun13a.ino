#include <Stepper.h>
#define Boton1 4
#define Boton2 3
#define Boton3 2
const int pasos_T = 2048; 
Stepper stepper(pasos_T, 8, 10, 9, 11);
 
void setup() {
  stepper.setSpeed(14);
  pinMode(Boton1, INPUT_PULLUP); //Configura el estado del pin como entrada con pull up 
  pinMode(Boton2, INPUT_PULLUP); //Configura el estado del pin como entrada con pull up 
  pinMode(Boton3, INPUT_PULLUP); //Configura el estado del pin como entrada con pull up 
}
 
void loop() {
  
  if(digitalRead(Boton1) == LOW){  //Si se cumple la funcion de if boton
  stepper.step(-11096);
  delay(2000);
  }
  if(digitalRead(Boton2) == LOW){  //Si se cumple la funcion de if boton
  stepper.step(4009);
  delay(2000);
  }
  if(digitalRead(Boton3) == LOW){  //Si se cumple la funcion de if boton
  stepper.step(11096);
  delay(2000);
  }

  
}