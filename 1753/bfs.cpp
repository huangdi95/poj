/* 
数据结构：队列。 
思路：bfs 不需要递归
难点：bfs 
复杂度：时间复杂度好像还是O(2^n)，因为最坏情况下每一种状态都要遍历到。空间复杂度取决于队列中元素最多的情况，O(1)? 
其实我并不知道这种n固定的情况复杂度怎么算 
*/ 
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct Node{
	int state;
	int step;
};

int visit[65536] = {0};                                                   //visit==true表示访问过了，无需继续访问 

int change[16] = {                                                        //使用异或进行flip, 1 ^ 1 = 0, 0 ^ 1 = 1； 
	51200,58368,29184,12544,  
    35968,20032,10016,4880,  
    2248,1252,626,305,  
    140,78,39,19
	};

int bfs(int state){
	queue<Node>q;                                                         //使用queue进行bfs 
	Node cur, next;
	cur.state = state;
	cur.step = 0;
	q.push(cur);
	visit[cur.state] = true;
	
	if(cur.state == 0 || cur.state == 0xffff)                             //0xffff==65535，全b  
		return cur.step;
	
	while(!q.empty()){
		cur = q.front();
		q.pop();
		
		for(int i = 0; i < 16; i++){	
			next.state = cur.state ^ change[i];                           //flip 
			next.step = cur.step + 1;                                     //由于后面访问过的就不push，因此step可以直接+1 
			if(visit[next.state])
				continue;
			if(next.state == 0 || next.state == 0xffff)                   
				return next.step;
			visit[next.state] = true;
			q.push(next);
		}
	}
	
	return -1;                                                             //全部状态遍历完毕 
} 

int main(){
	char a[5][5];
	int state;
	int ans;
	
	for(int i = 0; i < 4; i++)
		scanf("%s", a[i]);
	
	state = 0;
	for(int i = 0; i < 4; i++){                                            //将wb，转换为01表示的int 
		for(int j = 0; j < 4; j++){
			state <<= 1;
			if(a[i][j] == 'b') state++;
		}
	}
	
	ans = bfs(state);
	if(ans == -1) printf("Impossible");
	else printf("%d", ans);
	
	return 0;
}
