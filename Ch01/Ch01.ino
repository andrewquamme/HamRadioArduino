void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // send_hi_k();
  send_cq_dx();
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
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
}

void space() {
  delay(100);
}

void dah() {
  digitalWrite(13, HIGH);
  delay(100*3);
  digitalWrite(13, LOW);
  delay(100);
}

//Send "C"
void send_c() {
  dah(); dit(); dah(); dit();
  space(); space();
}

//Send "D"
void send_d() {
  dah(); dit(); dit();
  space(); space();
}

//Send "H"
void send_h() {
  dit(); dit(); dit(); dit();
  space(); space();
}

//Send "I"
void send_i() {
  dit(); dit();
  space(); space();
}

//Send "K"
void send_k() {
  dah(); dit(); dah();
  space(); space();
}

//Send "Q"

//Send "X"

void word_space() {
  space(); space(); space();
}
