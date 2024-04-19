#include <stdio.h>
#include <stdlib.h>

int greatestCommonFactor(void);
void printFibonacci(void);

struct repetitions{
    char ch;
    int rep;
};
void printChars(struct repetitions *s, FILE *outfile);
void getRepetitions(char *infile, char *outfile, struct repetitions *s);
void decompress(char *infile, char *outfile);

int main() {
    //int gcf = greatestCommonFactor();
    //printf("GCF = %d", gcf);

    //printFibonacci();

    struct repetitions s;
    getRepetitions("sources.txt","compressed.txt",&s);
    decompress("compressed.txt", "decompressed.txt");

    return 0;
}

//Exercise 1
int greatestCommonFactor(void){
    int num1, num2, gcf;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    if (num2 > num1) {
        int x = num1;
        num1 = num2;
        num2 = x;
    }
    while (1){
        gcf = num1%num2;
        num1 = num2;
        num2 = gcf;
        if (num1 % num2 == 0){
            break;
        }
    }
    return gcf;
}

//Exercise 2
void printFibonacci(void){
    int num1 = 0, num2= 1, n;
    printf("How many terms of the fibonacci sequence you want to print: ");
    scanf("%d", &n);
    if(n<=1){
        printf("%d", num1);
        exit(EXIT_SUCCESS);
    }
    else{
        printf("%d\n%d\n",num1,num2);
    }
    for(int i = 0; i<n; i++){
        int x = num2;
        num2 = num2 + num1;
        num1 = x;
        printf("%d\n",num2);
    }
}

//EXERCISE 3
void getRepetitions(char *infile, char *outfile, struct repetitions *s){
    FILE *fp = fopen(infile, "r");
    if (!fp){
        fprintf(stdout, "Problem with input file!");
        exit(EXIT_FAILURE);
    }

    FILE *f_out = fopen(outfile, "w");
    if (!f_out){
        fprintf(stdout, "Problem with output file!");
        exit(EXIT_FAILURE);
    }
    char curr= fgetc(fp), next;
    s->rep = 0;
    while (!feof(fp)){
        next = fgetc(fp);
        if (curr == next&& s->rep<9){
            s->ch=curr;
            s->rep++;
        }
        else if(s->rep == 9){
            printChars(s, f_out);
        }
        else{
            if(s->rep>0){
                printChars(s, f_out);
            }
            else{
                fprintf(f_out,"%c", curr);
            }
        }
        curr=next;
    }
    fclose(fp);
    fclose(f_out);
}

void printChars(struct repetitions *s, FILE *outfile){
    if (s->rep > 1){
        fprintf(outfile, "%c!%d", s->ch, s->rep);
    }
    else{
        for (int i = 0; i <= s->rep; i++){
            fprintf(outfile, "%c", s->ch);
        }
    }
    s->rep = 0;

}

void decompress(char *infile, char *outfile){
    struct repetitions dc;
    FILE *fp = fopen(infile, "r");
    if (!infile){
        fprintf(stdout, "Problem with input file!");
    }
    FILE *f_out = fopen(outfile, "w");
    if (!f_out){
        fprintf(stdout, "Problem with output file!");
    }
    char curr= fgetc(fp);
    while (!feof(fp)){
        char next = fgetc(fp);
        if(next == EOF){
            break;
        }
        if (next == '!'){
            next = fgetc(fp);
            dc.ch=curr;
            dc.rep = next -'0';
            for (int i = 0; i <= dc.rep; i++) {
                fprintf(f_out, "%c", dc.ch);
            }
            dc.rep = 0;
            curr = fgetc(fp);
        }
        else{
            fprintf(f_out,"%c", curr);
            curr = next;
        }
    }
    fclose(fp);
}

