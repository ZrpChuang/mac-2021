#include<iostream>
#include<queue>
using namespace std;

struct treenode {
	int *chosen;//选择的位置
	int level;
};
queue<treenode> q;//这次直接把两种结构体定义成一种
int n = 4;
int outcome[10] = { 0 };//第一个位置空出来

bool place(treenode* checknode, int nowlevel) {
	for (int i = 1; i < nowlevel; i++) {
		if (checknode->chosen[i] == checknode->chosen[nowlevel]) return false;
		if (abs(checknode->level - i) == abs(checknode->chosen[i] - checknode->chosen[nowlevel])) return false;
	}
	return true;
}
void pushqueue(int level,treenode *prents,int chosen) {//现有的位置，父亲节点，选择的位置
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
		q.pop();//删除队头元素
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
