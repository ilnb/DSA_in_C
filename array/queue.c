#include <stdio.h>
#define MAX 20

typedef struct {
  int arr[MAX];
  int front;
  int rear;
} queue;

void menu();
void enqueue(queue *, int);
int dequeue(queue *);
void display(queue);
int isFull(queue);
int isEmpty(queue);

int main(void) {
  queue q = {0};
  while (1) {
    menu();
    printf("Enter an appropriate option: ");
    int option;
    scanf("%d", &option);
    switch (option) {
      case 1: {
        printf("Enter the value to be queued: ");
        int val;
        scanf("%d", &val);
        enqueue(&q, val);
        printf("The updated queue:\n");
        display(q);
        break;
      }
      case 2: {
        int i = dequeue(&q);
        if (i != -273) {
          printf("The value dequeued is %d.\n", i);
          printf("The updated queue:\n");
          display(q);
        }
        break;
      }
      case 3:
        display(q);
      case 4:
        break;
      default:
        printf("Invalid option.\n");
    }
    if (option == 4)
      break;
  }
  return 0;
}

void menu() {
  printf("1. Inqueue\n");
  printf("2. Dequeue\n");
  printf("3. Display\n");
  printf("4. Exit\n");
  printf("What do you want to do? ");
}

void enqueue(queue *q, int val) {
  if (isFull(*q))
    printf("The queue is full");
  else {
    q->arr[q->rear] = val;
    q->rear = (q->rear + 1) % MAX;
  }
}

int dequeue(queue *q) {
  if (isEmpty(*q)) {
    printf("The queue is empty.\n");
    return -273;
  } else {
    int val = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    return val;
  }
}

void display(queue q) {
  if (isEmpty(q)) {
    printf("The queue is empty.\n");
    return;
  }
  int i = q.front;
  while (i != q.rear) {
    printf("%d ", q.arr[i]);
    i = (i + 1) % MAX;
  }
  printf("\n");
}

int isFull(queue q) { return (q.rear + 1) % MAX == q.front; }

int isEmpty(queue q) { return q.front == q.rear; }
