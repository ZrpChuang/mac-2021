#include<iostream>
using namespace std;

int partition(int* list, int front, int end) {
	int buffer = list[front];
	while (front < end) {
		while (front<end && list[end]>=buffer) end--;
		list[front] = list[end];
		while (front < end && list[front] <= buffer) front++;
		list[end] = list[front];
	}
	list[front] = buffer;
	return front;
}
void sort(int* list, int front, int end) {
	if (front >= end) return;
	int middle = partition(list, front, end);
	if (front < middle - 1) sort(list, front, middle - 1);
	if (end > middle - 1) sort(list, middle + 1, end);
	return;
}

int bestplan(int s, int n, int* list) {
	int* serve = new int[s];
	int miniplace = 0;
	int ttwaitt = 0;
	for (int i = 0; i < s; i++) serve[i] = 0;
	for (int i = 0; i < n; i++) {
		ttwaitt += (serve[miniplace]+list[i]);//一进去就默认好选哪个位置
		printf("%-7d安排到%7d\n", list[i], miniplace + 1);

		serve[miniplace] += list[i];
		for (int j = 0; j < s; j++) {
			if (serve[j] < serve[miniplace]) miniplace = j;
		}
	}
	return ttwaitt;
}

int main(void) {
	
	int s = 2;
	int n = 9;
	int list[9] = {56,12,1,99,234,33,55,99,812};
	cout << "test example:" << endl;
	cout << s << "     " << n << endl;

	for (auto i : list) {
		cout << i << endl;
	}
	
	sort(list,0,n-1);
	float result = bestplan(s, n, list)/n;
	
	cout << "\n\n" << "the result is:" << result << endl;
	return 0;
}