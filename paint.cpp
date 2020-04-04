#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point {
	int x, y;
} point;

typedef struct queue {
	int start, end, size;
	point **elements;
} queue;

/****************************
* implement functions below *
****************************/

queue *new_queue(int size) {
	queue *q = (queue*)(malloc(sizeof(queue)));
	q->elements = (point *)malloc(size*sizeof(point*));
	for (int i = 0; i < size; i++) q->elements[i] = NULL;
	q->size = size;
	q->start = 0;
	q->end = 0;
	return q;
}

void delete_queue(queue *q) {
	free(q);
}

void put(queue *q, point *value) {
	q->elements[q->end++] = value;
	if (q->end == q->size)q->end = 0;
}

point *get(queue *q) {
	point*p = q->elements[q->start];
	q->start++;
	if (q->start == q->size)q->start = 0;
	return  p;
}

bool is_empty(queue *q) {
	return (q->end == q->start);
}

void fill(int **image, int n, int x, int y, int color) {
	queue *points = new_queue(n * n);
	point *p = malloc(sizeof(point));
	p->x = x;
	p->y = y;
	put(points, p);
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	while (!is_empty(points)) {
		p = get(points);
		image[p->x][p->y] = color;
		for (int i = 0; i < 4; i++) {
			if (p->x + dx[i] < n && p->y + dy[i] < n &&
				p->x + dx[i] >= 0 && p->y + dy[i] >= 0 &&
				image[p->x + dx[i]][p->y + dy[i]] == 0) {
		point *t = malloc(sizeof(point));
		t->x = p->x + dx[i];
		t->y = p->y + dy[i];
		put(points, t);
	}
	;
		}

	}
	delete_queue(points);
}

int main() {
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);

	int **image = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		image[i] = malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {
			scanf("%d", &image[i][j]);
		}
	}

	int x, y, color;
	for (int i = 0; i < k; i++) {
		scanf("%d", &x);
		scanf("%d", &y);
		scanf("%d", &color);
		fill(image, n, x, y, color);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", image[i][j]);
		}
		printf("\n");
		free(image[i]);
	}
	free(image);
}
