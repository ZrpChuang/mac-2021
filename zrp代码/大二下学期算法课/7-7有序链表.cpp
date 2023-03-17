#include<iostream>
#define INFINITY 100
using namespace std;

void processor(int *value,int *link,int n) {
	cout << endl << "please tell which number you want to search for processor:";
	int destination;
	cin >> destination;
	int time = sqrt(n);
	int start = link[0], end = 0;
	int min = 0, max = 100;
	for (int i = 1; i < time; i++) {
		int j = rand();
		j = j % n;
		if (value[j]<n && value[j]>min) {
			min = value[j];//底数改成这个数字
			start = j;//起始指针改成这个
		}
		if (value[j] > n && value[j] < max) {
			max = value[j];
			end = j;
		}
	}

	int flag = 0;
	for (int pointer = start; pointer != end; ) {
		int next = link[pointer];
		if (value[next] == destination) {
			cout << "the processor is:" << value[pointer]<<endl;
			flag = 1;
			break;
		}
		if (value[next] > destination) {
			cout << "no element to match what you input!" << endl;
			break;
		}
		pointer = next;
	}
	if(flag==0) cout<<"no element to match what you input!" << endl;
	return;
}

void successor(int* value, int* link, int n) {
	cout << endl << "please tell which number you want to search for successor:";
	int destination;
	cin >> destination;
	int time = sqrt(n);
	int start = link[0], end = 0;
	int min = 0, max = 100;
	for (int i = 1; i < time; i++) {
		int j = rand();
		j = j % n;
		if (value[j]<n && value[j]>min) {
			min = value[j];//底数改成这个数字
			start = j;//起始指针改成这个
		}
		if (value[j] > n && value[j] < max) {
			max = value[j];
			end = j;
		}
	}

	int flag = 0;
	for (int pointer = start; pointer != end; ) {
		int next = link[pointer];
		if (value[pointer] == destination) {
			
			cout << "the processor is:" << value[next] << endl;
			flag = 1;
			break;
		}
		if (value[next] > destination) {
			cout << "no element to match what you input!" << endl;
			break;
		}
		pointer = next;
	}
	if (flag == 0) cout << "no element to match what you input!" << endl;
	return;
}
void max(int* value, int* link, int n) {
	int time = sqrt(n);
	int start = link[0], end = 0;
	int min = 0;
	for (int i = 1; i < time; i++) {
		int j = rand();
		j = j % n;
		if (link[j]==0) {
			cout << "the max is :" << value[j]<<endl;
			return;
		}
		else if (value[j] > min) {
			min = value[j];
			start = j;
		}
	}
	int pointer = start;
	for (; link[pointer] != end; ) pointer = link[pointer];
	cout << "the max is :" << value[pointer] << endl;
	return;
}
int main(void) {
	int value[8] = { INFINITY,2,3,11,1,5,17,8 };
	int link[8] = { 4,2,5,6,1,7,0,3 };//两个数组初始化



	cout << "test example:" << endl;

	char c = '~';
	for (int i = 0; i < 8; i++) {

		if (value[i] == INFINITY) printf("%-3c",c );
		else printf("%-3d", value[i]);
	}
	cout << endl;
	for (int i = 0; i < 8; i++)  printf("%-3d", link[i]); 

	processor(value, link, 7);
	successor(value, link, 7);
	max(value, link, 7);

	cout << "the Min is:" << value[link[0]] << endl;

	return 0;
}