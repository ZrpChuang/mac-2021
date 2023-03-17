#include<iostream>
#include<queue>
using namespace std;

struct treenode {
	int *chosen;//ѡ���λ��
	int level;
};
queue<treenode> q;//���ֱ�Ӱ����ֽṹ�嶨���һ��
int n = 4;
int outcome[10] = { 0 };//��һ��λ�ÿճ���

bool place(treenode* checknode, int nowlevel) {
	for (int i = 1; i < nowlevel; i++) {
		if (checknode->chosen[i] == checknode->chosen[nowlevel]) return false;
		if (abs(checknode->level - i) == abs(checknode->chosen[i] - checknode->chosen[nowlevel])) return false;
	}
	return true;
}
void pushqueue(int level,treenode *prents,int chosen) {//���е�λ�ã����׽ڵ㣬ѡ���λ��
	treenode* newnode = new treenode;
	newnode->level = level;
	newnode->chosen = new int[level + 1];
	newnode->chosen[0] = 0;
	newnode->chosen[level] = chosen;
	for (int i = level - 1; i >= 1; i--) {
		newnode->chosen[i] = prents->chosen[i];
	}
	bool flag = place(newnode, level);
	if (flag) {//place(newnode, level)
		q.push(*newnode);
		treenode* b = newnode;
	}
	else delete newnode;
}

void nqueenBB(int n) {
	int nowlevel = 0;
	treenode head = { NULL,0 };
	treenode* nowpointer = &head;
	int flag = 0;
	while (nowlevel < n) {
		for (int i = 1; i <= n; i++) pushqueue(nowlevel + 1, nowpointer, i);
		flag = q.empty();
		if (flag) return;
		nowpointer = &q.front();
		q.pop();//ɾ����ͷԪ��
		//printf("%d    %d\n", nowpointer->chosen,nowpointer->level);
		nowlevel = nowpointer->level;
	}
	for (int i = 1; i <= n; i++) {
		outcome[i] = nowpointer->chosen[i];
	}
	return;
}

int main(void) {

	nqueenBB(n);
	cout << "test example:" << n << endl;
	if (outcome[1] == 0) cout << "no result" << endl;
	else {
		for (int i = 1; i <= n; i++) {
			cout << outcome[i] << "  ";
		}
	}
	cout << endl;

	return 0;
}
