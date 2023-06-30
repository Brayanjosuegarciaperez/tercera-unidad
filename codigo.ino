#include <LedControl.h> //libreria para las led matricial
#include <Adafruit_NeoPixel.h>//libreria para la rueda led
#include <Servo.h>//se instala esta libreria para el servo motor
#include <SoftwareSerial.h>//para el bluetoo


SoftwareSerial miBT(8, 9);//se indica el tx rxt de los pines que van y tambien el nombre del bluetooo
Adafruit_NeoPixel tira = Adafruit_NeoPixel(7,12);//SE INDICA EL NUMERO DE PIXELES A USAR Y EL PIN CON EL QUE SE VA A CONTROLAR
LedControl MATLED = LedControl(11,13,10,1);	// crea objeto

byte caracter[8] = {		//Arreglo para mostrar la figura	1	
0x0, 0x18, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3c
};

byte caracter_2[8] = { //Arreglo para mostrar la figura	2
0x0, 0x3c, 0x42, 0x4, 0x8, 0x10, 0x20, 0x7e
};
byte caracter_3[8] = { //Arreglo para mostrar la figura	3
0x3c, 0x66, 0x6, 0x1c, 0x6, 0x66, 0x3c, 0x0
};

 
char Dato;//nos ayudaran a leer el dato que viene como caracter 

//los pines se indican para las leds
int LED_1=2;
int LED_2=3;
int LED_3=4;
int LED_4=5;

//nos ayudaran para los estados de los botones para hacerlo que se pueda encender y apagar con el mismo boton
bool estado = 0;
bool estado1=0;
bool estado2=0;
bool estado3=0;

//nos ayudaran para el valor del bluetooo
int valor=0;
int valor_luces;

//para el servo
Servo jota;

void setup() {
  miBT.begin(9600);//se inicializa el bluetoo
  Serial.begin(9600);//se inicializa el monitor serial 
  //se indica los pines como salida
  pinMode(LED_1,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);
  pinMode(LED_4,OUTPUT);
  tira.begin();//se inicializa la rueda led
  tira.show();//se utiliza para la rueda led
  MATLED.shutdown(0,false);			// enciende la matriz
  MATLED.setIntensity(0,4);			// establece brillo
  MATLED.clearDisplay(0);	//se indica para limpiar la matriz led
  jota.attach(6);//se indica que pin va el servo 

}

 

void loop() {

  if (miBT.available() > 0){//se indica lo que lleva la configuración del bluetoo
    Dato = miBT.read();//se indica que dato sea igual que lee el bluetoo
   Serial.println(Dato);// y que imprima el valor del dato

   if(Dato == '1')//se dato es igual a el caracter A hace lo siguiente 
   estado=!estado;// para apagar y encender con el mismo boton
   digitalWrite(LED_1, estado);

    if(Dato == '2')//se dato es igual a el caracter A hace lo siguiente 
   estado1=!estado1;// para apagar y encender con el mismo boton
   digitalWrite(LED_2, estado1);

    if(Dato == '3')//se dato es igual a el caracter A hace lo siguiente 
   estado2=!estado2;// para apagar y encender con el mismo boton 
   digitalWrite(LED_3, estado2);

    if(Dato == '4')//se dato es igual a el caracter A hace lo siguiente 
   estado3=!estado3;// para apagar y encender con el mismo boton
   digitalWrite(LED_4, estado3);


   if(Dato == '5')//se dato es igual a el caracter A hace lo siguiente 
   caracter1();//que haga la función

   if(Dato == '6')//se dato es igual a el caracter A hace lo siguiente 
   caracter2();//que gaha la función


   if(Dato == '7')//se dato es igual a el caracter A hace lo siguiente 
   caracter3();//que haga la función


   if(Dato == '8')//se dato es igual a el caracter A hace lo siguiente 
     for(int i = 0; i<7; i = i+1 ){//se crea una variable adentro que su valor es cero y ahí en for se indica que cuando i<7 este salga de ese bucle y despues se indica como se va a incrimentar
      tira.setBrightness(100);//reasignará el máximo para toda la tira
      tira.setPixelColor(i, 75,178,150);// se le indica que el pin y luego los tres configuraciones para que de un color
      tira.show();//para la tira led 
      delay(100);//que tome un tiempo
    }

  }
  servo();//que haga la función servo
  secuencia();//que haga la función cambios 

 }

 void caracter1(){//se crea la funcion para figura
     for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
      {
     MATLED.setRow(0,i,caracter[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
 }


void caracter2(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_2[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }

}
void caracter3(){//se crea la funcion para figura
     for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_3[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

void servo(){//que crea la función 
  if (miBT.available() > 0){//que si el bluetoo es mayor que cero
    valor = miBT.read();//valor sea a lee el bluetoo
    Serial.println(valor);//imprima el valor
    jota.write(valor); //y que el servo haga lo que este en el valor del servo
  }
}

void secuencia(){//se crea la variable para los cambios en las leds
  if (miBT.available() > 0){//que si el bluetoo es mayor que cero
    valor_luces = miBT.read();//valor_luces sea a lee el bluetoo
    Serial.println(valor_luces);//imprima el valor_luces
    if(valor_luces >= 200){//si luces es mayor e igual a 190
      digitalWrite(LED_1,HIGH);//este encienda la led1
    }
    if(valor_luces >= 215){//si luces es mayor e igual a 200
      digitalWrite(LED_2,HIGH);//este encienda la led2
    }
    if(valor_luces >= 225)//si luces es mayor e igual a 215
    {
      digitalWrite(LED_3,HIGH);//este encienda la led3
    }
    
    if(valor_luces >= 235)//si luces es mayor e igual a 235
    {
      digitalWrite(LED_4,HIGH);//este encienda la led4
    }
  }
}
