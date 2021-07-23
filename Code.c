// C++ code
//
int enA = 10;
int enB = 11;
int in1 = 9;
int in2 = 12;
int in3 = 8;
int in4 = 13;
int PotentiometerVert = A0;
int PotentiometerHorz = A1;
int MS1 = 0;
int MS2 = 0;
int PVert = 512;
int PHorz = 512;  
 
void setup()
{ 
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);  
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(enB, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
 
void loop()
{
  
  PVert = analogRead(PotentiometerVert); 
  PHorz = analogRead(PotentiometerHorz);  
  if (PVert < 460)
  {  
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW); 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);  
    PVert = PVert - 460; 
    PVert = (PVert * (-1));
    MS1 = map(PVert, 0, 460, 0, 255);
    MS2 = map(PVert, 0, 460, 0, 255);
 
  }
  
  else if (PVert > 564)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW); 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW); 
    MS1 = map(PVert, 564, 1023, 0, 255);
    MS2 = map(PVert, 564, 1023, 0, 255); 
  }
  else
  {
    MS1 = 0;
    MS2 = 0; 
  }
    
  if (PHorz < 460)
  {
    
    PHorz = PHorz - 460;
    PHorz = (PHorz * -1);
    PHorz = map(PHorz, 0, 460, 0, 255);
    MS1 = MS1 - PHorz;
    MS2 = MS2 + PHorz;
    
    if (MS1 < 0)MS1 = 0;
    if (MS2 > 255)MS2 = 255;
 
  }
  else if (PHorz > 564)
  {
 
    PHorz = map(PHorz, 564, 1023, 0, 255);
    MS1 = MS1 + PHorz;
    MS2 = MS2 - PHorz;
  
    if (MS1 > 255)MS1 = 255;
    if (MS2 < 0)MS2 = 0;      
 
  }
 
  analogWrite(enA, MS1);
  analogWrite(enB, MS2);
 
}