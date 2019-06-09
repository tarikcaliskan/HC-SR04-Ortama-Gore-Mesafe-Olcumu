const int trigger_pin = 8;
const int echo_pin = 9;

int sure;
int mesafe;


float sicaklik = 25.8; //Ondalık yazma şansınız yoksa direk 25 de yazabilirsiniz.


//Sesin ortamda yayılma hızının sıcaklığa göre matematiksel olarak hesaplanması

float formul = 1 + sicaklik / 273;
float formulKarekok = sqrt(formul);
float sesHizi = 1 / ((331 * formulKarekok) / 10000);


void setup() {
  
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger_pin, LOW);
  sure = pulseIn(echo_pin, HIGH);
  mesafe = (sure/2) / sicaklik;

  Serial.print("Mesafe = ");
  Serial.println(mesafe + " cm");

}
