/*  Teclado rápido BÁSICO para edición (macros)
    por: Mario de Making Robotics Colombia
    se usa: arduino LEONARDO + Shield Joystick keyes (trae una sección para prototipado)
    https://www.youtube.com/MakingRoboticsColombia
*/

#include "Keyboard.h" // incluye libreria Keyboard

void setup() {
  pinMode(2, INPUT_PULLUP);  //tecla seleccion palabra
  pinMode(3, INPUT_PULLUP);  //tecla pegar
  pinMode(4, INPUT_PULLUP);  //tecla deshacer
  pinMode(5, INPUT_PULLUP);  //tecla copiar
  pinMode(6, INPUT_PULLUP);  //tecla rehacer

  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Keyboard.begin();          //
}

void loop() {

  if (digitalRead(6) == LOW) {
    presionaComando('y');
  }

  if (digitalRead(5) == LOW) {
    presionaComando('c');
  }

  if (digitalRead(4) == LOW) {
   presionaComando('z');
  }

  if (digitalRead(3) == LOW) {
    presionaComando('v');
  }

   if (digitalRead(2) == LOW) {// 
   Keyboard.press(KEY_LEFT_CTRL);
   Keyboard.press(KEY_LEFT_SHIFT);
   Keyboard.press(KEY_LEFT_ARROW);
   digitalWrite(13,HIGH);
   delay(300);
   Keyboard.releaseAll();//libero todas las teclas usadas
   digitalWrite(13,LOW);
  }
}
//comandos para edición
//CTRL + c   copiar
//CTRL + x   cortar
//CTRL + v   pegar
//CTRL + y   rehacer
//CTRL + z   deshacer
//CTRL + /   comentar/descomentar
//CTRL + +   aumentar tamaño de fuente
//CTRL + -   dsiminuir tamaño de fuente
//CTRL + TAB navegar entre programas    (KEY_TAB)

int presionaComando(int tecla)
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(tecla);
  digitalWrite(13,HIGH);//enciendo el led 13
  delay(200);
  Keyboard.releaseAll();//libero todas las teclas usadas
  digitalWrite(13,LOW); //apago el led 13
}
/*
KEY_LEFT_CTRL
KEY_LEFT_SHIFT
KEY_LEFT_ALT
KEY_LEFT_GUI
KEY_RIGHT_CTRL
KEY_RIGHT_SHIFT
KEY_RIGHT_ALT
KEY_RIGHT_GUI
KEY_UP_ARROW
KEY_DOWN_ARROW
KEY_LEFT_ARROW
KEY_RIGHT_ARROW
KEY_BACKSPACE
KEY_TAB
KEY_RETURN
KEY_ESC
KEY_INSERT
KEY_DELETE
KEY_PAGE_UP
KEY_PAGE_DOWN
KEY_HOME
KEY_END
KEY_CAPS_LOCK
KEY_F1
KEY_F2
KEY_F3
KEY_F4
KEY_F5
KEY_F6
KEY_F7
KEY_F8
KEY_F9
KEY_F10
KEY_F11
KEY_F12
KEY_F13
KEY_F14
KEY_F15
KEY_F16
KEY_F17
KEY_F18
KEY_F19
KEY_F20
KEY_F21
KEY_F22
KEY_F23
KEY_F24
*/
