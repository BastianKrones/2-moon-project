  
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

1. Exercise 1
2. Exercise 2
3. Simulation
    1. Next function
    2. Plot
    3. Energy check
    4. varriable stepsize



### TODO-List
7. some tests are missing
12. PARTY!!!


## Arguments

| argument      | meaning                   |
|---------------|:-------------------------:|
| -h            | set initial steplenght    |
| -v            | calculate the inital velocity|
| -th           | set the runtime in hours  |
| -td           | set the runtime in days   |
| -ty           | set the runtime in years  |
| -u            | set the steplenght when saving the data to the file|
| -ec           | enables energy check      |
| -sc           | enables step check (programm gets for long simulations really slow and the simulation gets really bad, probably there is a better solution for comparring 2 steps with one step)|
| -vs           | enables varriable stepsize|
| -pmin         | set minimap precition     |
| -pmax         | set maximal precition     |

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
