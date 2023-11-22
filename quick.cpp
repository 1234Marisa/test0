#define MAX 13
#include <stdio.h>
#include <stdlib.h>
int a[MAX] = { 5,8,455,9,2,6,7,9,88,3,4,5,9 };//define array
void exchange(int i, int j, int a[])
{
	int t = 0;
	t = a[i];
	a[i] = a[j];
	a[j] = t;
}
void putout(int a[], int n)//show the array a
{
	for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
	printf("%d", a[n - 1]);
}
void q_sort(int i, int j, int a[])
{
	//i��ǰ����ߣ�j�Ӻ���ǰ��
	if (i == j) return;
	int i0 = i; int j0 = j; int s = a[i];//ѡȡ��һ��Ԫ����Ϊ���м�Ԫ�ء�
	while (i < j)
	{
		if (a[i] >= s && a[j] <= s) exchange(i, j, a);//ֻ�е�����Ԫ�ض����Ϸ���ʱ�����ǲŽ������ǣ��������ߵ�λ�ö�����ȷ
		if (a[i] == s) j--;//����������2�����ϵ�s ʱ����ѭ��������ǿ������������Ϊ��һ��s ������λ�ö��ǺϷ���
		if (a[i] < s) i++;/*������Ϊ��iָ���Ԫ��С��sʱ������λ���ǺϷ��ģ�����������������һ���Ƿ�Ϸ�*/
		if (a[j] > s) j--;//ͬ����
	}//ʵ������Զ��һ��i/jָ�����s ������ʵ���������ǽ�����֮��ʹ���һ��������֤Ԫ�صĺϷ���
	if (i0 <= i - 1) q_sort(i0, i - 1, a);//������ж��Ƿ�ֹ�±�Խ��
	if (j + 1 <= j0) q_sort(j + 1, j0, a);
}
int main()
{
	putout(a, MAX);
	q_sort(0, MAX - 1, a);
	putout(a, MAX);
	return 0;
}
