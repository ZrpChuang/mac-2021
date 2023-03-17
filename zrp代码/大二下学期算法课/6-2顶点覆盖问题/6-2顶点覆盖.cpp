#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct treenode {//�ڵ�
	treenode* parent;//���׽ڵ�
	int chosen;
	int pointnum;//Ŀǰ������㸲�����˶��ٸ�����
};
struct edge {//��
	int leftnode;//������Ψһ
	int rightbode;//������Ϊһ
};

struct queuenode {
	int level;//��¼λ��
	int piority;//���ȼ�
	treenode *nodeontree;//���ϵĽڵ�	
};

struct cmp2
{
	bool operator()(const queuenode& a, const queuenode& b){
		return a.piority > b.piority;
	}
};

int n = 7;//�������
int m = 10;//�ߵĸ���
int best = 100;
edge sumup[10] = { {1,6},{2,4},{2,5},{3,6},{4,5},{4,6},{6,7},{2,5},{3,4},{2,3} };//��¼���б�
int edgelestweight[7] = {1,1,1,1,1,1,10};
int weight[7] = { 3,4,6,7,4,10,1 };
int testlist[10] = {0};
priority_queue <queuenode, vector<queuenode>, cmp2 > q;//���ȶ���

void addqueue(int level,int chosen,treenode *parent) {
	treenode* Tnode = new treenode;
	treenode*  b= Tnode;

	Tnode->chosen = chosen;
	Tnode->parent = parent;
	Tnode->pointnum = 0;//���¼���
	b = Tnode;
	for (int i = 0; i < n; i++) testlist[i] = 0;//��ʼ��Ϊ��
	for (int i = level; i >= 1; i--, b = b->parent) testlist[(b->chosen) - 1] = 1;//ѡ��
	for (int i = 0; i < n; i++) if (testlist[i] == 1) Tnode->pointnum += weight[i];//��֤�����ظ���
	
	int sumleft = 0;
	for (int i = level; i < m; i++) {
		if(!testlist[sumup[level].leftnode-1]&&!testlist[sumup[level].rightbode - 1])
		sumleft += edgelestweight[i];//���ż��Ķ���ʣ��δѡ�߱����ѡ��һЩ
	}
	queuenode* qnode = new queuenode;
	qnode->nodeontree = Tnode;//�ڵ���ص�����ȥ
	qnode->level = level;
	qnode->piority = Tnode->pointnum;// +sumleft;//���ȼ�
	
	
	q.push(*qnode);//���
	
	return;
}
int main(void) {
	int nowlevel = 0;
	treenode head = {NULL,0,0};
	treenode *parents = &head;//��ʼ��ָ��ͷ�ڵ�
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
	for (int i = 0; i < n; i++) testlist[i] = 0;//��ʼ��Ϊ��
	for (int i = m; i >= 1; i--, b = b->parent) {
		//printf("%-5d%-5d\n", b->pointnum, b->chosen);
		testlist[(b->chosen) - 1] = 1;
	}
	for (int i = 0; i < n; i++) cout << testlist[i];
	cout << endl;

	return 0;
}




//printf("��������������");
	//while (b->parent != NULL) {
		//testlist[(b->chosen) - 1] = 1;//ѡ��
		//b = b->parent;
	//}
	//printf("123");
	//cout << endl; for (int i = 0; i < n; i++) cout << testlist[i]; cout << endl;

//printf("%-5d%-5d%-5d\n", qnode->level, qnode->nodeontree.chosen,qnode->nodeontree.pointnum);
/*printf("%-5d%-5d%-5d\n", qnode->level, qnode->nodeontree.chosen, qnode->nodeontree.pointnum);*/
