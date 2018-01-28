  
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
    1. fInternal complete
    2. fExternal comoplete
    3. acceleration complete
4. next function
    1. advanced copy function
    3. calculate orders function 



### TODO-List
1. calculate energ
2. energy check
3. export data
4. programm gnuplot 
5. progress status bar for calculation
6. next function
    1. put everything together
7. step check
12. PARTY!!!


## Arguments

| argument      | meaning                   |
|---------------|:-------------------------:|
| -h            | set initial steplenght    |

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
