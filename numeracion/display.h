
const int codigo[] = {A, B, C, D, E, F1, G};

const int digitos[10][8] = {
  {0, 0, 0, 0, 0, 0, 1},  //cero
  {1, 0, 0, 1, 1, 1, 1},  //uno
  {0, 0, 1, 0, 0, 1, 0},  //dos
  {0, 0, 0, 0, 1, 1, 0},  //tres
  {1, 0, 0, 1, 1, 0, 0},  //cuatro
  {0, 1, 0, 0, 1, 0, 0},  //cinco
  {0, 1, 0, 0, 0, 0, 0},  //seis
  {0, 0, 0, 1, 1, 1, 1},  //siete
  {0, 0, 0, 0, 0, 0, 0},  //ocho
  {0, 0, 0, 1, 1, 0, 0}   //nueve
};

const int guion_cod[] = {1, 1, 1, 1, 1, 1, 0};

void guion() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(codigo[i], guion_cod[i]);
  }
}


void numero(int num) {

  for (int i = 0; i < 7; i++) {
    digitalWrite(codigo[i], digitos[num][i]);
  }
}

const int displays[] = {DIG1, DIG2, DIG3, DIG4};

const int act_disp[4][4] = {
  {1, 0, 0, 0}, //DISP1
  {0, 1, 0, 0}, //DISP2
  {0, 0, 1, 0}, //DISP3
  {0, 0, 0, 1}  //DISP4
};

void en_display(int disp) {
  for (int k = 0; k < 4; k++) {
    digitalWrite(displays[k], act_disp[disp][k]);
  }
}

const int codigoError[] = { 0, 1, 1, 0, 0, 0, 0};

void Error() {
  for (int k = 0; k < 4; k++) {
    en_display(k);
    for (int i = 0; i < 7; i++) {
      digitalWrite(codigo[i], codigoError[i]);
    }
  }
}

/// Representacion por el display

void display(int nume) {
  int g[] = {0, 0, 0, 0};
  int np = 0;
  if ((nume < 0) and (-nume < 1000)){           ///numero negativo
    en_display(0);
    guion();
    delay(2);
    nume *= -1;

    for (int i = 0; i < 3; i++) {
      np = 0;
      np = nume / pow(10, (2 - i));
      g[i] = np;
      for (int y = 0; y < i; y++) {
        g[i] = g[i] - (g[y] * pow(10, i - y));
      }
      en_display(i + 1);
      numero(g[i]);
      delay(2);
    }
  } else if ((nume < 10000)and (nume>=0)) {          ///numero positivo <10.000
    for (int i = 0; i < 4; i++) {

      np = 0;
      np = nume / pow(10, (3 - i));
      g[i] = np;
      for (int y = 0; y < i; y++) {
        g[i] = g[i] - (g[y] * pow(10, i - y));
      }
      en_display(i);
      numero(g[i]);
      delay(2);
    }
  } else  {           /// Error
    Error();
  }
}
