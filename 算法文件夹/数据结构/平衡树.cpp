#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, INF = 1e8;

int n;//表示的是元素个数
struct Node
{
    int l, r;//分别表示左右孩子
    int key;//这个表示的是关键字
    int val;//实际上是随机出来的数字，是的树尽量是一个随机一点的树
    int cnt;//表示个数
    int size;//表示树的大小
}tr[N];//线性链表

int root, idx;//表示根节点，目前分配空间到什么位置
 
void pushup(int p)
{
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
    //更新树的大小，包括当前节点的个数的总数
}

int get_node(int key)//获取一个新的节点，这个很好理解，就是新分配一个空间
{
    tr[ ++ idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    return idx;
}

void zig(int &p)    // 右旋
{//这里的细节是为什么需要传递引用，因为传过来的是父亲节点的指针
    int q = tr[p].l;
    tr[p].l = tr[q].r, tr[q].r = p, p = q;
    pushup(tr[p].r), pushup(p);
}

void zag(int &p)    // 左旋
{
    int q = tr[p].r;
    tr[p].r = tr[q].l, tr[q].l = p, p = q;
    pushup(tr[p].l), pushup(p);
}

void build()//初始化一个平衡树
{
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
    pushup(root);

    if (tr[1].val < tr[2].val) zag(root);
}


void insert(int &p, int key)
{
    if (!p) p = get_node(key);
    else if (tr[p].key == key) tr[p].cnt ++ ;
    else if (tr[p].key > key)
    {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val) zig(p);
    }
    else
    {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val) zag(p);
    }
    pushup(p);
}

void remove(int &p, int key)
{
    if (!p) return;
    if (tr[p].key == key)
    {
        if (tr[p].cnt > 1) tr[p].cnt -- ;
        else if (tr[p].l || tr[p].r)
        {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val)
            {
                zig(p);
                remove(tr[p].r, key);
            }
            else
            {
                zag(p);
                remove(tr[p].l, key);
            }
        }
        else p = 0;
    }
    else if (tr[p].key > key) remove(tr[p].l, key);
    else remove(tr[p].r, key);

    pushup(p);
}

int get_rank_by_key(int p, int key)    // 通过数值找排名
{
    if (!p) return 0;   // 本题中不会发生此情况
    if (tr[p].key == key) return tr[tr[p].l].size + 1;
    if (tr[p].key > key) return get_rank_by_key(tr[p].l, key);
    return tr[tr[p].l].size + tr[p].cnt + get_rank_by_key(tr[p].r, key);
}

int get_key_by_rank(int p, int rank)   // 通过排名找数值
{
    if (!p) return INF;     // 本题中不会发生此情况
    if (tr[tr[p].l].size >= rank) return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
}

int get_prev(int p, int key)   // 找到严格小于key的最大数
{
    if (!p) return -INF;
    if (tr[p].key >= key) return get_prev(tr[p].l, key);
    return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key)    // 找到严格大于key的最小数
{
    if (!p) return INF;
    if (tr[p].key <= key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main()
{
    build();//初始化平衡树

    scanf("%d", &n);
    while (n -- )
    {
        int opt, x;
        scanf("%d%d", &opt, &x);
        if (opt == 1) insert(root, x);//插入
        else if (opt == 2) remove(root, x);
        else if (opt == 3) printf("%d\n", get_rank_by_key(root, x) - 1);
        else if (opt == 4) printf("%d\n", get_key_by_rank(root, x + 1));
        else if (opt == 5) printf("%d\n", get_prev(root, x));
        else printf("%d\n", get_next(root, x));
    }

    return 0;
}


/*
    之前一直无法理解treap的原因是因为不清楚treap并不是一个严格控制树高的AVL树
    它只是类似于随机块排一样的做法，并不是avl树
*/