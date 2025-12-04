//--------------------------------------------------------------
//  Otto Happy Birthday + Movimentos SEM CAIR
//--------------------------------------------------------------
#include <Otto.h>
Otto Otto;

#define LeftLeg 2 
#define RightLeg 3
#define LeftFoot 4 
#define RightFoot 5 
#define Buzzer 12

// ------------------ Música Happy Birthday ---------------------
int speakerPin = Buzzer;

char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16,
                1, 2, 2, 8, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16 };
int tempo = 130;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = {'C','D','E','F','G','A','B',
                  'c','d','e','f','g','a','b',
                  'x','y'};
  int tones[] = {1915,1700,1519,1432,1275,1136,1014,
                  956,834,765,593,468,346,224,
                  655,715};

  for (int i = 0; i < 16; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration / 5);
    }
  }
}

// ---------------------- SETUP ---------------------------------
void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
  pinMode(speakerPin, OUTPUT);
  Otto.home();
  delay(500);
}

// ---------------------- LOOP -----------------------------------
void loop() {

// -------- 1) TOCA HAPPY BIRTHDAY --------
  for (int i = 0; i < sizeof(beats)/sizeof(int); i++) {
    if (notes[i] == ' ') delay(beats[i] * tempo);
    else playNote(notes[i], beats[i] * tempo);
    delay(tempo);
  }

  delay(400);
  Otto.home();
  delay(300);

// -------- 2) MOVIMENTOS ESTABILIZADOS --------

// Caminhar suave
  Otto.walk(2, 1300, 1);
  Otto.walk(2, 1300, -1);

// Giros mais estáveis
  Otto.turn(2, 1300, 1);

  Otto._tone(10, 3, 1);
  Otto.bendTones(150, 200, 1.03, 10, 10);

  Otto.home();
  delay(200);

// Giro lado oposto
  Otto.turn(2, 1300, -1);

// Bend com amplitude reduzida
  Otto.bend(1, 900, 1);
  Otto.bend(1, 1200, -1);

// ShakeLeg muito reduzido para não cair
  Otto.shakeLeg(1, 1100, 1);
  Otto.home();
  delay(200);

  Otto.shakeLeg(1, 1200, -1);

// Moonwalker seguro
  Otto.moonwalker(3, 1100, 10, 1);
  Otto.moonwalker(3, 1100, 10, -1);

// Crusaito seguro
  Otto.crusaito(2, 1100, 10, 1);
  Otto.crusaito(2, 1100, 10, -1);

// Flapping seguro
  Otto.flapping(2, 1100, 10, 1);
  Otto.flapping(2, 1100, 10, -1);

// Movimentos pouco arriscados
  Otto.swing(2, 1100, 15);
  Otto.tiptoeSwing(2, 1100, 15);
  Otto.jitter(2, 1000, 15);

// UpDown reduzido
  Otto.updown(2, 1500, 12);

// Pulo padrão
  Otto.jump(1, 650);

  Otto.home();
  delay(300);
}
