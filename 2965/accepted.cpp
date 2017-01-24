/*
-表示打开，用0；+表示关上， 用1

注意到对于每一个'+'，可以将其所在行列全部反转一遍，这样'+'翻转了奇数次，而其他所有格子都只翻转了偶数次。又注意到当格子翻转偶数次时可以消去，可解

比bfs快了不少，但是似乎有一定的局限性，由题目翻转方式所导致（格子是奇数还是偶数倒是无所谓，改下策略即可） 

如果将题目改成类似孔明灯的反转方式，似乎只要将边界扩大1就可以同解了，效率稍慢（因为每次翻转都要对整个棋盘操作），但是可能还是比bfs要快一点 
*/

#include<stdio.h>
#include<string.h>

char a[5][5];
int state = 0;                                                   //This 'state' is different from the 'state' of bfs. The 'bit x of state == 1' here means bit[x] need to be changed.
int change[16] = {
	63624, 62532, 61986, 61713,
	36744, 20292, 12066, 7953,
	35064, 17652, 8946, 4593,
	34959, 17487, 8751, 4383,
};

void solve(){
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(a[i][j] == '+')
				state = state ^ change[15 - (i * 4 + j)];        //'state' is reversed here to be output in the right way.

	return;
}

void output(){                                                   //Each '1' in state means 1 flip on that bit.
	int s, step;
	s = state;
	step = 0;
	for(int i = 0; i < 16; i++){
		if(s == 0) break;
		if(s & 1 == 1) step++;
		s >>= 1;
	}
	printf("%d\n", step);
		
	s = state;
	for(int i = 0; i < 16; i++){
		if(s & 1 == 1) printf("%d %d\n", i / 4 + 1, i % 4 + 1);
		s >>= 1;
	}
	
	return;
}

int main(){
	for(int i = 0; i < 4; i++)
		scanf("%s", a[i]);		
	
	solve();
	output();
	
	return 0;	
}
