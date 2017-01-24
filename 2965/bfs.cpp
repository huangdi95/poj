/*
-表示打开，用0；+表示关上， 用1

愚蠢无比的bfs，参照1753，超时
*/
#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;
int steps;
int best[16];
int change[16] = {
	63624, 62532, 61986, 61713,
	36744, 20292, 12066, 7953,
	35064, 17652, 8946, 4593,
	34959, 17487, 8751, 4383,
};
bool visit[65536] = {0};

struct Node{
	int state;
	int step;
	int method[16];
};

void bfs(int state){
	int s = state;
	Node cur, next;
	queue<Node>q;
	cur.state = s;
	cur.step = 0;
	visit[cur.state] = true;
	q.push(cur);
	if(cur.state == 0){
		steps = 0;
		return;
	}
	
	while(!q.empty()){
		cur = q.front();
		q.pop();
		for(int i = 0; i < 16; i++){
			
			next.state = cur.state ^ change[i];
			if(visit[next.state]) continue;
			
			next.step = cur.step + 1;
			for(int k = 0; k < cur.step; k++){
				next.method[k] = cur.method[k];
			}
			next.method[cur.step] = i;
			
			if(next.state == 0){
				steps = next.step;
				for(int j = 0; j < steps; j++)
					best[j] = next.method[j];
				return;
			}
			q.push(next);
			visit[next.state] = true;	
			
		}
	}
	
	steps = -1;
	return;
	
}

int main(){
	char a[5][5];
	int state = 0;
	for(int i = 0; i < 4; i++)
		scanf("%s", a[i]);
		
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			state <<= 1;
			if(a[i][j] == '+') state++;
		}
	}
	
	bfs(state);

	printf("%d\n", steps);
	for(int i = 0; i < steps; i++){
		int line, row;
		line = best[i] / 4 + 1;
		row = best[i] % 4 + 1;
		printf("%d %d\n", line, row);
	} 
	
	return 0;
} 
