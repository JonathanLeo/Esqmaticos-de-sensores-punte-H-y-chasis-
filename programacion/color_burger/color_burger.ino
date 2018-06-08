int motormenos1 = 2;
int motormas1 = 3;
int motormenos2 = 4;
int motormas2 = 5;
int velocidadmas1 = 0;
int velocidadmas2 = 0;
bool velocidadmenos1 = 0;
bool velocidadmenos2 = 0;
int tabla = 0;
int sizquierda = 0;
int scentroiz = 0;
int scentrode = 0;
int sderecha = 0;
int RPM = 255; // 0-255

void setup()  //declarando entradas salidas
{
 
pinMode(motormenos1,OUTPUT); // 2 salida motor 1 -
pinMode(motormas1,OUTPUT); // 3 salida PWM motor 1 +
pinMode(motormenos2,OUTPUT);//  4 salida motor 2 -
pinMode(motormas2,OUTPUT);//  5 salida PWM motor 2 +

pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(13,INPUT); 

Serial.begin(9600); // inicializa el puerto usb a esa velocidad
}

void loop()
{ 
  //------------------------------------------------------------------------------------------
  //lectura de sensores
tabla = 0;
 if (analogRead(A0)>= 290)  sizquierda = 0,digitalWrite(8,LOW),(tabla = tabla + 0);
     else                   sizquierda = 1,digitalWrite(8,HIGH),(tabla = tabla + 8);
        
 if (analogRead(A1)>= 575)  scentroiz = 0, digitalWrite(9,LOW),(tabla = tabla + 0);
     else                   scentroiz = 1, digitalWrite(9,HIGH),(tabla = tabla + 4);

 if (analogRead(A2)>= 525)  scentrode = 0, digitalWrite(10,LOW),(tabla = tabla + 0);
     else                   scentrode = 1, digitalWrite(10,HIGH),(tabla = tabla + 2);

 if (analogRead(A3)>= 475)  sderecha = 0, digitalWrite(11,LOW),(tabla = tabla + 0);
     else                   sderecha = 1, digitalWrite(11,HIGH),(tabla = tabla + 1);

/*CREACION DE MATRIZ
tabla = 0;
if (sderecha = 1)      (tabla = tabla + 0);
if (sderecha = 0)      (tabla = tabla + 1);

if (scentrode = 0)     (tabla = tabla + 0);
if (scentrode = 1)      (tabla = tabla + 2); 

if (scentroiz = 0)     (tabla = tabla + 0);
if (scentroiz = 1)      (tabla = tabla + 4);

if (sizquierda = 0)    (tabla = tabla + 0);
if (sizquierda = 1)    (tabla = tabla + 8); */


Serial.println(tabla);
  //DECIDIENDO CONDICIONES
 //--------------------------------------------------------------------------------------------
 if (tabla == 0)
    velocidadmas1 = 0,//REVERSA 
    velocidadmenos1= HIGH, 
    velocidadmas2 = 0, //REVERSA 
    velocidadmenos2= HIGH; //
     
 if (tabla == 1)
    velocidadmas1 = 0,    //  RPM
    velocidadmenos1= LOW, // ADELANTE
    velocidadmas2 = RPM,
    velocidadmenos2= LOW; //PARAR
 
 if (tabla == 2)
    velocidadmas1 = 0,//RPM = 50% DE MOTOR
    velocidadmenos1= LOW, // ADELANTE
    velocidadmas2 = RPM,
    velocidadmenos2= LOW; //PARAR
 
  if (tabla == 3) 
    velocidadmas1 = 0,//RPM = 50% DE MOTOR
    velocidadmenos1= LOW, // ADELANTE
    velocidadmas2 = RPM,
    velocidadmenos2= LOW; //PARAR

 if (tabla == 4) 
    velocidadmas1 = RPM,//RPM = 50% DE MOTOR
    velocidadmenos1= LOW, // ADELANTE
    velocidadmas2 = 0,
    velocidadmenos2= HIGH; //PARAR

 
 if (tabla == 5)
    velocidadmas1   = velocidadmas1, //seguir con el estado anterior
    velocidadmenos1 = velocidadmenos1,
    velocidadmas2   = velocidadmas2,
    velocidadmenos2 = velocidadmenos2;  
 
 if (tabla == 6)
    velocidadmas1 = RPM,//adelante
    velocidadmenos1= LOW, // parar
    velocidadmas2 = HIGH, //adelante
    velocidadmenos2= LOW;
 
 if (tabla == 7)    
    velocidadmas1 = RPM,
    velocidadmenos1= LOW,//parar 
    velocidadmas2 = 0,
    velocidadmenos2= LOW; //adelante 
 
 if (tabla == 8)   
    velocidadmas1 = RPM, //parar
    velocidadmenos2= LOW, 
    velocidadmas2 = 0,//adelante 
    velocidadmenos2= LOW;
     
 if (tabla == 9)    
    velocidadmas1   = velocidadmas1, //seguir con el estado anterior
    velocidadmenos1 = velocidadmenos1,
    velocidadmas2   = velocidadmas2,
    velocidadmenos2 = velocidadmenos2; 

 if (tabla == 10)    
    velocidadmas1 = RPM,//parar
    velocidadmenos1= LOW, 
    velocidadmas2 = 0,//adelante
    velocidadmenos2= LOW; 
 
 if (tabla == 11)    
    velocidadmas1 = 0,//RPM = 50% DE MOTOR
    velocidadmenos1= LOW, // ADELANTE
    velocidadmas2 = RPM,
    velocidadmenos2= LOW; //PARAR 
 
 if (tabla == 12) 
    velocidadmas1 = RPM,//parar
    velocidadmenos1= LOW, 
    velocidadmas2 = 0, //adelante
    velocidadmenos2= HIGH; //
 
 if (tabla == 13)    
    velocidadmas1 = RPM,//parar
    velocidadmenos1= LOW, 
    velocidadmas2 = 0, //adelante
    velocidadmenos2= LOW; //
    
 if (tabla == 14)   
    velocidadmas1 = RPM,//parar
    velocidadmenos1= LOW, 
    velocidadmas2 = 0, //adelante
    velocidadmenos2= LOW; //
    
 if (tabla == 15)
    velocidadmas1 = RPM,//adelante
    velocidadmenos1= LOW, 
    velocidadmas2 = RPM, //adelante
    velocidadmenos2= LOW; // 
 //--------------------------------------------------------------------------------------------
 //enviando velocidad a motores
  analogWrite(motormas1,velocidadmas1);// envia señal analogica al (pwm)
  digitalWrite(motormenos1,velocidadmenos1);
  analogWrite(motormas2,velocidadmas2);//
  digitalWrite(motormenos2,velocidadmenos2);
  //delay(100);
  }

