#include "timer.h"
double timespec_diff(struct timespec *stop, struct timespec *start)
{
        double diff = difftime(stop->tv_sec, start->tv_sec);
	diff *= 1000;
	diff += (stop->tv_nsec - start->tv_nsec) / 1e6;
	return diff;
}