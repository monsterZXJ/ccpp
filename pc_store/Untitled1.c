#include <stdio.h>
#include <stdlib.h>

/*����ı仯 ����Ϊ�������� Ϊ��Ϊ���� */

int main()
{
	int a,b,i;
	int mac,ideapad;
	int day;

	printf("please input your record number:\n");
	scanf("%d",&day);

	printf("please input your number of mac and ideapad:\n");
	scanf("%d %d",&mac,&ideapad);

	for(i=1;i<=day;i++)
	{

		printf("please input your number's change:\n");
		//�����ű�ʾ
		scanf("%d %d",&a,&b);
		mac+=a;
		ideapad+=b;
		printf("your store of mac is %d\n",mac);
		printf("your store of ideapad is %d\n",ideapad);

	}
	return 0;
}
