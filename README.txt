***********************
*      TODO list      *
***********************
Done InterCode.h
Need to fillup implementation in .cpp file

Start working on other parts !!!

***********************
*        Usage        *
***********************
make     <--- build executable
make run <--- build and run
make clean <- clean up obj-files

***********************
* System Architecture *
***********************

     [GUI Layer]
          |
          |
    [Parser Layer]
          |
          |
  [Script Generator]

Components:
[GUI Layer]
This part will render the GUI and accept user inputs.

[Parser Layer]
This part will translate the configuration given by the [GUI layer] into a [Intermediate Code].

[Script Generator]
This part will read the [Intermediate Code] and generate a shell script with the coresponding function.

[Intermediate Code]
This is a list comtaining pseudo-commands.
