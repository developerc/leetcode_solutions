//29. Divide Two Integers
#include <stdio.h>
#include <math.h>

int divide(int dividend, int divisor);
void decToBin(signed long long number, int * binNum, char * lengthNum, char * cntOnes, char * lastOne);

void main(){
	int dividend = -2147483648;
	int divisor = 2;
	
	int quotient = divide(dividend, divisor);
	printf("quotient = %d\n", quotient);
}

int divide(int dividend, int divisor){
	signed long long dividendB = (signed long long) dividend;
	signed long long divisorB = (signed long long) divisor;
	int quotient = 0;
	int binDividend[64] = {0};
	int binDivisor[64] = {0};
	int binQuotient[64] = {0};
	int binDifference[64] = {0};
	int plusB[64] = {0};
	int minusB[64] = {0};
	char lengthQuotient = 0;	//длина частного
	char lengthDividend = 0;	//длина делимого
	char lengthDivisor = 0;		//длина делителя
	char signDividend = 1;		//знак делимого равен 1 если оно положительно
	char signDivisor = 1;		//знак делителя равен 1 если он положительный
	char signQuotient = 1;		//знак результата деления равен 1 если он положительный
	char overload = 0;			//переполнение при сложении
	char k = 0;					//сдвиг делителя (числа В)
	char cntOnes = 0;			//количество единиц в двоичном коде числа
	char lastOne = 0;			//индекс последней единицы
	
	if(dividendB == 0){
		printf("string 35\n");
		return 0;
	}
	
	if((dividend == -2147483648) && (divisor == -1)) {return 2147483647;}
	
	if(divisor == 1) {return dividend;}
	if(divisor == -1) {
		dividendB = 0 - dividendB;
		dividend = (int) dividendB;
		return dividend;
	}
	
	if(dividendB < 0){	
		dividendB = 0 - dividendB;
		signDividend = -1;
	} else {
		signDividend = 1;
	}
	if(divisorB < 0){
		divisorB = 0 - divisorB;
		signDivisor = -1;
	} else {
		signDivisor = 1;
	}
	
	if(signDividend == 1){					// находим знак результата деления
		if(signDivisor == 1) {
			signQuotient = 1;
		} else {
			signQuotient = -1;
		}
	} else {
		if(signDivisor == 1) {
			signQuotient = -1;
		} else {
			signQuotient = 1;
		}
	}
	
	//printf("signQuotient = %d\n", signQuotient);
	//printf("dividendB = %d, divisorB = %d\n", dividendB, divisorB);
	
	if((dividendB == divisorB) && (signQuotient > 0)){
		//quotient == 1;
		//printf("string 70\n");
		return 1;
	}
	if((dividendB == divisorB) && (signQuotient < 0)){
		//quotient == -1;
		//printf("string 75\n");
		return -1;
	}
	
	if(dividendB < divisorB){
		//printf("string 81\n");
		return 0;
	}
	
	decToBin(dividendB, binDividend, &lengthDividend, &cntOnes, &lastOne);	//переводим в двоичную форму делимое
	decToBin(divisorB,  binDivisor,  &lengthDivisor,  &cntOnes, &lastOne);		//переводим в двоичную форму делитель
	k = lengthDividend - lengthDivisor;					//количество сдвигов
	
	//printf("cntOnes = %d, lastOne = %d\n", cntOnes, lastOne);
	
	if(cntOnes == 1){
		dividendB = dividendB >> lastOne;
		dividend = (int) dividendB;
		if(signDividend < 0){
			dividend = 0 - dividend;
		}
		return dividend;
	}
	
	//printf("k = %d\n", k);
	//printf("lengthDividend = %d\n", lengthDividend);
	//printf("lengthDivisor = %d\n", lengthDivisor);
	//распечатаем числа в двоичной форме
	//printf("binDividend = ");
	/*for(int i=0; i<64; i++){
		printf("%d", binDividend[63-i]);
	}
	printf("\n binDivisor = ");
	for(int i=0; i<64; i++){
		printf("%d", binDivisor[63-i]);
	}
	printf("\n");	*/
	//конец распечатки
	
	for(int i=31; i>=0+k; i--){
		plusB[i] = binDivisor[i-k];
	}
	for(int i=k-1; i>=0; i--){		//1. получили сдвинутое число В
		plusB[i] = 0;
	}
	/*printf("      plusB = ");
	for(int i=0; i<64; i++){
		printf("%d", plusB[63-i]);
	}
	printf("\n");*/
	
	for(int i=0; i<64; i++){		//2. получили число В в обратном коде
		if(plusB[i] == 0){
			minusB[i] = 1;
		} else {
			minusB[i] = 0;
		}
	}
	/*printf("     minusB = ");
	for(int i=0; i<64; i++){
		printf("%d", minusB[63-i]);
	}
	printf("\n");*/
	
	for(int i=0; i<64; i++){		//3. прибавляем 1 для получения дополнительного кода
		if(i == 0){
			minusB[i] = minusB[i] + 1;
			if(minusB[i] == 2){
				minusB[i] = 0;
				overload = 1;
			}
		} else {
			if(overload ==1){
				minusB[i] = minusB[i] + overload;
				overload = 0;
				if(minusB[i] == 2){
					minusB[i] = 0;
					overload = 1;
				}
			}
		}		
	}
	/*printf(" minusB + 1 = ");
	for(int i=0; i<64; i++){
		printf("%d", minusB[63-i]);
	}
	printf("\n");*/
	
	for(int i=0; i<64; i++){		//4. Вычитаем из делимого А делитель В (т.е. прибавляем -В)
		binDifference[i] = binDividend[i] + minusB[i] + overload;
		if( binDifference[i] == 2){
			binDifference[i] = 0;
			overload = 1;
		} else if(binDifference[i] == 3){
			binDifference[i] = 1;
			overload = 1;
		} else {
			overload = 0;
		}
	}
	overload = 0;
	/*printf("  A = ");
	for(int i=0; i<64; i++){
		printf("%d", binDividend[63-i]);
	}
	printf("\n");
	printf(" -B = ");
	for(int i=0; i<64; i++){
		printf("%d", minusB[63-i]);
	}
	printf("\n");
	printf("dif = ");
	for(int i=0; i<64; i++){
		printf("%d", binDifference[63-i]);
	}
	printf("\n");*/
	
	if(binDifference[63] == 1){				//5. Анализируем знак полученного частичного остатка (63-й разряд)
		binQuotient[lengthQuotient] = 0;	//В регистр результата записываем "0" если остаток отрицательный и единицу в противном случае
		//printf("binQuotient[i] = %d\n", binQuotient[lengthQuotient]);
		lengthQuotient++;					//Помним, что отрицательному числу соответствует наличие единицы в 63-м разряде и наоборот
	} else {
		binQuotient[lengthQuotient] = 1;
		///printf("binQuotient[i] = %d\n", binQuotient[lengthQuotient]);
		lengthQuotient++;
	}
	
	for(int j=0; j<k; j++){					// Пункты 6 - 8 повторяем k раз
	binDividend[0] = 0;						//6. Сдвигаем частичный остаток на один разряд влево
	for(int i=0; i<62; i++){						//При этом крайний правый (младший) разряд заполняется нулем,
		binDividend[i+1] = binDifference[i];
		binDividend[63] = binDifference[63];//а знаковый разряд (63-й) в процессе сдвига не участвует
	}
	/*printf("  A = ");
	for(int i=0; i<64; i++){
		printf("%d", binDividend[63-i]);
	}
	printf("\n");*/
	
	if(binDividend[63] == 1){				//7. Прибавляем к частичному остатку делитель В если остаток отрицательный
		for(int i=0; i<64; i++){		
		binDifference[i] = binDividend[i] + plusB[i] + overload;
		if( binDifference[i] == 2){
			binDifference[i] = 0;
			overload = 1;
		} else if(binDifference[i] == 3){
			binDifference[i] = 1;
			overload = 1;
		} else {
			overload = 0;
		}
	}
	overload = 0;
	/*printf(" +B = ");
	for(int i=0; i<64; i++){
		printf("%d", plusB[63-i]);
	}
	printf("\n");*/
	} else {								//либо вычитаем делитель в противном случае.
		for(int i=0; i<64; i++){		
		binDifference[i] = binDividend[i] + minusB[i] + overload;
		if( binDifference[i] == 2){
			binDifference[i] = 0;
			overload = 1;
		} else if(binDifference[i] == 3){
			binDifference[i] = 1;
			overload = 1;
		} else {
			overload = 0;
		}
	}
	overload = 0;
	/*printf(" -B = ");
	for(int i=0; i<64; i++){
		printf("%d", minusB[63-i]);
	}
	printf("\n");*/
	}	
	/*printf("dif = ");
	for(int i=0; i<64; i++){
		printf("%d", binDifference[63-i]);
	}
	printf("\n");*/
	
	if(binDifference[63] == 1){				//8. Анализируем знак полученного частичного остатка (31-й разряд)
		binQuotient[lengthQuotient] = 0;	//В регистр результата записываем "0" если остаток отрицательный и единицу в противном случае
		//printf("binQuotient[i] = %d\n", binQuotient[lengthQuotient]);
		lengthQuotient++;					//Помним, что отрицательному числу соответствует наличие единицы в 31-м разряде и наоборот
	} else {
		binQuotient[lengthQuotient] = 1;
		//printf("binQuotient[i] = %d\n", binQuotient[lengthQuotient]);
		lengthQuotient++;
	}
	}
	//printf("lengthQuotient = %d\n", lengthQuotient);
	
	//printf("binary quotient = ");
	for(int i=0; i<64; i++){				//преобразуем результат деления из двоичной формы в десятичную
		//printf("%d", binQuotient[i] );
		if(binQuotient[i] == 1){
			quotient = quotient + pow(2, lengthQuotient - i - 1);//операцией возведения в степень не запрещалось пользоваться
		}
	}
	//printf("\n");
	
	if(signQuotient < 0){
		quotient = 0 - quotient;
	}
	
	return quotient;
}

void decToBin(signed long long number, int * binNum, char * lengthNum, char * cntOnes, char * lastOne){ //преобразуем число из десятичного вида в двоичный
	//printf("from decToBin: number = %d\n", number);
	char cntO = 0;			//количество единиц в двоичном коде числа
	char lastO = 0;			//индекс последней единицы
	char i = 0;
	while(number){				//повторяем цикл пока исходное число больше ноля
		binNum[i] = number & 1;	//находим значение младшего бита, выполняя операцию побитового умножения (простейшая маска)
		number = number >> 1;	//сдвигаем вправо битовое представление числа, младший бит обрезается
		if(binNum[i] == 1){		//проверим является ли число степенью двойки, если после деления cntOnes = 1, lastOne - степень двойки
			cntO++;
			lastO =  i;
		}
		i++;
	}
	*lengthNum = i;
	* cntOnes = cntO;
	* lastOne = lastO;
	//printf("cntO = %d, lastO = %d\n", cntO, lastO);
}