#include <stdio.h>

void swap(double* x, double* y);
void sort_desc(double* ary, int size);
void print_num(double* ary, int size);
double get_avg(double* ary, int size);


int main() {

	double num[3];
	double avg = 0;
	const int size = sizeof(num) / sizeof(num[0]);


	for (int i = 0; i < size; i++)
	{
		scanf_s("%lf", &num[i]);
	}
	
	sort_desc(num, size);
	printf("정렬 결과: ");
	print_num(num, size);

	swap(&num[0], &num[size - 1]);
	printf("최댓값과 최솟값 교환: ");
	print_num(num, size);
	
	avg = get_avg(num, size);
	printf("평균 값: %.1lf",avg);

	return 0;
}


void swap(double* x, double* y)
{
	double temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

void sort_desc(double* ary, int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		int max_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (ary[j] > ary[max_index])
			{
				max_index = j;
			}
		}
		if(i != max_index)
		{
			swap(&ary[i], &ary[max_index]);
		}
	}
}


double get_avg(double* ary, int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += ary[i];
	}

	return sum / size;
}

void print_num(double* ary, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%.1lf ", ary[i]);
		
	}
	printf("\n");
}
