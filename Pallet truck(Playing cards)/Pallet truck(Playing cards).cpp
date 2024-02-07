#include<bits/stdc++.h>
#include<windows.h>
#define debug false
//#define int long long
using namespace std;
string s="#AAAA222233334444555566667777888899990000QQQQKKKKJJJJOO";
bool vis[60];
deque<char>p1,p2;
int win;
int find(vector<char>a,char c)
{
	int cnt=0;
	for(;cnt<a.size();)
	{
		if(a[cnt]==c)
			return cnt;
		cnt++;
	}
	return a.size();
}
signed main()
{
	srand((int)time(0));
	system("pause");
	cout<<"准备中......\n";
	for(int i=1;i<=54;i++)
	{
		if((i&1)==1)
		{
			int x=rand()%54+1;
			while(vis[x])
				x=rand()%54+1;
			vis[x]=true;
			p1.push_back(s[x]);
		}
		else
		{
			int x=rand()%54+1;
			while(vis[x])
				x=rand()%54+1;
			vis[x]=true;
			p2.push_back(s[x]);
		}
		cout<<char(13)<<"已完成："<<i*100/54<<"%";
		Sleep(50);
	}
	Sleep(500);
	system("cls");
	int ju=1,cnt=0;
	vector<char>pa,tmp;
	while(win==0)
	{
		system("cls");
		cout<<++cnt<<"局\n";
		char p=ju==1?p1.back():p2.back();
		if(ju==1)
			p1.pop_back(),ju=0;
		else
			p2.pop_back(),ju=1;
		for(char i:pa)
		{
			if(i=='0')
				cout<<"10";
			else if(i=='O')
				cout<<"JOKER";
			else
				cout<<i;
			cout<<'\n';
		}
		cout<<p;
		pa.push_back(p);
		if(::find(pa,p)!=pa.size()-1)
		{
			int len=pa.size();
			for(int i=int(::find(pa,p));i<len;i++)
				tmp.push_back(pa.back()),pa.pop_back();
			for(char c:tmp)
				if(ju==1)
					p2.push_front(c);
				else
					p1.push_front(c);
			tmp.clear();
			if(ju==1)
				ju=0;
			else
				ju=1;
		}
		Sleep(10);
		if(p1.empty())
			win=2;
		if(p2.empty())
			win=1;
	}
	system("cls");
	cout<<"过了"<<cnt<<"局，p"<<win<<"赢了!";
	return 0;
}
