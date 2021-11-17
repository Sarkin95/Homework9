/*
The point of this program is to read a resistance in paralel with another 10k ohm resister
This was constructed for CPE 422 homework 9
*/

#include <iostream>
#include "analogIn.h"
#include <iomanip>
using namespace std;

int main()
{
  AnalogIn AIN(0);
  cout << "Using AIN" << AIN.getNumber() << " to read analog value." << std::endl;

  int rawADC;
  rawADC = AIN.readADCsample();

  cout << "ADC value is: " << rawADC << endl;
  float convADC, voltage, resistor, calcResistor;
  voltage = 1.8;
  resistor = 10000.0;
  cout << "Converting to voltage" << endl;
  convADC = (float)rawADC * voltage/4096;
  calcResistor = resistor / ((voltage/convADC) - 1);

  cout << "Calculated resistance = " << calcResistor << endl;
}
