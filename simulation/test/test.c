#include "minunit.h"
#include "stdlib.h"
#include "stdio.h"

#include "../input_parameters.h"
#include "../internal_force.h"
#include "../external_force.h"

//
// input parameters tests
//
MU_TEST(h_check) {
	mu_check(h == 0.05);
}

MU_TEST(initial_velocity_check) {
	mu_check(initial_velocities(1,1) == -23630);
}

MU_TEST(initial_masses_check) {
	mu_check(initial_masses(2) == 125252);
}

MU_TEST(initial_pos_check) {
	mu_check(initial_pos(1,1) == 6532892);
}

MU_TEST_SUITE(input_parameters_suite) {
	MU_RUN_TEST(h_check);
	MU_RUN_TEST(initial_velocity_check);
	MU_RUN_TEST(initial_masses_check);
	MU_RUN_TEST(initial_pos_check);
}

//
// internal_force
//
MU_TEST(fInternal_check) {
	// ONLY WORKS FOR D = 2 AND N > 3

	// expectet value
	double should = -1 * 1.030254536 * pow(10, -12);

	// allowed error for float
	double eps = 0.00000000000000000001;

	// masses and positions for the system
	double m[] = {54278, 1241, 1252};
	double x[3][2] = {{0, 0}, {6319, 653}, {4567, -4674}};


	mu_check(fabs(fInternal(1, 2, 0, x, m) - should) <= eps);
	mu_check(fInternal(1, 1, 0, x, m) == 0);
	mu_check(fInternal(0, 2, 0, x, m) == 0);
}

MU_TEST_SUITE(internal_force_suite) {
	MU_RUN_TEST(fInternal_check);
}

//
// external force
//
MU_TEST(fExternal_check) {
	// ONLY WORKS FOR D = 2 AND N > 3

	// expectet value
	double should = -1 * 1.118381 * pow(10, -10);

	// allowed error for float
	double eps = 0.00000000000000000001;

	// masses and positions for the system
	double m[] = {54278, 1241, 1252};
	double x[3][2] = {{0, 0}, {6319, 653}, {4567, -4674}};

	mu_check(fabs(fExternal(1, 0, x, m) - should) <= eps);
	mu_check(fExternal(0, 1, x, m) == 0);
}

MU_TEST_SUITE(external_force_suite) {
	MU_RUN_TEST(fExternal_check);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(input_parameters_suite);
	MU_RUN_SUITE(internal_force_suite);
	MU_RUN_SUITE(external_force_suite);
	MU_REPORT();
	return 0;
}