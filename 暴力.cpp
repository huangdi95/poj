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
/*	char c = 'w';
	printf("%c\n", c);
	ChangeColor(c);
	printf("%c\n", c);
	*/
//	flip(3, 0);
	
	/*for(int i = 0; i < 4; i++){
		printf("\n");
		for(int j = 0; j < 4; j++){
			printf("%c", a[i][j]);
		}
	}*/
	
	int times;
	for(times = 0; times <= 16; times++){
		if(numsToBeChanged(times, -1, -1)) break;
	}
	
	printf("%d", times);
	
	//if(judge(a)) printf("true");
	
	return 0;
}

bool judge(){
	int standard = a[0][0];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(a[i][j] != standard) return false;
		}
	}
	return true;
} 

bool numsToBeChanged(int n, int rank, int row){
	if(n == 0)
		return judge();
		
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i <= rank && j <= row) continue;
			//printf("\n%d %d %d", n, i, j);
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
