#include "commonstore.h"

CommonStore::~CommonStore()
{
}

void CommonStore::process(const QSharedPointer<vtx::flux::Action>& action)
{
    switch (action->getType<ActionType>())
    {
        case ActionType::ActionStart:
            {
                mStateMachine.raise_ev_start();
                mStateMachine.runCycle();
                break;
            }

        case ActionType::ActionStop:
            {
                mStateMachine.raise_ev_stop();
                mStateMachine.runCycle();
                break;
            }

        case ActionType::ActionReset:
            {
                mStateMachine.raise_ev_reset();
                mStateMachine.runCycle();
                break;
            }

        default:
            break;
    }
}

void CommonStore::cbGotoIdleState()
{
    emit stateIdle();
}

void CommonStore::cbGotoStartState()
{
    emit stateStart();
}

void CommonStore::cbGotoStopState()
{
    emit stateStop();
}

int ArrayCmp(int n, unsigned char* t1, unsigned char* t2) {
	int i;
	for (i = 0; i < n; i++) {
		if (t1[i] > t2[i])
			return -1;
		else if (t1[i] < t2[i])
			return 1;
	}
	return 0;
}

/*
The recursive function
Link: http://www.programmingsimplified.com
*/
int Fibonacci(int n) {
	if ( n == 0 )
		return 0;
	else if ( n == 1 )
		return 1;
	else {
		int x = Fibonacci(n-1);
		int y =  Fibonacci(n-2);
		return x+y;
	}
}

/*
Find maximum element in array
Link: http://www.programmingsimplified.com/c/source-code/c-program-find-maximum-element-in-array
*/
int find_maximum(int a[], int n) {
	int c, max, index;

	max = a[0];
	index = 0;

	for (c = 1; c < n; c++) {
		if (a[c] > max) {
			index = c;
			max = a[c];
		}
	}

	return index;
}
/*
Add digits of number in c
Link: http://www.programmingsimplified.com/c/program/c-program-add-number-digits
*/
int add_digits(int n) {
	static int sum = 0;

	if (n == 0) {
		return 0;
	}
	sum = n%10 + add_digits(n/10);

	return sum;
}

/*
Reverse number using recursion
Link: http://www.programmingsimplified.com/c/source-code/c-program-reverse-number
*/
long reverse(long n) {
	static long r = 0;

	if (n == 0)
		return 0;

	r = r * 10;
	r = r + n % 10;
	reverse(n/10);
	return r;
}

/*

 diamond using recursion
Link: http://www.programmingsimplified.com/c/source-code/c-program-print-diamond-pattern
*/
void print (int r) {
	int c, space;
	int stars = -1;

	if (r <= 0)
		return;

	space = r - 1;
	stars += 2;

	for (c = 0; c < space; c++)
		printf(" ");

	for (c = 0; c < stars; c++)
		printf("*");

	printf("\n");
	print(--r);

	space = r + 1;
	stars -= 2;

	for (c = 0; c < space; c++)
		printf(" ");

	for (c = 0; c < stars; c++)
		printf("*");

	printf("\n");
}


CommonStore::CommonStore()
{
    mStateMachine.setDefaultSCI_OCB(this);
    mStateMachine.init();
    mStateMachine.enter();
}
