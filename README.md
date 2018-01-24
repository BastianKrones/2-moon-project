  
                         ██████╗ ███╗   ███╗ ██████╗  ██████╗ ███╗   ██╗███████╗      
                         ╚════██╗████╗ ████║██╔═══██╗██╔═══██╗████╗  ██║██╔════╝      
                          █████╔╝██╔████╔██║██║   ██║██║   ██║██╔██╗ ██║███████╗█████╗
                         ██╔═══╝ ██║╚██╔╝██║██║   ██║██║   ██║██║╚██╗██║╚════██║╚════╝
                         ███████╗██║ ╚═╝ ██║╚██████╔╝╚██████╔╝██║ ╚████║███████║      
                         ╚══════╝╚═╝     ╚═╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚══════╝      

                         ██████╗ ██████╗  ██████╗      ██╗███████╗ ██████╗████████╗   
                         ██╔══██╗██╔══██╗██╔═══██╗     ██║██╔════╝██╔════╝╚══██╔══╝   
                         ██████╔╝██████╔╝██║   ██║     ██║█████╗  ██║        ██║      
                         ██╔═══╝ ██╔══██╗██║   ██║██   ██║██╔══╝  ██║        ██║      
                         ██║     ██║  ██║╚██████╔╝╚█████╔╝███████╗╚██████╗   ██║      
                         ╚═╝     ╚═╝  ╚═╝ ╚═════╝  ╚════╝ ╚══════╝ ╚═════╝   ╚═╝      
                                                                       

## Project progress

1. Exercise 1 complete
2. Exercise 2 complete
3. Simulation
    1. Next funtion implemented
    2. Need to calculate the number of steps



### TODO-List
2. Energy Check
3. Export data --> <span style="color:red">work in progress</span>
4. Programm Gnuplot 
5. Progress status for calculation --> <span style="color:red">work in progress</span>
6. Write (Unit)-Tests --> <span style="color:red">work in progress</span>
7. Implement #ifndef to avoid multiple variable calls
8. Adjust the pow function so that there isin't a int as parameter
9. fix calculate_energy 
10. fix reference in next
11. (optional) include .json parameters
12. PARTY!!!


# Unit-Testing with `Minunit`
For more defails see https://github.com/siu/minunit
1. Write your test in `test.c`
 
```c
#include "../minunit.h"

MU_TEST(test_check) {
	mu_check(5 == 7);
}
MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_check);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
```

2. Compile your test-file `test.c` 

```
gcc test.c -lrt -lm
```
3. Run the executable 
```
./path/to/executable/a.out
```
4. Watch output
