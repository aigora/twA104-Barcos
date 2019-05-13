// ----- Electrónica PIC -----
//
// Ejercicio 1.
//
// Encendido y apagado del Led 13 mediante puerto serie.

int Led = 5 , Led2 = 4 , Led3 = 24 , Led4 = 25 , Led5 = 26 , Led6 = 27 , Led7 = 8 , Led8 = 7 ;
int Led9 = 30 , Led10 = 31 , Led11 = 32 , Led12 = 33 , Led13 = 11 , Led14 = 10 , Led15 = 34 ;
int Led16 = 35 , Led17 = 36 , Led18 = 37 ;   // Declaramos la variable pin del Led.
char caracter;
String comando;

void setup()
{
  pinMode(Led, OUTPUT);  
  pinMode(Led2, OUTPUT);  // Inicializa el pin del LED como salida:
  pinMode(Led3, OUTPUT);  
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);  
  pinMode(Led6, OUTPUT);
  pinMode(Led7, OUTPUT);  
  pinMode(Led8, OUTPUT);  
  pinMode(Led9, OUTPUT);  
  pinMode(Led10, OUTPUT);
  pinMode(Led11, OUTPUT);  
  pinMode(Led12, OUTPUT);
  pinMode(Led13, OUTPUT);
  pinMode(Led14, OUTPUT);  
  pinMode(Led15, OUTPUT);
  pinMode(Led16, OUTPUT);
  pinMode(Led17, OUTPUT);  
  pinMode(Led18, OUTPUT);
  Serial.begin(115200);     // Puerto serie 115200 baudios.
  
}

void loop()
{
  /*
    Voy leyendo carácter a carácter lo que se recibe por el canal serie
    (mientras llegue algún dato allí), y los voy concatenando uno tras otro
    en una cadena. En la práctica, si usamos el "Serial monitor" el bucle while
    acabará cuando pulsamos Enter. El delay es conveniente para no saturar el
    canal serie y que la concatenación se haga de forma ordenada.
  */
  while (Serial.available() > 0)
  {
    caracter = Serial.read();
    comando.concat(caracter);
    delay(10);
  }

  /*
    Una vez ya tengo la cadena "acabada", compruebo su valor y hago que
    la placa Arduino reacciones según sea este. Aquí podríamos hacer lo
    que quisiéramos: si el comando es "tal", enciende un Led, si es cual,
    mueve un motor... y así.
  */

  // Si le llega el mensaje Luz_ON.
  if (comando.equals("AGUA1") == true)
  {
    digitalWrite(Led, HIGH); // Enciende el Led 13.
    Serial.write("ON - Led encendido.");    // Envía este mensaje a C++.
  }
    if (comando.equals("AGUA2") == true)
  {
    digitalWrite(Led3, HIGH); // Enciende el Led 13.
    Serial.write("ON - Led encendido.");    // Envía este mensaje a C++.
  }
  if (comando.equals("AGUA3") == true)
  {
    digitalWrite(Led5, HIGH); // Enciende el Led 13.
    Serial.write("ON - Led encendido.");    // Envía este mensaje a C++.
  }
  if (comando.equals("AGUA4") == true)
  {
    digitalWrite(Led7, HIGH); // Enciende el Led 13.
    Serial.write("ON - Led encendido.");    // Envía este mensaje a C++.
  }
  if (comando.equals("AGUA5") == true)
  {
    digitalWrite(Led9, HIGH); // Enciende el Led 13.
    Serial.write("ON - Led encendido.");    // Envía este mensaje a C++.
  }
  if (comando.equals("AGUA6") == true)
  {
    digitalWrite(Led11, HIGH); // Enciende el Led 13.
    Serial.write("ON - Led encendido.");    // Envía este mensaje a C++.
  }
  if (comando.equals("AGUA7") == true)
  {
    digitalWrite(Led13, HIGH); // Enciende el Led 13.
    Serial.write("ON - Led encendido.");    // Envía este mensaje a C++.
  }
  if (comando.equals("AGUA8") == true)
  {
    digitalWrite(Led15, HIGH); // Enciende el Led 13.
    Serial.write("ON - Led encendido.");    // Envía este mensaje a C++.
  }
  if (comando.equals("AGUA9") == true)
  {
    digitalWrite(Led17, HIGH); // Enciende el Led 13.
    Serial.write("ON - Led encendido.");    // Envía este mensaje a C++.
  }


  // Si le llega el mensaje Luz_ON.
  if (comando.equals("TOCADO1") == true)
  {
    digitalWrite(Led2, HIGH); // Apaga el Led 13.
    Serial.write("OFF - Led apagado. ");  // Envía este mensaje a C++.
  }
    if (comando.equals("TOCADO2") == true)
  {
    digitalWrite(Led4, HIGH); // Apaga el Led 13.
    Serial.write("OFF - Led apagado. ");  // Envía este mensaje a C++.
  }  if (comando.equals("TOCADO3") == true)
  {
    digitalWrite(Led6, HIGH); // Apaga el Led 13.
    Serial.write("OFF - Led apagado. ");  // Envía este mensaje a C++.
  }  if (comando.equals("TOCADO4") == true)
  {
    digitalWrite(Led8, HIGH); // Apaga el Led 13.
    Serial.write("OFF - Led apagado. ");  // Envía este mensaje a C++.
  }  if (comando.equals("TOCADO5") == true)
  {
    digitalWrite(Led10, HIGH); // Apaga el Led 13.
    Serial.write("OFF - Led apagado. ");  // Envía este mensaje a C++.
  }  if (comando.equals("TOCADO6") == true)
  {
    digitalWrite(Led12, HIGH); // Apaga el Led 13.
    Serial.write("OFF - Led apagado. ");  // Envía este mensaje a C++.
  }  if (comando.equals("TOCADO7") == true)
  {
    digitalWrite(Led14, HIGH); // Apaga el Led 13.
    Serial.write("OFF - Led apagado. ");  // Envía este mensaje a C++.
  }  if (comando.equals("TOCADO8") == true)
  {
    digitalWrite(Led16, HIGH); // Apaga el Led 13.
    Serial.write("OFF - Led apagado. ");  // Envía este mensaje a C++.
  }  if (comando.equals("TOCADO9") == true)
  {
    digitalWrite(Led18, HIGH); // Apaga el Led 13.
    Serial.write("OFF - Led apagado. ");  // Envía este mensaje a C++.
  }
  if (comando.equals("FIN") == true)
  {
    delay(6000);
    digitalWrite(Led, LOW); // Apaga el Led 13.
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
    digitalWrite(Led4, LOW);
    digitalWrite(Led5, LOW);
    digitalWrite(Led6, LOW);
    digitalWrite(Led7, LOW);
    digitalWrite(Led8, LOW);
    digitalWrite(Led9, LOW);
    digitalWrite(Led10, LOW);
    digitalWrite(Led11, LOW);
    digitalWrite(Led12, LOW);
    digitalWrite(Led13, LOW);
    digitalWrite(Led14, LOW);
    digitalWrite(Led15, LOW);
    digitalWrite(Led16, LOW);
    digitalWrite(Led17, LOW);
    digitalWrite(Led18, LOW);
  }
  
  
  
  
  

  // Limpiamos la cadena para volver a recibir el siguiente comando.
  comando = "";
}
