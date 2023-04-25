#include "LedControl.h"

int ledVerde = 2;
int ledGalben = 3;
int ledRosu = 4;
int senzor = 5;
int delayLeduri = 150;
int buton = 6;
int statusButon = 0;
bool butonApasat = false;
LedControl matriceLeduri = LedControl(12,11,10,1);
int delayMatrice = 500;
int stareSistem;
String com;
int timeout = 100;
String cuvant;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }
  pinMode (ledVerde, OUTPUT);
  pinMode (ledGalben, OUTPUT);
  pinMode (ledRosu, OUTPUT);
  pinMode (senzor, INPUT);
  pinMode (buton, INPUT);

  matriceLeduri.shutdown(0,false);
  matriceLeduri.setIntensity(0,8);
  matriceLeduri.clearDisplay(0);
  Serial.println("Alegeti o comanda:");
  Serial.println("1.3 leduri");
  Serial.println("2+Litere.Matrice leduri");
  stareSistem = 1;
  Serial.setTimeout(timeout);
}

void loop() {
  com = Serial.readString();
  if(com.toInt() != 0)
    stareSistem = com.toInt();

  //Serial.println(stareSistem);delay(50);
  if(stareSistem == 1){
    verificaButon();
    verificaSenzor();
  }
  else if(stareSistem == 2){
    if(com.length() > 2)
      cuvant = com.substring(1, com.length());
    for(int i = 0; i <= cuvant.length(); i++)
         afiseazaLitera(cuvant.charAt(i));
  }
}


void verificaButon()
{
  if(digitalRead(buton) == HIGH && butonApasat == false){
        statusButon++;
        butonApasat = true;
  }
  else if(digitalRead(buton) == LOW)
    butonApasat = false;
      
  if(statusButon == 1)
     lumineazaLeduri();
  if(statusButon == 2)
     lumineazaLeduri2();
  else if(statusButon >= 3)
     statusButon = 0;
}

void verificaSenzor()
{
  if(digitalRead(senzor) == 1)
      delayLeduri += 50;
  if(delayLeduri == 600)
      delayLeduri = 50;
}

void lumineazaLeduri()
{
  digitalWrite(ledVerde, HIGH);
  delay(delayLeduri);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledGalben, HIGH);
  delay(delayLeduri);
  digitalWrite(ledGalben, LOW);
  digitalWrite(ledRosu, HIGH);
  delay(delayLeduri);
  digitalWrite(ledRosu, LOW);
}

void lumineazaLeduri2()
{
  digitalWrite(ledRosu, HIGH);
  digitalWrite(ledGalben, HIGH);
  digitalWrite(ledVerde, HIGH);
  delay(delayLeduri);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledGalben, LOW);
  digitalWrite(ledRosu, LOW);
  delay(delayLeduri);
}

void afiseazaLitera(char litera)
{
  byte A[8] = { B01111110,B01000010,B01000010,B01000010,B01111110,B01000010,B01000010,B01000010};
  byte B[8] = { B01111100,B01000010,B01000010,B01000010,B01111100,B01000010,B01000010,B01111100};
  byte C[8] = { B01111100,B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01111100};
  byte D[8] = { B01111100,B01000010,B01000010,B01000001,B01000001,B01000010,B01000010,B01111100};
  byte E[8] = { B00000000,B01111110,B01000000,B01000000,B01111100,B01000000,B01000000,B01111110};
  byte F[8] = { B00000000,B01111110,B01000000,B01000000,B01111100,B01000000,B01000000,B01000000};
  byte G[8] = { B01111110,B01000000,B01000000,B01000000,B01001110,B01000010,B01000010,B01111110};
  byte H[8] = { B00000000,B01000010,B01000010,B01000010,B01111110,B01000010,B01000010,B01000010};
  byte I[8] = { B00010000,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000};
  byte J[8] = { B00000100,B00000100,B00000100,B00000100,B00000100,B01000100,B01000100,B00111000};
  byte K[8] = { B01000010,B01000100,B01001000,B01110000,B01001000,B01000100,B01000010,B01000010};
  byte L[8] = { B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01000000,B01111110};
  byte M[8] = { B00000000,B01100011,B01010101,B01001001,B01000001,B01000001,B01000001,B01000001};
  byte N[8] = { B00000000,B01000001,B01100001,B01010001,B01001001,B01000101,B01000011,B01000001};
  byte O[8] = { B00011000,B00100100,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000};  
  byte P[8] = { B00000000,B01111100,B01000100,B01000100,B01111100,B01000000,B01000000,B01000000};
  byte Q[8] = { B00111100,B01000010,B01000010,B01000010,B01001010,B01000110,B00111110,B00000001};
  byte R[8] = { B11111100,B10000100,B10000100,B11111000,B10100000,B10010000,B10001000,B10000100};
  byte S[8] = { B00000000,B01111110,B01000000,B01000000,B01111110,B00000010,B00000010,B01111110};
  byte T[8] = { B00000000,B11111110,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000};
  byte U[8] = { B00000000,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B01111110};
  byte V[8] = { B00000000,B10000001,B10000001,B10000001,B10000001,B01000010,B00100100,B00011000};
  byte W[8] = { B00000000,B00000000,B10000001,B10000001,B10100101,B10011001,B01011010,B00100100};
  byte X[8] = { B10000001,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B10000001};
  byte Y[8] = { B00000000,B10000010,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000};
  byte Z[8] = { B00000000,B01111111,B00000010,B00000100,B00001000,B00010000,B00100000,B01111111};

  switch(litera){
    case 'A':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,A[i]);
    }
    break;

    case 'B':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,B[i]);
    }
    break;

    case 'C':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,C[i]);
    }
    break;

    case 'D':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,D[i]);
    }
    break;

    case 'E':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,E[i]);
    }
    break;

    case 'F':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,F[i]);
    }
    break;

    case 'G':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,G[i]);
    }
    break;

    case 'H':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,H[i]);
    }
    break;

    case 'I':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,I[i]);
    }
    break;

    case 'J':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,J[i]);
    }
    break;

    case 'K':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,K[i]);
    }
    break;

    case 'L':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,L[i]);
    }
    break;

    case 'M':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,M[i]);
    }
    break;

    case 'N':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,N[i]);
    }
    break;

    case 'O':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,O[i]);
    }
    break;

    case 'P':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,P[i]);
    }
    break;

    case 'Q':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,Q[i]);
    }
    break;

    case 'R':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,R[i]);
    }
    break;

    case 'S':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,S[i]);
    }
    break;

    case 'T':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,T[i]);
    }
    break;

    case 'U':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,U[i]);
    }
    break;

    case 'V':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,V[i]);
    }
    break;

    case 'W':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,W[i]);
    }
    break;

    case 'X':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,X[i]);
    }
    break;

    case 'Y':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,Y[i]);
    }
    break;

    case 'Z':
    for (int i=0; i<8; i++){
       matriceLeduri.setRow(0,i,Z[i]);
    }
    break;
    }

    delay(delayMatrice);
    for(int i=0; i<8; i++){
      matriceLeduri.setRow(0,i,0);
    }
}
