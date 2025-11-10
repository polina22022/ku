#include <stdio.h>
#include <locale.h>
#include <math.h>
double fa(double x);
void print_table(double (*func)(double), double a, double b, int step) {
	double step_size = (b - a) / step;
	printf("Таблица значений:\n");
	for (int i = 0; i <= step; i++) {
		double x = a + i * step_size;
		printf("x = %.4f, y = %.6f\n", x, func(x));
	}
}
double fa(double x) {
	double y;
	double sum = 0;
	if (x < -1) {
		y = 1 / sqrt(1 - x);
	}
	else if (x >= -1 && x < 0) {
		y = tanh(pow(x, 2));
	}
	else if (x > 0 && x < 2) {
		y = log(1 + 2 * x) / x;
	}
	else {
		for (int n = 0; n <= 6; ++n)
		{
			double k = pow(x, 2 * n);
			long long factorial = 1;
			for (int i = 1; i <= 2 * n; i++) {
				factorial *= i;
			}
			double denominator = factorial * (n + 1);
			sum += k / denominator;
		}
		y = sum;
	}
	return y;
}
int main() {
	int choice;
	setlocale(LC_ALL, "RUS");
	double x;
	double a, b;
	int step;
	printf("\nВыберите операцию:\n");
	printf("1. Значение в точке\n");
	printf("2. Таблица значений\n");
	printf("3. Вычисление интеграла\n");
	printf("4. Поиск x при заданном Y\n");
	printf("5. Вторая производная в точке\n");
	printf("0. Выход\n");
	printf("Ваш выбор: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		printf("Введите x: ");
		scanf("%lf", &x);
		printf("f(%.4f) = %.6f\n", x, fa(x));
		break;
	case 2:
		printf("Введите интервал [a, b]:\n");
		printf("a = ");
		scanf("%lf", &a);
		printf("b = ");
		scanf("%lf", &b);
		printf("Введите шаг для таблицы (например, 1): ");
		scanf("%d", &step);
		print_table(fa, a, b, step);
		break;


	}

}
