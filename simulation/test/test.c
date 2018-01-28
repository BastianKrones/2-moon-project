#include "minunit.h"
#include "stdlib.h"
#include "stdio.h"

#include "../utilities/input_parameters.h"
#include "../forces/internal_force.h"
#include "../forces/external_force.h"
#include "../forces/acceleration.h"
#include "../check_simulation/energy.h"
#include "../runge_kutta/next_copy.h"

//
// input parameters tests
//
MU_TEST(h_check)
{
	mu_check(h == 0.05);
}

MU_TEST(initial_velocity_check)
{
	mu_check(initial_velocities(1, 1) == -23630);
}

MU_TEST(initial_masses_check)
{
	mu_check(initial_masses(2) == 125252);
}

MU_TEST(initial_pos_check)
{
	mu_check(initial_pos(1, 1) == 6532892);
}

MU_TEST_SUITE(input_parameters_suite)
{
	MU_RUN_TEST(h_check);
	MU_RUN_TEST(initial_velocity_check);
	MU_RUN_TEST(initial_masses_check);
	MU_RUN_TEST(initial_pos_check);
}

//
// internal_force
//
MU_TEST(fInternal_check)
{
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

MU_TEST_SUITE(internal_force_suite)
{
	MU_RUN_TEST(fInternal_check);
}

//
// external force
//
MU_TEST(fExternal_check)
{

	// expected value
	double should = -1 * 1.11838089 * pow(10, -10);

	// allowed error for float
	double eps = 0.000000000000000001;

	// masses and positions for the system
	double m[] = {54278, 1241, 1252};
	double x[3][2] = {{0, 0}, {6319, 653}, {4567, -4674}};

	mu_check(fabs(fExternal(1, 0, x, m) - should) <= eps);
	mu_check(fExternal(0, 1, x, m) == 0);
}

MU_TEST_SUITE(external_force_suite)
{
	MU_RUN_TEST(fExternal_check);
}

//
// acceleration
//
MU_TEST(calculate_acceleration_check)
{

	//expected value
	double should = -1 * 9.011933036 * pow(10, -14);

	// allowed error for float
	double eps = 0.000000000000000001;

	// masses and positions for the system
	double m[] = {54278, 1241, 1252};
	double x[3][2] = {{0, 0}, {6319, 653}, {4567, -4674}};

	mu_check(fabs(calculate_acceleration(1, 0, x, m) - should) <= eps);
	mu_check(calculate_acceleration(0, 1, x, m) == 0);
}

MU_TEST_SUITE(acceleration_suite)
{
	MU_RUN_TEST(calculate_acceleration_check);
}

//
// energy
//
MU_TEST(kin_energy_check)
{

	// expected value
	long double should = 661663058491691136;

	// allowed error for float
	double eps = 0.0000000000000000001;

	double v[3][2] = {{0, 0}, {325634, -23630}, {15324, -36234}};
	double m[] = {542781632, 12414421, 125252};

	mu_check(fabs(calculate_kin_energy(1, v, m) - should) <= eps);
}

MU_TEST_SUITE(energy_suite)
{
	MU_RUN_TEST(kin_energy_check);
}

// next_copy
//
MU_TEST(adv_copy_check)
{
	double xprime[3][2];
	double vprime[3][2];

	//allowed float error
	double eps = 0.000000000000000001;

	// masses, position and speeds for the Test system
	double x[3][2] = {{0, 0}, {6319, 653}, {4567, -4674}};
	double v[3][2] = {{0, 0}, {325634, -23630}, {15324, -36234}};
	double k[3][2][4] = {{{2, 4, 6, 3}, {3.5, 7.3, 3.5, 7.4}}, {{4.7, 3.8, 5.87, 3.7}, {7.3, 5.7, 2.5, 7.8}}, {{6.3, 5.9, 2.6, 8.9}, {44.7, 3.9, 5.9, 3.6}}};
	double w[3][2][4] = {{{3.7, 4.7, 5.9, 5.7}, {4.7, 3.5, 8.9, 5.4}}, {{4.6, 77.9, 4.4, 3.7}, {4.6, 7.4, 5.6, 7.9}}, {{2.6, 7.8, 95.34, 5.5}, {2.5, 3.6, 4.2, 4.7}}};

	//mode 0
	adv_copy(vprime, xprime, v, x, 0, w, k);
	mu_check(xprime[1][0] == x[1][0]);
	mu_check(vprime[1][0] == v[1][0]);

	//mode 1
	adv_copy(vprime, xprime, v, x, 1, w, k);
	mu_check(fabs(xprime[1][0] - 6320.9) <= eps);
	mu_check(fabs(vprime[1][0] - 325672.95) <= eps);

	//mode 2
	adv_copy(vprime, xprime, v, x, 2, w, k);
	mu_check(fabs(xprime[1][0] - 6321.935) <= eps);
	mu_check(fabs(vprime[1][0] - 325636.2) <= eps);

	//mode 3
	adv_copy(vprime, xprime, v, x, 3, w, k);
	mu_check(fabs(xprime[1][0] - 6322.7) <= eps);
	mu_check(fabs(vprime[1][0] - 325637.7) <= eps);
}

MU_TEST_SUITE(next_copy_suite)
{
	MU_RUN_TEST(adv_copy_check);
}

int main(int argc, char *argv[])
{
	// ONLY WORKS FOR D = 2 AND N > 3
	if (D == 2 && N >= 3)
	{
		MU_RUN_SUITE(input_parameters_suite);
		MU_RUN_SUITE(internal_force_suite);
		MU_RUN_SUITE(external_force_suite);
		MU_RUN_SUITE(acceleration_suite);
		MU_RUN_SUITE(energy_suite);
		MU_RUN_SUITE(next_copy_suite);
		MU_REPORT();
	}
	else
	{
		printf("ERROR: tests work only for D = 2 and N >= 3");
	}
	return 0;
}
