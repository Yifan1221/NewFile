#include<iostream>
#include<cstdlib>
#include<set>
#include<ctime>
#include<string.h>
#include<string>
#include<sstream>
using namespace std;
#define random(x) (rand()%x)
int a[100];
char s[4]={'+','-','*','/'};
char sym[100];
char brackets[100];
int num[100];
string numToString(int num)
{
	stringstream ss;
	string as="";
	ss<<num;
	ss>>as;
	return as;
}
void dfs(int s,int e)//使用dfs递归添加括号 
{
	if(!random(4)) //四分之一的概率，不进行任何操作 
	{
		return;
	}
	if(e-s<=1)//只有一个元素或没有元素，不进行任何操作 
	{
		return;
	} 
	int s1=random(e-s-1)+s;//随机生成插入括号的位置 
	int e1=random(e-s1)+s1;
	while(s1<s||e1>e||s1>=e1||(s1==s&&e1==e))//避免无用括号 
	{ 
		s1=random(e-s-1)+s;e1=random(e-s1)+s1;
	}
	if(brackets[s1]==')'||brackets[e1]=='(') 
	{
		return;
	} 
	brackets[s1]='(';
	brackets[e1]=')';
	num[s1]++;
	num[e1]++; 
	dfs(s,s1-1);//插入括号的左边几个元素 
	dfs(e1+1,e);//括号之间的几个元素 
	dfs(s1,e1);//括号右边的几个元素 
}
int main()
{
	srand(time(NULL)); 
	int T=500,n;
	set<string> mySet;
	string ans;
	while(T--)
	{
		ans="";
		n=random(8)+2;
		memset(brackets,'.',sizeof(brackets));
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)
		{
			a[i] = random(999)+1;
			sym[i]=s[random(4)];
		}
		dfs(1,n);
		while(brackets[1]=='('&&num[1]--)
		{
			ans+='(';
		}
		ans+=numToString(a[1]);
		for(int i=2;i<=n;i++)
		{
			ans+=sym[i];
			while(brackets[i]=='('&&num[i]--)
			{
				ans+='(';
			} 
			ans+=numToString(a[i]);
			while(brackets[i]==')'&&num[i]--)
			{
				ans+=')'; 
			} 
		}
		if(!mySet.count(ans)){
			cout<<ans<<endl;
			mySet.insert(ans);
		}
		else
		{
			T++;
		}
		
	}
	return 0;
}