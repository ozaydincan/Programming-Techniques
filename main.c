#include <stdio.h>
#include <stdlib.h>
#define PI 3.14


//Exercise 4

/*
float areaDiagonal(float d);
float areaSide(float s);
float areaRadius(float r);

int main() {
    char shape;
    printf("Enter Q for square, I for circle: ");
    scanf("%c", &shape);
    fflush(stdin);
    if (shape =='Q'){
        printf("Enter D to compute by diagonal, enter S to compute by side then enter the length: ");
        float a;
        char type;
        scanf("%c",&type);
        scanf("%f", &a);
        if (type=='D'){
            printf("The are of the square is %.1f", areaDiagonal(a));
        }
        else if(type =='S'){
            printf("The are of the square is %.1f", areaSide(a));
        }
    } else if (shape =='I'){
        float a;
        char type;
        fprintf(stdout, "Enter D to compute by diameter, enter R to compute by radius the enter the length: ");
        scanf("\n%c%f", &type, &a);
        if(type=='D'){
            printf("The area of the circle is %.1f", areaRadius(a/2));
        }else if(type =='R'){
            printf("The area of the circle is %.1f", areaRadius(a));
        }
        else{
            fprintf(stdout, "Wrong input!");
            exit(EXIT_FAILURE);
        }
    } else{
        fprintf(stdout, "Wrong input!");
        exit(EXIT_FAILURE);
    }
    return 0;
}

float areaDiagonal(float d){
    float A = (d*d)/2;
    return A;
};

float areaSide(float s){
    float A = (s*s);
    return A;
}


float areaRadius(float r){
    float A = PI *(r*r);
    return A;
}
*/


//Exercise 5

/*
struct elements {
    float op1, op2, result;
    char operand;
};

struct elements calculator(struct elements s);

int main(){
    struct elements s = calculator(s);
    printf("%c %.2f", s.operand, s.result);
    return 0;
}

struct elements calculator(struct elements s){
    printf("Enter the operation and enter the numbers as floating point numbers with spaces in between: " );
    s.operand = getchar();
    scanf(" %f %f",&s.op1, &s.op2);
    if (s.operand == '+'){
        s.result = s.op1 + s.op2;
    }
    else if (s.operand == '-'){
        s.result = s.op1 - s.op2;
    }
    else if (s.operand == '*'){
        s.result = s.op1 * s.op2;
    }
    else if (s.operand == '/'){
        s.result = s.op1 / s.op2;
    }
    else{
        printf("Wrong input");
        exit(EXIT_FAILURE);
    }
    return s;
}
*/

//Exercise 6

struct operations{
    float op1, op2;
    char operator;
};

void printToFile(struct operations *s, FILE *f_out);
void readOperations(struct operations *s, FILE *fp, FILE *f_out);

int main(void){
    struct operations s;
    FILE *fp, *f_out;
    fp = fopen("operations.txt", "r");
    if (!fp){
        printf("Input file couldn't be opened!");
        exit(EXIT_FAILURE);
    }

    f_out = fopen("results.txt", "w");
    if (!f_out){
        printf("Output file couldn't be opened!");
        exit(EXIT_FAILURE);
    }
    readOperations(&s,  fp, f_out);
    fclose(fp);
    fclose(f_out);
    return 0;
}

void readOperations(struct operations *s, FILE *fp, FILE *f_out){
    while (!feof(fp)){
        fscanf(fp,"%c %f %f\n", &s->operator, &s->op1, &s->op2);
        printToFile(s, f_out);
    }
}

void printToFile(struct operations *s, FILE *f_out){
    if (s->operator == '+'){
        fprintf(f_out,"%c %.2f\n", s->operator, s->op1 + s->op2);
    }
    else if(s->operator == '-'){
        fprintf(f_out,"%c %.2f\n", s->operator, s->op1 - s->op2);
    }
    else if (s->operator == '*'){
        fprintf(f_out,"%c %.2f\n", s->operator, s->op1 * s->op2);
    }
    else if(s->operator == '/'){
        fprintf(f_out,"%c %.2f\n", s->operator, s->op1 / s->op2);
    }
    else{
        printf("Wrong operator!");
    }

}
