#ifndef __STRMATCHING_H__
#define __STRMATCHING_H__

#include <string.h>

int BruteForceMatch(const char T[], const char P[]);

// Boyer-Moore Searching
void LastOccurenceFunc(const char P[], const char setOfChar[], int L[]);
int BoyerMooreMatch(const char T[], const char P[], const char setOfChar[]);

// KMP - Knuth-Morris-Pratt's
void FailureFunction(const char P[], int F[]);
int KMPMatch(const char T[], const char P[]);
#endif