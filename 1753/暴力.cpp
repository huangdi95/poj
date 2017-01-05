/* 
最为粗糙的递归枚举算法，尚可优化，比如使用bitmap代替二维数组进行记录。优化后应当不会超时。

数据结构：数组 。 
思路：每个棋子只有“已翻转”和“未翻转”两种状态，因此可以从times=0开始，依次枚举times次翻转是否能达成纯色目标。
难点：递归调用。 
复杂度：时间复杂度O(2^n)，空间复杂度O(n)，n为格子数 。 
*/ 

#include<stdio.h>

#define ChangeColor(x) x = (x == 'w' ? 'b' : 'w')


bool judge();
bool numsToBeChanged(int n, int rank, int row);
void change(int i, int j);
void flip(int i, int j);

char a[4][4];

int main(){
	
	for(int i = 0; i < 4; i++){                     //input 
		scanf("\n");
		for(int j = 0; j < 4; j++)
			scanf("%c", &a[i][j]);
		
	}
	
	int times;
	for(times = 0; times <= 16; times++){
		if(numsToBeChanged(times, -1, -1)) break;
	}
	
	printf("%d", times);
	
	return 0;
}

bool judge(){                                       //判断是否纯色 
	int standard = a[0][0];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(a[i][j] != standard) return false;
		}
	}
	return true;
} 

bool numsToBeChanged(int n, int rank, int row){     //需要翻转的次数 
	if(n == 0)
		return judge();
		
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i <= rank && j <= row) continue;
			flip(i, j);
			if(numsToBeChanged(n - 1, i, j)) return true;
			else flip(i, j);
		}
	}
	return false;
}

void change(int i, int j){                           
	if(i < 0 || j < 0 || i > 3 || j > 3) return;
	ChangeColor(a[i][j]);
	return;
}

void flip(int i, int j){                               
	 change(i - 1, j);
	 change(i, j - 1);
	 change(i, j);
	 change(i, j + 1);
	 change(i + 1, j);
	 return; 
}
