# Calculator
## Why
Chapter 4.3 describes the implementation of a "reverse Polish" calculator. For some reason, my head just cannot wrap around the concept and / or implementation. I think the problem is the book works upwards from first principles, and my brain backwards from last principles. Solution? Our own "naive" (because it will be riddled with errors and lack of support for anything outside of mainstream use-cases) implementation. Also known as "figure it out the hard way". Would it be easier to learn the first principles first and methodically apply them to the requirements? Sure. But we are wired a little bit backwards.  

To be clear, this is a *really* shitty calculator. DO NOT USE IT!  
  
## Design
- Line by line: put in as many operands and operators as you want, in whatever order you want. We figure out what you want to do and give you a result. One line. Just hit enter.  
- Support: we support positive integers and the operands: +, -, *, /. Watch this space for updates.  
- Stack: int[] or char[]?  
    - Intuitively, int[] is "easier" because "they are numbers".  
    - A small, naive test (1 + 1) shows char[] is better because:  
        - Easier to identify operators  
        - Trivial to convert operands to int (vs less trivial to convert operators)  
        - Less work: otherwise need to convert an operator from char to int, back to char  
    - BUT:  
        - We don't need to put the operators into the stack (we replace the operands leading up to the operator with the result)
        - char [] makes it hard to store negative numbers  
        - So, we are back to int []?  

## Files
- 070-stack_calculator.c  

## Get Started
`cc 070-stack_calculator -o stack_calculator -lm`, and `./stack_calculator`.

## Requirements
- [x] 4.3: add support for modulo (%) operations  
- [x] 4.3: add support for negative numbers  
- [x] 4.4: add a command to print the top element of the stack without poping it  
- [x] 4.4: add a command to duplicate the top element  
- [x] 4.4: add a command to swap the top two elements  
- [x] 4.4: add a command to clear the stack  
- [ ] 4.5: add access to library functions (sin, exp, pow)  )
- [x] 4.6: add commands for handling variables  
- [x] 4.6: add a variale for the most recently printed variable  
- [ ] 4.7: write a routine (unget) that will push back an entire string  
- [ ] 4.9: correctly handle EOF push back  
- [x] 4.10: update the calcualtor to use getline  

## SPEC
Not sure how SPEC files are (if at all) written in the industry. So this is our interpretation. We had this as a separate file but merged it into PLAN.md for simplicty. Yes, it is *wrong*.  

### Methods
- main:  
- push:  
    - signature: void push(int, int[])  
    - Puts a single int into the next available position of an int array
- pop:  
- getlines:  
- parse_line:  
- isoperator:  
- run_operation:  
- atoi:  

### External variables
- stack:  
    - <int []> of len = `MAXSTACK`  
- stack_index:  
    - Last known position an int was inserted into <stack>  
- line:  
    - 

## Pop up notes (pun not intended)
- By 5 minutes in, we already need an input parser  
- PLAN and SPEC files would be better off as a single file  
- Negative numbers on unsigned int "go around" (e.g. -3 is 253)  