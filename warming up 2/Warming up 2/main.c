#define _CRT_SECURE_NO_WARNINGS
#define Pro 4
#include<stdio.h>
#include<time.h>
#include<math.h>


#if Pro == 4

typedef struct Rectangle {
	int x1, x2, y1, y2;
}rectangle;

int collider(rectangle a, rectangle b);

int main()
{
	srand(time(NULL));
	rectangle a, b;
	int temp = 0;
	a.x1 = rand() % 799 + 1;
	a.x2 = rand() % 799 + 1;
	while (a.x2 <= a.x1) {
		if (a.x1 > a.x2) {
			temp = a.x1;
			a.x1 = a.x2;
			a.x2 = temp;
		}
		else if (a.x1 = a.x2) {
			a.x2 = rand() % 799 + 1;
		}
	}

	a.y1 = rand() % 599 + 1;
	a.y2 = rand() % 599 + 1;
	while (a.y2 <= a.y1) {
		if (a.y1 > a.y2) {
			temp = a.y1;
			a.y1 = a.y2;
			a.y2 = temp;
		}
		else if (a.y1 = a.y2) {
			a.y2 = rand() % 599 + 1;
		}
	}

	b.x1 = rand() % 799 + 1;
	b.x2 = rand() % 799 + 1;
	while (b.x2 <= b.x1) {
		if (b.x1 > b.x2) {
			temp = b.x1;
			b.x1 = b.x2;
			b.x2 = temp;
		}
		else if (b.x1 = b.x2) {
			b.x2 = rand() % 799 + 1;
		}
	}

	b.y1 = rand() % 599 + 1;
	b.y2 = rand() % 599 + 1;
	while (b.y2 <= b.y1) {
		if (b.y1 > b.y2) {
			temp = b.y1;
			b.y1 = b.y2;
			b.y2 = temp;
		}
		else if (b.y1 = b.y2) {
			b.y2 = rand() % 599 + 1;
		}
	}

	printf("�簢�� 1�� ��ǥ (%d, %d) / (%d, %d)\n", a.x1, a.y1, a.x2, a.y2);
	printf("�簢�� 2�� ��ǥ (%d, %d) / (%d, %d)\n", b.x1, b.y1, b.x2, b.y2);

	if (collider(a, b) == 1)
		return 0;

	int select = 0;

	char c;

	while (1) {

		printf("wasd�� �̵��ϼ���\n 1�� �簢�� ���� �̵��մϴ�!\n");
		scanf(" %c", &c);

		switch (c) {
		case 'w':
			if (select == 0) {
				select = 1;
				a.y1 -= 50;
				a.y2 -= 50;
				if (a.x1 < 0 || a.x2 > 800 || a.y1 < 0 || a.y2 > 600) {
					printf("������ ������ϴ�.\n");
					a.y1 -= 50;
					a.y2 -= 50;
				}
				else {
					printf("�̵� �� ��ǥ (%d, %d) / (%d, %d)\n", a.x1, a.y1, a.x2, a.y2);
				}
				break;
			}

			else if (select == 1) {
				select = 0;
				b.y1 -= 50;
				b.y2 -= 50;
				if (b.x1 < 0 || b.x2 > 800 || b.y1 < 0 || b.y2 > 600) {
					printf("������ ������ϴ�.\n");
					b.y1 -= 50;
					b.y2 -= 50;
				}
				else {
					printf("�̵� �� ��ǥ (%d, %d) / (%d, %d)\n", b.x1, b.y1, b.x2, b.y2);
				}
				break;
			}

		case 'a':
			if (select == 0) {
				select = 1;
				a.x1 -= 50;
				a.x2 -= 50;
				if (a.x1 < 0 || a.x2 > 800 || a.y1 < 0 || a.y2 > 600) {
					printf("������ ������ϴ�.\n");
					a.x1 += 50;
					a.x2 += 50;
				}
				else {
					printf("�̵� �� ��ǥ (%d, %d) / (%d, %d)\n", a.x1, a.y1, a.x2, a.y2);
				}
				break;
			}

			else if (select == 1) {
				select = 0;
				b.x1 -= 50;
				b.x2 -= 50;
				if (b.x1 < 0 || b.x2 > 800 || b.y1 < 0 || b.y2 > 600) {
					printf("������ ������ϴ�.\n");
					b.x1 += 50;
					b.x2 += 50;
				}
				else {
					printf("�̵� �� ��ǥ (%d, %d) / (%d, %d)\n", b.x1, b.y1, b.x2, b.y2);
				}
				break;
			}

		case 's':
			if (select == 0) {
				select = 1;
				a.y1 += 50;
				a.y2 += 50;
				if (a.x1 < 0 || a.x2 > 800 || a.y1 < 0 || a.y2 > 600) {
					printf("������ ������ϴ�.\n");
					a.y1 -= 50;
					a.y2 -= 50;
				}
				else {
					printf("�̵� �� ��ǥ (%d, %d) / (%d, %d)\n", a.x1, a.y1, a.x2, a.y2);
				}
				break;
			}

			else if (select == 1) {
				select = 0;
				b.y1 += 50;
				b.y2 += 50;
				if (b.x1 < 0 || b.x2 > 800 || b.y1 < 0 || b.y2 > 600) {
					printf("������ ������ϴ�.\n");
					b.y1 -= 50;
					b.y2 -= 50;
				}
				else {
					printf("�̵� �� ��ǥ (%d, %d) / (%d, %d)\n", b.x1, b.y1, b.x2, b.y2);
				}
				break;
			}

		case 'd':
			if (select == 0) {
				select = 1;
				a.x1 += 50;
				a.x2 += 50;
				if (a.x1 < 0 || a.x2 > 800 || a.y1 < 0 || a.y2 > 600) {
					printf("������ ������ϴ�.\n");
					a.x1 -= 50;
					a.x2 -= 50;
				}
				else {
					printf("�̵� �� ��ǥ (%d, %d) / (%d, %d)\n", a.x1, a.y1, a.x2, a.y2);
				}
				break;
			}

			else if (select == 1) {
				select = 0;
				b.x1 += 50;
				b.x2 += 50;
				if (b.x1 < 0 || b.x2 > 800 || b.y1 < 0 || b.y2 > 600) {
					printf("������ ������ϴ�.\n");
					b.x1 -= 50;
					b.x2 -= 50;
				}
				else {
					printf("�̵� �� ��ǥ (%d, %d) / (%d, %d)\n", b.x1, b.y1, b.x2, b.y2);
				}
				break;
			}

		}
		if (collider(a, b) == 1)
			break;
	}
}

int collider(rectangle a, rectangle b)
{
	if ((a.x1 <= b.x2 && a.x1 >= b.x1 && a.y1 <= b.y2 && a.y1 >= b.y1) || (a.x2 >= b.x1 && a.x2 <= b.x2 && a.y1 <= b.y2 && a.y1 >= b.y1) || (a.x1 <= b.x2 && a.x1 >= b.x1 && a.y2 >= b.y1 && a.y2 <= b.y2) || (a.x2 >= b.x1 && a.x2 <= b.x2 && a.y2 >= b.y1 && a.y2 <= b.y2)) {
		printf("�浹\n");
		return 1;
	}
}


#elif Pro == 5

typedef struct List {
	int x[10], y[10], z[10];
	int x_clone[10], y_clone[10], z_clone[10];
	double data[10], data_clone[10];
}List;

void printmenu();

int main()
{
	List list;

	for (int i = 0; i < 10; i++) {
		list.x[i] = 0; list.y[i] = 0; list.z[i] = 0; list.data[i] = 0; list.data_clone[i] = 0;
		list.x_clone[i] = 0; list.y_clone[i] = 0; list.z_clone[i] = 0;
	}

	char menu = 0;
	int top = 0, bottom = 0;
	int x, y, z;

	//m
	int max = 0;

	//n
	int min = 0;

	//s
	int temp = 0;
	int onS = 0;
	int c_top = 0;

	while (menu != 'q') {

		printmenu();
		printf("\n���Ͻô� �޴��� �Է����ּ��� : ");
		scanf(" %c", &menu);
		switch (menu) {
		case '+':
			if (top >= 10 && bottom > 0) {
				printf("�Է��� x, y, z���� �����ּ���: ");
				scanf("%d %d %d", &x, &y, &z);
				list.x[bottom] = x; list.y[bottom] = y; list.z[bottom] = z; list.data[bottom] = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
				bottom--;
				printf("\n");
				for (int i = bottom; i < top; i++) {
					printf("���� : %d | %d, %d, %d\n", i, list.x[i], list.y[i], list.z[i]);
				}
				break;
			}

			else if (top >= 10 && bottom <= 0) {
				printf("\n�����Ͱ� ����á���ϴ�.\n");
				break;
			}

			else {
				printf("�Է��� x, y, z���� �����ּ���: ");
				scanf("%d %d %d", &x, &y, &z);
				list.x[top] = x; list.y[top] = y; list.z[top] = z; list.data[top] = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
				top++;
				printf("\n");
				for (int i = bottom; i < top; i++) {
					printf("���� : %d | %d, %d, %d\n", i, list.x[i], list.y[i], list.z[i]);
				}
				break;
			}

		case '-':
			if (top <= bottom) {
				printf("�� �̻� ���� �����Ͱ� �����ϴ�.\n");
				break;
			}

			else {
				list.x[top] = 0; list.y[top] = 0; list.z[top] = 0; list.data[top] = 0;
				top--;
				printf("\n");
				for (int i = bottom; i < top; i++) {
					printf("���� : %d | %d, %d, %d\n", i, list.x[i], list.y[i], list.z[i]);
				}
				break;
			}

		case 'e':
			if (bottom == 0) {
				for (int i = top; i >= 0; i--) {
					list.x[i + 1] = list.x[i];
					list.y[i + 1] = list.y[i];
					list.z[i + 1] = list.z[i];
				}
				printf("�Է��� x, y, z���� �����ּ���: ");
				scanf("%d %d %d", &x, &y, &z);
				list.x[0] = x; list.y[0] = y; list.z[0] = z;
				top++;
				printf("\n");
				for (int i = bottom; i < top; i++) {
					printf("���� : %d | %d, %d, %d\n", i, list.x[i], list.y[i], list.z[i]);
				}
				break;
			}

			else {
				printf("�Է��� x, y, z���� �����ּ���: ");
				scanf("%d %d %d", &x, &y, &z);
				bottom--;
				list.x[bottom] = x; list.y[bottom] = y; list.z[bottom] = z; list.data[bottom] = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
				printf("\n");
				for (int i = bottom; i < top; i++) {
					printf("���� : %d | %d, %d, %d\n", i, list.x[i], list.y[i], list.z[i]);
				}
				break;
			}

		case 'd':
			list.x[bottom] = 0; list.y[bottom] = 0; list.z[bottom] = 0; list.data[bottom] = 0;
			bottom++;
			printf("\n");
			for (int i = bottom; i < top; i++) {
				printf("���� : %d | %d, %d, %d\n", i, list.x[i], list.y[i], list.z[i]);
			}
			break;

		case 'l':
			printf("\n���� ���� : %d\n", top - bottom);
			break;

		case 'c':
			top = bottom = 0;
			break;

		case 'm':
			max = list.data[bottom];
			x = list.x[bottom]; y = list.y[bottom]; z = list.z[bottom];
			for (int i = bottom; i <= top; i++) {
				if (list.data[i] > max) {
					max = list.data[i]; 
					x = list.x[i]; y = list.y[i]; z = list.z[i];
				}
			}

			printf("�������� ���� �� �Ÿ��� �ִ� ���� ��ǥ : (%d, %d, %d)\n", x, y, z);

			break;

		case 'n':
			min = list.data[bottom];
			x = list.x[bottom]; y = list.y[bottom]; z = list.z[bottom];
			for (int i = bottom; i < top; i++) {
				if (list.data[i] < min) {
					min = list.data[i];
					x = list.x[i]; y = list.y[i]; z = list.z[i];
				}
			}

			printf("�������� ���� ����� �Ÿ��� �ִ� ���� ��ǥ : (%d, %d, %d)\n", x, y, z);

			break;

		case 's':
			if (onS == 0) {
				onS = 1;
				for (int i = bottom; i < top; i++) {
					list.x_clone[i] = list.x[i]; list.y_clone[i] = list.y[i]; list.z_clone[i] = list.z[i];
					list.data_clone[i] = list.data[i];
				}

				for (int i = bottom; i < top; i++) {
					for (int j = 0; j < top - 1; j++) {
						if (list.data_clone[j] > list.data_clone[j + 1]) {
							temp = list.data_clone[j];
							list.data_clone[j] = list.data_clone[j + 1];
							list.data_clone[j + 1] = temp;

							temp = list.x_clone[j];
							list.x_clone[j] = list.x_clone[j + 1];
							list.x_clone[j + 1] = temp;

							temp = list.y_clone[j];
							list.y_clone[j] = list.y_clone[j + 1];
							list.y_clone[j + 1] = temp;

							temp = list.z_clone[j];
							list.z_clone[j] = list.z_clone[j + 1];
							list.z_clone[j + 1] = temp;
						}
					}
				}
				c_top = top - bottom;
				printf("\n");
				for (int i = bottom; i <= c_top; i++) {
					printf("���� : %d | %d, %d, %d\n", i, list.x_clone[i], list.y_clone[i], list.z_clone[i]);
				}
				break;
			}

			else {
				onS = 0;
				printf("\n");
				for (int i = bottom; i < top; i++) {
					printf("���� : %d | %d, %d, %d\n", i, list.x[i], list.y[i], list.z[i]);
				}
				break;
			}
		}
	}
}

void printmenu()
{
	printf("\n�޴� ���\n");
	printf("+ : x y z: ����Ʈ�� �� ���� �Է� (x, y, z: ����)\n");
	printf("- : ����Ʈ�� �� ������ �����Ѵ�\n");
	printf("e : x y z: ����Ʈ�� �� �Ʒ��� �Է� (��ɾ� +�� �ݴ��� ��ġ, ����Ʈ�� ����� �����Ͱ��� ���� �ö󰣴�.)\n");
	printf("d: ����Ʈ�� �� �Ʒ����� �����Ѵ�. (����Ʈ���� ������ ĭ�� ����ִ�.)\n");
	printf("c: ����Ʈ�� ����. ����Ʈ�� ��� �� �ٽ� �Է��ϸ� 0������ ����ȴ�.\n");
	printf("m: �������� ���� �� �Ÿ��� �ִ� ���� ��ǥ���� ����Ѵ�.\n");
	printf("n: �������� ���� ����� �Ÿ��� �ִ� ���� ��ǥ���� ����Ѵ�.\n");
	printf("s: �������� �Ÿ��� �����Ͽ� �������� (�Ǵ� ��������)���� �����Ͽ� ����Ѵ�. �ε��� 0������ �� ĭ���� �����Ͽ� ����Ѵ�. �ٽ� s�� ������ ������ �ε��� ��ġ�� ����Ѵ�.\n");
	printf("l: ����Ʈ�� ����� ���� ������ ����Ѵ�.\n");
	printf("q: ���α׷��� �����Ѵ�.\n");
}

#endif