
#define in1 5
#define in2 6
#define button 4
#define button1 7


int pressed = false;
bool parado = true ;
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button1, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  // Read button - Debounce
     digitalRead(button);
     if(!parado){
        if (digitalRead(button)== 1){
       
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      Serial.println("left");
      
    
      }else{
        digitalRead(button1);
        digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      Serial.println("right");
      }
      } else {
        if ( digitalRead(button)||digitalRead(button1)){
          parado = false;
        }
      }
    
    
    
     
 }
