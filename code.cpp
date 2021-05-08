#include<bits/stdc++.h>
using namespace std;
vector<int> fac;
void getPrime(){
	for(int i=1;i<=100;i++){
		if(100%i==0){
			fac.push_back(i);
			fac.push_back(i*10);
			fac.push_back(i*100);
			fac.push_back(i*1000);
			fac.push_back(i*10000);
			fac.push_back(i*100000);
		}
	}
	return;
}

struct Result{
	int kana=0,kanaVolume=0,apt=0,aptVolume=0,buffer=0;
	Result(int kanaVolume=0,int kana=0,int aptVolume=0, int apt =0,int buffer =0){
		this->kana = kana;
		this->apt = apt;
		this->buffer = buffer;
		this->kanaVolume = kanaVolume;
		this->aptVolume = aptVolume;
	}
	friend bool operator < (const Result &a,const Result &b){
		if(a.kana != b.kana){
			return a.kana > b.kana;
		}
		if(a.apt != b.apt){
			return a.apt > b.apt;
		}
		//if(a.buffer != b.buffer){
		return a.buffer > b.buffer;
	}
	/*
	friend  bool operator < (Result a){
		if(this->kana != a.kana){
			return this->kana < a.kana;
		}
		if(this->apt != a.apt){
			return this->apt < a.apt;
		}
		if(this->buffer != a.buffer){
			return this->buffer < a.buffer;
		}
	}*/
};

int main(){
	getPrime();
	while(1) {
		printf("请输入配置溶液体积（100，200，400）\n");
		int n;
		cin >> n;
		if (n!=100&&n!=200&&n!=400){
			printf("error input");
		}
		set<Result> st;
		printf("请输入配置溶液Running Buffer 最少体积（请根据配置溶液体积自行计算）\n");
		int lim;
		cin >> lim;
		lim = n - lim;
		printf("请输入kana 目标浓度 apt目标浓度\n");
		int a1,a2;
		cin>>a1>>a2;
		//cout<<a1<<a2<<endl;
		printf("请输入筛选浓度最小值\n");
		int mn=500;
		cin>>mn;
		int cnt =0,tot =0;
		for(int i=0;i<fac.size();i++){
			for(int j=0;j<fac.size();j++){
				int c1=fac[i],c2=fac[j];
				for(int x = 1;x<lim;x++){
					for(int y = 1;y<lim;y++){
						if (x+y>lim)continue;
						if(c2*y == n*a2 && c1*x == n*a1){
							tot ++;
							if(c1< mn ||c2< mn )
								continue;
							cnt++;
							st.insert(Result(x,c1,y,c2,n-(x+y)));
							//printf("kana (%d ml,%d 纳克) apt (%d ml,%d 纳摩) running buffer %d\n",x,c1,y,c2,n-(x+y));
						}
					}
				}
			}
		}

		set<Result>::iterator it;
		for(it=st.begin();it!=st.end();it++){
				//kana=0,=0,apt=0,=0,buffer=0;
			printf("kana (%d ml,%d 纳克) apt (%d ml,%d 纳摩) running buffer %d\n",it->kanaVolume,it->kana,it->aptVolume,it->apt,it->buffer);
		}
		printf("%d\n",st.size());
		cout<<"搜索结束，共"<<tot<<"结果，符合筛选条件共"<<cnt<<"个"<<endl;
	}
	return 0;
}
//200 160 200 5 1000

