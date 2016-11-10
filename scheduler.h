/*
 * Changsong Li and Siyuan Ni
 * 11/07/2016
 *
 * CS 441/541: CPU Scheduler (Project 4)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>

/******************************
 * Defines
 ******************************/


/******************************
 * Structures
 ******************************/
struct process {
    int pid; // pid
    int priority; // priority
    int cpu_burst_time; // cpu_burst_time
    int waiting_time; // waiting_time
    int turnaround_time; // turnaroud_time
    int remain_time; // remain_time unused
    int status; // status
};
typedef struct process process;

/******************************
 * Global Variables
 ******************************/
int command_type = -1;
int quantum = -1;
char *filename ;
int LINELEN = 256;
process** process_arr; // pointer to an process* array
int process_num= 0;


/******************************
 * Function declarations
 ******************************/

/*
 * program function 
 * It will 1) check the command line
 * then run the schedule algorithm based on the commond line input parameters
 */
int program(int argc,char **argv);

/*
 * parse_command function
 * Parse the command 
 * The command input parameters include
 * 1)filename
 * 2)which scheduling algorithm to use
 * 3)quantum
 * Attention --> the command is not ordered !!!
 */
int parse_command(int argc,char **argv);

/*
 * schedule function
 * After parse command program will run the schedule function
 * There exists 4 scheduling algorithm
 * 1) FCFS
 * 2) SJF
 * 3) Priority
 * 4) RR
 */
void schedule();

/*
 * process_file
 * Process the file 
 * Build the struct to store the process information
 */
int process_file(char *filename);

/*
 * FCFS function
 * First-Come, First-Served scheduling algorithm
 */
void FCFS();

/*
 * SJF function
 * Shortest-Job First scheduling algorithm
 */
void SJF();

/*
 * Priority function
 */
void Priority();

/*
 * RR function
 * Round-Robin scheduling algorithm
 */
void RR();

/*
 * Print the information of each process before run the 
 * scheduling algorithm
 */
void commmon_info_echo();

/*
 * Calculate the time after run the schedulding algorithm
 */
void common_time_echo();

/* 
 * Judge whether the string is a valid int
 */
int is_valid_int(char* str);

/*
 * Tool function
 * split one string based on delimiter
 */
char** str_split(char* a_str, const char a_delim);

/*
 * Free the memory malloced before
 */
void free_memory();
