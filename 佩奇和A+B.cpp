#include <iostream>
#include <stdio.h>
using namespace std;

namespace Problem {
	char a[505];
	int al;
	unsigned long long total,ans;
	int q;
	unsigned long long tmp;
	unsigned long long Read() {
		tmp=0;
		while (q<al&&isdigit(a[q])) tmp=(tmp<<3)+(tmp<<1)+(a[q++]-'0');
		return tmp;
	}
	void parse() {
		q=0;
		total=Read();
		while (q<al) {
			switch (a[q++]) {
				case '+':
					total+=Read();
					break;
				case '-':
					total-=Read();
					break;
				case '*':
					total*=Read();
					break;
				case '/':
					total/=Read();
					break;
			}
		}
		
	}
	void ReadA() {
		al=0;
		char c=getchar();
		while (c!='\n') {
			a[al++]=c;
			c=getchar();
		}
		a[al]='\0';
	}
	void Solve() {
		ReadA();
		parse();
		ans+=total;
		ReadA();
		parse();
		cout<<(ans+total)%19260817<<endl;
		return;
	}
}

int main() {
	Problem::Solve();
	return 0;
}
