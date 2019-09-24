#include<cstdio>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int map[500001];
int queue[500000];
int num = 0;

int main(void)
{
	for (int i = 0; i < 500000; i++)
	{
		map[i] = -1;
		queue[i] = -1;
	}
	map[500000] = -1;
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < N + M; i++)
	{
		int flag;
		scanf("%d", &flag);
		if (flag == 1)
		{
			int student, target, hand;
			scanf("%d", &student);
			scanf("%d", &target);
			scanf("%d", &hand);
			if (target == -1)
			{
				queue[0] = student;
				map[student] = 0;
			}
			else
			{
				int position;
				if (hand == 0)
					position = map[target];
				if (hand == 1)
					position = map[target] + 1;
				for (int k = num - 1; k >= position; k--)
				{
					queue[k + 1] = queue[k];
					map[queue[k + 1]] = k + 1;
				}
				queue[position] = student;
				map[student] = position;
			}
			num++;
		}
		if (flag == 0)
		{
			int student;
			scanf("%d", &student);
			int position = map[student];
			for (int k = position; k < num - 1; k++)
			{
				queue[k] = queue[k + 1];
				map[queue[k]] = k;
			}
			queue[num - 1] = -1;
			map[student] = -1;
			num--;
		}
	}
	for (int i = 0; i < N - M + 1; i++)
		printf("%d ", queue[i]);
	return 0;
}
