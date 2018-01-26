#include "minunit.h"
#include "../input_parameters.h"
#include "../cmd_args.h"

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



int main(int argc, char *argv[]) {
	MU_RUN_SUITE(input_parameters_suite);
	MU_REPORT();
	return 0;
}