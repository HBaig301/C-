#include <iostream>
#include <math.h>

using namespace std;

int main() {
    char resistorvalue;
    char colorCode[4];
    int colorValue[4];
	double tolerance; 
	double resistance;


    cout << "Enter the four resistor color codes: ";
    cin >> colorCode;
	
	for (int i =0; i < 4; i++) {

    switch (colorCode[i]) {
  
	case('k'):
		if (i!=3) {
			colorValue [i] = 0;
		}
		else {
			cerr <<"Error: Invalid color code entered!";
		
			return -1; 
	}


    case('n'):
    colorValue [i] = 1;
    break;
	
    case('R'):
    colorValue [i] = 2;
    break;

    case('O'):
		if (i!=3) {
    colorValue [i] = 3;
		}
		else {
			cerr <<"Error: Invalid color code entered!";
			
			return -1;
		}
	
    break;
	
    case('Y'):
		if (i!=3) {
    colorValue [i] = 4;
		}
		else {
			cerr <<"Error: Invalid color code entered!";
			
			return -1;
		}
    break;

    case('G'):
    colorValue [i] = 5;
    break;
	
    case('B'):
    colorValue [i] = 6;
    break;
	
	case('v'):
    case('V'):
    colorValue [i] = 7;
    break;
	
	case('y'):
    colorValue [i] = 8;
    break;
	
	case('W'):
		if (i!=3) {
    colorValue [i] = 9;
		}
		else {
			cerr <<"Error: Invalid color code entered!";
			
			return -1;
		}
    break;
	
	case('d'):
		if (i == 2) {
			colorValue [i] = -1;
			break;
		}
		else if (i == 3) {
			colorValue [i] = 5;
		}
		else {
			cerr <<"Error: Invalid color code entered!";
			
			return -1;
		}
	break;
	case ('S'):
		if (i == 2) {
			colorValue [i] = -2;		
		}
		else if (i == 3){
			colorValue [i] = 10;
		}
		else {
			cerr <<"Error: Invalid color code entered!";
			
			return -1;
		}
    break;
	case ('N'):
		if (i == 3) {
			colorValue [i] = 20;
			;
		}
		else {
			cerr <<"Error: Invalid color code entered!";
			
			return -1;
		}
	break;
	

    default:
	cerr << "Error: Invalid color code entered!" << endl;
	
		return -1;
	break;
		}
	}
    

	if (colorCode[3] == 'G' or colorCode[3] == 'B' or colorCode[3] == 'V' or colorCode[3] == 'y' ) {
	tolerance = (colorValue[3]) * 0.00001;
	}
	else {
		tolerance = colorValue[3]*0.01;
	}
	
	resistance = (colorValue[0]*10+colorValue[1])*pow(10,colorValue[2]);
	cout <<"Resistance is " <<resistance <<" ohms (+/-"<<resistance*tolerance<< " ohms tolerance)";

	return 0;

}

	