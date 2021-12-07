#define pin_Led1 11
#define pin_Led2 13

#define pas 9
char data; //recuperer les donnée de qt
int x ; //demunier l'intesité pour l'envoyer a la diode
void setup() {
  // put your setup code here, to run once:
  pinMode (pin_Led2,OUTPUT);
  digitalWrite (pin_Led2,LOW );
  pinMode(pin_Led2,OUTPUT);
  analogWrite(pin_Led1,0);
  Serial.begin(9600);
  x=0;
  

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available())
  {
    data=Serial.read();//read tout les données et sauvgarder dans la variable data
    if(data=='1')
    {
      digitalWrite(pin_Led2,HIGH);
      Serial.write('1');
   
      }

          else if(data=='0')
          {
            digitalWrite(pin_Led2,LOW);//off la diode pine_led2
            Serial.write('0');
            }
        else if (data=='2')
        {
          if(x+pas<255)

           {
            x=x+pas;
            analogWrite(pin_Led1,x);
            Serial.write(x);
            
            }
      else if(data=='1')
          {

            if(x>pas)
             x=x-pas;
             else
             x=0;
             analogWrite(pin_Led1,x);
            }
          }
    
    }

}
