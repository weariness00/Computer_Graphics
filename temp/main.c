#include<stdio.h>
#include<time.h>

typedef struct Rectangle {
	int x1, x2, y1, y2;
}rectangle;

int main()
{
	rectangle a, b;
	a.x1 = rand() % 799 + 1;
	a.x2 = rand() % 799 + 1;
	while(a.x2> a.x1)
		a.x2 = rand() % 799 + 1;

	a.y1 = rand() % 599 + 1;
	while (a.y2 > a.y1)
		a.x2 = rand() % 599 + 1;

	srand(time(NULL));

	int select = 0;

	char c;
	
	while (!collider) {

		scanf(" %c", &c);
		switch (c) {
		case 'w':
			if (select == 0) {
				select = 1;
				a.y1 += 50;
				a.y2 += 50;
				if (a.x1 < 0 || a.x2 > 800 || a.y1 < 0 || a.y2 > 600) {
					printf("범위를 벗어났습니다.\n");
				}
				break;
			}

			else if (select == 1) {
				select == 0;
				b.y1 += 50;
				b.y2 += 50;
			}

			break;
		}
	}
}

int collider(rectangle a, rectangle b)
{
	if (a.x1 < b.x2 || a.x2 > b.x1 || a.y1 < b.y2 || a.y2> b.y1) {
		printf("충돌\n");
		return 1;
	}
}
