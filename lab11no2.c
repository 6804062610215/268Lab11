#include <stdio.h>

#define NO_SCORE 5
#define NO_STUDENT 10

typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;

void readStudentData(Student s[]);
void writeFile(Student s[]);
void readFile(Student s[]);
void findTotalScore(Student *pStd);
float findAverage(Student s);
void findLessThanTen(Student s);

int main() {
    Student std[NO_STUDENT];
    int i;
    float avg;

    readStudentData(std);
    writeFile(std);

    printf("\n\n--- Read data from file ---\n");
    readFile(std);

    for(i=0;i<NO_STUDENT;i++){
        findTotalScore(&std[i]);
        avg = findAverage(std[i]);
        printf("\nAverage score = %.2f", avg);
        findLessThanTen(std[i]);
        printf("\n--------------------------\n");
    }

    return 0;
}

void readStudentData(Student s[]) {
    int i,j;

    for(i=0;i<NO_STUDENT;i++){
        printf("\nStudent %d\n",i+1);

        printf("Name : ");
        scanf("%s", s[i].name);

        printf("Surname : ");
        scanf("%s", s[i].surname);

        for(j=0;j<NO_SCORE;j++){
            printf("Score %d : ",j+1);
            scanf("%d",&s[i].score[j]);
        }
    }
}

void writeFile(Student s[]){
    FILE *fp;
    fp = fopen("Wlab11no2lstd10.dat","wb");

    fwrite(s,sizeof(Student),NO_STUDENT,fp);

    fclose(fp);
}

void readFile(Student s[]){
    FILE *fp;
    fp = fopen("Wlab11no2lstd10.dat","rb");

    fread(s,sizeof(Student),NO_STUDENT,fp);

    fclose(fp);
}

void findTotalScore(Student *pStd){
    int i;
    pStd->total = 0;

    printf("\n%s %s score :",pStd->name,pStd->surname);

    for(i=0;i<NO_SCORE;i++){
        printf(" %d",pStd->score[i]);
        pStd->total += pStd->score[i];
    }

    printf("\nTotal = %.2f",pStd->total);
}

float findAverage(Student s){
    return s.total/NO_SCORE;
}

void findLessThanTen(Student s){
    int i,count=0;

    printf("\nScore < 10");

    for(i=0;i<NO_SCORE;i++){
        if(s.score[i] < 10){
            printf("\nTest %d = %d",i+1,s.score[i]);
            count++;
        }
    }

    if(count==0)
        printf(" : None");
}
