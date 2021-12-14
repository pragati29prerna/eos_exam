# EMBEDDED OPERATING SYSTEM EXAM
Open the file /usr/share/dictionary.txt in process P1 and send the strings starting with letter 'm' to process P2 using share memory. In process P2 find and print the length of string.

## Algorithm
1)  Open the dictionary.text file using the open system call in process P1.
2) Create a shared memory in the Process P1
3) Read the file content line by line and if word starts with 'm' found then send it to process P2. 
4) In the Process P2 Create a shared memory with same attributes and name and print the output and its length as received.