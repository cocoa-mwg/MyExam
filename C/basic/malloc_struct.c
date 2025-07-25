#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double* arr;
	int size;
}double_arr;

void print_arr(double* arr, int size);
double_arr creat_arr(void);
void input_arr(double* arr, int size);
double avg_arr(double* arr, int size);

int main() {
	double_arr arr;
	double avg_result = 0;
	arr = creat_arr();
	input_arr(arr.arr, arr.size);
	print_arr(arr.arr, arr.size);
	avg_result = avg_arr(arr.arr, arr.size);
	printf("평균값 : %.2lf\n", avg_result);
	
	free(arr.arr);
	return 0;
}

double_arr creat_arr(void)
{
	double_arr arr;
	int num = 0;
	printf("입력할 데이터 개수를 입력하세요:");
	scanf("%d", &num);
	arr.size = num;
	arr.arr = calloc(arr.size, sizeof(double));
	return arr;
}

void input_arr(double* arr, int size)
{
	int count = 1;

	for (int i = 0; i < size; i++)
	{
		while (scanf("%lf", &arr[i]) != 1)
		{
			while (getchar() != '\n');
			printf("다시 입력해주세요. :");

		}
		if (arr[i] >= 5000)
		{
			printf("이상값 감지 -> 저장 안함\n");
			arr[i] = 0;
			i--;
			continue;
		}
		if (i > 0)
		{
			if (arr[i] == arr[i - 1])
			{
				count++;
				if (count == 3)
				{
					printf("통신 정지 위험\n");
					count = 1;
				}
			}
			else
				count = 1;
		
				
		}
		
		
	}
}



void print_arr(double* arr, int size)
{
	printf("저장 데이터 출력 :\n");
	for (int i = 0; i < size; i++)
	{
		
		printf("%.1lf\t", arr[i]);
	}
	printf("\n");
}

double avg_arr(double* arr, int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum / size;
}
