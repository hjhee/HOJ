#include <stdio.h>
#define INIT(i, id, map, t, j) { \
	cube[i].line[id][0]=map; \
	cube[i].line[id][1]=t; \
	cube[i].line[id][2]=j; \
}
#define SCAN(id, r) { \
	for(i=0; i<3; ++i){ \
		scanf("%s", string); \
		cube[id].map[r][i]=string[0]; \
	} \
}
#define PUT(id, r) { \
	for(i=0; i<3; ++i) \
		putchar(cube[id].map[r][i]); \
}

typedef struct{
	char map[3][4];
	int line[4][3];
}rubik;

rubik cube[7];

void init_cube(void){
	INIT(1, 0, 5, 0, 0); INIT(1, 1, 2, 0, 0);
	INIT(1, 2, 6, 0, 0); INIT(1, 3, 4, 0, 2);
	INIT(2, 0, 5, 1, 2); INIT(2, 1, 3, 0, 0);
	INIT(2, 2, 6, 1, 0); INIT(2, 3, 1, 0, 2);
	INIT(3, 0, 5, 0, 2); INIT(3, 1, 4, 0, 0);
	INIT(3, 2, 6, 0, 2); INIT(3, 3, 2, 0, 2);
	INIT(4, 0, 5, 1, 0); INIT(4, 1, 1, 0, 0);
	INIT(4, 2, 6, 1, 2); INIT(4, 3, 3, 0, 2);
	INIT(5, 0, 4, 1, 0); INIT(5, 1, 3, 1, 0);
	INIT(5, 2, 2, 1, 0); INIT(5, 3, 1, 1, 0);
	INIT(6, 0, 2, 1, 2); INIT(6, 1, 3, 1, 2);
	INIT(6, 2, 4, 1, 2); INIT(6, 3, 1, 1, 2);
}

void input(void){
	int i,j,k;
	char string[10];
	for(i=0; i<3; ++i)
		for(j=0; j<3; ++j){
			scanf("%s", string);
			cube[5].map[i][j]=string[0];
		}
	for(j=0; j<3; ++j)
		for(k=1; k<=4; ++k){
			SCAN(k, j);
		}
	for(i=0; i<3; ++i)
		for(j=0; j<3; ++j){
			scanf("%s", string);
			cube[6].map[i][j]=string[0];
		}
}

void output(void){
	int i,j,k;
	for(j=0; j<3; ++j){
		PUT(5, j);
		putchar('\n');
	}
	for(j=0; j<3; ++j){
		for(k=1; k<=4; ++k){
			PUT(k, j);
		}
		putchar('\n');
	}
	for(j=0; j<3; ++j){
		PUT(6, j);
		putchar('\n');
	}
}

int main(void){
	int set,opt;
	init_cube();
	scanf("%d", &set);
	while(set--){
		input();
		output();
		while(scanf("%d", &opt), opt);
		/*
			rotate(opt);
		printf("%s\n", (confirm())?"Yes, grandpa!\n":"No, you are wrong!");
		*/
	}
	return 0;
}
