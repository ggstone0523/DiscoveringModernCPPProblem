int main() 
{
	int a[10];
	int b[10];
	int c[10];

	int length = 10;
	int* dynamicA = new int[length];
	int* dynamicB = new int[length];
	int* dynamicC = new int[length];

	delete[] dynamicA; // dynamicA is deallocated correctly
	delete dynamicB;   // dynamicB is deallocated incorrectly
	// dynamicC has not been deallocated
	
	return 0;
}
