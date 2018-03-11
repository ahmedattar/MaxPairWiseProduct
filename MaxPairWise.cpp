// pairwise.cpp : Defines the entry point for the console application.
//

#include <iostream> //the library, make me able to do input / output operations
#include <vector> // here i used " vector " data structure
#include <algorithm>
// I defined " algorithm" library to be able of using " max () " function
using namespace std;
/* the next function : i used to get the maximum 2 elements of the vector elements and
 then return the product of them ,
it uses the naive algorithm at all : it's O(n^2) notation : it is bad for us */
int MaxPairWise(const vector <int>& numbers) {
	int product = 0; // defining the " product " variable with initial value of 0
	int count = numbers.size(); // passing the size of vector to integer varaiable called "count"
	// for loop to get the maximum product of 2 elements of the vector
	for (int i = 0; i < count; i++) {
		for (int j = i+1 ; j < count; j++) {
			product = max(product, numbers [i] * numbers[j]);
		}
	}
	return product; // returning the product after looping the vector


}
/* the next function : i used to get the maximum 2 elements of the vector elements and
then return the product of them ,
it uses modified algorithm ( better than the previous function) : it's O(2n) notation :
 because it loops the elements twice but in seperated ways, the algorithm is better for us than the last algorithm ,
 but we still can do better */
int MaxPairWiseFast(const vector <int>& numbers) {
	//defining the " product " variable with initial value of 0
	//defining the " first","second"  variables with initial value of 0,to get the fist,second maximum values respectively
	int first=0,second = 0, product=0;
	int count = numbers.size(); // passing the size of vector to integer varaiable called "count"
	// for loop to get the first maximum value of the vector
	for (int i = 0; i < count; i++) {
		first = max(first, numbers[i]);
	}
	// for loop to get the second maximum value of the vector
	for (int j = 0; j < count; j++) {
		if (numbers[j]!=first){
		second = max(second, numbers[j]);
	}

	}
	product = first*second;
	return product; //returning the product after looping the vector


}
/* the next function : i used to get the maixmum 2 elements of the vector elements and
then return the product of them ,
it uses modified algorithm ( the best without sorting ) : it's O(n) notation :
because it loops the elements one time, the algorithm is better for us than the  2 last algorithms ,
but we still can do better if we use sorting */
int MaxPairWiseTheFastest(const vector <int>& numbers) {
	//defining the " product " variable with initial value of 0
	//defining the " first","second"  variables with initial value of 0,to get the fist,second maximum values respectively
	int first = 0, second = 0, product = 0;
	int n = numbers.size();
	// one for loop to get the first and the second maximum values of the vector
	for (int i = 0; i < n; i++) {
		if (numbers[i] > first) {
			second = first;
			first = numbers[i];
		}
		else if ((numbers[i] > second) && (numbers[i] < first)) {
			second= numbers[i]; // passing the size of vector to integer varaiable called "count"
		}
	}
	product = first*second;
	return product; //returning the product after looping the vector


}
/* the next function : i used to get the maixmum 3 elements of the vector elements and
then return the product of them ,
it uses modified algorithm ( the best without sorting ) : it's O(n) notation :
because it loops the elements one time, the algorithm is better for us,
but we still can do better if we use sorting */
int MaxThreeWiseTheFastestOf3objects(const vector <int>& numbers) {
	//defining the " product " variable with initial value of 0
	//defining the " first","second","third" variables with initial value of 0,to get the fist,second, third maximum values respectively
	int first = 0, second = 0, third=0 , product = 0;
	int n = numbers.size();
	// one for loop to get the first and the second, third maximum values of the vector
	for (int i = 0; i < n; i++) {
		if (numbers[i] > first) {
			third = second;
			second = first;
			first = numbers[i];
		}
		else if ((numbers[i] > second) && (numbers[i] < first)) {
			third = second;
			second = numbers[i];
		}
		else if ((numbers[i] > third) && (numbers[i] < first) && ((numbers[i] < second))) {
			third = numbers[i];

		}
	}
	product = first*second*third;
	return product; //returning the product after looping the vector


}



int main()
{

	int count; // here i define integer variabe " count " to catch the size of vector in it
	cout << "enter the count of numbers , you want" << endl;
	cin >> count;
	vector <int> numbers(count); // i define vector called " numbers " with size of : " count"
	for (int i = 0; i < count; i++) {
		cout << " enter the " << i + 1 << " element "<<endl;
		cin >> numbers[i];

	}
	cout << " the max pairwise of 2 elements of the vector using the naive way is " << MaxPairWise(numbers) << endl;
	cout << " the max pairwise of 2 elements of the vector using the modified way is " << MaxPairWiseFast(numbers) << endl;
	cout << " the max pairwise of 2 elements of the vector using the fastest way is " << MaxPairWiseTheFastest(numbers) << endl;
	cout << " the max pairwise of 3 elements of the vector using the fastest way is " << MaxThreeWiseTheFastestOf3objects(numbers) << endl;

	return 0;
}


