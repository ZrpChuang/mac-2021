#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int weight[4][4] = {
 {0,0,0,0},
 {0,1,2,3},
 {0,3,2,1},
 {0,5,4,3}
};
int cost[4][4] = {
 {0,0,0,0},
 {0,1,2,3},
 {0,3,2,1},
 {0,3,4,5}
};
int n = 3;//��ʾ�������
int m = 3;
int limit = 10;
int bestlist[4] = { 0 };//�������
int lestcost[4] = {0,1,1,2};
int bestw = 0;

struct treenode {
	treenode* parent;//���׽ڵ�
	int chosen;//ѡ����̼�
	int nowweight;//Ŀǰ������㸲�����˶��ٸ�����
	int nowcost;
};
struct queuenode {
	int level;//��¼λ��
	int piority;//���ȼ�
	int piority2;
	treenode* nodeontree;//���ϵĽڵ�	
};
struct cmp1
{
	bool operator()(const queuenode& a, const queuenode& b) {
		return a.piority > b.piority;
	}
};
struct cmp2
{
	bool operator()(const queuenode& a, const queuenode& b) {
		return a.piority2 > b.piority2;
	}
};

priority_queue <queuenode, vector<queuenode>, cmp1 > q;//���ȶ���
priority_queue <queuenode, vector<queuenode>, cmp2 > q2;//���ȶ���
void addqueue(int level, int chosen, treenode* parent) {
	int cost1 = parent->nowcost + cost[level][chosen];//��¼�������
	int left = limit - cost1;//ʣ���Ǯ
	int leftneed = 0;
	for (int i = level + 1; i <= n; i++) {
		leftneed += lestcost[i];//�����ʣ�µ�Ǯ�����Ҫ����
	}
	if (cost1 <= limit && left >= leftneed) {
		//��ʼ��װ
		int weight1 = parent->nowweight + weight[level][chosen];
		treenode* T = new treenode;
		T->chosen = chosen;
		T->nowcost = cost1;
		T->parent = parent;
		T->nowweight = weight1;

		queuenode* Q = new queuenode;
		Q->nodeontree = T;
		Q->level = level;
		Q->piority = weight1;//�ݶ����ȼ�������
		Q->piority2 = left;
		q.push(*Q);//���
	}
	return;
}
void BBLessweight() {
	int nowlevel = 0;
	treenode head = { NULL,0,0 };
	treenode* parents = &head;//��ʼ��ָ��ͷ�ڵ�
	queuenode qtemp;
	queuenode qtemp2;

	while (nowlevel < n) {
		
		for (int i = 1; i <= m; i++) {
			addqueue(nowlevel+1, i,parents);
		}
		if (q.empty() == 1) {
			bestw = 0;
			return;
		}
		qtemp = q.top();
		//printf("%-5d%-5d%-5d\n", qtemp.level, qtemp.piority, qtemp.nodeontree->chosen);
		q.pop();
		
		int piority = qtemp.piority;
		q2.push(qtemp);
		while (piority == qtemp.piority && q.empty() == 0) {//�����ȼ���ͬ�Ķ�������
			qtemp2 = q.top();
			if (piority == qtemp2.piority) {
				q.pop();//����
				q2.push(qtemp2);
			}
			else break;
		}
		qtemp = q2.top();//��ȡ�������ȶ��е�����Ԫ��
		q2.pop();
		int levelnew = qtemp.level;
		while (q2.empty() == 0) {
			qtemp2 = q2.top();
			if(qtemp2.level>levelnew) q.push(qtemp2);
			
			q2.pop();
		}
		printf("%-5d%-5d%-5d\n", qtemp.level, qtemp.piority, qtemp.nodeontree->chosen);

		parents = qtemp.nodeontree;
		nowlevel = qtemp.level;
	}
	
	treenode* b = parents;
	bestw = b->nowweight;
	for (int i = n; i > 0; i--,b = b->parent) {
		bestlist[i] = b->chosen;//�洢���
	}
	return;
}


int main(void) {
	int  c = 0, w = 0;
	int x[4] = { 0 };
	
	BBLessweight();
	cout << "test example:" << endl;
	printf("%-3d%-3d%-3d\n\n", n, m, limit);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%-3d", cost[i][j]);
		}
		cout << endl;
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%-3d", weight[i][j]);
		}
		cout << endl;
	}
	//���ú���
	//BBLessweight();

	cout << "the result is:" << endl;
	if (bestw == 0) {
		cout << "no result" << endl;
	}
	else {
		cout << bestw << endl;
		for (int i = 1; i <= n; i++) {
			printf("%-3d", bestlist[i]);
		}
	}
	return 0;
}