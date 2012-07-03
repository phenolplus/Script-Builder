***********************
*      TODO list      *
***********************
Job: Setup Intermediate Code format
Job: List 1st proiority commands
Class: Intermediate Code
Class: Script Generator
Program: CLI script builder with Intermediate Code input

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