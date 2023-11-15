// 23.11.10
// on class: recurision--a function that calls itself
// by HHC

// recursion:solving a task by first solving its subtasks

// THE THREE QUESTION:
// What is a smaller task? ******
// How to solve the task given the solution to the smaller one? ***
// What is the smallest task? *
// It will be a LOOOOOOOOOOOOG way to go to master RECURSION!!!(it is a task to be down in four years)

// WARNING:code below legal,but not use

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        return 0;
    }

    printf("%s\n", argv[argc - 1]);

    main(argc - 1, argv); // main function calls itself

    return 0;
}
