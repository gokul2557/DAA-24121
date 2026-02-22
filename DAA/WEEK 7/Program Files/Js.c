//CH.SC.U4CSE24121
/* Job Sequencing using Greedy Method */

#include <stdio.h>
#define LIMIT 100

struct Task
{
    int taskId;
    int gain;
    int dueTime;
};

void sortTasks(struct Task taskList[], int count)
{
    int x, y;
    struct Task swapTemp;

    for(x = 0; x < count - 1; x++)
    {
        for(y = 0; y < count - x - 1; y++)
        {
            if(taskList[y].gain < taskList[y + 1].gain)
            {
                swapTemp = taskList[y];
                taskList[y] = taskList[y + 1];
                taskList[y + 1] = swapTemp;
            }
        }
    }
}

int getMaxDeadline(struct Task taskList[], int count)
{
    int index, maxDeadline = taskList[0].dueTime;

    for(index = 1; index < count; index++)
    {
        if(taskList[index].dueTime > maxDeadline)
        {
            maxDeadline = taskList[index].dueTime;
        }
    }
    return maxDeadline;
}

int main()
{

    struct Task taskList[LIMIT];
    int count, i, k;

    printf("Enter number of tasks: ");
    scanf("%d", &count);

    printf("Enter profits:\n");
    for(i = 0; i < count; i++)
    {
        taskList[i].taskId = i + 1;
        scanf("%d", &taskList[i].gain);
    }

    printf("Enter deadlines:\n");
    for(i = 0; i < count; i++)
    {
        scanf("%d", &taskList[i].dueTime);
    }

    sortTasks(taskList, count);

    int lastSlot = getMaxDeadline(taskList, count);
    int schedule[LIMIT];

    for(i = 1; i <= lastSlot; i++)
    {
        schedule[i] = -1;
    }

    int maxProfit = 0;

    for(i = 0; i < count; i++)
    {
        for(k = taskList[i].dueTime; k >= 1; k--)
        {
            if(schedule[k] == -1)
            {
                schedule[k] = taskList[i].taskId;
                maxProfit += taskList[i].gain;
                break;
            }
        }
    }

    printf("\nSlot Arrangement:\n");
    for(i = 1; i <= lastSlot; i++)
    {
        if(schedule[i] == -1)
            printf("Slot %d : _\n", i);
        else
            printf("Slot %d : T%d\n", i, schedule[i]);
    }

    printf("\nMaximum Profit = %d\n", maxProfit);

    return 0;
}

