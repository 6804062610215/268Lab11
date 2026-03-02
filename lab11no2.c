#include <stdio.h>
#define NO_SCORE 5

typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;

void readStudentData(Student *);
void findTotalScore(Student *);
float findAverage(Student);
void findLessThanTen(Student);

int main() {
    Student std;
    int amount = 2, i;
    float avg;

	for(i = 0; i < amount; i++){
		readStudentData(&std);
    	findTotalScore(&std);
	}

    avg = findAverage(std);
    printf("\n\nAverage score is %.2f", avg);

    findLessThanTen(std);

    return 0;
}

void readStudentData(Student *pStd) {
    int i;
    
    printf("Enter student data\n");

    printf("\tName : ");
    scanf("%s", pStd->name);

    printf("\tSurname : ");
    scanf("%s", pStd->surname);
	
    for (i = 0; i < NO_SCORE; i++) {
        printf("\tScore %d : ", i + 1);
        scanf("%d", &pStd->score[i]);
    }
}

void findTotalScore(Student *pStd) {
    int i;
    mkdir("lab11");
    mkdir("lab11\\no2");
    
    FILE *fp;
	fp = fopen("lab11\\no2\\std10.dat", "a");

    //printf("\n\nPrint student data");
    //printf("\n\t%s %s got score ", pStd->name, pStd->surname);
	fprintf(fp, "%s %s got score ", pStd->name, pStd->surname);
    pStd->total = 0.0;

    for (i = 0; i < NO_SCORE; i++) {
        fprintf(fp, "%6d", pStd->score[i]);
        pStd->total += pStd->score[i];
    }fprintf(fp, "\n");
	
    fclose(fp);
}

float findAverage(Student s) {
    return s.total / NO_SCORE;
}

void findLessThanTen(Student s) {
    int i, count = 0;

    printf("\n\nScore less than 10");

    for (i = 0; i < NO_SCORE; i++) {
        if (s.score[i] < 10) {
            printf("\n\tTest no.%d - %d", i + 1, s.score[i]);
            count++;
        }
    }

    if (count == 0) {
        printf(" -> None");
    }
}
