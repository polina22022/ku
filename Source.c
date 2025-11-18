#include <stdio.h>
#include <locale.h>
#include <math.h>
double fa(double x);

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
дома добавила
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>


double fa(double x);
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
			double d = factorial * (n + 1);
			sum += k / d;
		}
		y = sum;
	}
	return y;
}
double dx(double a, double b, int n) {
	double step = (b - a) / n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		double x = a + i * step;
		sum = sum + fa(x);
	}
	return sum * step;

}

int main() {
	int choice, n;
	setlocale(LC_ALL, "RUS");
	double x, step, a, b, Y;
	do {
		printf("                                                    Анализ функции\n            ");
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
			printf("Введите количество точек: ");
			scanf("%lf", &step);
			printf("|  x     |  f(x)    |\n");
			for (x = a; x <= b; x += step) {
				printf("| %.4f | %.6f |\n", x, fa(x));
			}
			break;
		case 3:
			printf("Введите интервал [a, b]:\n");
			printf("Левая граница интервала a: ");
			scanf("%lf", &a);
			printf("Правая граница интервала b: ");
			scanf("%lf", &b);
			printf("Количество отрезков n: ");
			scanf("%d", &n);
			printf("Значение интеграла = %.6f\n", dx(a, b, n));
			break;
		case 4:
			printf("Введите значение Y:");
			scanf("lf", Y);
			printf("Введите интервал [a, b]:\n ");
			printf("a = ");
			scanf("lf", &a);
			printf("b = ");
			scanf("lf", &b);


		}
	} while (choice != 0);
}



