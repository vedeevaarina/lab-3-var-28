#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int is_nat(const char *str) {
    if (str[0] == '\0' || str[0] == '0' || str[0] == '-') {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i = i+1) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_int(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
        start += 1;
    }
    if (str[start] == '\0') {
        return 0;
    }
    for (int i = start; str[i] != '\0'; i = i + 1) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_flt(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
        start += 1;
    }
    if (str[start] == '\0') {
        return 0;
    }
    int dots = 0;
    int digits = 0;
    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dots++;
            if (dots > 1) return 0;
        } else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        } else {
            return 0;
        }
    }
    if (digits == 0) return 0;
    return 1;
}

int main() {
    char *sN = NULL;
    char *sM = NULL;
    int N, M;

    while (1) {
        printf("Введите N: ");
        if (scanf("%ms", &sN) != 1) {
            printf("Ошибка чтения.\n");
            continue;
        }
        if (is_nat(sN)) {
            N = atoi(sN);
            break;
        } else {
            printf("Число должно быть натуральным!\n");
        }
    }

    while (1) {
        printf("Введите M: ");
        if (scanf("%ms", &sM) != 1) {
            printf("Ошибка чтения.\n");
            continue;
        }
        if (is_nat(sM)) {
            M = atoi(sM);
            break;
        } else {
            printf("Число должно быть натуральным!\n");
        }
    }
    
    float *A = malloc(N * M * sizeof(float));
    float *B = malloc(N * sizeof(float));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char *sElem = NULL;
            float val;
         
            while (1) {
                printf("Введите элемент [%i][%i]: ", i, j);
                if (scanf("%ms", &sElem) != 1) {
                    printf("Ошибка чтения.\n");
                    continue;
                }
                if (is_flt(sElem)) {
                    val = atof(sElem);
                    break;
                } else {
                    printf("Некорректный ввод!\n");
                }
            }
            A[i*M + j] = val;
        }
    }
   
    printf("\nМатрица A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("| %f |", A[i*M + j]);
        }
        printf("\n");
    }
    
    printf("\nМассив B (произведения строк):\n");
    for (int i = 0; i < N; i++) {
        B[i] = 1.0; 
        for (int j = 0; j < M; j++) {
            B[i] *= A[i*M + j];
        }
        printf("B[%d] = %f\n", i, B[i]);
    }

    double S = 0.0;
    for (int i = 0; i < N; i++) {
        S += 4.2 * (1.0 - B[i]) * cos(B[i]);
    }

    printf("\nСумма S = %lf\n", S);

    return 0;
}
