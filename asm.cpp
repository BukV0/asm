#include <iostream>
#include <stdio.h>
#include <locale.h>
int lab2(char xf, char zf, short yf) {
	// Выводим полученные параметры
	printf("x=%x, z=%x, y=%x\n", xf, zf, yf);
	// Блок описания переменных
	char x, z;
	short int y, vC, vA;
	// Блок определения переменных
	x = xf; y = yf; z = zf;
	// Блок вычисления функции на Си
	vC = -3 + ((7 * (x - 2) + y) / (z + 4));
	printf("Result in C: v=%x\n", vC);
	// Блок вчисления функции на ассемблере
	__asm
	{
		mov al, x; //x v al
		cbw; //расширяем[byte]AL до[word]AX
		sub ax, 2; // (x-2)
		mov bx, ax; // ax v bx
		mov ax, 7; // 7 v ax
		imul bx; // (7*(x-2)) v DX:AX
		mov bx, ax; //(7*(x-2)) v DX:BX
		mov cx, dx; // (7*(x-2))CX:BX
		mov ax, y; // y v ax
		cwd; // y v DX:AX
		add bx, ax;
		adc cx, dx; //(y+7*(x-2)) v CX:BX
			mov al, z;// z v al 
			cbw;//расширяем[byte]AL до[word]AX
			add ax, 4; // z+4 v ax
			xchg ax, bx;
		mov dx, cx;// (y + 7 * (x - 2)) v DX : AX
			idiv bx; // drob v ax
			sub ax, 3; // Вычитаем 3
			mov vA, ax //помещаем результат в vA
	}
	printf("Result in ASM: v=%x\n", vA);
}
int main()
{
	
	printf("Laba 2\nMigalin Sergey\nSKB151\nVar12\n\n");
	lab2(-0x1, -0x2, 0x13);
	printf("Expected result: v=%x\n", -0x4);
	printf("\n");
	lab2(-0x7E, 0x7F, 0x4FBA);
	printf("Expected result: v=%x\n", 0x91);
	getchar();

	return 0;
}
