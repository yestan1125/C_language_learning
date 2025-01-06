#include <stdio.h>

typedef struct {
    int id;
    int chinese;
    int math;
    int english;
} Student;

void swap(Student *a, Student *b) {//交换两个学生的信息
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortStudents(Student *student, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            int total1 = student[j].chinese + student[j].math + student[j].english;//计算总分
            int total2 = student[j+1].chinese + student[j+1].math + student[j+1].english;//计算总分
            if(total1 < total2){
                swap(&student[j], &student[j+1]);
            }
            else if(total1 == total2){
                if(student[j].chinese < student[j+1].chinese){
                    swap(&student[j], &student[j+1]);
                }
                }
            else if(student[j].chinese == student[j+1].chinese){
                    if(student[j].math < student[j+1].math){
                        swap(&student[j], &student[j+1]);
                    }
                }
            else if(student[j].math == student[j+1].math){
                if(student[j].english < student[j+1].english){
                    swap(&student[j], &student[j+1]);
                }
                }
            else if(student[j].english == student[j+1].english){
                if(student[j].id > student[j+1].id){
                    swap(&student[j], &student[j+1]);
                }
            }
        }
    }
}

int main(){
    int m,n;
    scanf("%d %d", &m, &n);
    Student *student = (Student *)malloc(m * sizeof(Student));
    if(student == NULL){
        printf("malloc failed\n");
        return -1;
    }
    for(int i=0; i<m; i++){
        student[i].id = i+1;
    }
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &student[i].chinese, &student[i].math, &student[i].english);
    }
    sortStudents(student, m);
    int flag = 0;
    for(int i=0; i<n; i++){
        if(flag == 0){
            printf("%d", student[i].id);
            flag = 1;
        }
        else{
            printf(" %d", student[i].id);
        }
    }
    return 0;
}
