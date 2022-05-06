/*Функция возведения числа в степень*/
double RaiseToPow(double x, int power)
{
	double res;
	int i;
	res = 1.0;
	if (power == 0) {
		return 1;
	}
	else if (power == 1) {
		return x;
	}

	else
		for (i = 1; i <= power; i++)
		{
			res = res * x;
		}
	return(res);
}
/* Функция нахождения факториала числа */
double fact(int k) {
	if (k < 2)
		return 1;
	return k * fact(k - 1);
}
/* Функция нахождения модуля числа */
double fabs(double x) {
	if (x > 0)
		return x;
	else return x * -1;
}
/* Функция нахождения синуса разложением в ряд Тейлора */
double sinus(double x) {
	int n;
	double sin;
	sin = 0.0;
	for (n = 1; n <= 18; n++)
	{
		sin = sin + (RaiseToPow(-1, n - 1) * RaiseToPow(x, (2 * n - 1)) / fact(2 * n - 1));
	}

	return(sin);
}
/*Функция для проверки точности вычисления синуса*/
int test_sin() {
	int r;
	r = 0;

	r = r || (fabs(sinus(0) - 0.0) >= 0.0001);
	r = r || (fabs(sinus(1) - 0.8415) >= 0.0001);
	r = r || (fabs(sinus(2) - 0.9093) >= 0.0001);
	r = r || (fabs(sinus(4) + 0.7568) >= 0.0001);
	r = r || (fabs(sinus(10) + 0.5440) >= 0.0001);
	return r;
}

int main(int argc, char** argv) {
	return test_sin();
}
