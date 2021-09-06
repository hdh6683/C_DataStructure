#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#define MAZE_WIDTH 15
#define MAZE_HEIGHT 11

int maze[MAZE_HEIGHT + 2][MAZE_WIDTH + 2];
maze = {{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{}}
int mark[MAZE_HEIGHT + 2][MAZE_WIDTH + 2];

typedef struct {
	short int vert;
	short int horiz;
}offsets;
offsets move[8];

typedef struct {
	short int row;
	short int col;
	short int dir;
}element;
element stack[MAX_STACK_SIZE];
int top = -1;


int isFull() {
	if (top >= MAX_STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

int isEmpty() {
	if (top < 0)
		return 1;
	else
		return 0;
}

void add(element item) {
	if (isFull()) {
		printf("스택이 꽉 찼습니다.\n");
		return;
	}
	stack[++top] = item;
}

element delete() {
	if (isEmpty()) {
		printf("Stack Empty.\n");
		return;
	}
	return stack[top--];
}


void path(void) {
	int i, row, col, next_row, next_col, dir;
	int found = 0;//FALSE
	element position;
	move[0].vert = -1; move[0].horiz = 0;
	move[1].vert = -1; move[1].horiz = 1;
	move[2].vert = 0; move[2].horiz = 1;
	move[3].vert = 1; move[3].horiz = 1;
	move[4].vert = 1; move[4].horiz = 0;
	move[5].vert = 1; move[5].horiz = -1;
	move[6].vert = 0; move[6].horiz = -1;
	move[7].vert = -1; move[7].horiz = -1;

	mark[1][1] = 1;  top = 0;
	stack[0].row = 1;  stack[0].col = 1;  stack[0].dir = 2;
	while (top > -1 && !found) { // stack이 empty가 아니고, 아직
						   // 경로를 발견 못할 때까지 실행
		position = delete(&top);	 // top의 위치로 이동
		row = position.row;      col = position.col;
		dir = position.dir;
		while (dir < 8 && !found) { // 8방향을 차례대로 검사
			next_row = row + move[dir].vert;     // move in direction dir
			next_col = col + move[dir].horiz;
			if (next_row == EXIT_ROW && next_col == EXIT_COL)
				found = 1;	 // 출구 발견. 경로는 어디에?
			else if (!maze[next_row][next_col] &&!mark[next_row][next_col]) { // 아직 안 가본 길
				mark[next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				add(&top, position);  // 현재 좌표와 방향을 stack 저장
				row = next_row;  // 안 가본 길로 전진. 방향은 북쪽
				col = next_col;
				dir = 0;
			}
			else  ++dir;
		}
	}
	if (found) {	// stack에 저장된 경로 출력
		printf(" The path is: \n ");
		printf("row  col \n");
		for (i = 0; i <= top; i++)
			printf(" %2d %5d ", stack[i].row, stack[i].col);
		printf(" %2d %5d \n ", row, col);
		printf(" %2d %5d \n ", EXIT_ROW, EXIT_COL);
	}
	else printf(" The maze does not have a path \n ");
}

}