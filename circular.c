#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 5;
    int ch, rear = -1, front = -1;
    int queue[size], value;

    while (1)
    {
        printf("\nEnter choice 1.insert\t2.delete\t3.display\t4.exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if ((front == 0 && rear == size - 1) || (front == rear + 1))
            {
                printf("Queue is overflow\n");
            }
            else
            {
                if (front == -1)
                {
                    front = 0;
                }
                rear = (rear + 1) % size; // Update rear using modulo to make it circular
                printf("Enter the value: ");
                scanf("%d", &value);
                queue[rear] = value;
            }
            break;
        case 2:
            if (front == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("The element deleted is %d\n", queue[front]);
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front = (front + 1) % size; // Update front using modulo
                }
            }
            break;
        case 3:
            printf("Index no = value\n");
            if (front == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                int i = front;
                while (1)
                {
                    printf("%d = %d\n", i, queue[i]);
                    if (i == rear)
                        break;
                    i = (i + 1) % size; // Update index using modulo
                }
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
