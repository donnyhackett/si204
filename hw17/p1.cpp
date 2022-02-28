#include <iostream>
using namespace std;

// lenUnitCF(fromUnit,toUnit) - this function returns
// conversion factors between different units of length
// for units it understands, and returns 0.0 for units
// it does not understand.
// It understands: feet, inches, yards, miles, millimeters,
// centimeters, meters, kilometers, nautical-miles and light-years.
double lenUnitCF(string fromUnit, string toUnit);

double tooFeet(string fromUnit); // This jsut helps with lenUnitCF

int main()
{
  string u1, u2, temp, to;
  double n1, n2;
  cin >> temp >> temp >> to >> n1 >> u1 >> temp>> n2 >> u2 >> temp;
  double in = tooFeet(u1)*n1 + tooFeet(u2)*n2;
  cout << lenUnitCF("feet", to)*in << " " << to << endl;
  return 0;
}

double lenUnitCF(string fromUnit, string toUnit)
{
  return tooFeet(fromUnit)/tooFeet(toUnit);
}

double tooFeet(string fromUnit)
{
  if (fromUnit == "feet") return 1.0;
  else if (fromUnit == "inches") return 1.0/12.0;
  else if (fromUnit == "yards") return 3.0;
  else if (fromUnit == "miles") return 5280;
  else if (fromUnit == "millimeters") return 0.00328084;
  else if (fromUnit == "centimeters") return 0.0328084;
  else if (fromUnit == "meters") return 3.28084;
  else if (fromUnit == "kilometers") return 3280.84;
  else if (fromUnit == "nautical-miles") return 6076.12;
  else if (fromUnit == "light-years") return 3.1038479e16;
  else return 0.0;
}

