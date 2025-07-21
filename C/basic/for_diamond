#include <stdio.h>

int main() {

	int num = 0;
	int half_num = 0;
	if (scanf_s("%d", &num) != 1)
	{
		printf("잘못입력");
		return 1;
	}
	else
	{
		half_num = num / 2;

		for (int i = 0; i < half_num + 1; i++)
		{
			for (int j = 0; j < half_num - i; j++)
			{
				printf(" ");
			}

			for (int k = 0; k < 2 * i + 1; k++)
			{
				printf("*");
			}
			printf("\n");
		}

		for (int i = half_num - 1; i >= 0; i--)
		{
			for (int j = 0; j < half_num - i; j++)
			{
				printf(" ");
			}

			for (int k = 0; k < 2 * i + 1; k++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	

	return 0;
}
