
// FRONT
#define R_FWD 8
#define R_BWD 7

#define L_FWD 4
#define L_BWD 5

void setup() {
  
 Serial.begin(9600);
  pinMode(R_FWD, OUTPUT);
  pinMode(R_BWD, OUTPUT);


  pinMode(L_FWD, OUTPUT);
  pinMode(L_BWD, OUTPUT);



}

void loop() {

 while(Serial.available()){
  char val = Serial.read();
  command(val);
 }
}

void command(char val) {
  Serial.print(val,DEC);
  switch(val){
    case 'w':forward();break;
    case 'a':left();break;
    case 's': reverse();break;
    case 'd': right();break;
    case 'b':brake();break;
    default: Serial.println(val,DEC);
  }
}

void forward(){
  
  analogWrite(R_FWD, 1023);
  digitalWrite(R_BWD, LOW);

  analogWrite(L_FWD, 1023);
  digitalWrite(L_BWD, LOW);

}

void right(){

  digitalWrite(R_FWD, HIGH);
  digitalWrite(R_BWD, LOW);


  digitalWrite(L_FWD, LOW);
  digitalWrite(L_BWD, HIGH);
}

void left(){
 
  digitalWrite(R_FWD, LOW);
  digitalWrite(R_BWD, HIGH);

  digitalWrite(L_FWD, HIGH);
  digitalWrite(L_BWD, LOW);
}

void reverse(){
 
  digitalWrite(R_FWD, LOW);
  digitalWrite(R_BWD, HIGH);


  digitalWrite(L_FWD, LOW);
  digitalWrite(L_BWD, HIGH);

}

void brake(){

  digitalWrite(R_FWD, LOW);
  digitalWrite(R_BWD, LOW);

  digitalWrite(L_FWD, LOW);
  digitalWrite(L_BWD, LOW);



}
