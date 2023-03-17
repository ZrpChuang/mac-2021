#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct treenode {//节点
	treenode* parent;//父亲节点
	int chosen;
	int pointnum;//目前这个定点覆盖用了多少个顶点
};
struct edge {//边
	int leftnode;//顶点编号唯一
	int rightbode;//顶点编号为一
};

struct queuenode {
	int level;//记录位置
	int piority;//优先级
	treenode *nodeontree;//树上的节点	
};

struct cmp2
{
	bool operator()(const queuenode& a, const queuenode& b){
		return a.piority > b.piority;
	}
};

int n = 7;//顶点个数
int m = 10;//边的个数
int best = 100;
edge sumup[10] = { {1,6},{2,4},{2,5},{3,6},{4,5},{4,6},{6,7},{2,5},{3,4},{2,3} };//记录所有边
int edgelestweight[7] = {1,1,1,1,1,1,10};
int weight[7] = { 3,4,6,7,4,10,1 };
int testlist[10] = {0};
priority_queue <queuenode, vector<queuenode>, cmp2 > q;//优先队列

void addqueue(int level,int chosen,treenode *parent) {
	treenode* Tnode = new treenode;
	treenode*  b= Tnode;

	Tnode->chosen = chosen;
	Tnode->parent = parent;
	Tnode->pointnum = 0;//重新计算
	b = Tnode;
	for (int i = 0; i < n; i++) testlist[i] = 0;//初始化为零
	for (int i = level; i >= 1; i--, b = b->parent) testlist[(b->chosen) - 1] = 1;//选上
	for (int i = 0; i < n; i++) if (testlist[i] == 1) Tnode->pointnum += weight[i];//保证不能重复加
	
	int sumleft = 0;
	for (int i = level; i < m; i++) {
		if(!testlist[sumup[level].leftnode-1]&&!testlist[sumup[level].rightbode - 1])
		sumleft += edgelestweight[i];//最优集的定义剩下未选边必须得选上一些
	}
	queuenode* qnode = new queuenode;
	qnode->nodeontree = Tnode;//节点挂载到上面去
	qnode->level = level;
	qnode->piority = Tnode->pointnum;// +sumleft;//优先级
	
	
	q.push(*qnode);//入队
	
	return;
}
int main(void) {
	int nowlevel = 0;
	treenode head = {NULL,0,0};
	treenode *parents = &head;//初始化指向头节点
	queuenode qtemp;

	while (nowlevel < m) {
		int chosen;
		chosen = sumup[nowlevel].leftnode;

		addqueue(nowlevel + 1, chosen, parents);

		chosen = sumup[nowlevel].rightbode;
		addqueue(nowlevel + 1, chosen, parents);
		qtemp = q.top();
		//printf("%-5d%-5d%-5d\n", qtemp.piority, qtemp.level, qtemp.nodeontree->chosen);
		q.pop();
		parents = qtemp.nodeontree;
		nowlevel = qtemp.level;
	}
	cout << "test example:" << endl;
	cout << n << "   " << m << endl;
	for (int i = 0; i < n; i++) cout << weight[i] << " ";
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << sumup[i].leftnode << "   " << sumup[i].rightbode << endl;
	}
	treenode* b = parents;
	cout << endl << "the result is:" << endl;
	cout << parents->pointnum << endl;
	for (int i = 0; i < n; i++) testlist[i] = 0;//初始化为零
	for (int i = m; i >= 1; i--, b = b->parent) {
		//printf("%-5d%-5d\n", b->pointnum, b->chosen);
		testlist[(b->chosen) - 1] = 1;
	}
	for (int i = 0; i < n; i++) cout << testlist[i];
	cout << endl;

	return 0;
}




//printf("哈哈哈哈哈哈哈");
	//while (b->parent != NULL) {
		//testlist[(b->chosen) - 1] = 1;//选上
		//b = b->parent;
	//}
	//printf("123");
	//cout << endl; for (int i = 0; i < n; i++) cout << testlist[i]; cout << endl;

//printf("%-5d%-5d%-5d\n", qnode->level, qnode->nodeontree.chosen,qnode->nodeontree.pointnum);
/*printf("%-5d%-5d%-5d\n", qnode->level, qnode->nodeontree.chosen, qnode->nodeontree.pointnum);*/
