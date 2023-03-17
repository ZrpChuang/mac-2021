#include <windows.h>
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
const int MAXM = 109;
const int Inf = 0x3f3f3f3f;
//typedef struct MOUSE_EVENT_RECORD{ 
//  COORD dwMousePosition;  // 当前鼠标位置
//  DWORD dwButtonState;  // 鼠标按钮状态
//  DWORD dwControlKeyState; // 键盘控制键状态
//  DWORD dwEventFlags;   // 事件状态
//}MOUSE_EVENT_RECORD;
inline int read()
{
	int sum = 0, fh = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')fh = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		sum = sum * 10 + c - '0';
		c = getchar();
	}
	return sum * fh;
}
void niudunhuan() {
	float x1[10], x2[10], dm[10], d[5];
	int m[] = { 20,19,18,17,16,10,9,8,7,6 };
	float k = 0, R;
	int i;
	printf("每输入一个数据隔一个空格\n");
	for (i = 0; i < 10; i++) {
		printf("当环序为%d时，输入左右两边的暗环位置（单位mm）：\n", m[i]);
		scanf("%f %f", &x1[i], &x2[i]);
		dm[i] = fabs(x1[i] - x2[i]);
		printf("此时暗环直径为%4.3f\n", dm[i]);
	}
	for (i = 0; i < 5; i++) {
		d[i] = (dm[i] * dm[i]) - (dm[i + 5] * dm[i + 5]);
	}
	printf("\n直径平方差分别为\n");
	for (i = 0; i < 5; i++) {
		k = k + d[i];
		printf("%4.3f ", d[i]);
	}
	k = k / 5;
	printf("\n平均直径平方差为%4.3f \n", k);
	R = k * 25 / 589.3;
	printf("当钠光灯波长为589.3nm时，平凸透镜的曲率半径为%4.3f 米\n", R);
}
typedef struct M {
	double tg[100], te[100];
	int m;
	double N, v1, v2, t1, t2, e, K, r, d;
	long double q;
}Miligen[100];
void miligen(Miligen& M) {
	double e0 = 1.6e-19;
	cout << "请输入所测的油滴个数" << endl;
	int n;
	cin >> n;
	for (int i = 1; i <= 5; i++) {
		cout << "请输入第" << i << "个的油滴的平衡电压与提升电压" << endl;
		cin >> M[i].v1 >> M[i].v2;
		cout << "请输入该油滴的五个下落时间及上升时间" << endl;
		for (int j = 1; j <= 5; j++) {
			cin >> M[i].tg[j];
		}
		for (int j = 1; j <= 5; j++) {
			cin >> M[i].te[j];
		}
		M[i].t1 = (M[i].tg[1] + M[i].tg[2] + M[i].tg[3] + M[i].tg[4] + M[i].tg[5]) / 5;
		M[i].t2 = (M[i].te[1] + M[i].te[2] + M[i].te[3] + M[i].te[4] + M[i].te[5]) / 5;
		M[i].r = sqrt(9 * 1.83e-5 * 1.6e-3 / (2 * M[i].t1 * 979.7072 * 9.794));
		M[i].K = 0.00000013 * sqrt((1.83e-5 / (1 + 6.17e-6 / (76 * M[i].r))) * (1.83e-5 / (1 + 6.17e-6 / (76 * M[i].r))) * (1.83e-5 / (1 + 6.17e-6 / (76 * M[i].r))));
		M[i].q = M[i].K * (1 / M[i].v2) * (1 / M[i].t1 + 1 / M[i].t2) * sqrt(1 / M[i].t1);
		M[i].N = M[i].q / e0;
		if ((int)(M[i].N + 0.5) > (int)M[i].N) {
			M[i].m = (int)M[i].N + 1;
		}
		else {
			M[i].m = (int)M[i].N;
		}
		M[i].e = M[i].q / M[i].m;
		M[i].d = (M[i].e - e0) / e0;
		if (M[i].d < 0) {
			M[i].d = -M[i].d;
		}
	}
	for (int i = 1; i <= 5; i++) {
		cout << "第" << i << "个油滴的" << endl;
		cout << "平衡电压:" << M[i].v1 << "V" << endl;
		cout << "提升电压:" << M[i].v2 << "V" << endl;
		cout << "平均下降时间:" << M[i].t1 << "s" << endl;
		cout << "平均上升时间:" << M[i].t2 << "s" << endl;
		cout << "K:" << M[i].K << endl;
		cout << "半径:" << M[i].r << "m" << endl;
		cout << "所带电荷量:" << M[i].q << "C" << endl;
		cout << "电子电荷测量值:" << M[i].e << "C" << endl;
		cout << "相对误差:" << 100 * M[i].d << "%" << endl;
		cout << endl;
	}
}
void fallingball() {
	float d1[6], d2[6], t1[6], t2[6], zero, H, pj1 = 0, pj2 = 0, pjd[2], v[2];
	int i;
	printf("        实验：落球\n");
	printf("请输入零点误差(mm):");
	scanf("%f", &zero);
	printf("请输入所测小球的直径(mm):\n");
	for (i = 0; i < 5; i++) {
		printf("请输入第%d个:", i + 1);
		scanf("%f", &d1[i]);
	}
	printf("请输入所测大球的直径(mm):\n");
	for (i = 0; i < 5; i++) {
		printf("请输入第%d个:", i + 1);
		scanf("%f", &d2[i]);
	}
	for (i = 0; i < 5; i++) pj1 += d1[i];
	for (i = 0; i < 5; i++) pj2 += d2[i];
	pjd[0] = pj1 / 5 - zero; pjd[1] = pj2 / 5 - zero;
	printf("所测小球的平均值为%f(mm):\n", pjd[0]);
	printf("所测大球的平均值为%f(mm):\n", pjd[1]);
	pj1 = pj2 = 0;
	printf("请输入球下落高度(m):");
	scanf("%f", &H);
	printf("请输入所测小球下落的时间(s):\n");
	for (i = 0; i < 5; i++) {
		printf("请输入第%d个:", i + 1);
		scanf("%f", &t1[i]);
	}
	printf("请输入所测大球下落的时间(s):\n");
	for (i = 0; i < 5; i++) {
		printf("请输入第%d个:", i + 1);
		scanf("%f", &t2[i]);
	}
	for (i = 0; i < 5; i++) pj1 += t1[i];
	for (i = 0; i < 5; i++) pj2 += t2[i];
	v[0] = H / (pj1 / 5); v[1] = H / (pj2 / 5);
	printf("所测小球速度为%f(m/s):\n", v[0]);
	printf("所测大球速度为%f(m/s):\n", v[1]);
	float ball[2], l, D;
	printf("请输入大球,小球,液体密度(kg/m^3)(空格分隔):");
	scanf("%f %f %f", &ball[0], &ball[1], &l);
	printf("请输入所测圆筒的内径(mm):");
	scanf("%f", &D);
	float nz[2], g = 9.788;
	nz[0] = (ball[0] - l) * g * pow(pjd[0] / 1000, 2) / (18 * v[0]) * (1 - 2.4 * (pjd[0] / D) - 3.3 * ((pjd[0] / 1000) / (2 * H)));
	nz[1] = (ball[1] - l) * g * pow(pjd[1] / 1000, 2) / (18 * v[1]) * (1 - 2.4 * (pjd[1] / D) - 3.3 * ((pjd[1] / 1000) / (2 * H)));
	printf("小球所测粘滞系数为%f(Pa*s):\n", nz[0]);
	printf("大球所测粘滞系数为%f(Pa*s):\n", nz[1]);
}
void menu_huoer() {
	//菜单
	printf("_______________________________________________________________________\n");
	printf("|                              霍尔效应法测磁场                        |\n");
	printf("|             0、退出此程序                                            |\n");
	printf("|             1、当磁场（励磁电流）不变时，求霍尔电压与工作电流的关系  |\n");
	printf("|             2、当工作电流不变时，求霍尔电压与磁场（励磁电流）的关系  |\n");
	printf("|             3、利用霍尔元件测绘螺线管轴线上磁感应强度的分布          |\n");
	printf("_______________________________________________________________________|\n");
}
void huoer() {
	float Is[100], Im[100], U1[100], U2[100], U3[100], U4[100], Uh[100], x[100], B[100];
	float IS, y, Kh, m;
	int i, k, choice;
	while (1) {
		menu_huoer();
		printf("请选择相应的功能：");
		scanf("%d", &choice);
		switch (choice) {
		case 0:
			return;
		case 1:
			printf("1、当磁场（励磁电流）不变时，求霍尔电压与工作电流的关系\n");
			printf("请问要输入几组数据？\n");
			scanf("%d", &i);
			printf("请输入工作电流Is的大小，单位为mA（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &Is[k]);
			}
			printf("请输入电压U1的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U1[k]);
			}
			printf("请输入电压U2的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U2[k]);
			}
			printf("请输入电压U3的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U3[k]);
			}
			printf("请输入电压U4的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U4[k]);
			}
			for (k = 0; k < i; k++) {
				Uh[k] = ((fabs(U1[k])) + (fabs(U2[k])) + (fabs(U3[k])) + (fabs(U4[k]))) / 4;
			}
			for (k = 0; k < i; k++) {
				printf("当Is=%4.2f mA时,Uh=%4.2f mV\n", Is[k], Uh[k]);
			}
			break;
		case 2:
			printf("2、当工作电流不变时，求霍尔电压与磁场（励磁电流）的关系\n");
			printf("请问要输入几组数据？\n");
			scanf("%d", &i);
			printf("请输入励磁电流Im的大小，单位为mA（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &Im[k]);
			}
			printf("请输入电压U1的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U1[k]);
			}
			printf("请输入电压U2的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U2[k]);
			}
			printf("请输入电压U3的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U3[k]);
			}
			printf("请输入电压U4的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U4[k]);
			}
			for (k = 0; k < i; k++) {
				Uh[k] = ((fabs(U1[k])) + (fabs(U2[k])) + (fabs(U3[k])) + (fabs(U4[k]))) / 4;
			}
			for (k = 0; k < i; k++) {
				printf("当Im=%4.2f mA时,Uh=%4.2fmV\n", Im[k], Uh[k]);
			}
			break;
		case 3:
			printf("3、利用霍尔元件测绘螺线管轴线上磁感应强度的分布\n");
			printf("请输入工作电流Ts（单位mA），y坐标（单位mm），Kh（单位mV/mA*T）（每输入一个数据隔一个空格）\n");
			scanf("%f %f %f", &IS, &y, &Kh);
			m = Kh * IS;
			printf("请问要输入几组数据？\n");
			scanf("%d", &i);
			printf("请输入x的大小，单位为mm（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &x[k]);
			}
			printf("请输入工作电流U1的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U1[k]);
			}
			printf("请输入工作电流U2的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U2[k]);
			}
			printf("请输入工作电流U3的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U3[k]);
			}
			printf("请输入工作电流U4的大小，单位为mV（每输入一个数据隔一个空格）\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U4[k]);
			}
			for (k = 0; k < i; k++) {
				Uh[k] = ((fabs(U1[k])) + (fabs(U2[k])) + (fabs(U3[k])) + (fabs(U4[k]))) / 4;
			}
			for (k = 0; k < i; k++) {
				B[k] = (Uh[k] / m) * 1000;
			}
			for (k = 0; k < i; k++) {
				printf("当x=%4.2f mm时,Uh=%4.2fmV,B=%4.2fmT\n", x[k], Uh[k], B[k]);
			}
			break;
		default:
			break;
		}
	}
}
void zhuandong() {
	float m1[5], m2[5], t1[3], t2[3], pjt1[5], pjt2[5], x1[5], x2[5], pj = 0;
	int i, j;
	printf("        实验：转动惯量\n");
	printf("请输入仅测量载物盘时砝码和钩码的总重量(g):\n");
	for (i = 0; i < 5; i++) {
		printf("第%d次:", i + 1);
		scanf("%f", &m1[i]);
		printf("请输入所测量的时间(s):\n");
		for (j = 0; j < 3; j++) {
			printf("t%d:", j + 1);
			scanf("%f", &t1[j]);
		}
		for (j = 0; j < 3; j++)
			pj += t1[j];
		pjt1[i] = pj / 3;
		pj = 0;
		printf("所测量的时间的平均值为(s):%f\n", pjt1[i]);
	}
	printf("t平方的倒数为:");
	for (i = 0; i < 4; i++) {
		x1[i] = 1 / pow(pjt1[i], 2);
		printf("%f  ", x1[i]);
	}
	printf("\n");
	printf("请输入测量载物盘及圆环时砝码和钩码的总重量(g):\n");
	for (i = 0; i < 5; i++) {
		printf("第%d次:", i + 1);
		scanf("%f", &m2[i]);
		printf("请输入所测量的时间(s):\n");
		for (j = 0; j < 3; j++) {
			printf("t%d:", j + 1);
			scanf("%f", &t2[j]);
		}
		for (j = 0; j < 3; j++)
			pj += t2[j];
		pjt2[i] = pj / 3;
		pj = 0;
		printf("所测量的时间的平均值为(s):%f\n", pjt2[i]);
	}
	printf("t平方的倒数为:");
	for (i = 0; i < 4; i++) {
		x2[i] = 1 / pow(pjt2[i], 2);
		printf("%f  ", x2[i]);
	}
	printf("\n");
	float R1, R2, M, I;
	printf("请输入圆环的外径(cm),内径(cm),与质量(g)(空格分隔):");
	scanf("%f %f %f", &R1, &R2, &M);
	I = 0.5 * (M / 1000) * (pow(R1 / 100, 2) + pow(R2 / 100, 2));
	printf("圆环转动惯量的理论值为:%f\n", I);
	printf("摩擦力矩及实际转动惯量请用图解法求出并计算相对误差。");
}
void yangshi() {
	float d[6], c1[10], c2[10], pjc[9], zero, L, pj, pjd, L0[9], k, m, g = 9.788;
	int i, j = 1;
	printf("        实验：杨氏模量\n");
	printf("请输入零点误差(mm):");
	scanf("%f", &zero);
	printf("请输入所测金属丝的直径(mm):\n");
	for (i = 0; i < 5; i++) {
		printf("请输入第%d个:", i + 1);
		scanf("%f", &d[i]);
	}
	for (i = 0; i < 5; i++) pj += d[i];
	pjd = pj / 5; pj = 0;
	printf("所测金属丝的直径平均值为(mm):%f\n", pjd - zero);
	printf("请输入所测金属丝的长度(m):");
	scanf("%f", &L);
	printf("请输入砝码质量(kg):");
	scanf("%f", &m);
	printf("请输入加入砝码后的读数(mm):\n");
	for (i = 0; i < 10; i++) {
		printf("加入%d个:", i);
		scanf("%f", &c1[i]);
	}
	printf("请输入移去砝码后的读数(mm):\n");
	for (i = 8; i >= 0; i--) {
		printf("移去%d个:", j);
		scanf("%f", &c2[i]);
		j++;
	}
	for (i = 0; i < 9; i++)
		pjc[i] = (c1[i] + c2[i]) / 2;
	printf("δLi分别为(mm):\n");
	for (i = 1; i < 9; i++) {
		L0[i] = pjc[i] - pjc[0];
		printf("δL%d:%f  ", i, L0[i]);
	}
	k = (L0[8] - L0[1]) / 1000 / (7 * m);
	printf("所作图的斜率k为:%f\n", k);
	float E;
	E = 4 * g * L / (3.14 * pow(pjd / 1000, 2) * k);
	printf("所测得的杨氏模量E为:%f\n", E);
}
void maikeer() {
	float digit[100];
	printf("迈克尔逊干涉仪测激光波长计算：\n");
	printf("输入N的值：");
	int N = read();
	printf("请输入数据个数:(偶数)");
	//	printf("接下来输入数据(mm)\n"); 
	int t = read();	float sum = 0;
	printf("接下来输入数据(mm)\n");
	for (int i = 0; i < t; i++) {
		scanf("%f", &digit[i]);
		if (i < t / 2)sum += digit[i];
		else sum -= digit[i];
	}


	float average = fabs(sum / t / t * 4);
	printf("average_d = %f mm\n", 1.0 * average);
	printf("2*▲d/N = %.10lf mm\n", 1.0 * 2 * average / N);
	printf("相对误差= （632.8nm-%.5fnm）/632.8nm", 1.0 * 2 * average / N * 1000000);
	int d2 = 1.0 * 2 * average / N * 1000000;
	printf("= %f %\n", fabs((632.8 - d2)) / 632.8 * 100);
}
void v_voice() {
	float f, Lambda, temp;
	float a[20];
	printf("声速的测量计算：\n");
	printf("一、干涉法\n");
	printf("请输入f的个数，接下来求f的平均值：");
	int t = read();
	printf("接下来输入数据(KHz)\n");
	f = 0;
	for (int i = 0; i < t; i++) {
		scanf("%f", &temp);
		f += temp;
	}
	f /= t;
	printf("\n f的平均值为：%.4f\n", f);
	printf("请输入接受序号的个数(偶数)，接下来用逐差法求平均差值：");
	t = read();
	printf("接下来输入数据Li(mm)\n");
	float sum = 0;
	for (int i = 0; i < t; i++) {
		scanf("%f", &a[i]);
		if (i < t / 2)sum += a[i];
		else sum -= a[i];
	}
	float average = fabs(sum / t / t * 4);
	printf("平均差值 = %f mm\n", 1.0 * average);
	printf("V=fλ= %.5f m/s\n\n", average * f * 2);









	printf("二、相位法\n");
	//	printf("请输入f的个数，接下来求f的平均值：");
		//int cont = read();
	//	printf("接下来输入数据(mm)\n"); 
	//	f = 0; 
	//	for(int i=0;i<cont;i++){
	//		scanf("%f",&temp);
	//		f += temp;
	//	}
	//	f /= cont;
	//	printf("\n f的平均值为：%.4f\n",f);
	printf("请输入接受序号的个数(偶数)，接下来用逐差法求平均差值：");
	t = read();
	printf("接下来输入数据Li(mm)\n");

	for (int i = 0; i < t; i++) {
		scanf("%f", &a[i]);
		if (i < t / 2)sum += a[i];
		else sum -= a[i];
	}
	average = fabs(sum / t / t * 4);
	printf("平均差值 = %f mm\n", 1.0 * average);
	printf("V=fλ= %.5f m/s\n", average * f);

	printf("三、时差法\n");
	//	printf("请输入f的个数，接下来求f的平均值：");
		//int cont = read();
	//	printf("接下来输入数据(mm)\n"); 
	//	f = 0; 
	//	for(int i=0;i<cont;i++){
	//		scanf("%f",&temp);
	//		f += temp;
	//	}
	//	f /= cont;
	//	printf("\n f的平均值为：%.4f\n",f);
	printf("请输入▲x的值：");
	float x;
	scanf("%f", &x);
	printf("请输入数据的个数(偶数)，接下来用逐差法求平均差值：");
	t = read();
	printf("接下来输入数据T(us)\n");

	for (int i = 0; i < t; i++) {
		scanf("%f", &a[i]);
		if (i < t / 2)sum += a[i];
		else sum -= a[i];
	}
	average = fabs(sum / t / t * 4);
	printf("▲T = %f us\n", 1.0 * average);
	printf("V=▲x/▲T = %f m/s\n\n", x / average * 1000);
}
struct node {
	float hz, v, T, x;
}node[100];
void dianxue() {
	printf("电学综合计算：\n请分别输入R内，C(nF)，R阻的值：");
	float R_nei, C, R_zu;
	scanf("%f %f %f", &R_nei, &C, &R_zu);
	printf("接下来一行一行地输入频率（Hz） 峰值pp（V） 周期T（ms） ▲x（us）\n请先输入要输入的行数： ");
	int t = read();
	for (int i = 0; i < t; i++) {
		scanf("%f %f %f %f", &node[i].hz, &node[i].v, &node[i].T, &node[i].x);
	}
	printf("\n");
	for (int i = 0; i < t; i++) {
		printf("%.0f 相位360°*▲x/T =%.3f\n", node[i].hz, 1.0 * 360 * node[i].x / node[i].T / 1000);
	}

	//	printf("请输入半衰期数据的个数：");
	//	int t2=read();
	printf("请依次逐行输入半衰期的数据 频率（Hz)  //输入为0 0时下一步\n");
	float a, b;
	while (1) {
		scanf("%f %f", &a, &b);
		if (a <= 0 && b <= 0)break;
		printf("理论值 T(1/2) = %.4f ms\n", 0.693 * (R_nei + R_zu) * C / 1000);
		float d1 = 0.693 * (R_nei + R_zu) * C / 1000;
		printf("相对误差为 %.3f - %.3f/%.3f", a, d1, a);
		printf(" = %.5f %\n", fabs((a - d1)) / a * 100);
	}
}
void fenguangji() {
	int a[7][4];
	float o[7];
	int i, k, m, A, b, c, d, x, y;
	float B, z, q;
	o[3] = 0;
	printf("每输入一个数据隔一个空格\n");
	for (i = 0; i < 7; i++) {
		for (k = 0; k < 4; k = k + 2) {
			if (k == 0) {
				printf("请输入第%d级的第一个度数，几度？几分？", i - 3);
				m = k + 1;
				scanf("%d %d", &a[i][k], &a[i][m]);
			}
			if (k == 2) {
				printf("请输入第%d级的第二个度数，几度？几分？", i - 3);
				m = k + 1;
				scanf("%d %d", &a[i][k], &a[i][m]);
			}
		}
	}
	printf("请输入光的平均波长\n");
	scanf("%f", &B);
	for (i = 0; i < 7; i++) {
		for (k = 0; k < 4; k++) {
			if (k == 0) { A = abs(a[i][k] - a[3][k]); if (A > 300) { A = 360 - A; } }
			if (k == 1) { b = abs(a[i][k] - a[3][k]); if (A > 300) { b = 60 - b; } }
			if (k == 2) { c = abs(a[i][k] - a[3][k]); if (c > 300) { c = 360 - c; } }
			if (k == 3) { d = abs(a[i][k] - a[3][k]); if (c > 300) { d = 60 - d; } }
		}
		x = (A + c) / 2;
		y = (b + d) / 2;
		printf("第K=%d时的衍射角为%d度%d分\n", i - 3, x, y);
		if (i != 3) {
			q = (x + y / 60) * 3.1415 / 180;
			o[i] = (abs(i - 3) * B / sin(q));
			printf("第K=%d时的光栅常数为%f纳米\n", i - 3, o[i]);
		}
	}
	z = 0;
	for (i = 0; i < 7; i++) {
		if (i != 3)z = o[i] + z;
	}
	z = z / 6;
	int n = (1 / z) * 1000000;
	printf("平均光栅常数为%f mm,光栅刻线的密度为%d条\n", z, n);
	printf("当光栅宽度L=4cm时，N=%d条", 40 * n);
}
void menu() {
	//菜单
	printf("                       ______________________________________________________________\n");
	printf("                       |                大学物理实验计算                            |\n");
	printf("                       |             1、霍尔效应法测磁场                            |\n");
	printf("                       |             2、密立根油滴实验                              |\n");
	printf("                       |             3、落球法测量液体粘滞系数                      |\n");
	printf("                       |             4、刚体转动惯量的测定                          |\n");
	printf("                       |             5、伸长法测杨氏模量                            |\n");
	printf("                       |             6、RC串联电路的暂态和稳态特性                  |\n");
	printf("                       |             7、迈克尔逊干涉仪测激光波长                    |\n");
	printf("                       |             8、声速的测量                                  |\n");
	printf("                       |             9、分光计的调节与光栅常熟的测定                |\n");
	printf("                       |             10、等厚干涉实验（牛顿环）                     |\n");
	printf("                       |           7777777、结束操作                                |\n");
	printf("                       |____________________________________________________________|\n");
	printf("                       单击左键进入计算 单击右键进入实验视频\n");
}

int main(void)
{
	// 获取标准输入输出设备句柄  
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	INPUT_RECORD    mouseRec;
	DWORD           res;
	COORD           crPos, crHome = { 0, 0 };

	printf("[Cursor Position] X: %2lu  Y: %2lu\n", 0, 0);
	// 初始状态
	menu();

	while (1)
	{
		ReadConsoleInput(hIn, &mouseRec, 1, &res);

		if (mouseRec.EventType == MOUSE_EVENT)
		{
			if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if (mouseRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
				{
					break;  // 左键双击 退出循环
				}
			}

			crPos = mouseRec.Event.MouseEvent.dwMousePosition;
			GetConsoleScreenBufferInfo(hOut, &bInfo);
			SetConsoleCursorPosition(hOut, crHome);
			printf("[Cursor Position] X: %2lu  Y: %2lu", crPos.X, crPos.Y);
			SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition);

			switch (mouseRec.Event.MouseEvent.dwButtonState)
			{
			case FROM_LEFT_1ST_BUTTON_PRESSED:          // 左键 输出A
				if (crPos.Y == 3) {

					huoer();
				}
				if (crPos.Y == 4) {

					Miligen M;
					miligen(M);
				}
				if (crPos.Y == 5) {

					fallingball();
				}
				if (crPos.Y == 6) {

					zhuandong();
				}
				if (crPos.Y == 7) {

					yangshi();
				}
				if (crPos.Y == 8) {
					dianxue();
				}
				if (crPos.Y == 9) {

					maikeer();
				}
				if (crPos.Y == 10) {

					v_voice();
				}
				if (crPos.Y == 11) {

					fenguangji();
				}
				if (crPos.Y == 12) {

					niudunhuan();
				}
				if (crPos.Y == 13) {
					return 0;
				}

				break;      // 如果使用printf输出，则之前需要先设置光标的位置

			case RIGHTMOST_BUTTON_PRESSED:              // 右键 输出a
				if (crPos.Y == 3) {
					ShellExecute(NULL, "open", "https://haokan.baidu.com/v?pd=wisenatural&vid=6146030310524778573", NULL, NULL, SW_SHOWNORMAL);

				}
				if (crPos.Y == 4) {

					ShellExecute(NULL, "open", "https://haokan.baidu.com/v?pd=wisenatural&vid=5191489893326460576", NULL, NULL, SW_SHOWNORMAL); Miligen M;

				}
				if (crPos.Y == 5) {
					ShellExecute(NULL, "open", "https://haokan.baidu.com/v?pd=wisenatural&vid=3103490188941306718", NULL, NULL, SW_SHOWNORMAL);

				}
				if (crPos.Y == 6) {
					ShellExecute(NULL, "open", "https://haokan.baidu.com/v?pd=wisenatural&vid=6328039304440158386", NULL, NULL, SW_SHOWNORMAL);

				}
				if (crPos.Y == 7) {
					ShellExecute(NULL, "open", "https://haokan.baidu.com/v?pd=wisenatural&vid=15907520833882895229", NULL, NULL, SW_SHOWNORMAL);

				}
				if (crPos.Y == 8) {
					printf("暂未找到相关视频\n");
				}
				if (crPos.Y == 9) {
					ShellExecute(NULL, "open", "https://v.qq.com/x/page/o0631t6hbw8.html", NULL, NULL, SW_SHOWNORMAL);

				}
				if (crPos.Y == 10) {
					ShellExecute(NULL, "open", "https://haokan.baidu.com/v?pd=wisenatural&vid=16759537673932651709", NULL, NULL, SW_SHOWNORMAL);

				}
				if (crPos.Y == 11) {
					ShellExecute(NULL, "open", "https://www.iqiyi.com/w_19rr8jn7vh.html", NULL, NULL, SW_SHOWNORMAL);

				}
				if (crPos.Y == 12) {
					ShellExecute(NULL, "open", "https://haokan.baidu.com/v?pd=wisenatural&vid=797194607954849513", NULL, NULL, SW_SHOWNORMAL);

				}
				if (crPos.Y == 13) {
					return 0;
				}
				break;

			default:
				break;
			}
		}
	}

	CloseHandle(hOut);  // 关闭标准输出设备句柄  
	CloseHandle(hIn);   // 关闭标准输入设备句柄  
	return 0;
}