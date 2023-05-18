#include <stdio.h>
#include <stdlib.h>

// A job has a start time and finish time.
typedef struct Activitiy {
	int start, finish;
} Act;

void printMaxActivities(Act givenActs[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; ++j){
            if (givenActs[j].finish > givenActs[j + 1].finish){
                Act temp = givenActs[j];
                givenActs[j] = givenActs[j + 1];
                givenActs[j + 1] = temp;
            }
        }
    }
	printf("Following activities are selected :\n");
	i=0;
	printf("(%d, %d)", givenActs[i].start, givenActs[i].finish);
	for (j = 1; j < n; j++)
	{
		if (givenActs[j].start >= givenActs[i].finish)
        {
			printf(", (%d, %d)",givenActs[j].start, givenActs[j].finish);
			i = j;
		}
	}
}

int main()
{
	Act givenActs[]={{1,3},{2,5},{3,4},{4,7},{7,10},{8,9},{9,11},{9,13},{11,12},{12,14}};
	//1,3,4,6,7,9,10 th Acts
	//1,3,4,8,9,11,12 --starting time
	int n = sizeof(givenActs) / sizeof(givenActs[0]);
	printMaxActivities(givenActs, n);
	return 0;
}
