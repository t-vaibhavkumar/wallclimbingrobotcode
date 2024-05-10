int ST = 8; //suction top
int SB = 9; //suction bottom
int CT =11; //cylinder top
int CB = 12; //cylinder bottom
int k=0;
int arr[4] = {8,9,11,12};

void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void moveUp(){
  digitalWrite(SB,LOW);
  delay(1500);
  digitalWrite(ST,HIGH);
  delay(1500);
  digitalWrite(CB, LOW);
  delay(500);
  digitalWrite(CB,HIGH);
  delay(1500);
  digitalWrite(ST,LOW);
  delay(1500);
  digitalWrite(SB,HIGH);
  delay(1500);
  digitalWrite(CT,LOW);
  delay(500);
  digitalWrite(CT,HIGH);
  delay(1500);
  digitalWrite(SB,LOW);
}

void moveDown(){
  digitalWrite(ST,LOW);
  delay(1500);
  digitalWrite(SB,HIGH);
  delay(1500);
  digitalWrite(CB, LOW);
  delay(500);
  digitalWrite(CB,HIGH);
  delay(1500);
  digitalWrite(SB,LOW);
  delay(1500);
  digitalWrite(ST,HIGH);
  delay(1500);
  digitalWrite(CT,LOW);
  delay(500);
  digitalWrite(CT,HIGH);
  delay(1500);
  digitalWrite(ST,LOW);
}


void loop() {

  if (k == 0) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(1000);
    k++;
  }
  digitalWrite(ST, LOW);
  digitalWrite(SB, LOW);
  delay(5000);

  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') {
      moveUp(); 
      delay(2000);
    } else if (command == '2') {
      moveDown();
      delay(2000);
    } else if (command == '3') {
      digitalWrite(CB,HIGH);
      digitalWrite(CT, HIGH);
      digitalWrite(ST, LOW);
      digitalWrite(SB, LOW);
      }
    }
  }

  
  // digitalWrite(ST,HIGH);
  // delay(1000);
  // digitalWrite(CB,LOW);
  // delay(1000);
  // digitalWrite(CB,HIGH);
  // delay(1000);
  // digitalWrite(ST,LOW);
  // delay(5000);
  // digitalWrite(SB,HIGH);
  // delay(1000);
  // digitalWrite(CT,LOW);
  // delay(1000);
  // digitalWrite(CT,HIGH);
  // delay(1000);
  // digitalWrite(SB,LOW);
  // delay(1000);


