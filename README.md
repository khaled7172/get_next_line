## *This project has been created as part of the 42 curriculum by<khhammou>*

# Get Next Line

## Description

## Get Next Line is a project that attempts to read the buffer size and keep reading until we find a \n and to return the start of the sentence till \n inclusive and return a single line each time it is called

## Instructions
## call fucntion repeatedly to read line-by-line from a file descriptor

## Resources
## Google

## How AI was used
## AI was used to explain the algorithm step-by-step in natural language
## Clarifying edge cases and logic flow
## AI did not provide any implementation code

## Methods to test the damned code
what is Echo?
it outputs text to stdout 
pipe | takes the output and takes it and sends output to input
< : This is called input redirection, file becomes stdin
like ./a.out < test.txt redirects contents of test.txt to stdin
Here document <<(multi line input), Example
./a.out << EOF
line 1
line 2
EOF
<< means read input until you see this delimiter which is EOF here
but it can be any word
Here string <<< (single string as input):
./a.out <<< "hello world"
it takes the string and sends it to stdin
equivalent to echo "hello world" | ./a.out
echo vs printf:
echo:
echo "hello" ## outputs hello\n adds newline
echo -n "hello" ## outputs hello(no newline since we did -n)
echo -e "a\nb" ## use -e when we want to interpret \n in the text
printf:
printf "hello" ## outputs hello
printf "hello\n" ## outputs hello\n
printf "a\nb\nc" ## outputs a\nb\nc interprets \n always
Single vs Double quotes:
single quotes:
echo 'hello\nworld' ## outputs hello\nworld(literal \n not interpreted)
echo "hello\nworld" ## outputs hello\nworld (literal without -e)
echo -e "hello\nworld" outputs hello (newline) world
$'...' ANSI-C quoting, interprets escapes
echo $'hello\nworld' outputs hello (newline) world
./a.out <<< $'line1\nline2' sends actual new lines
ctrl+D sends EOF, makes read return 0
echo -e (interpret escapes)
1_ Echo with pipe
echo "hello" | ./a.out 
echo -e "hello\nworld\n\test" | ./a.out
echo -e "no newline" | ./a.out
2_ Here document (<<)
./a.out << EOF
hello
world
test
EOF
3_ Here string(<<<)
./a.out <<< "hello world"
./a.out <<< $'hello\nworld\ntest'
4_ ./a.out < test.txt
cat file1.txt file2.txt | ./a.out
5_ printf
printf "hello\nworld\test" | ./a.out
echo -n "" | ./a.out test empty input
echo "" | ./a.out just a newline
printf "no newline" | ./a.out
printf "no newline\nffs\nugh" | ./a.out
printf "%0.s*" {1..10000} | ./a.out test very long line
Quick Reference:
| pipe output to input echo "hi" | ./a.out
< File to stdin 	   ./a.out < file.txt
<< Multi-line input	   ./a.out << EOF
<<< String to stdin	   ./a.out <<< "text"
echo -e Interpret escapes
printf fromatted output
CTRL+D SEND EOF