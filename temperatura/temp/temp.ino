/*control del arduino mediante
 ethernet 
*/
// librerias para ethernet
#include<SPI.h>
#include<Ethernet.h>
#include<Servo.h>

Servo microservo;
int pos = 0;
byte mac[] = { 0xA0, 0xB3, 0xCC, 0x87, 0xE7, 0x2E }; // direccion fisica MAC
byte ip[] = { 10, 0, 0, 150 };                        // ip local que se debe configurar
byte gateway[] = { 10, 0, 0, 1 };                     // puerta de enlace
byte subnet[] = { 255, 0, 0, 0 };                      // mascara de sub red
EthernetServer server(80);                            // se usa el puerto 80 del servidor
String readString; 

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
  // configurando ethernet
  Ethernet.begin(mac, ip, gateway, subnet);  //inicializa la conexion ethernet y el servidor
  server.begin();
  Serial.print("el servidor es:");
  Serial.println(Ethernet.localIP());    //imprime la direccion ip local

  // configurando los pin de salida de la temperatura  
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
  // conexion con la pagina

  // condiciones para el encendido del calefactor y ventilador
  
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


