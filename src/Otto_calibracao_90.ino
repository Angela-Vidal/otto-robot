#include <Otto.h>
Otto Otto;

// Pinos padrão (confirme os seus!)
#define LeftLeg 2 
#define RightLeg 3
#define LeftFoot 4 
#define RightFoot 5 
#define Buzzer  13 

void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
  
  // SÓ ISSO NO LOOP: põe todos os servos em 90 graus.
  Otto.home(); 
}

void loop() {
  // Nada aqui, deixe ele travado no home.
}