void setup() {
  // put your setup code here, to run once:
  //LED
  pinMode(13, OUTPUT);
  //Buzzer
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // send_hi_k();
  send_cq_dx();
}

byte element_wait=100;

void faster() {
  element_wait -= 10;
}

void slower() {
  element_wait += 10;
}

void send_hi_k() {
    send_h(); send_i();
    word_space();
    send_k();
    word_space();
}

void send_cq_dx() {
  send_c(); send_q();
  word_space();
  send_d(); send_x();
  word_space();
}
  
void dit() {
  digitalWrite(13, HIGH);
  tone(8, 700);
  delay(element_wait);
  digitalWrite(13, LOW);
  noTone(8);
  delay(element_wait);
}
void dah() {
  digitalWrite(13, HIGH);
  tone(8, 700);
  delay(element_wait*3);
  digitalWrite(13, LOW);
  noTone(8);
  delay(element_wait);
}

void space() {
  delay(element_wait);
}
void letter_space() {
  delay(element_wait*2);
}
void word_space() {
  delay(element_wait*6);
}

//Send "C"
void send_c() {
  dah(); dit(); dah(); dit();
  letter_space();
}
//Send "D"
void send_d() {
  dah(); dit(); dit();
  letter_space();
}
//Send "H"
void send_h() {
  dit(); dit(); dit(); dit();
  letter_space();
}
//Send "I"
void send_i() {
  dit(); dit();
  letter_space();
}
//Send "K"
void send_k() {
  dah(); dit(); dah();
  letter_space();
}
//Send "Q"
void send_q() {
  dah(); dah(); dit(); dah();
  letter_space();
}
//Send "X"
void send_x() {
  dah(); dit(); dit(); dah();
  letter_space();
}
