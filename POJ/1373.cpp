#include <cstdio>
#include <cstring>
using namespace std;

#define CHARMAX   16
#define QUEUEMAX  10000

char u[CHARMAX], v[CHARMAX], w[CHARMAX], z[CHARMAX];

int hash_inset(char *s, int *h) {
	int sum;
	for(sum = 0; *s; s++) {
		sum = sum*2 + *s -'a' + 1;
	}
	if(h[sum])
		return 0;
	h[sum] = 1;
	return 1;
}

void change(char *f, char *t) {
	*f = '\0';
	for(; *t; t++) {
		if(*t == 'a')
			strcat(f, u);
		if(*t == 'b')
			strcat(f, v);
	}
}

int bfs() {
	int front, rear, i;
	int hash[70000] = {0};
	char queue[QUEUEMAX][CHARMAX] = {0}, str[CHARMAX*15] = {0}, son[CHARMAX] = {0};
	char *open;
	if(strstr(w, z)) {
		return 1;
	}
	front = rear = 0;
	strcpy(queue[rear++], w);
	hash_inset(queue[front], hash);
	while(front != rear) {
		change(str, queue[front]);
		++front;
		front %= QUEUEMAX;
		if(strstr(str, z)) {
			return 1;
		}
		for(i = strlen(z), open = str; *open; open++) {
			strncpy(son, open, i);
			if(hash_inset(son, hash)) {
				strcpy(queue[rear++], son);
				rear %= QUEUEMAX;
			}
		}
	}
	return 0;
}

int main() {
	while(gets(u) != NULL) {
		gets(v);
		gets(w);
		gets(z);
		if(!z[0])
			printf("YES\n");
		else if(bfs())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
