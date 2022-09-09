#define Pro 3
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

#if Pro == 1

int det(int MatrixA[4][4], int n);
void Matrix_init(int MatrixA[4][4], int MatrixB[4][4], int n);
void printMatrix(int MatrixA[4][4], int MatrixB[4][4], int n);
void printmenu();
void transpose(int matrix[4][4], int n);

int main() {
	int MatrixA[4][4] = {0};
	int MatrixB[4][4] = { 0 };
	int MatrixC[4][4] = { 0 };

	int x = 3, y = 3;
	char mat = 0;

	srand(time(NULL));
	Matrix_init(MatrixA, MatrixB, x);
	printMatrix(MatrixA, MatrixB, x);
	 
	char menu = 0;
	char select = 0;

	while (menu != 'q') {
		printmenu();
		printf("\n메뉴:");
		scanf_s(" %c", &menu);

		switch (menu) {
		case 'm':
			printf("\n");
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					MatrixC[i][j] = 0;
					for (int k = 0; k < x; k++) {
						MatrixC[i][j] += MatrixB[i][k] * MatrixA[k][j];
					}
					printf("%d  ", MatrixC[i][j]);
				}
				printf("\n");
			}
				break;

		case 'a':
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					MatrixC[j][i] = MatrixA[j][i] + MatrixB[j][i];
					printf("%d  ", MatrixC[j][i]);
				}
				printf("\n");
			}
			break;

		case 'd':
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					MatrixC[j][i] = MatrixA[j][i] - MatrixB[j][i];
					printf("%d  ", MatrixC[j][i]);
				}
				printf("\n");
			}
			break;

		case 'r':
			printf("행렬A의 행렬식 : %d\n", det(MatrixA, x));
			printf("행렬B의 행렬식 : %d\n", det(MatrixB, x));
			break;

		case 't':
			printf("\n전치행렬A\n");
			transpose(MatrixA, x);
			printf("\n전치행렬B\n");
			transpose(MatrixB, x);
			break;

		case 'h':
			x = y = 4;
			MatrixA[3][3] = MatrixB[3][3] = 1;
			printMatrix(MatrixA, MatrixB, x);
			printf("\n");
			printf("행렬A의 행렬식 : %d\n", det(MatrixA, x));
			printf("행렬B의 행렬식 : %d\n", det(MatrixB, x));
		
			break;

		case 's':
			printf("\n행렬을 재설정 하였습니다.\n\n");
			Matrix_init(MatrixA, MatrixB, x);
			printMatrix(MatrixA, MatrixB, x);
			break;
		}
	}
}

int det(int MatrixA[4][4], int n)
{
	int i, j, k;
	int sum = 0, count1 = 0, count2 = 0;
	if (n == 1) return MatrixA[0][0];
	for (i = 0; i < n; i++) {
		count1 = 0, count2 = 0;//   
		int b[4][4] = {0};//          
		for (j = 1; j < n; j++) {
			for (k = 0; k < n; k++) {
				if (k == i) continue;
				else {
					b[count1][count2++] = MatrixA[j][k];//n-1         
				}
			}
			count1++; 
			count2 = 0;        
		}
		sum += MatrixA[0][i] * pow(-1, i) * det(b, n - 1);
	}
	return sum;
}

void Matrix_init(int MatrixA[4][4], int MatrixB[4][4], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			MatrixA[j][i] = rand() % 3;
			MatrixB[j][i] = rand() % 3;
		}
	}
}

void printMatrix(int MatrixA[4][4], int MatrixB[4][4], int n)
{
	printf("행렬A\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d  ", MatrixA[j][i]);
		}
		printf("\n");
	}

	printf("\n행렬B\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d  ", MatrixB[j][i]);
		}
		printf("\n");
	}
}

void printmenu()
{
	printf("\n메뉴 목록입니다.\n");
	printf("m : 행렬의 곱셈\n");
	printf("a : 행렬의 덧셈\n");
	printf("d : 행렬의 뺄셈\n");
	printf("r : 행렬식의 값\n");
	printf("t : 전치 행렬과 행렬식의 값\n");
	printf("h : 4x4행렬로 변환 후 행렬식의 값\n");
	printf("s : 행렬 재설정\n");
	printf("q : 프로그램 종료\n");
}

void transpose(int matrix[4][4], int n)
{
	int matrixT[4][4] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrixT[i][j] = matrix[j][i];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d  ", matrixT[j][i]);
		}
		printf("\n");
	}

	printf("행렬식 : %d\n", det(matrix, n));
}

#elif Pro == 2

int main()
{
	int MAX = 100;
	FILE* fp = fopen("data.txt", "r");

	char* n[10];
	char* name;

	int word = 0;
	int number = 0;
	int capital = 0;

	if (fp == NULL)
	{
		fprintf(stderr, "File Open Error!\n");
		exit(1);
	}

	for (int i = 0; i < 10; i++)
	{
		name = (char*)malloc(sizeof(char) * MAX);
		fgets(name, MAX, fp);
		n[i] = name;
		printf("%s", name);
	}
	printf("\n\n");

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < strlen(n[i]); j++) {
			if (n[i][j] == ' ' )
				word++;

			else if ((n[i][j] >= 48 && n[i][j] <= 57) && (n[i][j+1] == ' ' || n[i][j + 1] == '\n'))
				number++;
            
			else if (n[i][j] >= 65 && n[i][j] <= 90 && n[i][j+1] != ' ')
				capital++;
		}
	}

	for (int i = 0; i < 10; i++)
		free(n[i]);

	printf("단어 개수 : %d\n", word + 10 - number);
	printf("숫자 개수 : %d\n", number);
	printf("대문자 단어 개수 : %d\n", capital);

	fclose(fp);

	return 0;
}

#elif Pro == 3


void printmenu();

int main()
{
	int MAX = 100;
	FILE* fp = fopen("data.txt", "r");

	char* n[10];
	char* name;
    char menu = 0;
    
    //e
    int onE = 0;

    //d
    char temp;

    //f
    char save[10][100] = {0};
    int onF = 0;
	int g = 0;
	char* s[10];

    //g
    char select, change;

	if (fp == NULL)
	{
		fprintf(stderr, "File Open Error!\n");
		exit(1);
	}

	for (int i = 0; i < 10; i++)
	{
		name = (char*)malloc(sizeof(char) * MAX);
		fgets(name, MAX, fp);
		n[i] = name;
		printf("%s", name);
	}

	printf("\n");

	for (int i = 0; i < 10; i++) {
		s[i] = (char*)malloc(sizeof(char) * MAX);
		strcpy(s[i], n[i]);
		printf("%s\n", s[i]);
	}

    while (menu != 'q') {

        printmenu();
        printf("\n메뉴를 입력해주세요 : ");
        scanf(" %c", &menu);

        switch (menu) {
        case 'd':
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < strlen(n[i]) / 2; j++) {
                    temp = n[i][strlen(n[i]) - j - 1];
                    n[i][strlen(n[i]) - j - 1] = n[i][j];
                    n[i][j] = temp;
                }
                printf("%s\n", n[i]);
            }
            break;

        case 'e':

            if (onE == 0) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < strlen(n[i]); j++) {
                        if (j % 5 == 3) {
                            memmove(n[i] + j + 2, n[i] + j, strlen(n[i]));
                            n[i][j] = '@';
                            n[i][j + 1] = '@';
                        }
                    }
                    printf("%s\n", n[i]);
                }
                onE = 1;
                break;
            }

            else if (onE == 1) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < strlen(n[i]); j++) {
                        if (n[i][j] == '@') {
                            memmove(n[i] + j, n[i] + j + 2, strlen(n[i]));
                        }
                    }
                    printf("%s\n", n[i]);
                }
                onE = 0;
                break;
            }

		case 'f':
			if (onF == 0) {
				for (int i = 0; i < 10; i++) {
					char *save = strtok(s[i], " ");
					while (save != NULL) {
						for (int j = strlen(n[i]); j > -1; j--) {
							if (save[j] == '\n') continue;
							printf("%c", save[j]);
						}
						printf(" ");
						save = strtok(NULL, " ");
					}
					printf("\n");
				}
				onF = 1;
				break;
			}

			else if (onF == 1) {
				for (int i = 0; i < 10; i++) {
					n[i] = s[i];
					printf("%s\n", n[i]);
				}
				onF = 0;
				break;
			}
			break;

        case 'g':
            printf("바꿀 문자를 선택해 주세요 : ");
            scanf(" %c", &select);
            printf("어떤 문자로 바꾸시겠습니까? : ");
            scanf(" %c", &change);

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < strlen(n[i]); j++) {
                    if (n[i][j] == select) {
                        n[i][j] = change;
                    }
                }
                printf("%s\n", n[i]);
            }
            break;

        case 'h':
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < strlen(n[i]); j++) {
                    if (n[i][j] == n[i][strlen(n[i]) - 1 - j]) {
                        printf("%c", n[i][j]);
                    }

                    else {
                        printf("null\n");
                        break;
                    }
                }
            }
            break;
        }
    }


}

void printmenu()
{
	printf("\n\n메뉴 목록입니다.\n");
	printf("d : 문장 전체를 뒤집기\n");
	printf("e : 동일한 간격에 특수문자 삽입\n");
	printf("f : 띄어쓰기를 기준으로 단어 뒤집기\n");
	printf("g : 특정 문자를 다른 문자로 바꾸기\n");
	printf("h : 앞뒤에서 읽었을 때 어디까지 같은 문자인지 출력하기\n");
	printf("q : 프로그램 종료\n");
}


#endif