

int sinal_pedestre[2] = {A1, A0};
int  sinal_carros[3] = {A2, A3, A4};

byte botao = 12;

unsigned long t_0;
unsigned long t_1;
unsigned long t_aux;
unsigned  int safe_time;

unsigned int t = 4000;


int  disp[10][8] = { { 0, 1, 1, 1, 1, 1, 1, 0 }, // = Digit 0
  { 0, 1, 0, 0, 1, 0,  0, 0 }, // = Digit 1
  { 0, 0, 1, 1, 1, 1, 0, 1 }, // = Digit 2
  { 0, 1,  1, 0, 1, 1, 0, 1 }, // = Digit 3
  { 0, 1, 0, 0, 1, 0, 1, 1 }, // = Digit 4
  { 0, 1, 1, 0, 0, 1, 1, 1 }, // = Digit 5
  { 0, 1, 1, 1, 0, 1, 1, 1 }, // =  Digit 6
  { 0, 1, 0, 0, 1, 1, 0, 0 }, // = Digit 7
  { 0, 1, 1, 1, 1, 1, 1,  1 }, // = Digit 8
  { 0, 1, 1, 0, 1, 1, 1, 1 }  // = Digit 9
};

void  setup() {

  
  for (int i = 2; i < 9; i++)
  {
    pinMode(i, OUTPUT);
  }
  
  for (int  i = A0; i < A5; i++)
  {
    pinMode(i, OUTPUT);
  }
  
  pinMode(botao, INPUT);
  t_0 = millis();
}

void  loop() {

  
  number_display(5);

  
  t_1 = millis();
  if (t_1 - t_0 < t) {
    safe_time = t_1 - t_0;
  }

  
  digitalWrite(sinal_carros[2],  HIGH);
  digitalWrite(sinal_pedestre[0], HIGH);
  
  if (digitalRead(botao) == HIGH)
  {

    delay(8000 - safe_time);

    
    digitalWrite(sinal_carros[2], LOW);
    digitalWrite(sinal_carros[1],  HIGH);

    delay(2500);

    
    digitalWrite(sinal_carros[1],  LOW);
    digitalWrite(sinal_carros[0], HIGH);
    digitalWrite(sinal_pedestre[0],  LOW);
    digitalWrite(sinal_pedestre[1], HIGH);

    
    t_0 = millis();
    t_aux = 0;
    while (t_aux  < 5000) {
      idle_display();
      t_aux = millis() - t_0;
    }

    for (int k = 9; k > 0; k--) {
      number_display(k);

      delay(1000);
    }
    
    digitalWrite(sinal_carros[0],  LOW);
    digitalWrite(sinal_pedestre[1], LOW);

    t_0 = millis();
  }

}

void  number_display(int m) {

  for (int j = 2; j < 9; j++) {
    digitalWrite(j,  disp[m][j - 1]);
  }

}

void idle_display() {
  turnOf_display();
  digitalWrite(3, 1);
  delay(150);
  digitalWrite(3, 0);
  digitalWrite(8,  1);
  delay(150);
  digitalWrite(8, 0);
  digitalWrite(6, 1);
  delay(150);
  digitalWrite(6, 0);
  delay(150);

}

void turnOf_display() {
  for (int i = 2; i < 9; i++) {
    digitalWrite(i, 0);
  }
}
