#include <Otto.h>

Otto Otto;

#define LeftLeg 2
#define RightLeg 3
#define LeftFoot 4
#define RightFoot 5
#define Buzzer 13

void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
  Otto.home();
  delay(1000);
}

void loop() {
  Otto.moonwalker(3, 1000, 25, 1);
  delay(500);
  Otto.moonwalker(3, 1000, 25, -1);
  delay(500);
  Otto.crusaito(3, 1000, 20, 1);
  delay(500);
  Otto.undulation(3, 1000, 20);
  delay(500);
  Otto.swing(3, 1000, 20);
  delay(500);
  Otto.tiptoeSwing(3, 1000, 20);
  delay(500);
  Otto.jitter(20, 100);
  delay(500);
  Otto.crazy(3, 1000);
  delay(800);
}
