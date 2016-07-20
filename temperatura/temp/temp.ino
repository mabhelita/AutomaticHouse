float tempC;
int tempPin=0;
int calefaccion=12;
int ventilador=13;
// pin donde se conectan loa leds para el fotoresistor
int pinLed1= 2;
int pinLed2= 3;
// pin de entrada para el LDR
int pinLDR=1;
// variable para almacenar valor del LDR
int valorLDR=0;
void setup()
{
  Serial.begin(9600);
  pinMode(calefaccion,OUTPUT);
  pinMode(ventilador,OUTPUT);

  // configuramos los pines de salidas del led para el LDR
  pinMode(pinLed1,OUTPUT);
  pinMode(pinLed2,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  tempC=analogRead(tempPin);
  tempC=(5.0*tempC*100.0)/1024.0;
  Serial.print(tempC);
   Serial.print("grados celsius/n");
   Serial.println("   ");
   
   delay(5000);  
   if(tempC<20){
    digitalWrite(calefaccion,HIGH);
    }
    else{
      digitalWrite(calefaccion,LOW);
    if(tempC>27){
      digitalWrite(ventilador,HIGH);
      }
    } 
  /// apagar los leds del ldr al inicio
  digitalWrite(pinLed1,LOW);
  digitalWrite(pinLed2,LOW);
  // guardamos el valor leido por el LDR}
  valorLDR=analogRead(pinLDR);
  // devolver el valor al monitor
  Serial.println(valorLDR);
}


