#include <infrarrojo.h>// libreria para los sensores

int motor1 =  5;  // el numero del pin para el primer motor V(-)
int motor1a =  6;   //el numero del pin para el primer motor V(+)
int motor2 =  10;  // el numero del pin para el segundo motor V(+)
int motor2a =  11;   //el numero del pin para el segundo motor V(-)

infrarrojo sen1(2);//El numero de pin a usar para el sensor 1
infrarrojo sen2(4);//El numero de pin a usar para el sensor 2
infrarrojo sen3(7);//El numero de pin a usar para el sensor 3
infrarrojo sen4(8);//El numero de pin a usar para el sensor 4

int VALOR;//variable que recibe el valor del dato de sensor

int estadosen1;//almacena el que tiene la variable VALOR en el valor del sensor 1
int estadosen2;//almacena el que tiene la variable VALOR en el valor del sensor 2
int estadosen3;//almacena el que tiene la variable VALOR en el valor del sensor 3
int estadosen4;//almacena el que tiene la variable VALOR en el valor del sensor 4


void setup() {
  //se configuran los motores como salida
  pinMode(motor1, OUTPUT);  
  pinMode(motor1a, OUTPUT);
  pinMode(motor2, OUTPUT);  
  pinMode(motor2a, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  //Se utiliza monitor serial para poder conocer el estado que identifica cada sensor, es una aplicacion para pruebas
  Serial.print("\n Leyendo estado sensor: \n");

  //obteniendo el valor del primer sensor via monitor serial 
  Serial.print(sen1.lectura(VALOR));//imprime el estado logico en el monitor serial del sensor 1
  estadosen1 = sen1.lectura(VALOR);

    //obteniendo el valor del segundo sensor via monitor serial 
  Serial.print(sen2.lectura(VALOR));//imprime el estado logico en el monitor serial del sensor 2
  estadosen2 = sen2.lectura(VALOR);

    //obteniendo el valor del tercer sensor via monitor serial 
  Serial.print(sen3.lectura(VALOR));//imprime el estado logico en el monitor serial del sensor 3
  estadosen3 = sen3.lectura(VALOR);
  
  //obteniendo el valor del cuarto sensor via monitor serial 
  Serial.print(sen4.lectura(VALOR));//imprime el estado logico en el monitor serial del sensor 4
  estadosen4 = sen4.lectura(VALOR);
  
    if((estadosen1 == 1)&&(estadosen2 ==1)&&(estadosen3 ==0)&&(estadosen4 ==0))//si el sensor 1 y 2 estan en negro (1) el carro avanza
  {
    analogWrite(motor1,0);  //reversa
    analogWrite(motor1a, 200); //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2,200);  //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2a, 0);//reversa
  }

  if((estadosen1 == 1)&&(estadosen2 ==1)&&(estadosen3 ==1)&&(estadosen4 ==1))//si el sensor 1, 2, 3 y 4  estan en negro (1) el carro avanza
  {
    analogWrite(motor1,0);  //reversa
    analogWrite(motor1a, 200); //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2,200);  //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2a, 0);//reversa
  }
  
   if((estadosen1 == 0)&&(estadosen2 ==0)&&(estadosen3 ==0)&&(estadosen4 ==0))//si el sensor 1, 2, 3 y 4 estan en blanco (0) el carro se detiene
  {
    analogWrite(motor1,200);  //reversa
    analogWrite(motor1a, 0); //adelante
    analogWrite(motor2,0);  //adelante
    analogWrite(motor2a, 200);//reversa
  }

  if((estadosen3 == 1)&&(estadosen1 ==0)&&(estadosen2 ==0)&&(estadosen4 ==0))//si el sensor 3 esta en negro (1) el carro avanza y gira hacia la derecha
  {
    analogWrite(motor1,0);  //reversa
    analogWrite(motor1a, 200); //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2,0);  //adelante
    analogWrite(motor2a, 0);//reversa
  }

  if((estadosen4 == 1)&&(estadosen1 ==0)&&(estadosen2 ==0)&&(estadosen3 ==0))//si el sensor 4 esta en negro (1) el carro avanza y gira hacia la izquierda
  {
    analogWrite(motor1,0);  //reversa
    analogWrite(motor1a, 0); //adelante
    analogWrite(motor2, 200);  //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2a, 0);//reversa
  }

  if((estadosen3 == 1)&&(estadosen1 ==0)&&(estadosen2 ==1)&&(estadosen4 ==0))//si el sensor 3 y 2 estan en negro (1) el carro avanza y gira hacia la derecha
  {
    analogWrite(motor1,0);  //reversa
    analogWrite(motor1a, 200); //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2,0); //adelante
    analogWrite(motor2a, 0);//reversa
  }

  if((estadosen4 == 1)&&(estadosen1 ==1)&&(estadosen2 ==0)&&(estadosen3 ==0))//si el sensor 4 y 1 estan en negro (1) el carro avanza y gira hacia la izquierda
  {
    analogWrite(motor1,0);  //reversa
    analogWrite(motor1a, 0); //adelante
    analogWrite(motor2,200);  //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2a, 0);//reversa
  }
  if((estadosen3 == 1)&&(estadosen1 ==1)&&(estadosen2 ==1)&&(estadosen4 ==0))//si el sensor 3, 2 y 1 estan en negro (1) el carro avanza y gira hacia la derecha
  {
    analogWrite(motor1,0);  //reversa
    analogWrite(motor1a, 200); //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2,0);  //adelante
    analogWrite(motor2a, 0);//reversa
  }
  if((estadosen4 == 1)&&(estadosen1 ==1)&&(estadosen2 ==1)&&(estadosen3 ==0))//si el sensor 4, 1 y 2 estan en negro (1) el carro avanza y gira hacia la izquierda
  {
    analogWrite(motor1,0);  //reversa
    analogWrite(motor1a, 0); //adelante
    analogWrite(motor2,200);  //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2a, 0);//reversa
  }
  if((estadosen3 == 0)&&(estadosen1 ==0)&&(estadosen2 ==1)&&(estadosen4 ==0))//si el sensor 2 esta en negro (1) el carro avanza y gira hacia la derecha
  {
    analogWrite(motor1,0);  //reversa
    analogWrite(motor1a, 200); //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2,0);  //adelante
    analogWrite(motor2a, 0);//reversa
  }
   if((estadosen4 == 0)&&(estadosen1 ==1)&&(estadosen2 ==0)&&(estadosen3 ==0))//si el sensor 1 esta en negro (1) el carro avanza y gira hacia la izquierda
  {
    analogWrite(motor1,0);  //reversa
    analogWrite(motor1a, 0); //adelante
    analogWrite(motor2,200);  //adelante, con un valor analogico de 200 para la velocidad del los motorreductores
    analogWrite(motor2a, 0);//reversa
  }
}
