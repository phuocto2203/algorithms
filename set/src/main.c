#include <stdio.h>

#include "set.h"

int main() {
	struct set_t *A = new_set("0");
	struct set_t *B = new_set("4");
	struct set_t *C = new_set("0");
	struct set_t *un = NULL, *in = NULL, *df = NULL;
	
	
	// Add 1,2,3,4 to A
	set_add(A, "1");
	set_add(A, "2");
	set_add(A, "3");
	set_add(A, "4");
	
	// Add 4,5,6,7 to B
	set_add(B, "0");
	set_add(B, "7");
	set_add(B, "4");
	set_add(B, "5");
	set_add(B, "6");
	set_add(B, "7");
	
	// Add 1,2,3,4 to C
	set_add(C, "1");
	set_add(C, "2");
	set_add(C, "3");
	set_add(C, "4");
	
	// Compute union, intersection, difference, subset
	un = set_union(A, B);
	in = set_intersection(A, B);
	df = set_difference(A, B);
	
	// Print A, B, C, un, and in
	printf("A: ");
	set_print(A);
	printf("B: ");
	set_print(B);
	printf("C: ");
	set_print(C);
	printf("A union B: ");
	set_print(un);
	printf("A intersect B: ");
	set_print(in);
	printf("A in B: ");
	set_print(df);
	
	// Subset testing
	if(set_subset(A, B)) {
		printf("A is a subset of B\n");
	} else {
		printf("A is not a subset of B\n");
	}
	
	if(set_subset(A, C)) {
		printf("A is a subset of C\n");
	} else {
		printf("A is not a subset of C\n");
	}
	
	// Equivilance testing
	if(set_equals(A, B)) {
		printf("A and B are equal\n");
	} else {
		printf("A and B are not equal\n");
	}
	
	if(set_equals(A, C)) {
		printf("A and C are equal\n");
	} else {
		printf("A and C are not equal\n");
	}
	
	// Free all sets
	free_set(A);
	free_set(B);
	free_set(C);
	free_set(un);
	free_set(in);
	free_set(df);

	return 0;
}
