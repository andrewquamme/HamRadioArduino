byte led_pin = 13;
byte buzzer_pin = 8;
byte slower_pin = 2;
byte faster_pin = 3;

byte element_wait=100;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(slower_pin, INPUT_PULLUP); //Turn on 20K pullup resistors
  pinMode(faster_pin, INPUT_PULLUP); //on these two pins
  Serial.begin(9600);
}

void loop() {
  // send_hi_k();
  send_cq_dx();
}

void dit() {
  check_speed();
  digitalWrite(led_pin, HIGH);
  tone(buzzer_pin, 700);
  delay(element_wait);
  digitalWrite(led_pin, LOW);
  noTone(buzzer_pin);
  delay(element_wait);
}
void dah() {
  check_speed();
  digitalWrite(led_pin, HIGH);
  tone(buzzer_pin, 700);
  delay(element_wait*3);
  digitalWrite(led_pin, LOW);
  noTone(buzzer_pin);
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

void faster() {
  if (element_wait > 50) {
    element_wait -= 10;
  }
  Serial.print("faster: element_wait = ");
  Serial.println(element_wait);
}

void slower() {
  if (element_wait < 200) {
    element_wait += 10;
  }
  Serial.print("slower: element_wait = ");
  Serial.println(element_wait);
}

void check_speed() {
  if (digitalRead(faster_pin) == LOW) {
    faster();
  }
  if (digitalRead(slower_pin) == LOW) {
    slower();
  }
}
