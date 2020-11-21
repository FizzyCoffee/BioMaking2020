int east_led_pin = 6; 
int east_pot_pin = A0;

int north_led_pin = 10; 
int north_pot_pin = A1;

int east_output;
int east_led_value;

int north_output;
int north_led_value;

int initial_east_pot = 0;
int initial_north_pot = 0;

int initial_east_led_value = 0;
int initial_north_led_value = 0;

int uneast_led_pin = 5; 
int uneast_led_value;
int unnorth_led_pin = 9; 
int unnorth_led_value;

void setup() {
  pinMode(east_led_pin, OUTPUT);
  pinMode(north_led_pin, OUTPUT);
  pinMode(uneast_led_pin, OUTPUT);
  pinMode(unnorth_led_pin, OUTPUT);
  Serial.begin(9600);
  initial_east_pot = analogRead(east_pot_pin);
  initial_north_pot = analogRead(north_pot_pin);
  Serial.print("north");
  Serial.print(initial_north_pot);
  Serial.print("east");
  Serial.print(initial_east_pot);
  initial_east_led_value = map(initial_east_pot, 600, 1023, 0, 255);
  initial_north_led_value = map(initial_north_pot, 600, 1023, 0, 255);
   Serial.print("Vnorth");
  Serial.print(initial_north_led_value);
  Serial.print("Veast");
  Serial.print(initial_east_led_value);
  
}
void loop() {
  //Reading from potentiometer
  east_output = analogRead(east_pot_pin);
  north_output = analogRead(north_pot_pin);
 
  if(east_output > 600){
   //Mapping the Values from 600-1023 to 0-255
  east_led_value = map(east_output, 600, 1023, 0, 255);
  analogWrite(east_led_pin, east_led_value);
  //switching the opposite LED off
  analogWrite(uneast_led_pin, 0);
  }
    if(east_output < 500){
      //Mapping from 0-500 to 255-0
  east_led_value = map(east_output, 0, 500, 255, 0);
 //switching the opposite LED off
  analogWrite(east_led_pin, 0);
  //turning the LED on
  analogWrite(uneast_led_pin, east_led_value);
  }
 //same for north
    if(north_output > 600){
  north_led_value = map(north_output, 600, 1023, 0, 255);
  analogWrite(north_led_pin, north_led_value);
  analogWrite(unnorth_led_pin, 0);
  }
    if(north_output < 500){
  north_led_value = map(north_output, 0, 500, 255, 0);
  analogWrite(north_led_pin, 0);
  analogWrite(unnorth_led_pin, north_led_value);
  }
  delay(1);
  
}
