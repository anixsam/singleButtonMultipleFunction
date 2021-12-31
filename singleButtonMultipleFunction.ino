#define sw 2


int lastButtonState = HIGH;  
unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50;   
bool buttonState = HIGH; 
byte tapCounter;
int timediff; 
bool flag1, flag2; 
long double presstime, releasetime; 


void setup() 
{
  Serial.begin(9600); 
  pinMode(sw, INPUT_PULLUP); 
}

void loop() 
{

  int reading = digitalRead(sw);

  if (reading != lastButtonState) {
     lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
    }
  }
   if (buttonState == 0 && flag2 == 0)
  {
    presstime = millis(); 
    flag1 = 0;
    flag2 = 1;
    tapCounter++; 
    //delay(10); //To Reduce bebouncing
  }
  if (buttonState == 1 && flag1 == 0)
  {
    releasetime = millis(); 
    flag1 = 1;
    flag2 = 0;

    timediff = releasetime - presstime; 
    //delay(10); //To Reduce bebouncing
  }

  if ((millis() - presstime) > 400 && buttonState == 1) 
  {
    if (tapCounter == 1) 
    {
      if (timediff >= 400) //if time diff is larger than 400 then its a hold
      {
        Serial.write("h");
       	hold(); //hold function
      }
      else 
      {
        Serial.write("s");
        singleTap(); //single tap function
       
      }
    }
    else if (tapCounter == 2 )
    {
      if (timediff >= 400) 
      {
        tapAndHold(); //Tap and hold function
      }
      else 
      {
        Serial.write('d');
        doubleTap(); //double tap function
      }
    }
    else if (tapCounter == 3) //if tapcounter is 3 //then its triple tap
    {
      Serial.write('t');
      tripleTap(); //triple tap function
    }
    else if (tapCounter == 4) 
    {
      Serial.write('f');
      fourTap();//four tap function
    }
    tapCounter = 0;
  }
  lastButtonState = reading;
}


void nolight()
{
}
void singleTap()
{
}
void doubleTap()
{
}
void tripleTap()
{
}
void fourTap()
{
}
void hold()
{
}
void tapAndHold()
{
}
