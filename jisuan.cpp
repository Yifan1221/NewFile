#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define random(x) (rand()%x)
int gcd(int a,int b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main(){
	int n=30,a,b,i,d,e,s,f,a1,b1,d1,e1;
	char syb;
	srand(time(NULL)); 
	while(n--){
		
		s=random(2);
		a=random(99);a++;
		b=random(99);b++;
		i=random(4);
		if(s){				//′|àí·?êy 
			d=random(99);d++;
			e=random(99);e++;
			a%=b,d%=e;		//·???′óóú·?×ó
			f=gcd(a,b);		//??·?êy·?×ó·???è￥3y×?′ó1???êy 
			a/=f,b/=f;
			f=gcd(d,e);
			d/=f,e/=f;
			a1=a*e,b1=b*e,d1=b*d;
			if(i==0){		//??DD?ó??3?3y???? 
				a1+=d1;syb='+';
			}else if(i==1){
				a1-=d1;syb='-';
			}else if(i==2){
				a1=a*d;syb='*';
			}else if(i==3){
				a1=a*e;
				b1=b*d;syb='/';
			}
			f=gcd(abs(a1),b1);
			a1/=f,b1/=f;
			cout<<a<<"/"<<b<<" "<<syb<<" "<<d<<"/"<<e<<" = "<<a1<<"/"<<b1<<endl;
		}else{
			b1=0;
			if(i==0){
				a1=a+b;syb='+';
			}else if(i==1){
				a1=a-b;syb='-';
			}else if(i==2){
				a1=a*b;syb='*';
			}else if(i==3){
				a1=a/b;
				b1=a%b; 
				syb='/';
			}
			cout<<a<<" "<<syb<<" "<<b<<" = "<<a1;
			if(b1)cout<<"+"<<b1<<"/"<<b;
			cout<<endl; 
		}
	}
	return 0;
} 