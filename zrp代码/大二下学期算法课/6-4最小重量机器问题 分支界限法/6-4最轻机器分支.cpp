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
int n = 3;//表示零件个数
int m = 3;
int limit = 10;
int bestlist[4] = { 0 };//结果序列
int lestcost[4] = {0,1,1,2};
int bestw = 0;

struct treenode {
	treenode* parent;//父亲节点
	int chosen;//选择的商家
	int nowweight;//目前这个定点覆盖用了多少个顶点
	int nowcost;
};
struct queuenode {
	int level;//记录位置
	int piority;//优先级
	int piority2;
	treenode* nodeontree;//树上的节点	
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

priority_queue <queuenode, vector<queuenode>, cmp1 > q;//优先队列
priority_queue <queuenode, vector<queuenode>, cmp2 > q2;//优先队列
void addqueue(int level, int chosen, treenode* parent) {
	int cost1 = parent->nowcost + cost[level][chosen];//记录如果加入
	int left = limit - cost1;//剩余的钱
	int leftneed = 0;
	for (int i = level + 1; i <= n; i++) {
		leftneed += lestcost[i];//计算出剩下的钱最多需要多少
	}
	if (cost1 <= limit && left >= leftneed) {
		//开始包装
		int weight1 = parent->nowweight + weight[level][chosen];
		treenode* T = new treenode;
		T->chosen = chosen;
		T->nowcost = cost1;
		T->parent = parent;
		T->nowweight = weight1;

		queuenode* Q = new queuenode;
		Q->nodeontree = T;
		Q->level = level;
		Q->piority = weight1;//暂定优先级是质量
		Q->piority2 = left;
		q.push(*Q);//入队
	}
	return;
}
void BBLessweight() {
	int nowlevel = 0;
	treenode head = { NULL,0,0 };
	treenode* parents = &head;//初始化指向头节点
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
		while (piority == qtemp.piority && q.empty() == 0) {//把优先级相同的都拉出来
			qtemp2 = q.top();
			if (piority == qtemp2.piority) {
				q.pop();//弹出
				q2.push(qtemp2);
			}
			else break;
		}
		qtemp = q2.top();//读取二级优先队列的最优元素
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
		bestlist[i] = b->chosen;//存储结果
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
	//调用函数
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