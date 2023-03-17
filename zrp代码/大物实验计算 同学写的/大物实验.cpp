#include <windows.h>
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
const int MAXM = 109;
const int Inf = 0x3f3f3f3f;
//typedef struct MOUSE_EVENT_RECORD{ 
//  COORD dwMousePosition;  // ��ǰ���λ��
//  DWORD dwButtonState;  // ��갴ť״̬
//  DWORD dwControlKeyState; // ���̿��Ƽ�״̬
//  DWORD dwEventFlags;   // �¼�״̬
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
	printf("ÿ����һ�����ݸ�һ���ո�\n");
	for (i = 0; i < 10; i++) {
		printf("������Ϊ%dʱ�������������ߵİ���λ�ã���λmm����\n", m[i]);
		scanf("%f %f", &x1[i], &x2[i]);
		dm[i] = fabs(x1[i] - x2[i]);
		printf("��ʱ����ֱ��Ϊ%4.3f\n", dm[i]);
	}
	for (i = 0; i < 5; i++) {
		d[i] = (dm[i] * dm[i]) - (dm[i + 5] * dm[i + 5]);
	}
	printf("\nֱ��ƽ����ֱ�Ϊ\n");
	for (i = 0; i < 5; i++) {
		k = k + d[i];
		printf("%4.3f ", d[i]);
	}
	k = k / 5;
	printf("\nƽ��ֱ��ƽ����Ϊ%4.3f \n", k);
	R = k * 25 / 589.3;
	printf("���ƹ�Ʋ���Ϊ589.3nmʱ��ƽ͹͸�������ʰ뾶Ϊ%4.3f ��\n", R);
}
typedef struct M {
	double tg[100], te[100];
	int m;
	double N, v1, v2, t1, t2, e, K, r, d;
	long double q;
}Miligen[100];
void miligen(Miligen& M) {
	double e0 = 1.6e-19;
	cout << "������������͵θ���" << endl;
	int n;
	cin >> n;
	for (int i = 1; i <= 5; i++) {
		cout << "�������" << i << "�����͵ε�ƽ���ѹ��������ѹ" << endl;
		cin >> M[i].v1 >> M[i].v2;
		cout << "��������͵ε��������ʱ�估����ʱ��" << endl;
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
		cout << "��" << i << "���͵ε�" << endl;
		cout << "ƽ���ѹ:" << M[i].v1 << "V" << endl;
		cout << "������ѹ:" << M[i].v2 << "V" << endl;
		cout << "ƽ���½�ʱ��:" << M[i].t1 << "s" << endl;
		cout << "ƽ������ʱ��:" << M[i].t2 << "s" << endl;
		cout << "K:" << M[i].K << endl;
		cout << "�뾶:" << M[i].r << "m" << endl;
		cout << "���������:" << M[i].q << "C" << endl;
		cout << "���ӵ�ɲ���ֵ:" << M[i].e << "C" << endl;
		cout << "������:" << 100 * M[i].d << "%" << endl;
		cout << endl;
	}
}
void fallingball() {
	float d1[6], d2[6], t1[6], t2[6], zero, H, pj1 = 0, pj2 = 0, pjd[2], v[2];
	int i;
	printf("        ʵ�飺����\n");
	printf("������������(mm):");
	scanf("%f", &zero);
	printf("����������С���ֱ��(mm):\n");
	for (i = 0; i < 5; i++) {
		printf("�������%d��:", i + 1);
		scanf("%f", &d1[i]);
	}
	printf("��������������ֱ��(mm):\n");
	for (i = 0; i < 5; i++) {
		printf("�������%d��:", i + 1);
		scanf("%f", &d2[i]);
	}
	for (i = 0; i < 5; i++) pj1 += d1[i];
	for (i = 0; i < 5; i++) pj2 += d2[i];
	pjd[0] = pj1 / 5 - zero; pjd[1] = pj2 / 5 - zero;
	printf("����С���ƽ��ֵΪ%f(mm):\n", pjd[0]);
	printf("��������ƽ��ֵΪ%f(mm):\n", pjd[1]);
	pj1 = pj2 = 0;
	printf("������������߶�(m):");
	scanf("%f", &H);
	printf("����������С�������ʱ��(s):\n");
	for (i = 0; i < 5; i++) {
		printf("�������%d��:", i + 1);
		scanf("%f", &t1[i]);
	}
	printf("������������������ʱ��(s):\n");
	for (i = 0; i < 5; i++) {
		printf("�������%d��:", i + 1);
		scanf("%f", &t2[i]);
	}
	for (i = 0; i < 5; i++) pj1 += t1[i];
	for (i = 0; i < 5; i++) pj2 += t2[i];
	v[0] = H / (pj1 / 5); v[1] = H / (pj2 / 5);
	printf("����С���ٶ�Ϊ%f(m/s):\n", v[0]);
	printf("��������ٶ�Ϊ%f(m/s):\n", v[1]);
	float ball[2], l, D;
	printf("���������,С��,Һ���ܶ�(kg/m^3)(�ո�ָ�):");
	scanf("%f %f %f", &ball[0], &ball[1], &l);
	printf("����������ԲͲ���ھ�(mm):");
	scanf("%f", &D);
	float nz[2], g = 9.788;
	nz[0] = (ball[0] - l) * g * pow(pjd[0] / 1000, 2) / (18 * v[0]) * (1 - 2.4 * (pjd[0] / D) - 3.3 * ((pjd[0] / 1000) / (2 * H)));
	nz[1] = (ball[1] - l) * g * pow(pjd[1] / 1000, 2) / (18 * v[1]) * (1 - 2.4 * (pjd[1] / D) - 3.3 * ((pjd[1] / 1000) / (2 * H)));
	printf("С������ճ��ϵ��Ϊ%f(Pa*s):\n", nz[0]);
	printf("��������ճ��ϵ��Ϊ%f(Pa*s):\n", nz[1]);
}
void menu_huoer() {
	//�˵�
	printf("_______________________________________________________________________\n");
	printf("|                              ����ЧӦ����ų�                        |\n");
	printf("|             0���˳��˳���                                            |\n");
	printf("|             1�����ų������ŵ���������ʱ���������ѹ�빤�������Ĺ�ϵ  |\n");
	printf("|             2����������������ʱ���������ѹ��ų������ŵ������Ĺ�ϵ  |\n");
	printf("|             3�����û���Ԫ��������߹������ϴŸ�Ӧǿ�ȵķֲ�          |\n");
	printf("_______________________________________________________________________|\n");
}
void huoer() {
	float Is[100], Im[100], U1[100], U2[100], U3[100], U4[100], Uh[100], x[100], B[100];
	float IS, y, Kh, m;
	int i, k, choice;
	while (1) {
		menu_huoer();
		printf("��ѡ����Ӧ�Ĺ��ܣ�");
		scanf("%d", &choice);
		switch (choice) {
		case 0:
			return;
		case 1:
			printf("1�����ų������ŵ���������ʱ���������ѹ�빤�������Ĺ�ϵ\n");
			printf("����Ҫ���뼸�����ݣ�\n");
			scanf("%d", &i);
			printf("�����빤������Is�Ĵ�С����λΪmA��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &Is[k]);
			}
			printf("�������ѹU1�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U1[k]);
			}
			printf("�������ѹU2�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U2[k]);
			}
			printf("�������ѹU3�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U3[k]);
			}
			printf("�������ѹU4�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U4[k]);
			}
			for (k = 0; k < i; k++) {
				Uh[k] = ((fabs(U1[k])) + (fabs(U2[k])) + (fabs(U3[k])) + (fabs(U4[k]))) / 4;
			}
			for (k = 0; k < i; k++) {
				printf("��Is=%4.2f mAʱ,Uh=%4.2f mV\n", Is[k], Uh[k]);
			}
			break;
		case 2:
			printf("2����������������ʱ���������ѹ��ų������ŵ������Ĺ�ϵ\n");
			printf("����Ҫ���뼸�����ݣ�\n");
			scanf("%d", &i);
			printf("���������ŵ���Im�Ĵ�С����λΪmA��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &Im[k]);
			}
			printf("�������ѹU1�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U1[k]);
			}
			printf("�������ѹU2�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U2[k]);
			}
			printf("�������ѹU3�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U3[k]);
			}
			printf("�������ѹU4�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U4[k]);
			}
			for (k = 0; k < i; k++) {
				Uh[k] = ((fabs(U1[k])) + (fabs(U2[k])) + (fabs(U3[k])) + (fabs(U4[k]))) / 4;
			}
			for (k = 0; k < i; k++) {
				printf("��Im=%4.2f mAʱ,Uh=%4.2fmV\n", Im[k], Uh[k]);
			}
			break;
		case 3:
			printf("3�����û���Ԫ��������߹������ϴŸ�Ӧǿ�ȵķֲ�\n");
			printf("�����빤������Ts����λmA����y���꣨��λmm����Kh����λmV/mA*T����ÿ����һ�����ݸ�һ���ո�\n");
			scanf("%f %f %f", &IS, &y, &Kh);
			m = Kh * IS;
			printf("����Ҫ���뼸�����ݣ�\n");
			scanf("%d", &i);
			printf("������x�Ĵ�С����λΪmm��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &x[k]);
			}
			printf("�����빤������U1�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U1[k]);
			}
			printf("�����빤������U2�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U2[k]);
			}
			printf("�����빤������U3�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
			for (k = 0; k < i; k++) {
				scanf("%f", &U3[k]);
			}
			printf("�����빤������U4�Ĵ�С����λΪmV��ÿ����һ�����ݸ�һ���ո�\n");
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
				printf("��x=%4.2f mmʱ,Uh=%4.2fmV,B=%4.2fmT\n", x[k], Uh[k], B[k]);
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
	printf("        ʵ�飺ת������\n");
	printf("�����������������ʱ����͹����������(g):\n");
	for (i = 0; i < 5; i++) {
		printf("��%d��:", i + 1);
		scanf("%f", &m1[i]);
		printf("��������������ʱ��(s):\n");
		for (j = 0; j < 3; j++) {
			printf("t%d:", j + 1);
			scanf("%f", &t1[j]);
		}
		for (j = 0; j < 3; j++)
			pj += t1[j];
		pjt1[i] = pj / 3;
		pj = 0;
		printf("��������ʱ���ƽ��ֵΪ(s):%f\n", pjt1[i]);
	}
	printf("tƽ���ĵ���Ϊ:");
	for (i = 0; i < 4; i++) {
		x1[i] = 1 / pow(pjt1[i], 2);
		printf("%f  ", x1[i]);
	}
	printf("\n");
	printf("��������������̼�Բ��ʱ����͹����������(g):\n");
	for (i = 0; i < 5; i++) {
		printf("��%d��:", i + 1);
		scanf("%f", &m2[i]);
		printf("��������������ʱ��(s):\n");
		for (j = 0; j < 3; j++) {
			printf("t%d:", j + 1);
			scanf("%f", &t2[j]);
		}
		for (j = 0; j < 3; j++)
			pj += t2[j];
		pjt2[i] = pj / 3;
		pj = 0;
		printf("��������ʱ���ƽ��ֵΪ(s):%f\n", pjt2[i]);
	}
	printf("tƽ���ĵ���Ϊ:");
	for (i = 0; i < 4; i++) {
		x2[i] = 1 / pow(pjt2[i], 2);
		printf("%f  ", x2[i]);
	}
	printf("\n");
	float R1, R2, M, I;
	printf("������Բ�����⾶(cm),�ھ�(cm),������(g)(�ո�ָ�):");
	scanf("%f %f %f", &R1, &R2, &M);
	I = 0.5 * (M / 1000) * (pow(R1 / 100, 2) + pow(R2 / 100, 2));
	printf("Բ��ת������������ֵΪ:%f\n", I);
	printf("Ħ�����ؼ�ʵ��ת����������ͼ�ⷨ��������������");
}
void yangshi() {
	float d[6], c1[10], c2[10], pjc[9], zero, L, pj, pjd, L0[9], k, m, g = 9.788;
	int i, j = 1;
	printf("        ʵ�飺����ģ��\n");
	printf("������������(mm):");
	scanf("%f", &zero);
	printf("�������������˿��ֱ��(mm):\n");
	for (i = 0; i < 5; i++) {
		printf("�������%d��:", i + 1);
		scanf("%f", &d[i]);
	}
	for (i = 0; i < 5; i++) pj += d[i];
	pjd = pj / 5; pj = 0;
	printf("�������˿��ֱ��ƽ��ֵΪ(mm):%f\n", pjd - zero);
	printf("�������������˿�ĳ���(m):");
	scanf("%f", &L);
	printf("��������������(kg):");
	scanf("%f", &m);
	printf("��������������Ķ���(mm):\n");
	for (i = 0; i < 10; i++) {
		printf("����%d��:", i);
		scanf("%f", &c1[i]);
	}
	printf("��������ȥ�����Ķ���(mm):\n");
	for (i = 8; i >= 0; i--) {
		printf("��ȥ%d��:", j);
		scanf("%f", &c2[i]);
		j++;
	}
	for (i = 0; i < 9; i++)
		pjc[i] = (c1[i] + c2[i]) / 2;
	printf("��Li�ֱ�Ϊ(mm):\n");
	for (i = 1; i < 9; i++) {
		L0[i] = pjc[i] - pjc[0];
		printf("��L%d:%f  ", i, L0[i]);
	}
	k = (L0[8] - L0[1]) / 1000 / (7 * m);
	printf("����ͼ��б��kΪ:%f\n", k);
	float E;
	E = 4 * g * L / (3.14 * pow(pjd / 1000, 2) * k);
	printf("����õ�����ģ��EΪ:%f\n", E);
}
void maikeer() {
	float digit[100];
	printf("���˶�ѷ�����ǲ⼤�Ⲩ�����㣺\n");
	printf("����N��ֵ��");
	int N = read();
	printf("���������ݸ���:(ż��)");
	//	printf("��������������(mm)\n"); 
	int t = read();	float sum = 0;
	printf("��������������(mm)\n");
	for (int i = 0; i < t; i++) {
		scanf("%f", &digit[i]);
		if (i < t / 2)sum += digit[i];
		else sum -= digit[i];
	}


	float average = fabs(sum / t / t * 4);
	printf("average_d = %f mm\n", 1.0 * average);
	printf("2*��d/N = %.10lf mm\n", 1.0 * 2 * average / N);
	printf("������= ��632.8nm-%.5fnm��/632.8nm", 1.0 * 2 * average / N * 1000000);
	int d2 = 1.0 * 2 * average / N * 1000000;
	printf("= %f %\n", fabs((632.8 - d2)) / 632.8 * 100);
}
void v_voice() {
	float f, Lambda, temp;
	float a[20];
	printf("���ٵĲ������㣺\n");
	printf("һ�����淨\n");
	printf("������f�ĸ�������������f��ƽ��ֵ��");
	int t = read();
	printf("��������������(KHz)\n");
	f = 0;
	for (int i = 0; i < t; i++) {
		scanf("%f", &temp);
		f += temp;
	}
	f /= t;
	printf("\n f��ƽ��ֵΪ��%.4f\n", f);
	printf("�����������ŵĸ���(ż��)��������������ƽ����ֵ��");
	t = read();
	printf("��������������Li(mm)\n");
	float sum = 0;
	for (int i = 0; i < t; i++) {
		scanf("%f", &a[i]);
		if (i < t / 2)sum += a[i];
		else sum -= a[i];
	}
	float average = fabs(sum / t / t * 4);
	printf("ƽ����ֵ = %f mm\n", 1.0 * average);
	printf("V=f��= %.5f m/s\n\n", average * f * 2);









	printf("������λ��\n");
	//	printf("������f�ĸ�������������f��ƽ��ֵ��");
		//int cont = read();
	//	printf("��������������(mm)\n"); 
	//	f = 0; 
	//	for(int i=0;i<cont;i++){
	//		scanf("%f",&temp);
	//		f += temp;
	//	}
	//	f /= cont;
	//	printf("\n f��ƽ��ֵΪ��%.4f\n",f);
	printf("�����������ŵĸ���(ż��)��������������ƽ����ֵ��");
	t = read();
	printf("��������������Li(mm)\n");

	for (int i = 0; i < t; i++) {
		scanf("%f", &a[i]);
		if (i < t / 2)sum += a[i];
		else sum -= a[i];
	}
	average = fabs(sum / t / t * 4);
	printf("ƽ����ֵ = %f mm\n", 1.0 * average);
	printf("V=f��= %.5f m/s\n", average * f);

	printf("����ʱ�\n");
	//	printf("������f�ĸ�������������f��ƽ��ֵ��");
		//int cont = read();
	//	printf("��������������(mm)\n"); 
	//	f = 0; 
	//	for(int i=0;i<cont;i++){
	//		scanf("%f",&temp);
	//		f += temp;
	//	}
	//	f /= cont;
	//	printf("\n f��ƽ��ֵΪ��%.4f\n",f);
	printf("�������x��ֵ��");
	float x;
	scanf("%f", &x);
	printf("���������ݵĸ���(ż��)��������������ƽ����ֵ��");
	t = read();
	printf("��������������T(us)\n");

	for (int i = 0; i < t; i++) {
		scanf("%f", &a[i]);
		if (i < t / 2)sum += a[i];
		else sum -= a[i];
	}
	average = fabs(sum / t / t * 4);
	printf("��T = %f us\n", 1.0 * average);
	printf("V=��x/��T = %f m/s\n\n", x / average * 1000);
}
struct node {
	float hz, v, T, x;
}node[100];
void dianxue() {
	printf("��ѧ�ۺϼ��㣺\n��ֱ�����R�ڣ�C(nF)��R���ֵ��");
	float R_nei, C, R_zu;
	scanf("%f %f %f", &R_nei, &C, &R_zu);
	printf("������һ��һ�е�����Ƶ�ʣ�Hz�� ��ֵpp��V�� ����T��ms�� ��x��us��\n��������Ҫ����������� ");
	int t = read();
	for (int i = 0; i < t; i++) {
		scanf("%f %f %f %f", &node[i].hz, &node[i].v, &node[i].T, &node[i].x);
	}
	printf("\n");
	for (int i = 0; i < t; i++) {
		printf("%.0f ��λ360��*��x/T =%.3f\n", node[i].hz, 1.0 * 360 * node[i].x / node[i].T / 1000);
	}

	//	printf("�������˥�����ݵĸ�����");
	//	int t2=read();
	printf("���������������˥�ڵ����� Ƶ�ʣ�Hz)  //����Ϊ0 0ʱ��һ��\n");
	float a, b;
	while (1) {
		scanf("%f %f", &a, &b);
		if (a <= 0 && b <= 0)break;
		printf("����ֵ T(1/2) = %.4f ms\n", 0.693 * (R_nei + R_zu) * C / 1000);
		float d1 = 0.693 * (R_nei + R_zu) * C / 1000;
		printf("������Ϊ %.3f - %.3f/%.3f", a, d1, a);
		printf(" = %.5f %\n", fabs((a - d1)) / a * 100);
	}
}
void fenguangji() {
	int a[7][4];
	float o[7];
	int i, k, m, A, b, c, d, x, y;
	float B, z, q;
	o[3] = 0;
	printf("ÿ����һ�����ݸ�һ���ո�\n");
	for (i = 0; i < 7; i++) {
		for (k = 0; k < 4; k = k + 2) {
			if (k == 0) {
				printf("�������%d���ĵ�һ�����������ȣ����֣�", i - 3);
				m = k + 1;
				scanf("%d %d", &a[i][k], &a[i][m]);
			}
			if (k == 2) {
				printf("�������%d���ĵڶ������������ȣ����֣�", i - 3);
				m = k + 1;
				scanf("%d %d", &a[i][k], &a[i][m]);
			}
		}
	}
	printf("��������ƽ������\n");
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
		printf("��K=%dʱ�������Ϊ%d��%d��\n", i - 3, x, y);
		if (i != 3) {
			q = (x + y / 60) * 3.1415 / 180;
			o[i] = (abs(i - 3) * B / sin(q));
			printf("��K=%dʱ�Ĺ�դ����Ϊ%f����\n", i - 3, o[i]);
		}
	}
	z = 0;
	for (i = 0; i < 7; i++) {
		if (i != 3)z = o[i] + z;
	}
	z = z / 6;
	int n = (1 / z) * 1000000;
	printf("ƽ����դ����Ϊ%f mm,��դ���ߵ��ܶ�Ϊ%d��\n", z, n);
	printf("����դ���L=4cmʱ��N=%d��", 40 * n);
}
void menu() {
	//�˵�
	printf("                       ______________________________________________________________\n");
	printf("                       |                ��ѧ����ʵ�����                            |\n");
	printf("                       |             1������ЧӦ����ų�                            |\n");
	printf("                       |             2���������͵�ʵ��                              |\n");
	printf("                       |             3�����򷨲���Һ��ճ��ϵ��                      |\n");
	printf("                       |             4������ת�������Ĳⶨ                          |\n");
	printf("                       |             5���쳤��������ģ��                            |\n");
	printf("                       |             6��RC������·����̬����̬����                  |\n");
	printf("                       |             7�����˶�ѷ�����ǲ⼤�Ⲩ��                    |\n");
	printf("                       |             8�����ٵĲ���                                  |\n");
	printf("                       |             9���ֹ�Ƶĵ������դ����Ĳⶨ                |\n");
	printf("                       |             10���Ⱥ����ʵ�飨ţ�ٻ���                     |\n");
	printf("                       |           7777777����������                                |\n");
	printf("                       |____________________________________________________________|\n");
	printf("                       �������������� �����Ҽ�����ʵ����Ƶ\n");
}

int main(void)
{
	// ��ȡ��׼��������豸���  
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	INPUT_RECORD    mouseRec;
	DWORD           res;
	COORD           crPos, crHome = { 0, 0 };

	printf("[Cursor Position] X: %2lu  Y: %2lu\n", 0, 0);
	// ��ʼ״̬
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
					break;  // ���˫�� �˳�ѭ��
				}
			}

			crPos = mouseRec.Event.MouseEvent.dwMousePosition;
			GetConsoleScreenBufferInfo(hOut, &bInfo);
			SetConsoleCursorPosition(hOut, crHome);
			printf("[Cursor Position] X: %2lu  Y: %2lu", crPos.X, crPos.Y);
			SetConsoleCursorPosition(hOut, bInfo.dwCursorPosition);

			switch (mouseRec.Event.MouseEvent.dwButtonState)
			{
			case FROM_LEFT_1ST_BUTTON_PRESSED:          // ��� ���A
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

				break;      // ���ʹ��printf�������֮ǰ��Ҫ�����ù���λ��

			case RIGHTMOST_BUTTON_PRESSED:              // �Ҽ� ���a
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
					printf("��δ�ҵ������Ƶ\n");
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

	CloseHandle(hOut);  // �رձ�׼����豸���  
	CloseHandle(hIn);   // �رձ�׼�����豸���  
	return 0;
}