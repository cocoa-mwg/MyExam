/*
PLC에서 값을 PC로 실시간 전송하여 저장 중이다.
하지만 통신 오류로 인해 다음과 같은 문제가 발생한다:

같은 값이 3번 이상 연속해서 들어오는 경우가 있음

5000 이상 값이 갑자기 튀는 경우도 있음

🎯  목표:
실수형 데이터 20개를 입력받는다.

5000 이상 값이 입력되면

"⚠️ 이상값 감지 (5000 이상) → 값 저장 안 함" 출력

배열에 저장하지 않음

같은 값이 3번 이상 연속되면

"🚨 통신 정지 가능성 감지" 경고 출력

유효한 값만 저장된 최종 배열을 출력한다.
*/


#include <stdio.h>
void input_data(double* arr, int size);
void print_data(double* arr, int size);
void print_detect();
int main() {

	double signal_data[20] = {0};
	int size = sizeof(signal_data) / sizeof(signal_data[0]);

	input_data(signal_data, size);
	print_data(signal_data, size);
	return 0;
}

void input_data(double* arr, int size)
{
	int count = 0;
	double index_value = 0;
	for (int i = 0; i < size; i++)
	{

		
		while (scanf("%lf", &arr[i]) != 1) // 입력값이 실수가 아닌 값이 들어오면 다시 입력
		{
			while(getchar() != '\n');
			printf("data input fail\n");
			printf("again input :");
			
		}
		
		if (arr[i] >= 5000) // 5000 이상의 이상 데이터 감지 시에 값 저장 하지 않고 다시 입력 받음
		{
			print_detect();
			arr[i] = 0;
			i--;
			continue;
		}
		if (index_value != arr[i]) // 데이터 입력값이 연속 3번 동일 값일 때 신호정지 위험 알람
		{
			index_value = arr[i];
			count = 1;
		}
		else
			count++;

		if (count == 3)
		{
			printf("Risk of communication disruption\n");
		}
		
	}
	printf("data input success\n");
}



void print_data(double* arr, int size)
{

	printf("최종 저장된 데이터:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%.2lf ", arr[i]);
	}
}

void print_detect()
{
	printf("Abnormal data detection\n");
	printf("Failed to save data\n");
}
