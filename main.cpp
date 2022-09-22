/******************************
*
*    Copyright (C) 2021 VTX
*    File name: %{Cpp:License:FileName}
*    Author: phuongdm10@viettel.com.vn
*    Created: 8/10/2021
*
*******************************/
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "action/actionprovider.h"
#include "commonstore.h"
#include "flux/dispatcher.h"

int check_prime(int a) {
	int c;

	for ( c = 2 ; c <= a - 1 ; c++ ) {
		if ( a%c == 0 )
			return 0;
	}
	if ( c == a )
		return 1;
}

/*
Check Armstrong number using function
Link: http://www.programmingsimplified.com/c-program-find-armstrong-number
*/
int check_armstrong(long long);
long long power(int, int);

int check_armstrong(long long n) {
	long long sum = 0, temp;
	int remainder, digits = 0;

	temp = n;

	while (temp != 0) {
		digits++;
		temp = temp/10;
	}

	temp = n;

	while (temp != 0) {
		remainder = temp%10;
		sum = sum + power(remainder, digits);
		temp = temp/10;
	}

	if (n == sum)
		return 1;
	else
		return 0;
}

long long power(int n, int r) {
	int c;
	long long p = 1;

	for (c = 1; c <= r; c++)
		p = p*n;

	return p;
}
/*
Print Floyd's triangle using recursion
Link: http://www.programmingsimplified.com/c-program-print-floyd-triangle
*/
void print_floyd(int n) {
	static int row = 1, c = 1;
	int d;

	if (n <= 0)
		return;

	for (d = 1; d <= row; ++d)
		printf("%d ", c++);

	printf("\n");
	row++;

	print_floyd(--n);
}

/*
Find minimum element in array
Link: http://www.programmingsimplified.com/c/source-code/c-program-find-minimum-element-in-array
*/
int find_minimum(int a[], int n) {
	int c, min, index;

	min = a[0];
	index = 0;

	for (c = 1; c < n; c++) {
		if (a[c] < min) {
			index = c;
			min = a[c];
		}
	}

	return index;
}




/*
Reverse an array
Link: http://www.programmingsimplified.com/c-program-reverse-array
*/
void reverse_array(int *pointer, int n) {
	int *s, c, d;

	s = (int*)malloc(sizeof(int)*n);

	if( s == NULL )
		exit(EXIT_FAILURE);
	d = 0 ;
	for ( c = n - 1; c >= 0 ; c-- ) {
		*(s+d) = *(pointer+c);
		d++;
	}

	for ( c = 0 ; c < n ; c++ )
		*(pointer+c) = *(s+c);

	free(s);
}

/*
Concatenate strings without strcat function
Link: http://www.programmingsimplified.com/c-program-concatenate-strings
*/
void concatenate(char p[], char q[]) {
	int c, d;
	c = 0;

	while (p[c] != '\0') {
		c++;
	}

	d = 0;

	while (q[d] != '\0') {
		p[c] = q[d];
		d++;
		c++;
	}

	p[c] = '\0';
}

/*
Concatenate strings using pointers without strcat function
Link: http://www.programmingsimplified.com/c-program-concatenate-strings
*/
void concatenate_string(char *original, char *add) {
	while(*original)
		original++;

	while(*add) {
		*original = *add;
		add++;
		original++;
	}
	*original = '\0';
}

/*
Reverse a string using pointers
Link: http://www.programmingsimplified.com/c-program-reverse-string
*/
int string_length1(char *pointer) {
	int c = 0;

	while( *(pointer + c) != '\0' )
		c++;

	return c;
}


/*
Reverse a string using recursion
Link: http://www.programmingsimplified.com/c-program-reverse-string
*/
void reverse2(char *x, int begin, int end) {
	char c;

	if (begin >= end)
		return;

	c          = *(x+begin);
	*(x+begin) = *(x+end);
	*(x+end)   = c;

	reverse2(x, ++begin, --end);
}

/*
Link: http://www.programmingsimplified.com/c-program-find-palindrome
*/
int string_length(char *string) {
	int length = 0;

	while(*string) {
		length++;
		string++;
	}

	return length;
}
/*
Link: http://www.programmingsimplified.com/c-program-find-palindrome
*/
void copy_string(char *target, char *source) {
	while(*source) {
		*target = *source;
		source++;
		target++;
	}
	*target = '\0';
}
/*
Link: http://www.programmingsimplified.com/c-program-find-palindrome
*/
int compare_string(char *first, char *second) {
	while(*first==*second) {
		if ( *first == '\0' || *second == '\0' )
			break;

		first++;
		second++;
	}
	if( *first == '\0' && *second == '\0' )
		return 0;
	else
		return -1;
}

/*
Delete vowels from a string
Link: http://www.programmingsimplified.com/c/source-code/c-program-remove-vowels-from-string
*/
int check_vowel(char a) {
	if ( a >= 'A' && a <= 'Z' )
		a = a + 'a' - 'A';

	if ( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return 1;

	return 0;
}

/*
Check subsequence
Link: http://www.programmingsimplified.com/c/source-code/c-program-check-subsequence
*/
int check_subsequence (char a[], char b[]) {
	int c, d;

	c = 0;
	d = 0;

	while (a[c] != '\0') {
		while ((a[c] != b[d]) && b[d] != '\0') {
			d++;
		}
		if (b[d] == '\0')
			break;
		d++;
		c++;
	}
	if (a[c] == '\0')
		return 1;
	else
		return 0;
}

/*
Find frequency of characters in a string
Link: http://www.programmingsimplified.com/c-program-find-characters-frequency
*/
void find_frequency(char s[], int count[]) {
	int c = 0;

	while (s[c] != '\0') {
		if (s[c] >= 'a' && s[c] <= 'z' )
			count[s[c]-'a']++;
		c++;
	}
}

/*
Check whether two strings are anagrams or not,
Link: http://www.programmingsimplified.com/c/source-code/c-anagram-programcheck_subsequence
*/
int check_anagram(char a[], char b[]) {
	int first[26], second[26], c = 0;
	first[20] = 0;
	second[26]=0;
	while (a[c] != '\0') {
		first[a[c]-'a']++;
		c++;
	}

	c = 0;

	while (b[c] != '\0') {
		second[b[c]-'a']++;
		c++;
	}

	for (c = 0; c < 26; c++) {
		if (first[c] != second[c])
			return 0;
	}

	return 1;
}


// Function to find the largest number
// link: https://www.geeksforgeeks.org/find-largest-two-distinct-numbers-without-using-conditional-statements-operators/
int largestNum(int a, int b)
{
    return a * (bool)(a / b) + b * (bool)(b / a);
}

// function to find frequency of digit 
// in a number
// link: https://www.geeksforgeeks.org/find-the-frequency-of-a-digit-in-a-number/
int frequencyDigits(int n, int d)
{   
    // Counter variable to store
    // the frequency
    int c = 0;
     
    // iterate till number reduces to zero
    while (n > 0) {
         
        // check for equality
        if (n % 10 == d)
            c++;
        // reduce the number
        n = n / 10;
    }
     
    return c;
}

// Function that returns the length
// of the longest decreasing subsequence
// link: https://www.geeksforgeeks.org/longest-decreasing-subsequence/
int lds(int arr[], int n)
{
    int lds[n];
    int i, j, max = 0;
 
    // Initialize LDS with 1 for all index
    // The minimum LDS starting with any
    // element is always 1
    for (i = 0; i < n; i++)
        lds[i] = 1;
 
    // Compute LDS from every index
    // in bottom up manner
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
 
    // Select the maximum 
    // of all the LDS values
    for (i = 0; i < n; i++)
        if (max < lds[i])
            max = lds[i];
 
    // returns the length of the LDS
    return max;
}


// Function to find priority of given
// operator.
// link: https://www.geeksforgeeks.org/infix-to-prefix-conversion-using-two-stacks/
int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

// link: https://www.geeksforgeeks.org/number-of-distinct-prime-factors-of-first-n-natural-numbers/
// C++ program to find number of  distinct prime factors
// for all number in range [1, N]
void printDistinctPFs(int n)
{
   // array to store the number of distinct primes
    long long factorCount[n + 1];
 
    // true if index 'i' is a prime
    bool prime[n + 1];
 
    // initializing the number of factors to 0 and
    for (int i = 0; i <= n; i++) {
        factorCount[i] = 0;
        prime[i] = true;  // Used in Sieve
    }
 
    for (int i = 2; i <= n; i++) {
  
        // condition works only when 'i' is prime, 
        // hence for factors of all prime number, 
        // the prime status is changed to false
        if (prime[i] == true) { 
             
            // Number is prime
            factorCount[i] = 1; 
             
            // number of factor of a prime number is 1
            for (int j = i * 2; j <= n; j += i) {
 
                // incrementing factorCount all 
                // the factors of i
                factorCount[j]++; 
 
                // and changing prime status to false
                prime[j] = false; 
            }
        }
    }
}


// Returns the minumum steps required to make an array of N
// elements equal, where the first array element equals M
// link: https://www.geeksforgeeks.org/make-array-elements-equal-in-minimum-steps/
int steps(int N, int M)
{
    // Corner Case 1: When N = 1
    if (N == 1)
        return 0;
 
    // Corner Case 2: When N = 2
    else if (N == 2) // corner case 2
        return M;
 
    return 2 * M + (N - 3);
}

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterSingletonType<ActionProvider>("Flux", 1, 0, "ActionProvider",
                                             [](QQmlEngine * engine, QJSEngine * scriptEngine) -> QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        QQmlEngine::setObjectOwnership(ActionProvider::getInstance(), QQmlEngine::CppOwnership);
        return ActionProvider::getInstance();
    });
    qmlRegisterSingletonType<CommonStore>("Flux", 1, 0, "CommonStore",
                                          [](QQmlEngine * engine, QJSEngine * scriptEngine) -> QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        QQmlEngine::setObjectOwnership(&CommonStore::getInstance(), QQmlEngine::CppOwnership);
        return &CommonStore::getInstance();
    });
    vtx::flux::Dispatcher::instance().registerStore(QSharedPointer<vtx::flux::Store>(&CommonStore::getInstance(), [](vtx::flux::Store*) {}));
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject * obj, const QUrl & objUrl)
    {
        if (!obj && url == objUrl)
        {
            QCoreApplication::exit(-1);
        }
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
