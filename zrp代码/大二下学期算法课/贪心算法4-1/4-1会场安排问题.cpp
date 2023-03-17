#include<iostream>
using namespace std;
struct activity {
	int startt;
	int endtime;
	int choose;
};
struct imfomation {
	activity* list;
	int listnum;
};
int partition(activity* list, int start, int end) {
	if (start == end) return start;

	activity buf = list[start];//Ҫ�Ǻ�����Ҫ�Ķ��Ļ��Ͱ����е��ⲿ�ֽ����滻
	while (start < end){
		while (start<end && list[end].startt>=buf.startt) end--;
		list[start] = list[end];
		while (start < end && list[start].startt <= buf.startt) start++;
		list[end] = list[start];
	}
	list[start] = buf;
	return start;
}
void sort(activity* list,int start,int end) {//һ�ṹ���е�start��Ϊkey��������
	int middle = partition(list, start, end);
	if (start < middle-1) sort(list, start, middle - 1);
	if (end > middle + 1) sort(list, middle + 1, end);
}
int minplace(imfomation info) {
	sort(info.list,0,info.listnum-1);//���п�������
	int result = 0;
	int place[20] = {0};
	for (int i = 0; i < info.listnum; i++) {
		int flag = 0;
		for (int j = 0; j < result; j++) {
			if (info.list[i].startt > place[j]) {
				flag = 1;
				place[j] = info.list[i].endtime;
	cout << "�᳡" << j + 1 << "�" << info.list[i].startt << "\t" << info.list[i].endtime << endl;
	break;
			}
		}
		if (flag == 0) {
			place[result] = info.list[i].endtime;
			result++;
	cout << "�᳡" << result << "�" << info.list[i].startt << "\t" << info.list[i].endtime << endl;
			
		}
	}
	return result;
}
int main(void) {
	
	int n = 7;

	imfomation info;
	info.list = new activity[n];
	info.listnum = n;

	info.list[0] = { 1,23,0 };
	info.list[1] = { 12,28,0 };
	info.list[2] = { 25,35,0 };
	info.list[3] = { 27,80,0 };
	info.list[4] = { 36,50,0 };
	info.list[5] = { 2,60,0 };
	info.list[6] = { 51,90,0 };


	cout << "��������" << endl;
	cout << n << endl;
	for (int i = 0; i < info.listnum; i++) {
		printf("%-5d%-5d\n", info.list[i].startt, info.list[i].endtime);
	}
	cout << "\n\n\n";

	int result = minplace(info);

	cout << "���Ϊ��" << result << endl;



	return 0;
}

/*
int result = 0;
int flag = info.listnum;
while (flag > 0) {
		result++;
		int nowtime = 0;
		for (int i = 0; i < info.listnum; i++) {
			if (info.list[i].choose != 1&&info.list[i].startt>=nowtime) {
				info.list[i].choose = 1;
				nowtime = info.list[i].endtime;
				flag--;
			}
		}
	}
*/

/*
int result = 0;
	int flag = info.listnum;

	while (flag > 0) {
		result++;
		cout << "��" <<result<<"�᳡"<< endl;
		int nowtime = 0;
		for (int i = 0; i < info.listnum; i++) {
			if (info.list[i].choose != 1&&info.list[i].startt>=nowtime) {
				info.list[i].choose = 1;
				nowtime = info.list[i].endtime;
				flag--;
				cout << "���";
				printf("%-5d%-5d\n", info.list[i].startt, info.list[i].endtime);
				//out << "��ʼʱ��:" << info.list[i].startt << "����ʱ��:" << info.list[i].endtime  << endl;

			}
		}
	}
*/