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
	//i从前向后走，j从后向前走
	if (i == j) return;
	int i0 = i; int j0 = j; int s = a[i];//选取第一个元素作为“中间元素”
	while (i < j)
	{
		if (a[i] >= s && a[j] <= s) exchange(i, j, a);//只有当两个元素都不合法的时候我们才交换他们，这样两者的位置都会正确
		if (a[i] == s) j--;//当数组中有2个以上的s 时会死循环，我们强行跳过他，因为另一个s 在哪里位置都是合法的
		if (a[i] < s) i++;/*我们认为当i指向的元素小于s时，他的位置是合法的，就跳过他，看看下一个是否合法*/
		if (a[j] > s) j--;//同上理
	}//实际上永远有一个i/j指向的是s ，这样实际上我们是交换完之后就从另一个方向验证元素的合法性
	if (i0 <= i - 1) q_sort(i0, i - 1, a);//这里的判断是防止下标越界
	if (j + 1 <= j0) q_sort(j + 1, j0, a);
}
int main()
{
	putout(a, MAX);
	q_sort(0, MAX - 1, a);
	putout(a, MAX);
	return 0;
}
