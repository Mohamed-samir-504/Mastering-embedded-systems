

#include "keypad.h"

int Keypad_r[] = {R0, R1, R2, R3}; //rows of the keypad
int Keypad_c[] = {C0, C1, C2, C3};//columns

GPIO_PinConfig_t Pinconfig;

void Keypad_init(){
	//DataDir_KEYPAD_PORT &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	Pinconfig.GPIO_MODE = GPIO_MODE_INPUT_PD;
	for(int i = 0; i<4; i++){
		Pinconfig.GPIO_PinNumber = Keypad_r[i];
		MCAL_GPIO_Init(KEYPAD_PORT, &Pinconfig);
	}

	//DataDir_KEYPAD_PORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	Pinconfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	Pinconfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	for(int i = 0; i<4; i++){
		Pinconfig.GPIO_PinNumber = Keypad_c[i];
		MCAL_GPIO_Init(KEYPAD_PORT, &Pinconfig);
	}

	//KEYPAD_PORT = 0xFF;
	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);
}

unsigned char Keypad_getkey(){
	int i,j,k;
	for (i = 0; i < 4; i++){
		//set all columns as 1 at start

		//KEYPAD_PORT |= ((1<<Keypad_c[0]) | (1<<Keypad_c[1]) | (1<<Keypad_c[2]) | (1<<Keypad_c[3]));
		for(k = 0; k<4; k++){

			MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_c[k], GPIO_PIN_RESET);
		}
		//set column i as 0
		//if row j is detected as 0 then button[j][i] is clicked
		//because the rows are initialized as PU(default value is 1)

		//KEYPAD_PORT &= ~(1<<Keypad_c[i]);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Keypad_c[i], GPIO_PIN_SET);

		for(j = 0; j < 4; j++){
			//if a row is detected as 0 (button pressed)
			if (MCAL_GPIO_ReadPin(KEYPAD_PORT, Keypad_r[j]))
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, Keypad_r[j]));
				switch(i){
					case 0:
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
						break;
					case 1:
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					case 2:
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					case 3:
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
				}
			}
		}
	}
	return 'A';
}
